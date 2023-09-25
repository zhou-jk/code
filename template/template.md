#### Max Flow

```cpp
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=205,M=10005;
const long long INF=4557430888798830399;
struct Edge
{
	int from,to,next;
	long long val;
}edge[M];
int cur[N],head[N],cnt=1;
int n,m,s,t;
void add_edge(int u,int v,int w)
{
	cnt++;
    edge[cnt].from=u;
	edge[cnt].to=v;
	edge[cnt].val=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
int dep[N];
bool bfs(int s,int t)
{
    for(int i=1;i<=n;i++)
        dep[i]=-1;
	queue<int>q;
	q.push(s);
	dep[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dep[v]!=-1||edge[i].val<=0) continue;
			dep[v]=dep[u]+1;
			q.push(v);
		}
	}
	return dep[t]!=-1;
}
int pre[N];
long long dfs(int u,long long flow)
{
    if(u==t)
    {
        
    }
	if(u==t||flow==0) return flow;
	long long used=0;
	for(int &i=cur[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(dep[v]!=dep[u]+1||edge[i].val<=0) continue;
		long long now=dfs(v,min(flow,(long long)edge[i].val));
		flow-=now;
		edge[i].val-=now;
		edge[i^1].val+=now;
		used+=now;
		if(flow==0) break;
	}
	return used;
}
int gap[N];
long long isap()
{
    bfs(t,s);
    for(int i=1;i<=n;i++)
        gap[i]=0;
    for(int i=1;i<=n;i++)
        gap[dep[i]]++;
    int x=s;
    for(int i=1;i<=n;i++)
        cur[i]=head[i];
    while(dep[s]<n)
    {
        if(x==t)
        {

        }
    }
}
long long dinic()
{
	long long res=0;
	while(bfs(s,t))
	{
        for(int i=1;i<=n;i++)
            cur[i]=head[i];
		res+=dfs(s,INF);
	}
	return res;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,0);
	}
	printf("%lld",dinic());
	return 0;
}
```

#### Min Cost
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=5005,M=100005;
const long long INF=4557430888798830399;
struct Edge
{
	int to,next;
	int cost;
	long long flow;
}edge[M];
int cur[N],head[N],cnt=1;
int n,m,s,t;
void add_edge(int u,int v,int c,int f)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].cost=c;
	edge[cnt].flow=f;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
long long dis[N];
bool spfa()
{
	static bool vis[N];
	memset(vis,false,sizeof(vis));
	memset(dis,63,sizeof(dis));
	queue<int>q;
	vis[s]=true;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(edge[i].flow<=0) continue;
			if(dis[v]>dis[u]+edge[i].cost)
			{
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	return dis[t]!=INF;
}
bool book[N];
pair<long long,long long> dfs(int u,long long flow)
{
	if(u==t||flow==0) return make_pair(flow,0);
	book[u]=true;
	long long used=0,res=0;
	for(int &i=cur[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
		pair<long long,long long>t=dfs(v,min(flow,edge[i].flow));
		long long now=t.first;
		res+=t.second+now*edge[i].cost;
		flow-=now;
		edge[i].flow-=now;
		edge[i^1].flow+=now;
		used+=now;
		if(flow==0) break;
	}
	book[u]=false;
	return make_pair(used,res);
}
pair<long long,long long> dinic()
{
	long long ans=0,Min=0;
	while(spfa())
	{
		memcpy(cur,head,sizeof(head));
		pair<long long,long long> res=dfs(s,INF);
		ans+=res.first,Min+=res.second;
	}
	return make_pair(ans,Min);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z,c;
		scanf("%d%d%d%d",&x,&y,&z,&c);
		add_edge(x,y,c,z);
		add_edge(y,x,-c,0);
	}
	pair<long long,long long> ans=dinic();
	printf("%lld %lld",ans.first,ans.second);
	return 0;
}
```

#### NTT

```cpp
#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>
namespace poly_define
{
    const int g = 3;
    const int MOD = 998244353;
    int n;
    int ksm(int a, int b)
    {
        int res = 1;

        while (b)
        {
            if (b & 1)
                res = 1LL * res * a % MOD;

            a = 1LL * a * a % MOD, b >>= 1;
        }

        return res;
    }
    int getinv(int x)
    {
        return ksm(x, MOD - 2);
    }
    std::vector<int> W[2];
    void init_omega(int n)
    {
        for (int len = 1; len <= n; len <<= 1)
        {
            int w = ksm(g, (MOD - 1) / len), iw = getinv(w);
            W[0][len] = W[1][len] = 1;

            for (int k = 1; k < len; k++)
                W[0][len + k] = 1LL * W[0][len + k - 1] * w % MOD, W[1][len + k] = 1LL * W[1][len + k - 1] * iw % MOD;
        }

        return;
    }
    std::vector<int> inv;
    void init_inv(int n)
    {
        inv[1] = 1;

        for (int i = 2; i <= n; i++)
            inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;

        return;
    }
    void init_poly(int _n)
    {
        n = 1;
        while (n <= _n)
            n <<= 1;
        W[0].resize(n * 4 + 1);
        W[1].resize(n * 4 + 1);
        init_omega(n * 2);
        inv.resize(n * 2 + 1);
        init_inv(n * 2);
        return;
    }
    typedef std::vector<int> poly;
    poly operator+(const poly &a, const poly &b)
    {
        poly f = a, g = b;
        int n = std::max(a.size(), b.size());
        f.resize(n), g.resize(n);
        poly c(n);

        for (int i = 0; i < n; i++)
        {
            c[i] = f[i] + g[i];

            if (c[i] >= MOD)
                c[i] -= MOD;
        }

        return c;
    }
    poly operator-(const poly &a, const poly &b)
    {
        poly f = a, g = b;
        int n = std::max(a.size(), b.size());
        f.resize(n), g.resize(n);
        poly c(n);

        for (int i = 0; i < n; i++)
        {
            c[i] = f[i] - g[i];

            if (c[i] < 0)
                c[i] += MOD;
        }

        return c;
    }
    poly operator+(const poly &F, const int &x)
    {
        poly f = F;
        f[0] += x;

        if (f[0] >= MOD)
            f[0] -= MOD;

        return f;
    }
    poly operator+(const int &x, const poly &F)
    {
        poly f = F;
        f[0] += x;

        if (f[0] >= MOD)
            f[0] -= MOD;

        return f;
    }
    poly operator-(const poly &F, const int &x)
    {
        poly f = F;
        f[0] -= x;

        if (f[0] < 0)
            f[0] += MOD;

        return f;
    }
    poly operator-(const int &x, const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;

        for (int i = 0; i <= n; i++)
            f[i] = MOD - f[i];

        f[0] += x;

        if (f[0] >= MOD)
            f[0] -= MOD;

        return f;
    }
    poly ntt(const poly &F, const poly &G, const std::function<int(int, int)> &mul)
    {
        poly f = F, g = G;
        int n = f.size() - 1, m = g.size() - 1;
        m += n, n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        g.resize(n);
        std::vector<int> rev(n);

        for (int i = 0; i < n; i++)
        {
            rev[i] = rev[i >> 1] >> 1;

            if (i & 1)
                rev[i] |= n >> 1;
        }

        static const int BIT = 15;
        std::function<void(poly &)> dft = [=](poly &F)
        {
            int n = F.size();
            std::vector<unsigned long long> f(n);

            for (int i = 0; i < n; i++)
                f[i] = F[rev[i]];

            for (int len = 2; len <= n; len <<= 1)
            {
                if (len & (1 << BIT))
                {
                    for (int i = 0; i < n; i++)
                        f[i] %= MOD;
                }

                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        unsigned long long l = f[k];
                        int r = W[0][len + k - i] * f[k + len / 2] % MOD;
                        f[k] = l + r;
                        f[k + len / 2] = l + MOD - r;
                    }
            }

            for (int i = 0; i < n; i++)
                F[i] = f[i] % MOD;

            return;
        };
        dft(f);
        dft(g);

        for (int i = 0; i < n; i++)
            f[i] = mul(f[i], g[i]);

        std::function<void(poly &)> idft = [=](poly &F)
        {
            int n = F.size();
            std::vector<unsigned long long> f(n);

            for (int i = 0; i < n; i++)
                f[i] = F[rev[i]];

            for (int len = 2; len <= n; len <<= 1)
            {
                if (len & (1 << BIT))
                {
                    for (int i = 0; i < n; i++)
                        f[i] %= MOD;
                }

                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        unsigned long long l = f[k];
                        int r = W[1][len + k - i] * f[k + len / 2] % MOD;
                        f[k] = l + r;
                        f[k + len / 2] = l + MOD - r;
                    }
            }

            for (int i = 0; i < n; i++)
                F[i] = f[i] % MOD;

            int invn = getinv(n);

            for (int i = 0; i < n; i++)
                F[i] = 1LL * F[i] * invn % MOD;

            return;
        };
        idft(f);
        f.resize(m + 1);
        return f;
    }
    poly operator*(const poly &F, const poly &G)
    {
        return ntt(F, G, [=](const int &x, const int &y)
                   { return 1LL * x * y % MOD; });
    }
    poly operator*(const poly &F, const int &x)
    {
        poly f = F;
        int n = f.size() - 1;

        for (int i = 0; i <= n; i++)
            f[i] = 1LL * f[i] * x % MOD;

        return f;
    }
    poly operator*(const int &x, const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;

        for (int i = 0; i <= n; i++)
            f[i] = 1LL * f[i] * x % MOD;

        return f;
    }
    poly getinv(const poly &F)
    {
        poly f = F;
        int m = f.size() - 1;
        int n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        poly g = {getinv(f[0])};

        for (int m = 2; m <= n; m <<= 1)
        {
            poly t(f.begin(), f.begin() + m);
            g = ntt(t, g, [=](const int &x, const int &y)
                    { return (2 * y - 1LL * y * y % MOD * x % MOD + MOD) % MOD; });
            g.resize(m);
        }

        g.resize(m + 1);
        return g;
    }
    int w;
    struct Complex
    {
        int real, imag;
        bool operator==(const Complex &b) const
        {
            return real == b.real && imag == b.imag;
        }
        Complex operator*(const Complex &b) const
        {
            Complex res;
            res.real = (1LL * real * b.real + 1LL * w * imag % MOD * b.imag) % MOD;
            res.imag = (1LL * real * b.imag + 1LL * imag * b.real) % MOD;
            return res;
        }
        friend Complex ksm(Complex a, int b)
        {
            Complex res = (Complex){
                1, 0};

            while (b)
            {
                if (b & 1)
                    res = res * a;

                a = a * a, b >>= 1;
            }

            return res;
        }
    };
    int cipolla(int n)
    {
        static std::mt19937 myrand(time(NULL));

        if (n == 0)
            return 0;

        std::function<bool(int)> check = [=](const int &n)
        {
            return ksm(n, (MOD - 1) / 2) == 1;
        };

        if (!check(n))
            return -1;

        int a = myrand() % (MOD - 1) + 1;

        while (check((1LL * a * a - n + MOD) % MOD))
            a = myrand() % (MOD - 1) + 1;

        w = (1LL * a * a - n + MOD) % MOD;
        Complex res = ksm((Complex){
                              a, 1},
                          (MOD + 1) / 2);
        return res.real;
    }
    poly sqrt(const poly &F)
    {
        poly f = F;
        int m = f.size() - 1;
        int n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        int g0 = cipolla(f[0]);
        poly g = {std::min(g0, MOD - g0)};
        int inv2 = getinv(2);

        for (int m = 2; m <= n; m <<= 1)
        {
            poly t(f.begin(), f.begin() + m);
            g.resize(m);
            g = g * inv2 + ntt(t, getinv(g), [=](const int &x, const int &y)
                               { return 1LL * inv2 * x % MOD * y % MOD; });
            g.resize(m);
        }

        g.resize(m + 1);
        return g;
    }
    poly operator/(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int n = f.size() - 1, m = g.size() - 1;

        if (n < m)
            return poly(n - m + 1);

        reverse(f.begin(), f.end());
        reverse(g.begin(), g.end());
        f.resize(n - m + 1);
        g.resize(n - m + 1);
        poly q = f * getinv(g);
        q.resize(n - m + 1);
        reverse(q.begin(), q.end());
        return q;
    }
    poly operator%(const poly &F, const poly &G)
    {
        poly f = F, g = G, q = f / g;
        int m = g.size() - 1;
        g.resize(m);
        q.resize(m);
        poly c = g * q;
        c.resize(m);
        f.resize(m);
        return f - c;
    }
    poly diff_calc(const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;
        poly g(n);

        for (int i = 1; i <= n; i++)
            g[i - 1] = 1LL * f[i] * i % MOD;

        return g;
    }
    poly inte_calc(const poly &G)
    {
        poly g = G;
        int n = g.size() - 1;
        poly f(n + 2);

        for (int i = 1; i <= n + 1; i++)
            f[i] = 1LL * g[i - 1] * inv[i] % MOD;

        return f;
    }
    poly ln(const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;
        poly g = diff_calc(f) * getinv(f);
        g.resize(n + 1);
        g = inte_calc(g);
        g.resize(n + 1);
        return g;
    }
    poly exp(const poly &F)
    {
        poly f = F;
        int m = f.size() - 1;
        int n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        poly g = {1};

        for (int m = 2; m <= n; m <<= 1)
        {
            poly t(f.begin(), f.begin() + m);
            poly s = g;
            g.resize(m);
            g = s * (t - ln(g) + (poly){1});
            g.resize(m);
        }

        g.resize(m + 1);
        return g;
    }
    poly pow(const poly &F, const int &k)
    {
        poly f = F;
        int n = f.size() - 1;
        poly g(n + 1);
        int pos = -1;

        for (int i = 0; i <= n; i++)
            if (f[i] > 0)
            {
                g[i] = f[i];
                pos = i;
                break;
            }

        if (pos == -1)
            return g;

        int mu = f[pos], invm = getinv(mu);

        for (int i = 0; i <= n - pos; i++)
            f[i] = 1LL * f[i + pos] * invm % MOD;

        for (int i = n - pos + 1; i <= n; i++)
            f[i] = 0;

        g[pos] = 0;

        if (1LL * pos * k <= n || pos == 0)
        {
            g = exp(k * ln(f));
            int v = ksm(mu, k);

            for (int i = n; i >= pos * k; i--)
                g[i] = 1LL * g[i - pos * k] * v % MOD;

            for (int i = pos * k - 1; i >= 0; i--)
                g[i] = 0;
        }

        return g;
    }
    int poly_calc(const poly &F, const int &x)
    {
        poly f = F;
        int n = f.size() - 1;
        int fc = 1, res = 0;

        for (int i = 0; i <= n; i++)
            res = (res + 1LL * f[i] * fc) % MOD, fc = 1LL * fc * x % MOD;

        return res;
    }
    poly poly_eval(const poly &F, const poly &a)
    {
        poly f = F;
        int m = a.size();
        std::vector<poly> g(m << 2);
        std::function<void(int, int, int)> init_poly_eval = [&](int i, int l, int r)
        {
            if (l == r)
            {
                g[i] = (poly){
                    MOD - a[l], 1};
                return;
            }

            int mid = (l + r) / 2;
            init_poly_eval(i * 2, l, mid);
            init_poly_eval(i * 2 + 1, mid + 1, r);
            g[i] = g[i * 2] * g[i * 2 + 1];
            return;
        };
        init_poly_eval(1, 0, m - 1);
        poly res(m);
        std::function<void(int, int, int, const poly &)> solve_poly_eval = [&](int i, int l, int r, const poly &f)
        {
            if (l == r)
            {
                res[l] = f[0];
                return;
            }

            int mid = (l + r) / 2;
            solve_poly_eval(i * 2, l, mid, f % g[i * 2]);
            solve_poly_eval(i * 2 + 1, mid + 1, r, f % g[i * 2 + 1]);
            return;
        };
        solve_poly_eval(1, 0, m - 1, f);
        return res;
    }
    struct Point
    {
        int x, y;
    };
    poly poly_inte(const std::vector<Point> &p)
    {
        int n = p.size() - 1;
        std::vector<poly> g(n << 2);
        std::function<void(int, int, int)> init_poly_eval = [&](int i, int l, int r)
        {
            if (l == r)
            {
                g[i] = (poly){
                    MOD - p[l].x, 1};
                return;
            }

            int mid = (l + r) / 2;
            init_poly_eval(i * 2, l, mid);
            init_poly_eval(i * 2 + 1, mid + 1, r);
            g[i] = g[i * 2] * g[i * 2 + 1];
            return;
        };
        init_poly_eval(1, 0, n);
        poly x(n + 1);

        for (int i = 0; i <= n; i++)
            x[i] = p[i].x;

        poly F = poly_eval(diff_calc(g[1]), x);
        std::vector<int> a(n + 1);

        for (int i = 0; i <= n; i++)
            a[i] = 1LL * p[i].y * getinv(F[i]) % MOD;

        std::vector<poly> res(n << 2);
        std::function<void(int, int, int)> solve_poly_inte = [&](int i, int l, int r)
        {
            if (l == r)
            {
                res[i] = {a[l]};
                return;
            }

            int mid = (l + r) / 2;
            solve_poly_inte(i * 2, l, mid);
            solve_poly_inte(i * 2 + 1, mid + 1, r);
            res[i] = res[i * 2] * g[i * 2 + 1] + res[i * 2 + 1] * g[i * 2];
            return;
        };
        solve_poly_inte(1, 0, n);
        return res[1];
    }
    poly operator|(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int m = std::max(f.size() - 1, g.size() - 1), n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n), g.resize(n);
        std::function<void(poly &)> fwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k + len / 2] = (F[k + len / 2] + F[k]) % MOD;

            return;
        };
        fwt(f);
        fwt(g);

        for (int i = 0; i < n; i++)
            f[i] = 1LL * f[i] * g[i] % MOD;

        std::function<void(poly &)> ifwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k + len / 2] = (F[k + len / 2] - F[k] + MOD) % MOD;

            return;
        };
        ifwt(f);
        return f;
    }
    poly operator&(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int m = std::max(f.size() - 1, g.size() - 1), n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n), g.resize(n);
        std::function<void(poly &)> fwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k] = (F[k] + F[k + len / 2]) % MOD;

            return;
        };
        fwt(f);
        fwt(g);

        for (int i = 0; i < n; i++)
            f[i] = 1LL * f[i] * g[i] % MOD;

        std::function<void(poly &)> ifwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k] = (F[k] - F[k + len / 2] + MOD) % MOD;

            return;
        };
        ifwt(f);
        return f;
    }
    poly operator^(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int m = std::max(f.size() - 1, g.size() - 1), n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n), g.resize(n);
        std::function<void(poly &)> fwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        int l = F[k], r = F[k + len / 2];
                        F[k] = (l + r) % MOD;
                        F[k + len / 2] = (l - r + MOD) % MOD;
                    }

            return;
        };
        fwt(f);
        fwt(g);

        for (int i = 0; i < n; i++)
            f[i] = 1LL * f[i] * g[i] % MOD;

        std::function<void(poly &)> ifwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        int l = F[k], r = F[k + len / 2];
                        F[k] = (l + r) % MOD;
                        F[k + len / 2] = (l - r + MOD) % MOD;
                    }

            int invn = getinv(n);

            for (int i = 0; i < n; i++)
                F[i] = 1LL * F[i] * invn % MOD;

            return;
        };
        ifwt(f);
        return f;
    }
}
using poly_define::init_poly;
using poly_define::poly;
using poly_define::operator+;
using poly_define::operator-;
using poly_define::operator*;
using poly_define::operator/;
using poly_define::operator%;
using poly_define::operator^;
using poly_define::operator|;
using poly_define::diff_calc;
using poly_define::exp;
using poly_define::getinv;
using poly_define::inte_calc;
using poly_define::ln;
using poly_define::poly_calc;
using poly_define::poly_eval;
using poly_define::poly_inte;
using poly_define::pow;
using poly_define::sqrt;
using namespace std;
int main()
{
    init_poly(1000000);
    int n, m;
    scanf("%d%d", &n, &m);
    poly f, g;
    f.resize(n + 1), g.resize(m + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 0; i <= m; i++)
        scanf("%d", &g[i]);
    poly res = f * g;
    for (int u : res)
        printf("%d ", u);
    return 0;
}
```

#### MTT

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
using namespace std;
const double PI=acos(-1);
const int N=400005;
int MOD;
struct Complex
{
    double real,imag;
    Complex():real(0),imag(0){} 
    Complex(double xx,double yy):real(xx),imag(yy){}
    Complex operator=(const int &b)
    {
        real=b,imag=0;
        return *this;
    }
    Complex operator+(const Complex &b)const
    {
        return Complex(real+b.real,imag+b.imag);
    }
    Complex operator-(const Complex &b)const
    {
        return Complex(real-b.real,imag-b.imag);
    }
    Complex operator*(const Complex &b)const
    {
        return Complex(real*b.real-imag*b.imag,real*b.imag+imag*b.real);
    }
    friend Complex getinv(const Complex &rhs)
    {
        return Complex(rhs.real,-rhs.imag);
    }
};
Complex W[2][N<<1];
void init_omega(int n=400000)
{
    for(int len=1;len<=n;len<<=1)
        for(int k=0;k<len;k++)
            W[0][len+k]=Complex(cos(2*PI*k/len),sin(2*PI*k/len)),W[1][len+k]=Complex(cos(2*PI*k/len),-sin(2*PI*k/len));
    return;
}
typedef vector<int> Poly;
Poly mtt(const Poly &F,const Poly &G,const function<Complex(const Complex &,const Complex &)> &mul)
{
    int n=F.size()-1,m=G.size()-1;
    vector<Complex> a(n+1),b(n+1),c(m+1),d(m+1);
    for(int i=0;i<=n;i++)
        a[i]=F[i]>>15,b[i]=F[i]&0x7fff;
    for(int i=0;i<=m;i++)
        c[i]=G[i]>>15,d[i]=G[i]&0x7fff;
    m+=n,n=1;
    while(n<=m) n<<=1;
    a.resize(n),b.resize(n),c.resize(n),d.resize(n);
    vector<int>rev(n);
    for(int i=0;i<n;i++)
    {
        rev[i]=rev[i/2]>>1;
        if(i&1) rev[i]|=n/2;
    }
    function<void(vector<Complex> &)> dft=[=](vector<Complex> &F)
    {
        int n=F.size();
        vector<Complex> f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    Complex l=f[k];
                    Complex r=f[k+len/2]*W[0][len+k-i];
                    f[k]=l+r;
                    f[k+len/2]=l-r;
                }
        for(int i=0;i<n;i++)
            F[i]=f[i];
        return;
    };
    dft(a),dft(b),dft(c),dft(d);
    vector<Complex> ac(n),ad(n),bc(n),bd(n);
    for(int i=0;i<n;i++)
        ac[i]=mul(a[i],c[i]),ad[i]=mul(a[i],d[i]),bc[i]=mul(b[i],c[i]),bd[i]=mul(b[i],d[i]);
    function<void(vector<Complex> &)> idft=[=](vector<Complex> &F)
    {
        int n=F.size();
        vector<Complex> f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    Complex l=f[k];
                    Complex r=f[k+len/2]*W[1][len+k-i];
                    f[k]=l+r;
                    f[k+len/2]=l-r;
                }
        for(int i=0;i<n;i++)
            F[i]=f[i];
        return;
    };
    idft(ac),idft(ad),idft(bc),idft(bd);
    Poly AC(m+1),AD(m+1),BC(m+1),BD(m+1);
    for(int i=0;i<=m;i++)
        AC[i]=(long long)round(ac[i].real/n)%MOD,AD[i]=(long long)round(ad[i].real/n)%MOD,BC[i]=(long long)round(bc[i].real/n)%MOD,BD[i]=(long long)round(bd[i].real/n)%MOD;
    Poly res(m+1);
    for(int i=0;i<=m;i++)
        res[i]=(((long long)(AC[i])<<30)+((long long)(AD[i]+BC[i])<<15)+BD[i])%MOD;
    return res;
}
Poly operator*(const Poly &F,const Poly &G)
{
    return mtt(F,G,[=](const Complex &x,const Complex &y){return x*y;});
}
int main()
{
    init_omega();
    int n,m;
    scanf("%d%d%d",&n,&m,&MOD);
    Poly f,g;
    f.resize(n+1),g.resize(m+1);
    for(int i=0;i<=n;i++)
        scanf("%d",&f[i]);
    for(int i=0;i<=m;i++)
        scanf("%d",&g[i]);
    Poly res=f*g;
    for(int u:res)
        printf("%d ",u);
    return 0;
}
```

#### 三模 NTT

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
using namespace std;
const int N=(1<<19)+5;
const int g=3;
int MOD;
const int MOD1=998244353,MOD2=1004535809,MOD3=469762049;
int ksm(int a,int b,int P=MOD)
{
	int res=1;
	while(b)
	{
		if(b&1) res=1LL*res*a%P;
		a=1LL*a*a%P,b>>=1;
	}
	return res;
}
int getinv(int x,int P=MOD)
{
	return ksm(x,P-2,P);
}
struct Int
{
	int x1,x2,x3;
	Int(int a=0,int b=0,int c=0)
	{
		x1=(a%MOD1+MOD1)%MOD1,x2=(b%MOD2+MOD2)%MOD2,x3=(c%MOD3+MOD3)%MOD3;
		return;
	}
	Int(long long a,long long b,long long c)
	{
		x1=(a%MOD1+MOD1)%MOD1,x2=(b%MOD2+MOD2)%MOD2,x3=(c%MOD3+MOD3)%MOD3;
		return;
	}
	Int operator=(int x)
	{
		*this=(Int){x,x,x};
		return *this;
	}
	Int operator=(long long x)
	{
		*this=(Int){x,x,x};
		return *this;
	}
	Int operator+(const Int &rhs)const
	{
		Int c=(Int){x1+rhs.x1,x2+rhs.x2,x3+rhs.x3};
		return c;
	}
	Int operator-(const Int &rhs)const
	{
		Int c=(Int){x1-rhs.x1,x2-rhs.x2,x3-rhs.x3};
		return c;
	}
	Int operator*(const Int &rhs)const
	{
		Int c=(Int){1LL*x1*rhs.x1,1LL*x2*rhs.x2,1LL*x3*rhs.x3};
		return c;
	}
	Int operator/(const Int &rhs)const
	{
		Int c=(Int){1LL*x1*getinv(rhs.x1,MOD1),1LL*x2*getinv(rhs.x2,MOD2),1LL*x3*getinv(rhs.x3,MOD3)};
		return c;
	}
	Int operator+=(const Int &rhs)
	{
		*this=*this+rhs;
		return *this;
	}
	Int operator-=(const Int &rhs)
	{
		*this=*this-rhs;
		return *this;
	}
	Int operator*=(const Int &rhs)
	{
		*this=*this*rhs;
		return *this;
	}
	Int operator/=(const Int &rhs)
	{
		*this=*this/rhs;
		return *this;
	}
	int to_int(int P=MOD)const
	{
		static const int INV12=getinv(MOD1,MOD2),INV123=getinv(1LL*MOD1*MOD2%MOD3,MOD3);
		int k1=1LL*(x2-x1%MOD2+MOD2)*INV12%MOD2;
		long long x4=x1+1LL*k1*MOD1;
		int k4=(x3-x4%MOD3+MOD3)%MOD3*INV123%MOD3;
		long long x=(x4+1LL*k4%P*(1LL*MOD1*MOD2%P)%P)%P;
		return x;
	}
	friend Int getinv(const Int &rhs)
	{
		Int c=(Int){getinv(rhs.x1,MOD1),getinv(rhs.x2,MOD2),getinv(rhs.x3,MOD3)};
		return c;
	}
	Int operator+(const int &rhs)const
	{
		return *this+(Int){rhs,rhs,rhs};
	}
	Int operator+(const long long &rhs)const
	{
		return *this+(Int){rhs,rhs,rhs};
	}
	Int operator-(const int &rhs)const
	{
		return *this-(Int){rhs,rhs,rhs};
	}
	Int operator-(const long long &rhs)const
	{
		return *this-(Int){rhs,rhs,rhs};
	}
	Int operator*(const int &rhs)const
	{
		return *this*(Int){rhs,rhs,rhs};
	}
	Int operator*(const long long &rhs)const
	{
		return *this*(Int){rhs,rhs,rhs};
	}
	Int operator/(const int &rhs)const
	{
		return *this*getinv((Int){rhs,rhs,rhs});
	}
	Int operator/(const long long &rhs)const
	{
		return *this*getinv((Int){rhs,rhs,rhs});
	}
	friend Int operator+(const int &lhs,const Int &rhs)
	{
		return rhs+lhs;
	}
	friend Int operator+(const long long &lhs,const Int &rhs)
	{
		return rhs+lhs;
	}
	friend Int operator-(const int &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}-rhs;
	}
	friend Int operator-(const long long &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}-rhs;
	}
	friend Int operator*(const int &lhs,const Int &rhs)
	{
		return rhs*lhs;
	}
	friend Int operator*(const long long &lhs,const Int &rhs)
	{
		return rhs*lhs;
	}
	friend Int operator/(const int &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}*getinv(rhs);
	}
	friend Int operator/(const long long &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}*getinv(rhs);
	}
};
Int W[2][N<<1];
void init_omega(int n=1<<19)
{
	for(int len=1;len<=n;len<<=1)
	{
		Int w=(Int){ksm(g,(MOD1-1)/len,MOD1),ksm(g,(MOD2-1)/len,MOD2),ksm(g,(MOD3-1)/len,MOD3)},iw=getinv(w);
		W[0][len]=W[1][len]=1;
		for(int k=1;k<len;k++)
			W[0][len+k]=W[0][len+k-1]*w,W[1][len+k]=W[1][len+k-1]*iw;
	}
	return;
}
int inv[N];
void init_inv(int n=1<<19)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	return;
}
typedef vector<int> Poly;
Poly operator+(const Poly &a,const Poly &b)
{
	Poly f=a,g=b;
	int n=max(a.size(),b.size());
	f.resize(n),g.resize(n);
	Poly c(n);
	for(int i=0;i<n;i++)
		c[i]=(f[i]+g[i])%MOD;
	return c;
}
Poly operator-(const Poly &a,const Poly &b)
{
	Poly f=a,g=b;
	int n=max(a.size(),b.size());
	f.resize(n),g.resize(n);
	Poly c(n);
	for(int i=0;i<n;i++)
		c[i]=(f[i]-g[i]+MOD)%MOD;
	return c;
}
Poly ntt(const Poly &F,const Poly &G,const function<Int(const Int &,const Int &)> &mul)
{
	int n=F.size()-1,m=G.size()-1;
	vector<Int> f(n+1),g(m+1);
	for(int i=0;i<=n;i++)
		f[i]=F[i];
	for(int i=0;i<=m;i++)
		g[i]=G[i];
	m+=n,n=1;
	while(n<=m) n<<=1;
	f.resize(n);
	g.resize(n);
	vector<int>rev(n);
	for(int i=0;i<n;i++)
	{
		rev[i]=rev[i/2]>>1;
		if(i&1) rev[i]|=n/2;
	}
	function<void(vector<Int> &)> dft=[=](vector<Int> &F)
	{
		int n=F.size();
		vector<Int> f(n);
		for(int i=0;i<n;i++)
			f[i]=F[rev[i]];
		for(int len=2;len<=n;len<<=1)
			for(int i=0;i<n;i+=len)
				for(int k=i;k<i+len/2;k++)
				{
					Int l=f[k];
					Int r=W[0][len+k-i]*f[k+len/2];
					f[k]=l+r;
					f[k+len/2]=l-r;
				}
		for(int i=0;i<n;i++)
			F[i]=f[i];
		return;
	};
	dft(f);
	dft(g);
	for(int i=0;i<n;i++)
		f[i]=mul(f[i],g[i]);
	function<void(vector<Int> &)> idft=[=](vector<Int> &F)
	{
		int n=F.size();
		vector<Int> f(n);
		for(int i=0;i<n;i++)
			f[i]=F[rev[i]];
		for(int len=2;len<=n;len<<=1)
			for(int i=0;i<n;i+=len)
				for(int k=i;k<i+len/2;k++)
				{
					Int l=f[k];
					Int r=W[1][len+k-i]*f[k+len/2];
					f[k]=l+r;
					f[k+len/2]=l-r;
				}
		Int invn=getinv((Int){n,n,n});
		for(int i=0;i<n;i++)
			F[i]=f[i]*invn;
		return;
	};
	idft(f);
	Poly res(m+1);
	for(int i=0;i<=m;i++)
		res[i]=f[i].to_int();
	return res;
}
Poly operator*(const Poly &F,const Poly &G)
{
	return ntt(F,G,[=](const Int &x,const Int &y){return x*y;});
}
Poly operator*(const Poly &F,const int &x)
{
	Poly f=F;
	int n=f.size()-1;
	for(int i=0;i<=n;i++)
		f[i]=1LL*f[i]*x%MOD;
	return f; 
}
Poly operator*(const int &x,const Poly &F)
{
	Poly f=F;
	int n=f.size()-1;
	for(int i=0;i<=n;i++)
		f[i]=1LL*f[i]*x%MOD;
	return f; 
}
Poly getinv(const Poly &F)
{
	Poly f=F;
	int m=f.size()-1;
	int n=1;
	while(n<=m) n<<=1;
	f.resize(n);
	Poly g={getinv(f[0])};
	for(int m=2;m<=n;m<<=1)
	{
		Poly t(f.begin(),f.begin()+m);
		Poly yyx=g*g;
		yyx.resize(m);
		yyx=yyx*t;
		yyx.resize(m);
		g.resize(m);
		for(int i=0;i<m;i++)
			g[i]=(g[i]*2LL-yyx[i]+MOD)%MOD;
	}
	g.resize(m+1);
	return g;
}
Poly operator/(const Poly &F,const Poly &G)
{
	Poly f=F,g=G;
	int n=f.size()-1,m=g.size()-1;
	if(n<m) return Poly(n-m+1);
	reverse(f.begin(),f.end());
	reverse(g.begin(),g.end());
	f.resize(n-m+1);
	g.resize(n-m+1);
	Poly q=f*getinv(g);
	q.resize(n-m+1);
	reverse(q.begin(),q.end());
	return q;
}
Poly operator%(const Poly &F,const Poly &G)
{
	Poly f=F,g=G,q=f/g;
	int m=g.size()-1;
	g.resize(m);
	q.resize(m);
	Poly c=g*q;
	c.resize(m);
	f.resize(m);
	return f-c;
}
Poly diff_calc(const Poly &F)
{
	Poly f=F;
	int n=f.size()-1;
	Poly g(n);
	for(int i=1;i<=n;i++)
		g[i-1]=1LL*f[i]*i%MOD;
	return g;
}
Poly inte_calc(const Poly &G)
{
	Poly g=G;
	int n=g.size()-1;
	Poly f(n+2);
	for(int i=1;i<=n+1;i++)
		f[i]=1LL*g[i-1]*inv[i]%MOD;
	return f;
}
Poly ln(const Poly &F)
{
	Poly f=F;
	int n=f.size()-1;
	Poly g=diff_calc(f)*getinv(f);
	g.resize(n+1);
	g=inte_calc(g);
	g.resize(n+1);
	return g;
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&MOD);
	init_omega();
	init_inv();
	Poly f(n+1),g(m+1);
	for(int i=0;i<=n;i++)
		scanf("%d",&f[i]);
	for(int i=0;i<=m;i++)
		scanf("%d",&g[i]);
	Poly res=f*g;
	for(int i=0;i<=n+m;i++)
		printf("%d ",res[i]);
	return 0;
}
```

#### 计算几何

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<chrono>
#include<random>
#include<vector>
#include<functional>
#include<iomanip>
#include<algorithm>
using namespace std;
namespace Geometry
{
    const double eps=1e-10;
    const double PI=acos(-1);
    const double INF=1e18;
    bool equal(double a,double b)
    {
        return abs(a-b)<eps;
    }
    bool less(double a,double b)
    {
        return b-a>=eps;
    }
    bool greater(double a,double b)
    {
        return a-b>=eps;
    }
    bool less_equal(double a,double b)
    {
        return less(a,b)||equal(a,b);
    }
    bool greater_equal(double a,double b)
    {
        return greater(a,b)||equal(a,b);
    }
    class Point
    {
    public:
        double x,y;
        Point(){x=0,y=0;}
        Point(const double &_x,const double &_y):x(_x),y(_y) {}
        friend Point operator * (const Point &a,const double &b)
        {
            return Point(a.x*b,a.y*b);
        }
        friend Point operator * (const double &a,const Point &b)
        {
            return Point(a*b.x,a*b.y);
        }
        friend Point operator / (const Point &a,const double &b)
        {
            return Point(a.x/b,a.y/b);
        }
        friend Point operator + (const Point &a,const Point &b)
        {
            return Point(a.x+b.x,a.y+b.y);
        }
        Point operator += (const Point &b)
        {
            x+=b.x,y+=b.y;
            return *this;
        }
        friend Point operator - (const Point &a,const Point &b)
        {
            return Point(a.x-b.x,a.y-b.y);
        }
        Point operator -= (const Point &b)
        {
            x-=b.x,y-=b.y;
            return *this;
        }
        friend double cross(const Point &a,const Point &b)
        {
            return a.x*b.y-a.y*b.x;
        }
        friend double dot(const Point &a,const Point &b)
        {
            return a.x*b.x+a.y*b.y;
        }
        friend bool operator == (const Point &a,const Point &b)
        {
            return equal(a.x,b.x)&&equal(a.y,b.y);
        }
        friend bool operator < (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return less(a.y,b.y);
            else return less(a.x,b.x);
        }
        friend bool operator > (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return greater(a.y,b.y);
            else return greater(a.x,b.x);
        }
        friend bool operator <= (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return less_equal(a.y,b.y);
            else return less_equal(a.x,b.x);
        }
        friend bool operator >= (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return greater_equal(a.y,b.y);
            else return greater_equal(a.x,b.x);
        }
        Point operator - ()const
        {
            return Point(-x,-y);
        }
        double length()const
        {
            return sqrt(x*x+y*y);
        }
        Point unit()const
        {
            return *this/length();
        }
        double angle()const
        {
            return atan2(y,x);
        }
        int quadrant()const
        {
            if(x>0&&y>=0) return 1;
            else if(x<=0&&y>0) return 2;
            else if(x<0&&y<=0) return 3;
            else if(x>=0&&y<0) return 4;
            else return 0;
        }
        friend double angle(const Point &a,const Point &b)
        {
            return atan2(cross(a,b),dot(a,b));
        }
        Point rotate(const double &theta)const
        {
            return Point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
        }
        friend istream &operator>>(istream &in,Point &obj)
        {
            in>>obj.x>>obj.y;
            return in;
        }
        friend ostream &operator<<(ostream &out,const Point &obj)
        {
            out<<obj.x<<" "<<obj.y;
            return out;
        }
    };
    double distance(const Point &a,const Point &b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    enum Direction
    {
        COUNTER_CLOCKWISE,
        CLOCKWISE,
        ONLINE_BACK,
        ONLINE_FRONT,
        ON_SEGMENT
    };
    istream& operator>>(istream& in,Direction& direction)
    {
        string value;
        in>>value;
        if(value=="COUNTER_CLOCKWISE") direction=COUNTER_CLOCKWISE;
        else if(value=="CLOCKWISE") direction=CLOCKWISE;
        else if(value=="ONLINE_BACK") direction=ONLINE_BACK;
        else if(value=="ONLINE_FRONT") direction=ONLINE_FRONT;
        else if(value=="ON_SEGMENT") direction=ON_SEGMENT;
        else in.setstate(ios::failbit);
        return in;
    }
    ostream& operator<<(ostream& out,const Direction& direction)
    {
        if(direction==COUNTER_CLOCKWISE) out<<"COUNTER_CLOCKWISE";
        else if(direction==CLOCKWISE) out<<"CLOCKWISE";
        else if(direction==ONLINE_BACK) out<<"ONLINE_BACK";
        else if(direction==ONLINE_FRONT) out<<"ONLINE_FRONT";
        else if(direction==ON_SEGMENT) out<<"ON_SEGMENT";
        return out;
    }
    class Line
    {
    public:
        Point a,b;
        Line(){}
        Line(const Point &_a,const Point &_b):a(_a),b(_b){}
        Point projection(const Point &p)const
        {
            return a+(b-a).unit()*(dot(p-a,b-a)/(b-a).length());
        }
        Point reflection(const Point &p)const
        {
            return projection(p)*2-p;
        }
        Direction direction(const Point &p)const
        {
            double t=cross(b-a,p-a);
            if(greater(t,0)) return COUNTER_CLOCKWISE;
            if(less(t,0)) return CLOCKWISE;
            double l1=dot(p-a,b-a);
            if(less(l1,0)) return ONLINE_BACK;
            double l2=dot(b-a,b-a);
            if(l1>l2) return ONLINE_FRONT;
            else return ON_SEGMENT;
        }
        double distance(const Point &p)const
        {
            Point u=projection(p);
            if(direction(u)==ON_SEGMENT) return Geometry::distance(u,p);
            else return min(Geometry::distance(a,p),Geometry::distance(b,p));
        }
        friend istream &operator>>(istream &in,Line &obj)
        {
            in>>obj.a>>obj.b;
            return in;
        }
        friend ostream &operator<<(ostream &out,const Line &obj)
        {
            out<<obj.a<<" "<<obj.b;
            return out;
        }
    };
    bool parallel(const Line &x,const Line &y)
    {
        return equal(cross(x.b-x.a,y.b-y.a),0);
    }
    bool orthogonal(const Line &x,const Line &y)
    {
        return equal(dot(x.b-x.a,y.b-y.a),0);
    }
    vector<Point> cross_point(const Line &x,const Line &y)
    {
        if(parallel(x,y)) return {};
        Point u=x.a-y.a,v=x.b-x.a,w=y.b-y.a;
        double t=cross(w,u)/cross(v,w);
        return {x.a+t*v};
    }
    int sign(double x)
    {
        return greater(x,0)-less(x,0);
    }
    bool intersection(const Line &x,const Line &y)
    {
        if(x.direction(y.a)==ON_SEGMENT||x.direction(y.b)==ON_SEGMENT||y.direction(x.a)==ON_SEGMENT||y.direction(x.b)==ON_SEGMENT) return true;
        return sign(cross(x.b-x.a,y.a-x.a))*sign(cross(x.b-x.a,y.b-x.a))<0&&sign(cross(y.b-y.a,x.a-y.a))*sign(cross(y.b-y.a,x.b-y.a))<0;
    }
    double distance(const Line &x,const Line &y)
    {
        if(intersection(x,y)) return 0;
        else return min({x.distance(y.a),x.distance(y.b),y.distance(x.a),y.distance(x.b)});
    }
    const int IN=2,ON=1,OUT=0;
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    class Polygon
    {
    private:
        vector<Point>g;
    public:
        Polygon(){}
        Polygon(const int &n){g.resize(n);}
        Polygon(const vector<Point> &f):g(f){}
        void clear()
        {
            g.clear();
        }
        void resize(int n)
        {
            g.resize(n);
        }
        void push_back(const Point &x)
        {
            return g.push_back(x);
        }
        void push_back(const vector<Point> &x)
        {
            for(const Point &p:x)
                g.push_back(p);
            return;
        }
        void pop_back()
        {
            return g.pop_back();
        }
        Point& front()
        {
            return g.front();
        }
        const Point& front()const
        {
            return g.front();
        }
        Point& back()
        {
            return g.back();
        }
        const Point& back()const
        {
            return g.back();
        }
        size_t size()const
        {
            return g.size();
        }
        Point& operator [](const int &i)
        {
            return g[i];
        }
        const Point& operator [](const int &i)const
        {
            return g[i];
        }
        vector<Point>::iterator begin()
        {
            return g.begin();
        }
        vector<Point>::iterator end()
        {
            return g.end();
        }
        vector<Point>::const_iterator begin()const
        {
            return g.begin();
        }
        vector<Point>::const_iterator end()const
        {
            return g.end();
        }
        vector<Point>::reverse_iterator rbegin()
        {
            return g.rbegin();
        }
        vector<Point>::reverse_iterator rend()
        {
            return g.rend();
        }
        vector<Point>::const_reverse_iterator rbegin()const
        {
            return g.rbegin();
        }
        vector<Point>::const_reverse_iterator rend()const
        {
            return g.rend();
        }
        double area()const
        {
            int n=g.size();
            double res=0;
            for(int i=0;i<n;i++)
                res+=cross(g[i],g[(i+1)%n]);
            res/=2;
            return abs(res);
        }
        double perimeter()const
        {
            int n=g.size();
            double sum=0;
            for(int i=0;i<n;i++)
                sum+=distance(g[i],g[(i+1)%n]);
            return sum;
        }
        bool is_convex()const
        {
            int n=g.size();
            for(int i=0;i<n;i++)
                if(less(cross(g[(i+1)%n]-g[i],g[(i-1+n)%n]-g[i]),0)) return false;
            return true;
        }
        int point_containment(const Point &a)const
        {
            int n=g.size();
            for(int i=0;i<n;i++)
                if(Line(g[i],g[(i+1)%n]).direction(a)==ON_SEGMENT) return ON;
            function<bool(const Line &)> check=[=](const Line &l)
            {
                for(int i=0;i<n;i++)
                    if(parallel(l,Line(g[i],g[(i+1)%n]))) return false;
                for(int i=0;i<n;i++)
                    if(l.direction(g[i])==ON_SEGMENT||l.direction(g[i])==ONLINE_FRONT||l.direction(g[i])==ONLINE_BACK) return false;
                return true;
            };
            Line l=Line(a,Point(rnd(),rnd()));
            while(!check(l))
                l=Line(a,Point(rnd(),rnd()));
            int s=0;
            for(int i=0;i<n;i++)
                if(intersection(l,Line(g[i],g[(i+1)%n]))) s++;
            if(s&1) return IN;
            else return OUT;
        }
        double convex_diamater()const
        {
            int n=g.size();
            double ans=0;
            for(int i=0,j=0;i<n;i++)
            {
                while(less(cross(g[i]-g[j],g[(i+1)%n]-g[j]),cross(g[i]-g[(j+1)%n],g[(i+1)%n]-g[(j+1)%n]))) j=(j+1)%n;
                ans=max(ans,max(distance(g[j],g[i]),distance(g[j],g[(i+1)%n])));
            }
            return ans;
        }
        pair<Polygon,Polygon> convex_cut(const Line &l)const
        {
            Polygon res1,res2;
            int n=g.size();
            for(int i=0;i<(int)g.size();i++)
            {
                Point u=g[i],v=g[(i+1)%n];
                if(greater_equal(cross(l.b-l.a,u-l.a),0))
                {
                    res1.push_back(u);
                    if(less(cross(l.b-l.a,v-l.a),0)) res1.push_back(cross_point(Line(u,v),l));
                }
                else if(greater(cross(l.b-l.a,v-l.a),0)) res1.push_back(cross_point(Line(u,v),l));
            }
            for(int i=0;i<(int)g.size();i++)
            {
                Point u=g[i],v=g[(i+1)%n];
                if(greater_equal(cross(l.a-l.b,u-l.b),0))
                {
                    res2.push_back(u);
                    if(less(cross(l.a-l.b,v-l.b),0)) res2.push_back(cross_point(Line(u,v),l));
                }
                else if(greater(cross(l.a-l.b,v-l.b),0)) res2.push_back(cross_point(Line(u,v),l));
            }
            return make_pair(res1,res2);
        }
        Polygon kernel()const;
    };
    Polygon convex_hull(const vector<Point> &_p)
    {
        vector<Point> p=_p;
        int n=p.size();
        if(n<=2)
        {
            sort(p.begin(),p.end(),[](const Point &a,const Point &b){return a.y==b.y?a.x<b.x:a.y<b.y;});
            Polygon res;
            for(const Point &q:p)
                res.push_back(q);
            return res;
        }
        sort(p.begin(),p.end(),[](const Point &a,const Point &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
        vector<int>stk;
        int top=0;
        for(int i=0;i<n;i++)
        {
            while(top>=2&&less_equal(cross(p[stk[top-1]]-p[stk[top-2]],p[i]-p[stk[top-1]]),0)) stk.pop_back(),top--;
            stk.emplace_back(i),top++;
        }
        int tmp=top;
        for(int i=n-2;i>=0;i--)
        {
            while(top>tmp&&less_equal(cross(p[stk[top-1]]-p[stk[top-2]],p[i]-p[stk[top-1]]),0)) stk.pop_back(),top--;
            stk.emplace_back(i),top++;
        }
        stk.pop_back(),top--;
        vector<Point>hull;
        for(int i=0;i<top;i++)
            hull.emplace_back(p[stk[i]]);
        int t=min_element(hull.begin(),hull.end(),[](const Point &a,const Point &b){return a.y==b.y?a.x<b.x:a.y<b.y;})-hull.begin();
        Polygon res;
        for(int i=t;i<top;i++)
            res.push_back(hull[i]);
        for(int i=0;i<t;i++)
            res.push_back(hull[i]);
        return res;
    }
    Polygon non_strictly_convex_hull(const vector<Point> &_p)
    {
        vector<Point> p=_p;
        int n=p.size();
        if(n<=2)
        {
            sort(p.begin(),p.end(),[](const Point &a,const Point &b){return a.y==b.y?a.x<b.x:a.y<b.y;});
            Polygon res;
            for(const Point &q:p)
                res.push_back(q);
            return res;
        }
        sort(p.begin(),p.end(),[](const Point &a,const Point &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
        vector<int>stk;
        int top=0;
        for(int i=0;i<n;i++)
        {
            while(top>=2&&less(cross(p[stk[top-1]]-p[stk[top-2]],p[i]-p[stk[top-1]]),0)) stk.pop_back(),top--;
            stk.emplace_back(i),top++;
        }
        int tmp=top;
        for(int i=n-2;i>=0;i--)
        {
            while(top>tmp&&less(cross(p[stk[top-1]]-p[stk[top-2]],p[i]-p[stk[top-1]]),0)) stk.pop_back(),top--;
            stk.emplace_back(i),top++;
        }
        stk.pop_back(),top--;
        vector<Point>hull;
        for(int i=0;i<top;i++)
            hull.emplace_back(p[stk[i]]);
        int t=min_element(hull.begin(),hull.end(),[](const Point &a,const Point &b){return a.y==b.y?a.x<b.x:a.y<b.y;})-hull.begin();
        Polygon res;
        for(int i=t;i<top;i++)
            res.push_back(hull[i]);
        for(int i=0;i<t;i++)
            res.push_back(hull[i]);
        return res;
    }
    Polygon minkowski_sum(const vector<Point> &a,const vector<Point> &b)
    {
        assert(a.size()!=0&&b.size()!=0);
        Polygon ca=convex_hull(a),cb=convex_hull(b);
        int na=ca.size(),nb=cb.size();
        vector<Point>la,lb;
        for(int i=0;i<na;i++)
            la.emplace_back(ca[(i+1)%na]-ca[i]);
        for(int i=0;i<nb;i++)
            lb.emplace_back(cb[(i+1)%nb]-cb[i]);
        int pa=0,pb=0;
        vector<Point> l;
        l.emplace_back(ca[0]+cb[0]);
        while(pa<(int)la.size()&&pb<(int)lb.size())
        {
            double val=cross(la[pa],lb[pb]);
            if(greater(val,0)) l.emplace_back(l.back()+la[pa]),pa++;
            else if(less(val,0)) l.emplace_back(l.back()+lb[pb]),pb++;
            else l.emplace_back(l.back()+la[pa]+lb[pb]),pa++,pb++;
        }
        while(pa<(int)la.size())
            l.emplace_back(l.back()+la[pa]),pa++;
        while(pb<(int)lb.size())
            l.emplace_back(l.back()+lb[pb]),pb++;
        Polygon res=convex_hull(l);
        return res;
    }
    Polygon half_plane_intersection(const vector<Line> &l,double x1=-INF,double y1=-INF,double x2=INF,double y2=INF)
    {
        vector<pair<double,Line>>f;
        for(int i=0;i<(int)l.size();i++)
            f.emplace_back((l[i].b-l[i].a).angle(),l[i]);
        f.emplace_back(0,Line(Point(x1,y1),Point(x2,y1)));
        f.emplace_back(PI/2,Line(Point(x2,y1),Point(x2,y2)));
        f.emplace_back(PI,Line(Point(x2,y2),Point(x1,y2)));
        f.emplace_back(-PI/2,Line(Point(x1,y2),Point(x1,y1)));
        int n=f.size();
        sort(f.begin(),f.end(),[](const pair<double,Line> &a,const pair<double,Line> &b){return !equal(a.first,b.first)?a.first<b.first:a.second.direction(b.second.a)==CLOCKWISE;});
        vector<Line>Ql(n);
        vector<Point>Qp(n);
        Polygon res;
        int head=0,tail=-1;
        Ql[++tail]=f[0].second;
        for(int i=1;i<n;i++)
            if(!equal(f[i].first,f[i-1].first))
            {
                while(head<tail&&f[i].second.direction(Qp[tail-1])==CLOCKWISE) tail--;
                while(head<tail&&f[i].second.direction(Qp[head])==CLOCKWISE) head++;
                Ql[++tail]=f[i].second;
                if(head<tail)
                {
                    vector<Point> tmp=cross_point(Ql[tail],Ql[tail-1]);
                    if(!tmp.empty()) Qp[tail-1]=tmp[0];
                    else return res;
                }
            }
        while(head<tail&&Ql[head].direction(Qp[tail-1])==CLOCKWISE) tail--;
        while(head<tail&&Ql[tail].direction(Qp[head])==CLOCKWISE) head++;
        vector<Point> tmp=cross_point(Ql[tail],Ql[head]);
        if(tmp.empty()||tail-head+1<=2) return res;
        for(int i=head;i<tail;i++)
            res.push_back(Qp[i]);
        res.push_back(tmp[0]);
        return res;
    }
    Polygon Polygon::kernel()const
    {
        int n=g.size();
        vector<Line>l;
        for(int i=0;i<n;i++)
            l.emplace_back(Line(g[i],g[(i+1)%n]));
        return half_plane_intersection(l);
    }
    double closest_pair(const vector<Point> &_p)
    {
        vector<Point>p=_p;
        sort(p.begin(),p.end(),[](const Point &a,const Point &b){return a.x<b.x;});
        function<double(const int &,const int &)> solve=[&](const int &l,const int &r)
        {
            if(r-l+1<=1) return INF;
            if(r-l+1<=7)
            {
                double ans=INF;
                sort(p.begin()+l,p.begin()+r+1,[](const Point &a,const Point &b){return a.y<b.y;});
                for(int i=l;i<=r;i++)
                    for(int j=i+1;j<=r;j++)
                        ans=min(ans,distance(p[i],p[j]));
                return ans;
            }
            int mid=(l+r)/2;
            double w=p[mid].x;
            double d=min(solve(l,mid),solve(mid+1,r));
            inplace_merge(p.begin()+l,p.begin()+mid+1,p.begin()+r+1,[](const Point &a,const Point &b){return a.y<b.y;});
            vector<Point>q;
            for(int i=l;i<=r;i++)
                if(abs(w-p[i].x)<=d) q.emplace_back(p[i]);
            for(int i=0,j=0;i<(int)q.size();i++)
            {
                while(j<(int)q.size()&&q[j].y<=q[i].y+d) j++;
                for(int k=i+1;k<j;k++)
                    d=min(d,distance(q[i],q[k]));
            }
            return d;
        };
        return solve(0,p.size()-1);
    }
    class Circle
    {
    public:
        Point o;
        double r;
        Circle(){}
        Circle(const Point &_o,const double &_r):o(_o),r(_r){}
        friend istream &operator>>(istream &in,Circle &obj)
        {
            in>>obj.o>>obj.r;
            return in;
        }
        friend ostream &operator<<(ostream &out,const Circle &obj)
        {
            out<<obj.o<<" "<<obj.r;
            return out;
        }
        double area()const
        {
            return PI*r*r;
        }
        bool tangent(const Line &l)const
        {
            return equal(Geometry::distance(l.projection(o),o),r);
        }
        int point_containment(const Point &p)const
        {
            double d=distance(o,p);
            if(equal(d,r)) return ON;
            else if(less(d,r)) return IN;
            else return OUT;
        }
        vector<Point>cross_point(const Line &l)const
        {
            Point pr=l.projection(o),e=(l.b-l.a).unit();
            double d=distance(pr,o);
            if(greater(d,r)) return {};
            double t=sqrt(r*r-distance(pr,o)*distance(pr,o));
            if(equal(t,0)) return {pr};
            else return {pr-e*t,pr+e*t};
        }
        vector<Point>cross_point(const Circle &c)const
        {
            double d=distance(o,c.o);
            if(less(d,abs(r-c.r))||greater(d,r+c.r)) return {};
            double x=(r*r-c.r*c.r+d*d)/(d*2),h=sqrt(r*r-x*x);
            Point p=o+(c.o-o).unit()*x;
            if(equal(d,abs(r-c.r))||equal(d,r+c.r)) return {p};
            Point v=(c.o-o).unit().rotate(PI/2)*h;
            return {p-v,p+v};
        }
        vector<Point>tangent(const Point &p)const
        {
            double d=distance(o,p);
            if(greater(r,d)) return {};
            if(equal(d,r)) return {p};
            return cross_point(Circle(p,sqrt(d*d-r*r)));
        }
        vector<Line>common_tangent(const Circle &c)const
        {
            vector<Line>f=common_tangent_out(c),g=common_tangent_in(c);
            for(const Line &l:g)
                f.emplace_back(l);
            g.clear();
            sort(f.begin(),f.end(),[](const Line &x,const Line &y){return x.a.x<y.a.x||(x.a.x==y.a.x&&x.a.y<y.a.y);});
            return f;
        }
        double intersection_area(const Point &a,const Point &b)const
        {
            bool ta=less_equal(distance(o,a),r),tb=less_equal(distance(o,b),r);
            if(ta&&tb) return cross(a-o,b-o)/2;
            vector<Point>t=cross_point(Line(b,a));
            if(ta&&!tb) return angle(t.front()-o,b-o)*r*r/2+cross(a-o,t.front()-o)/2;
            if(!ta&&tb) return angle(a-o,t.back()-o)*r*r/2+cross(t.back()-o,b-o)/2;
            double s=angle(a-o,b-o)*r*r/2;
            if(greater_equal(Line(a,b).distance(o),r)) return s;
            return s+angle(t.front()-o,t.back()-o)*r*r/2-cross(t.front()-o,t.back()-o)/2;
        }
        double intersection_area(const Polygon &g)const
        {
            int n=g.size();
            double s=0;
            for(int i=0;i<n;i++)
                s+=intersection_area(g[i],g[(i+1)%n]);
            return s;
        }
        double intersection_area(const Circle &c)const
        {
            double d=distance(o,c.o);
            if(greater(d,r+c.r)) return 0;
            if(less_equal(d,abs(r-c.r))) return min(area(),c.area());
            vector<Point>t=cross_point(c);
            double alpha=acos((d*d+r*r-c.r*c.r)/(2*d*r))*2,beta=acos((d*d+c.r*c.r-r*r)/(2*d*c.r))*2;
            double s1=alpha*r*r/2,s2=beta*c.r*c.r/2,s3=sin(alpha)*r*r/2+sin(beta)*c.r*c.r/2;
            return s1+s2-s3;
        }
    private:
        vector<Line>common_tangent_out(const Circle &c)const
        {
            if(equal(r,c.r))
            {
                Point p=(c.o-o).unit().rotate(PI/2)*r;
                return {Line(o-p,c.o-p),Line(o+p,c.o+p)};
            }
            double d=distance(o,c.o);
            if(less(d,abs(r-c.r))) return {};
            Point p((o.x*c.r-c.o.x*r)/(c.r-r),(o.y*c.r-c.o.y*r)/(c.r-r));
            vector<Point>p1=tangent(p),p2=c.tangent(p);
            vector<Line>res;
            for(const Point &u:p1)
                for(const Point &v:p2)
                    if(u==v||tangent(Line(u,v))) res.emplace_back(Line(u,v));
            return res;
        }
        vector<Line>common_tangent_in(const Circle &c)const
        {
            double d=distance(o,c.o);
            if(less_equal(d,abs(r-c.r))) return {};
            Point p((o.x*c.r+c.o.x*r)/(r+c.r),(o.y*c.r+c.o.y*r)/(r+c.r));
            vector<Point>p1=tangent(p),p2=c.tangent(p);
            vector<Line>res;
            for(const Point &u:p1)
                for(const Point &v:p2)
                    if(u==v||tangent(Line(u,v))) res.emplace_back(Line(u,v));
            return res;
        }
    };
    const int SEPARATED=4,CIRCUMSCRIBED=3,INTERSECTED=2,INSCRIBED=1,INCLUDED=0;
    int intersection(const Circle &a,const Circle &b)
    {
        double d=distance(a.o,b.o);
        if(greater(d,a.r+b.r)) return SEPARATED;
        else if(equal(d,a.r+b.r)) return CIRCUMSCRIBED;
        else if(greater(d,abs(a.r-b.r))) return INTERSECTED;
        else if(equal(d,abs(a.r-b.r))) return INSCRIBED;
        else return INCLUDED;
    }
    class Triangle
    {
    public:
        Point A,B,C;
        Triangle(){}
        Triangle(const Point &_A,const Point &_B,const Point &_C):A(_A),B(_B),C(_C){}
        friend istream &operator>>(istream &in,Triangle &obj)
        {
            in>>obj.A>>obj.B>>obj.C;
            return in;
        }
        friend ostream &operator<<(ostream &out,const Triangle &obj)
        {
            out<<obj.A<<" "<<obj.B<<" "<<obj.C;
            return out;
        }
        Circle inscribed_circle()const
        {
            double a=distance(B,C),b=distance(A,C),c=distance(A,B);
            double p=(a+b+c)/2;
            double s=abs(cross(B-A,C-A))/2;
            double r=s/p;
            Point o((a*A.x+b*B.x+c*C.x)/(a+b+c),(a*A.y+b*B.y+c*C.y)/(a+b+c));
            return Circle(o,r);
        }
        Circle circumscribed_circle()const
        {
            double t1=A.x*A.x+A.y*A.y;
            double t2=B.x*B.x+B.y*B.y;
            double t3=C.x*C.x+C.y*C.y;
            double t=A.x*B.y+B.x*C.y+C.x*A.y-A.x*C.y-B.x*A.y-C.x*B.y;
            Point o((t2*C.y+t1*B.y+t3*A.y-t2*A.y-t3*B.y-t1*C.y)/t/2,(t3*B.x+t2*A.x+t1*C.x-t1*B.x-t2*C.x-t3*A.x)/t/2);
            double a=distance(B,C),b=distance(A,C),c=distance(A,B);
            double s=abs(cross(B-A,C-A))/2;
            double r=a*b*c/(4*s);
            return Circle(o,r);
        }
    };
    Circle smallest_enclosing_circle(const vector<Point> &_p)
    {
        vector<Point>p=_p;
        shuffle(p.begin(),p.end(),rnd);
        int n=p.size();
        Circle c=Circle(Point(0,0),0);
        for(int i=0;i<n;i++)
            if(c.point_containment(p[i])==OUT)
            {
                c=Circle(p[i],0);
                for(int j=0;j<i;j++)
                    if(c.point_containment(p[j])==OUT)
                    {
                        c=Circle((p[i]+p[j])/2,distance(p[i],p[j])/2);
                        for(int k=0;k<j;k++)
                            if(c.point_containment(p[k])==OUT)
                                c=Triangle(p[i],p[j],p[k]).circumscribed_circle();
                    }
            }
        return c;
    }
}
using namespace Geometry;
```

#### LCT
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int val,sum;
        int rev;
    }tree[N];
    void push_up(int u)
    {
        tree[u].sum=tree[tree[u].ls].sum^tree[tree[u].rs].sum^tree[u].val;
        return;
    }
    void reverse(int u)
    {
        swap(tree[u].ls,tree[u].rs);
        tree[u].rev^=1;
        return;
    }
    void push_down(int u)
    {
        if(!tree[u].rev) return;
        if(tree[u].ls) reverse(tree[u].ls);
        if(tree[u].rs) reverse(tree[u].rs);
        tree[u].rev=0;
        return;
    }
    int get(int u)
    {
        if(tree[tree[u].fa].ls==u) return 0;
        if(tree[tree[u].fa].rs==u) return 1;
        return -1;
    }
    bool isroot(int u)
    {
        return get(u)==-1;
    }
    void connect(int u,int v,int op)
    {
        if(u) tree[u].fa=v;
        if(v)
        {
            if(op==0) tree[v].ls=u;
            if(op==1) tree[v].rs=u;
        }
        return;
    }
    void rotate(int u)
    {
        int f=tree[u].fa,gf=tree[f].fa,r=get(u),gr=get(f);
        int v=0;
        if(r==1) v=tree[u].ls;
        if(r==0) v=tree[u].rs;
        connect(u,gf,gr);
        connect(v,f,r);
        connect(f,u,r^1);
        push_up(f);
        push_up(u);
        return;
    }
    void pushall(int u)
    {
        if(!isroot(u)) pushall(tree[u].fa);
        push_down(u);
        return;
    }
    void splay(int u)
    {
        pushall(u);
        while(!isroot(u))
        {
            int f=tree[u].fa;
            if(!isroot(f)) rotate(get(u)==get(f)?f:u);
            rotate(u);
        }
        return;
    }
    int access(int u)
    {
        int v;
        for(v=0;u;v=u,u=tree[u].fa)
        {
            splay(u);
            tree[u].rs=v;
            push_up(u);
        }
        return v;
    }
    void makeroot(int u)
    {
        access(u);
        splay(u);
        reverse(u);
        return;
    }
    int findroot(int u)
    {
        access(u);
        splay(u);
        push_down(u);
        while(tree[u].ls) u=tree[u].ls,push_down(u);
        splay(u);
        return u;
    }
    void split(int x,int y)
    {
        makeroot(x);
        access(y);
        splay(y);
        return;
    }
    bool link(int x,int y)
    {
        makeroot(x);
        if(findroot(y)==x) return false;
        tree[x].fa=y;
        return true;
    }
    bool cut(int x,int y)
    {
        if(findroot(x)!=findroot(y)) return false;
        split(x,y);
        if(tree[x].fa!=y||tree[x].rs) return false;
        tree[x].fa=tree[y].ls=0;
        push_up(y);
        return true;
    }
    int query(int x,int y)
    {
        split(x,y);
        return tree[y].sum; 
    }
    void modify(int u,int v)
    {
        splay(u);
        tree[u].val=v;
        return;
    }
}T;
int n,m;
int a[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        T.tree[i].sum=T.tree[i].val=a[i];
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==0) printf("%d\n",T.query(x,y));
        else if(op==1) T.link(x,y);
        else if(op==2) T.cut(x,y);
        else if(op==3) T.modify(x,y);
    }
    return 0;
}
```

#### 

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long qpow(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=(__int128)res*a%p;
        a=(__int128)a*a%p,b>>=1;
    }
    return res;
}
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
bool miller_rabin(long long n)
{
    if(n==1) return false;
    if(n%2==0) return n==2;
    static const int prime[]={2,325,9375,28178,450775,9780504,1795265022};
    long long u=n-1;
    int t=0;
    while(u%2==0) u/=2,t++;
    for(int a:prime)
    {
        if(a%n==0) continue;
        long long x=qpow(a,u,n);
        if(x==1||x==n-1) continue;
        for(int s=0;s<t;s++)
        {
            x=(__int128)x*x%n;
            if(x==n-1) break;
        }
        if(x!=n-1) return false;
    }
    return true;
}
long long find_factor(long long n)
{
    long long s=0,t=0;
    long long c=rnd()%(n-1)+1;
    for(int goal=1;;goal*=2)
    {
        long long val=1;
        for(int step=1;step<=goal;step++)
        {
            t=((__int128)t*t+c)%n;
            val=(__int128)val*abs(t-s)%n;
            if(step%127==0)
            {
                long long d=gcd(val,n);
                if(d>1) return d;
            }
        }
        long long d=gcd(val,n);
        if(d>1) return d;
        s=t;
    }
}
vector<pair<long long,int>>pollard_rho(long long n)
{
    if(n==1) return {};
    if(miller_rabin(n)) return {make_pair(n,1)};
    long long p=n;
    while(p>=n) p=find_factor(n);
    int cnt=0;
    while(n%p==0) n/=p,cnt++;
    vector<pair<long long,int>>res1=pollard_rho(n),res2=pollard_rho(p);
    for(auto &[x,i]:res2)
        i*=cnt;
    vector<pair<long long,int>>res;
    int p1=0,p2=0;
    while(p1<(int)res1.size()&&p2<(int)res2.size())
    {
        if(res1[p1].first<res2[p2].first) res.emplace_back(res1[p1]),p1++;
        else if(res1[p1].first>res2[p2].first) res.emplace_back(res2[p2]),p2++;
        else if(res1[p1].first==res2[p2].first) res.emplace_back(make_pair(res1[p1].first,res1[p1].second+res2[p2].second)),p1++,p2++;
    }
    while(p1<(int)res1.size())
        res.emplace_back(res1[p1]),p1++;
    while(p2<(int)res2.size())
        res.emplace_back(res2[p2]),p2++;
    return res;
}
```

#### O(1) LCA
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=500005;
int n,q,s;
vector<int>G[N];
int dfn[N],Index;
int mn[N][20],lg2[N];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    mn[Index][0]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
int main()
{
    scanf("%d%d%d",&n,&q,&s);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(s,0);
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
    return 0;
}
```

#### 虚树

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=500005;
int n,q;
vector<int>G[N];
int dfn[N],Index;
int mn[N][20],lg2[N];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    mn[Index][0]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
vector<int>E[N];
void build(vector<int>h)
{
    sort(h.begin(),h.end(),[=](const int &x,const int &y){return dfn[x]<dfn[y];});
    static int s[N],top;
    top=0;
    s[++top]=1;
    E[1].clear();
    for(int i=0;i<(int)h.size();i++)
        if(h[i]!=1)
        {
            int l=lca(h[i],s[top]);
            if(l!=s[top])
            {
                while(dfn[l]<dfn[s[top-1]])
                {
                    E[s[top]].emplace_back(s[top-1]),E[s[top-1]].emplace_back(s[top]);
                    top--;
                }
                if(dfn[l]>dfn[s[top-1]])
                {
                    E[l].clear();
                    E[l].emplace_back(s[top]),E[s[top]].emplace_back(l);
                    top--;
                    s[++top]=l;
                }
                else
                {
                    E[s[top-1]].emplace_back(s[top]),E[s[top]].emplace_back(s[top-1]);
                    top--;
                }
            }
            E[h[i]].clear();
            s[++top]=h[i];
        }
    for(int i=1;i<top;i++)
        E[s[i]].emplace_back(s[i+1]),E[s[i+1]].emplace_back(s[i]);
    return;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1,0);
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    return 0;
}
```