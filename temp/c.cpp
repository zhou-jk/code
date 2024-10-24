#include<bits/stdc++.h>
using namespace std;
constexpr int W = 64;
class Bitset {
private:
    vector<unsigned long long> a;
    int numBits;

    int highBit(unsigned long long x) const {
        return W - 1 - __builtin_clzll(x);
    }

    int lowBit(unsigned long long x) const {
        return __builtin_ffsll(x) - 1;
    }

public:
    Bitset(int size) : a((size + W - 1) / W, 0), numBits(size) {}

    // Copy constructor
    Bitset(const Bitset& other) : a(other.a), numBits(other.numBits) {}

    // Copy assignment operator
    Bitset& operator=(const Bitset& other) {
        if (this != &other) {
            a = other.a;
            numBits = other.numBits;
        }
        return *this;
    }

    // Move constructor
    Bitset(Bitset&& other) noexcept : a(std::move(other.a)), numBits(other.numBits) {
        other.numBits = 0;
    }

    void applyShiftLeft(int shift, int start, int end) {
        if (shift == 0) return;

        int startBlock = start / W;
        int endBlock = (end - 1) / W;
        int startOffset = start % W;
        int endOffset = (end - 1) % W + 1;

        if (shift >= end - start) {
            for (int i = startBlock; i <= endBlock; ++i) {
                a[i] &= ~(((1ull << (min(endOffset, W) - (i == startBlock ? startOffset : 0))) - 1) << (i == startBlock ? startOffset : 0));
            }
            return;
        }

        int blockShift = shift / W;
        int bitShift = shift % W;

        for (int i = endBlock; i >= startBlock; --i) {
            unsigned long long newValue = 0;
            if (i - blockShift >= startBlock) {
                newValue |= (a[i - blockShift] << bitShift);
                if (bitShift && i - blockShift - 1 >= startBlock) {
                    newValue |= (a[i - blockShift - 1] >> (W - bitShift));
                }
            }
            if (i == startBlock) {
                newValue &= (((1ull << (min(endOffset, W) - startOffset)) - 1) << startOffset);
            }
            a[i] &= ~(((1ull << (min(endOffset, W) - (i == startBlock ? startOffset : 0))) - 1) << (i == startBlock ? startOffset : 0));
            a[i] |= newValue;
        }
    }

    void applyShiftRight(int shift, int start, int end) {
        if (shift == 0) return;

        int startBlock = start / W;
        int endBlock = (end - 1) / W;
        int startOffset = start % W;
        int endOffset = (end - 1) % W + 1;

        if (shift >= end - start) {
            for (int i = startBlock; i <= endBlock; ++i) {
                a[i] &= ~(((1ull << (min(endOffset, W) - (i == startBlock ? startOffset : 0))) - 1) << (i == startBlock ? startOffset : 0));
            }
            return;
        }

        int blockShift = shift / W;
        int bitShift = shift % W;

        for (int i = startBlock; i <= endBlock; ++i) {
            unsigned long long newValue = 0;
            if (i + blockShift <= endBlock) {
                newValue |= (a[i + blockShift] >> bitShift);
                if (bitShift && i + blockShift + 1 <= endBlock) {
                    newValue |= (a[i + blockShift + 1] << (W - bitShift));
                }
            }
            if (i == startBlock) {
                newValue &= (((1ull << (min(endOffset, W) - startOffset)) - 1) << startOffset);
            }
            a[i] &= ~(((1ull << (min(endOffset, W) - (i == startBlock ? startOffset : 0))) - 1) << (i == startBlock ? startOffset : 0));
            a[i] |= newValue;
        }
    }

    // Move assignment operator
    Bitset& operator=(Bitset&& other) noexcept {
        if (this != &other) {
            a = std::move(other.a);
            numBits = other.numBits;
            other.numBits = 0;
        }
        return *this;
    }

    // 支持 << 区间
    Bitset operator<<(int shift) const {
        Bitset res = *this;
        res <<= shift;
        return res;
    }

    // 支持 >> 区间
    Bitset operator>>(int shift) const {
        Bitset res = *this;
        res >>= shift;
        return res;
    }

    // 支持 <<=
    Bitset& operator<<=(int shift) {
        if (shift >= numBits) {
            fill(a.begin(), a.end(), 0);
            return *this;
        }

        applyShiftLeft(shift, 0, numBits);
        return *this;
    }

    // 支持 >>=
    Bitset& operator>>=(int shift) {
        if (shift >= numBits) {
            fill(a.begin(), a.end(), 0);
            return *this;
        }

        applyShiftRight(shift, 0, numBits);
        return *this;
    }

    // 支持 []
    bool operator[](int index) const {
        if (index < 0 || index >= numBits) {
            throw out_of_range("Index out of range");
        }
        int blockIndex = index / W;
        int bitIndex = index % W;
        return (a[blockIndex] >> bitIndex) & 1;
    }

    // 支持从高到低的第一个置位
    int highestSetBit() const {
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != 0) {
                return min(i * W + highBit(a[i]), numBits - 1);
            }
        }
        return -1;
    }

    // 支持从高到低的下一个置位
    int nextHighestSetBit(int index) const {
        if (index < 0 || index >= numBits) {
            return -1;
        }
        int blockIndex = index / W;
        int bitIndex = index % W;
        unsigned long long mask;
        if (bitIndex == 0) {
            mask = 0;
        } else {
            mask = (1ull << bitIndex) - 1;
        }
        if ((a[blockIndex] & mask) != 0) {
            return blockIndex * W + highBit(a[blockIndex] & mask);
        }

        for (int i = blockIndex - 1; i >= 0; --i) {
            if (a[i] != 0) {
                return i * W + highBit(a[i]);
            }
        }

        return -1;
    }

    // 支持从低到高的第一个置位
    int lowestSetBit() const {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != 0) {
                return min(i * W + lowBit(a[i]), numBits - 1);
            }
        }
        return -1;
    }

    // 支持从低到高的下一个置位
    int nextLowestSetBit(int index) const {
        if (index < 0 || index >= numBits) {
            return -1;
        }
        int blockIndex = index / W;
        int bitIndex = index % W;
        unsigned long long mask;
        if (bitIndex == W - 1) {
            mask = 0;
        } else {
            mask = ~((1ull << (bitIndex + 1)) - 1);
        }
        if ((a[blockIndex] & mask) != 0) {
            return blockIndex * W + lowBit(a[blockIndex] & mask);
        }

        for (int i = blockIndex + 1; i < a.size(); ++i) {
            if (a[i] != 0) {
                return i * W + lowBit(a[i]);
            }
        }

        return -1;
    }

    // 支持 count
    int count() const {
        int cnt = 0;
        for (auto block : a) {
            cnt += __builtin_popcountll(block);
        }
        return cnt;
    }

    // 支持 any
    bool any() const {
        for (auto block : a) {
            if (block != 0) {
                return true;
            }
        }
        return false;
    }

    // 支持 none
    bool none() const {
        return !any();
    }

    // 支持 all
    bool all() const {
        for (int i = 0; i < numBits; ++i) {
            if (!(*this)[i]) {
                return false;
            }
        }
        return true;
    }

    // 支持 flip
    void flip() {
        for (auto& block : a) {
            block = ~block;
        }
        // Make sure no bits beyond numBits are set
        if (numBits % W != 0) {
            a.back() &= (1ull << (numBits % W)) - 1;
        }
    }

    // 支持 flip(int index)
    void flip(int index) {
        if (index < 0 || index >= numBits) {
            throw out_of_range("Index out of range");
        }
        int blockIndex = index / W;
        int bitIndex = index % W;
        a[blockIndex] ^= (1ull << bitIndex);
    }

    // 支持 set(int index)
    void set(int index) {
        if (index < 0 || index >= numBits) {
            throw out_of_range("Index out of range");
        }
        int blockIndex = index / W;
        int bitIndex = index % W;
        a[blockIndex] |= (1ull << bitIndex);
    }

    // 支持 set(int index, bool value)
    void set(int index, bool value) {
        if (value) {
            set(index);
        } else {
            reset(index);
        }
    }

    // 支持 set()
    void set() {
        for (auto& block : a) {
            block = ~0ull;
        }
        // Make sure no bits beyond numBits are set
        if (numBits % W != 0) {
            a.back() &= (1ull << (numBits % W)) - 1;
        }
    }

    // 支持 reset(int index)
    void reset(int index) {
        if (index < 0 || index >= numBits) {
            throw out_of_range("Index out of range");
        }
        int blockIndex = index / W;
        int bitIndex = index % W;
        a[blockIndex] &= ~(1ull << bitIndex);
    }

    // 支持 reset()
    void reset() {
        fill(a.begin(), a.end(), 0);
    }

    // 支持 |=
    Bitset& operator|=(const Bitset& other) {
        if (numBits != other.numBits) {
            throw invalid_argument("Bitsets must be of the same size");
        }
        for (int i = 0; i < a.size(); ++i) {
            a[i] |= other.a[i];
        }
        return *this;
    }

    // 支持 |
    Bitset operator|(const Bitset& other) const {
        Bitset res = *this;
        res |= other;
        return res;
    }

    // 支持 &=
    Bitset& operator&=(const Bitset& other) {
        if (numBits != other.numBits) {
            throw invalid_argument("Bitsets must be of the same size");
        }
        for (int i = 0; i < a.size(); ++i) {
            a[i] &= other.a[i];
        }
        return *this;
    }

    // 支持 &
    Bitset operator&(const Bitset& other) const {
        Bitset res = *this;
        res &= other;
        return res;
    }

    // 支持 ^=
    Bitset& operator^=(const Bitset& other) {
        if (numBits != other.numBits) {
            throw invalid_argument("Bitsets must be of the same size");
        }
        for (int i = 0; i < a.size(); ++i) {
            a[i] ^= other.a[i];
        }
        return *this;
    }

    // 支持 ^
    Bitset operator^(const Bitset& other) const {
        Bitset res = *this;
        res ^= other;
        return res;
    }

    // 支持 ~
    Bitset operator~() const {
        Bitset res = *this;
        for (int i = 0; i < a.size(); ++i) {
            res.a[i] = ~a[i];
        }
        if (numBits % W != 0) {
            res.a.back() &= (1ull << (numBits % W)) - 1;
        }
        return res;
    }

    // 支持 size
    int size() const {
        return numBits;
    }

    // 支持 test
    bool test(int index) const {
        return (*this)[index];
    }

    // 支持 to_ullong
    unsigned long long to_ullong() const {
        if (numBits > W) {
            throw overflow_error("Bitset size exceeds unsigned long long capacity");
        }
        return a[0] & ((1ull << numBits) - 1);
    }

    // 支持 to_ulong
    unsigned long to_ulong() const {
        if (numBits > sizeof(unsigned long) * CHAR_BIT) {
            throw overflow_error("Bitset size exceeds unsigned long capacity");
        }
        return static_cast<unsigned long>(a[0] & ((1ul << numBits) - 1));
    }

    // 支持 print（用于调试）
    void print() const {
        for (int i = 0; i < numBits; ++i) {
            cout << (*this)[i];
            if ((i + 1) % W == 0) cout << " ";
        }
        cout << endl;
    }

    class iterator {
    public:
        using iterator_category = bidirectional_iterator_tag;
        using difference_type = int;
        using value_type = int;
        using pointer = const int*;
        using reference = const int&;

    private:
        const Bitset* bitset;
        int index;

    public:
        iterator(const Bitset* bitset, int index) : bitset(bitset), index(index) {}

        value_type operator*() const { return index; }

        iterator& operator++() {
            index = bitset->nextLowestSetBit(index);
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator& operator--() {
            if (index == -1) {
                index = bitset->highestSetBit();
            } else {
                index = bitset->nextHighestSetBit(index);
            }
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        friend bool operator==(const iterator& a, const iterator& b) {
            return a.index == b.index;
        }

        friend bool operator!=(const iterator& a, const iterator& b) {
            return a.index != b.index;
        }
    };

    class reverse_iterator {
    public:
        using iterator_category = bidirectional_iterator_tag;
        using difference_type = int;
        using value_type = int;
        using pointer = const int*;
        using reference = const int&;

    private:
        const Bitset* bitset;
        int index;

    public:
        reverse_iterator(const Bitset* bitset, int index) : bitset(bitset), index(index) {}

        value_type operator*() const { return index; }

        reverse_iterator& operator++() {
            index = bitset->nextHighestSetBit(index);
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        reverse_iterator& operator--() {
            if (index == -1) {
                index = bitset->lowestSetBit();
            } else {
                index = bitset->nextLowestSetBit(index);
            }
            return *this;
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        friend bool operator==(const reverse_iterator& a, const reverse_iterator& b) {
            return a.index == b.index;
        }

        friend bool operator!=(const reverse_iterator& a, const reverse_iterator& b) {
            return a.index != b.index;
        }
    };

    iterator begin() const {
        int idx = lowestSetBit();
        return idx == -1 ? end() : iterator(this, idx);
    }

    iterator end() const {
        return iterator(this, numBits);
    }

    reverse_iterator rbegin() const {
        return reverse_iterator(this, highestSetBit());
    }

    reverse_iterator rend() const {
        return reverse_iterator(this, -1);
    }
};
const int N=5005,M=1000005;
int n,m;
int a[M],b[M];
int fa[N*4];
int siz[N*4];
int num[N*4][2];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int fu=getf(u),fv=getf(v);
    if(fu!=fv)
    {
        num[fu][0]+=num[fv][(fu>n*2)^(fv>n*2)];
        num[fu][1]+=num[fv][(fu>n*2)^(fv>n*2)^1];
        fa[fv]=fu;
    }
    return;
}
vector<pair<int,int>>G[N*2];
int col[N*2];
int cnt[2];
bitset<N>f[N*2];
int tot=0;
int rt[N*2],c[N*2][2];
vector<int>pos;
void dfs(int u,int color)
{
    pos.emplace_back(u);
    col[u]=color;
    cnt[color]++;
    for(auto [v,w]:G[u])
        if(col[v]==-1) dfs(v,color^w);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=n*4;i++)
        fa[i]=i,num[i][0]=1;
    vector<int>val;
    for(int i=1;i<=n*2;i++)
        val.emplace_back(1);
    int sum=0;
    for(int i=m;i>=1;i--)
    {
        int u=a[i],v=b[i];
        if(getf(u)==getf(v)||getf(u+n*2)==getf(v+n*2)) continue;
        if(getf(u)==getf(v+n*2)||getf(u+n*2)==getf(v)) continue;
        u=getf(u),v=getf(v);
        int w=1;
        cnt[0]=num[u][0],cnt[1]=num[u][1];
        if(u>n*2) w^=1,u-=n*2;
        int cu[2]={cnt[0],cnt[1]};
        if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
        sum-=cnt[0];
        val.erase(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]));
        cnt[0]=num[v][0],cnt[1]=num[v][1];
        if(v>n*2) w^=1,v-=n*2;
        int cv[2]={cnt[0],cnt[1]};
        if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
        sum-=cnt[0];
        val.erase(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]));
        cnt[0]=cu[0]+cv[w],cnt[1]=cu[1]+cv[w^1];
        if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
        sum+=cnt[0];
        val.insert(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]),cnt[1]-cnt[0]);
//             cerr<<"sum"<<sum<<'\n';
//             cerr<<"ins"<<cu[0]<<" "<<cv[1]<<"\n";
//             int tmp=0;
//             for(auto [c0,c1]:val)
//                 cerr<<"find"<<c0<<" "<<c1<<"\n",tmp+=c0;
//        assert(tmp==sum);
        if(sum>n)
        {
            val.erase(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]));
            sum-=cnt[0];
            cnt[0]=cu[0]+cv[w^1],cnt[1]=cu[1]+cv[w];
            if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
            val.insert(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]),cnt[1]-cnt[0]);
            sum+=cnt[0];
            if(w)
            {
                merge(u,v);
                merge(u+n*2,v+n*2);
            }
            else
            {
                merge(u,v+n*2);
                merge(u+n*2,v);
            }
            G[u].emplace_back(v,w^1);
            G[v].emplace_back(u,w^1);
            continue;
        }
        int ret=n-sum;
        Bitset f(N);
        f.set(0);
        for(auto c10:val)
        {
            f|=f<<c10;
            if(f[ret]) break;
        }
        if(!f[ret])
        {
            val.erase(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]));
            sum-=cnt[0];
            cnt[0]=cu[0]+cv[w^1],cnt[1]=cu[1]+cv[w];
            if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
            val.insert(lower_bound(val.begin(),val.end(),cnt[1]-cnt[0]),cnt[1]-cnt[0]);
            sum+=cnt[0];
            if(w)
            {
                merge(u,v);
                merge(u+n*2,v+n*2);
            }
            else
            {
                merge(u,v+n*2);
                merge(u+n*2,v);
            }
            G[u].emplace_back(v,w^1);
            G[v].emplace_back(u,w^1);
            continue;
        }
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
        if(w)
        {
            merge(u,v+n*2);
            merge(u+n*2,v);
        }
        else
        {
            merge(u,v);
            merge(u+n*2,v+n*2);
        }
//        cerr<<"Add"<<i<<"\n";
    }
    fill(col+1,col+n*2+1,-1);
    f[0][0]=1;
    tot=0;
    for(int u=1;u<=n*2;u++)
    {
        if(col[u]==-1)
        {
            cnt[0]=cnt[1]=0;
            dfs(u,0);
            rt[++tot]=u;
            c[tot][0]=cnt[0],c[tot][1]=cnt[1];
            f[tot]=(f[tot-1]<<cnt[0])|(f[tot-1]<<cnt[1]);
        }
    }
    assert(f[tot][n]);
    fill(col+1,col+n*2+1,-1);
    int ret=n;
    for(int i=tot;i>=1;i--)
    {
        int u=rt[i];
        if(ret>=c[i][0]&&f[i-1][ret-c[i][0]])
        {
            ret-=c[i][0];
            dfs(u,0);
        }
        else
        {
            ret-=c[i][1];
            dfs(u,1);
        }
    }
    for(int u=1;u<=n*2;u++)
        cout<<col[u];
    return 0;
}