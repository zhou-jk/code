#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
static const long long SCALE = 10000000LL;
static const __int128 LIM_SCALED = (__int128)1000000000LL * (__int128)SCALE;
static inline uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
struct SegKey {
    long long x1, y1, x2, y2; // normalized: horizontal x1<x2, y1==y2; vertical y1<y2, x1==x2
    bool operator==(const SegKey& other) const noexcept {
        return x1==other.x1 && y1==other.y1 && x2==other.x2 && y2==other.y2;
    }
};

struct SegKeyHash {
    size_t operator()(const SegKey& k) const noexcept {
        uint64_t h = 0;
        h ^= splitmix64((uint64_t)k.x1);
        h ^= splitmix64((uint64_t)k.y1 + 0x12345678ULL);
        h ^= splitmix64((uint64_t)k.x2 + 0x9abcdef0ULL);
        h ^= splitmix64((uint64_t)k.y2 + 0xfedcba98ULL);
        return (size_t)h;
    }
};

// --------- parsing (strict decimal, <= 7 digits after dot) ----------
static long long parseIntTokenOrWA(const string& tok, long long lo, long long hi, const char* name) {
    if (tok.empty()) quitf(_wa, "Empty token for %s.", name);
    for (char c : tok) if (!isdigit((unsigned char)c)) quitf(_wa, "Invalid integer token for %s: '%s'.", name, tok.c_str());
    __int128 v = 0;
    for (char c : tok) {
        v = v * 10 + (c - '0');
        if (v > (__int128)hi) break;
    }
    if (v < (__int128)lo || v > (__int128)hi) quitf(_wa, "%s out of range: %s (expected [%lld..%lld]).", name, tok.c_str(), lo, hi);
    return (long long)v;
}

static long long parseScaledDecimalOrWA(const string& tok, const char* name) {
    if (tok.empty()) quitf(_wa, "Empty token for %s.", name);
    int p = 0;
    bool neg = false;
    if (tok[p] == '-') { neg = true; p++; }
    else if (tok[p] == '+') { p++; } // tolerate '+'
    if (p >= (int)tok.size()) quitf(_wa, "Invalid number for %s: '%s'.", name, tok.c_str());

    __int128 intPart = 0;
    int intDigits = 0;

    while (p < (int)tok.size() && isdigit((unsigned char)tok[p])) {
        intPart = intPart * 10 + (tok[p] - '0');
        p++;
        intDigits++;
        // no early overflow needed; we clamp by range later
    }
    if (intDigits == 0) quitf(_wa, "Invalid number for %s: '%s' (no integer digits).", name, tok.c_str());

    __int128 fracPart = 0;
    int fracDigits = 0;

    if (p < (int)tok.size()) {
        if (tok[p] != '.') quitf(_wa, "Invalid number for %s: '%s' (unexpected character).", name, tok.c_str());
        p++;
        while (p < (int)tok.size() && isdigit((unsigned char)tok[p])) {
            if (fracDigits < 7) {
                fracPart = fracPart * 10 + (tok[p] - '0');
            }
            fracDigits++;
            p++;
        }
        if (p != (int)tok.size()) quitf(_wa, "Invalid number for %s: '%s' (trailing garbage).", name, tok.c_str());
        if (fracDigits > 7) quitf(_wa, "Too many digits after decimal for %s: '%s'.", name, tok.c_str());
    }

    // pad fraction to 7 digits
    while (fracDigits < 7) { fracPart *= 10; fracDigits++; }

    __int128 val = intPart * (__int128)SCALE + fracPart;
    if (neg) val = -val;

    if (val < -LIM_SCALED || val > LIM_SCALED) {
        quitf(_wa, "Coordinate %s out of range [-1e9,1e9]: '%s'.", name, tok.c_str());
    }
    return (long long)val;
}

// format helper for debug (not performance-critical)
static string fmtScaled(long long v) {
    bool neg = v < 0;
    unsigned long long a = (unsigned long long)(neg ? -(__int128)v : (__int128)v);
    unsigned long long ip = a / (unsigned long long)SCALE;
    unsigned long long fp = a % (unsigned long long)SCALE;
    string s = (neg ? "-" : "");
    s += to_string(ip);
    if (fp != 0ULL) {
        string f = to_string(fp + (unsigned long long)SCALE).substr(1); // 7 digits
        // trim trailing zeros
        while (!f.empty() && f.back() == '0') f.pop_back();
        s += ".";
        s += f;
    }
    return s;
}

struct HSeg { long long x1, x2, y; int eid; }; // horizontal
struct VSeg { long long x, y1, y2; int eid; }; // vertical

static inline bool isAdjEdge(int a, int b, int m) {
    return ((a + 1) % m == b) || ((b + 1) % m == a);
}

static inline bool isEndpoint(const vector<long long>& xs, const vector<long long>& ys, int m, int eid, long long x, long long y) {
    int j = eid + 1;
    if (j == m) j = 0;
    return (xs[eid] == x && ys[eid] == y) || (xs[j] == x && ys[j] == y);
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    unordered_map<SegKey, int, SegKeyHash> segMap;
    segMap.reserve((size_t)n * 2);
    segMap.max_load_factor(0.7f);

    for (int i = 0; i < n; i++) {
        long long x1 = inf.readLong();
        long long y1 = inf.readLong();
        long long x2 = inf.readLong();
        long long y2 = inf.readLong();

        // scale input by 1e7
        x1 *= SCALE; y1 *= SCALE; x2 *= SCALE; y2 *= SCALE;

        SegKey k;
        if (x1 == x2) {
            if (y1 == y2) quitf(_fail, "Input has zero-length segment, impossible by statement.");
            if (y1 > y2) swap(y1, y2);
            k = {x1, y1, x2, y2};
        } else if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            k = {x1, y1, x2, y2};
        } else {
            quitf(_fail, "Input has non-axis-aligned segment, impossible by statement.");
        }
        segMap.emplace(k, i);
    }

    // Jury: decides feasibility
    string juryFirst = ans.readToken();
    bool juryImpossible = (juryFirst == "NIE");

    // Contestant output
    string first = ouf.readToken();

    if (first == "NIE") {
        ouf.skipBlanks();
        if (!ouf.eof()) quitf(_wa, "Extra output after NIE.");
        if (!juryImpossible) quitf(_wa, "Contestant outputs NIE but solution exists (according to jury).");
        quitf(_ok, "Correct: NIE.");
    }

    if (juryImpossible) {
        quitf(_wa, "Contestant outputs a polygon but jury says NIE.");
    }

    long long mll = parseIntTokenOrWA(first, 4LL, 20LL * (long long)n, "m");
    int m = (int)mll;

    vector<long long> xs(m), ys(m);
    for (int i = 0; i < m; i++) {
        string tx = ouf.readToken();
        string ty = ouf.readToken();
        xs[i] = parseScaledDecimalOrWA(tx, "x");
        ys[i] = parseScaledDecimalOrWA(ty, "y");
    }
    ouf.skipBlanks();
    if (!ouf.eof()) quitf(_wa, "Extra tokens after reading all vertices.");

    // Build edges; also match input segments
    vector<unsigned char> isHoriz(m, 0);
    vector<HSeg> hs; hs.reserve(m/2 + 1);
    vector<VSeg> vs; vs.reserve(m/2 + 1);

    vector<char> used(n, 0);
    int matched = 0;

    for (int i = 0; i < m; i++) {
        int j = i + 1; if (j == m) j = 0;
        long long x1 = xs[i], y1 = ys[i];
        long long x2 = xs[j], y2 = ys[j];

        if (x1 == x2 && y1 == y2) {
            quitf(_wa, "Zero-length edge between vertex %d and %d.", i+1, j+1);
        }
        if (x1 != x2 && y1 != y2) {
            quitf(_wa, "Non-axis-aligned edge at %d: (%s,%s)->(%s,%s).",
                  i+1, fmtScaled(x1).c_str(), fmtScaled(y1).c_str(), fmtScaled(x2).c_str(), fmtScaled(y2).c_str());
        }

        bool horiz = (y1 == y2);
        isHoriz[i] = (unsigned char)horiz;

        if (horiz) {
            long long lx = min(x1, x2), rx = max(x1, x2);
            HSeg h{lx, rx, y1, i};
            hs.push_back(h);

            SegKey k{lx, y1, rx, y1};
            auto it = segMap.find(k);
            if (it != segMap.end()) {
                int idx = it->second;
                if (used[idx]) quitf(_wa, "Input segment #%d is used multiple times in polygon edges.", idx+1);
                used[idx] = 1;
                matched++;
            }
        } else {
            long long ly = min(y1, y2), uy = max(y1, y2);
            VSeg v{x1, ly, uy, i};
            vs.push_back(v);

            SegKey k{x1, ly, x1, uy};
            auto it = segMap.find(k);
            if (it != segMap.end()) {
                int idx = it->second;
                if (used[idx]) quitf(_wa, "Input segment #%d is used multiple times in polygon edges.", idx+1);
                used[idx] = 1;
                matched++;
            }
        }
    }

    if (matched != n) {
        quitf(_wa, "Not all input segments are polygon edges: matched %d of %d.", matched, n);
    }

    // consecutive edges must be perpendicular (including last-first)
    for (int i = 0; i < m; i++) {
        int j = i + 1; if (j == m) j = 0;
        if (isHoriz[i] == isHoriz[j]) {
            quitf(_wa, "Consecutive edges %d and %d are parallel.", i+1, j+1);
        }
    }

    // parallel overlap/touch checks for horizontals
    sort(hs.begin(), hs.end(), [](const HSeg& a, const HSeg& b){
        if (a.y != b.y) return a.y < b.y;
        if (a.x1 != b.x1) return a.x1 < b.x1;
        return a.x2 < b.x2;
    });
    for (size_t i = 1; i < hs.size(); i++) {
        if (hs[i].y == hs[i-1].y) {
            if (hs[i].x1 <= hs[i-1].x2) {
                quitf(_wa, "Horizontal edges intersect/overlap/touch at y=%s.", fmtScaled(hs[i].y).c_str());
            }
        }
    }

    // parallel overlap/touch checks for verticals
    sort(vs.begin(), vs.end(), [](const VSeg& a, const VSeg& b){
        if (a.x != b.x) return a.x < b.x;
        if (a.y1 != b.y1) return a.y1 < b.y1;
        return a.y2 < b.y2;
    });
    for (size_t i = 1; i < vs.size(); i++) {
        if (vs[i].x == vs[i-1].x) {
            if (vs[i].y1 <= vs[i-1].y2) {
                quitf(_wa, "Vertical edges intersect/overlap/touch at x=%s.", fmtScaled(vs[i].x).c_str());
            }
        }
    }

    // sweep to detect H-V intersections (only adjacent endpoint intersections allowed)
    // Prepare orders for horizontals by x1 and x2
    int H = (int)hs.size();
    vector<int> ordX1(H), ordX2(H);
    iota(ordX1.begin(), ordX1.end(), 0);
    iota(ordX2.begin(), ordX2.end(), 0);

    sort(ordX1.begin(), ordX1.end(), [&](int a, int b){
        if (hs[a].x1 != hs[b].x1) return hs[a].x1 < hs[b].x1;
        if (hs[a].x2 != hs[b].x2) return hs[a].x2 < hs[b].x2;
        return hs[a].y < hs[b].y;
    });
    sort(ordX2.begin(), ordX2.end(), [&](int a, int b){
        if (hs[a].x2 != hs[b].x2) return hs[a].x2 < hs[b].x2;
        if (hs[a].x1 != hs[b].x1) return hs[a].x1 < hs[b].x1;
        return hs[a].y < hs[b].y;
    });

    // Vertical segments already sorted by x (from earlier), but we changed sorting for overlap check.
    // Ensure sorted by x for sweep:
    vector<int> ordV((int)vs.size());
    iota(ordV.begin(), ordV.end(), 0);
    sort(ordV.begin(), ordV.end(), [&](int a, int b){
        if (vs[a].x != vs[b].x) return vs[a].x < vs[b].x;
        if (vs[a].y1 != vs[b].y1) return vs[a].y1 < vs[b].y1;
        return vs[a].y2 < vs[b].y2;
    });

    // Active horizontals at current x: store (y, edgeId)
    std::set<pair<long long,int>> active;

    int pAdd = 0, pRem = 0;

    for (int idxV : ordV) {
        const VSeg& v = vs[idxV];
        long long curX = v.x;

        while (pAdd < H && hs[ordX1[pAdd]].x1 <= curX) {
            const HSeg& h = hs[ordX1[pAdd]];
            active.insert({h.y, h.eid});
            pAdd++;
        }
        while (pRem < H && hs[ordX2[pRem]].x2 < curX) {
            const HSeg& h = hs[ordX2[pRem]];
            auto it = active.find({h.y, h.eid});
            if (it != active.end()) active.erase(it);
            pRem++;
        }

        auto it = active.lower_bound({v.y1, std::numeric_limits<int>::min()});
        int cnt = 0;

        while (it != active.end() && it->first <= v.y2) {
            long long iy = it->first;
            int hid = it->second;
            long long ix = curX;

            bool ok = isAdjEdge(v.eid, hid, m)
                      && isEndpoint(xs, ys, m, v.eid, ix, iy)
                      && isEndpoint(xs, ys, m, hid, ix, iy);

            if (!ok) {
                quitf(_wa,
                      "Forbidden intersection between edges %d and %d at (%s,%s).",
                      v.eid + 1, hid + 1, fmtScaled(ix).c_str(), fmtScaled(iy).c_str());
            }

            cnt++;
            if (cnt > 2) {
                quitf(_wa, "Vertical edge %d intersects more than 2 horizontals (self-intersection).", v.eid + 1);
            }
            ++it;
        }

        if (cnt != 2) {
            quitf(_wa, "Vertical edge %d has %d intersections with horizontals; expected 2.", v.eid + 1, cnt);
        }
    }

    quitf(_ok, "Polygon is valid and contains all %d segments; m=%d.", n, m);
}
