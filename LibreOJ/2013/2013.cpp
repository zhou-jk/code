#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
struct Basis
{
private:
    static const int N=63;
    long long a[N];
    vector<long long>b;
    int cnt;
public:
    Basis()
    {
        cnt=0;
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void clear()
    {
        cnt=0;
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    vector<long long>basis()const
    {
        vector<long long>c(b.size());
        for(int i=0;i<(int)b.size();i++)
            c[i]=a[b[i]];
        return c;
    }
    void insert(const long long &x)
    {
        cnt++;
        long long t=x;
        for(int i=N-1;i>=0;i--)
            if((t>>i)&1)
            {
                if(a[i]) t^=a[i];
                else
                {
                    for(int j=0;j<i;j++)
                        if((t>>j)&1) t^=a[j];
                    for(int j=i+1;j<N;j++)
                        if((a[j]>>i)&1) a[j]^=t;
                    a[i]=t;
                    break;
                }
            }
        b.clear();
        for(int i=0;i<N;i++)
            if(a[i]) b.push_back(i);
        return;
    }
    Basis insert(const Basis &rhs)
    {
		vector<long long>c=rhs.basis();
		for(int i=0;i<(int)c.size();i++)
			insert(c[i]);
        return *this;
    }
    int size()const
    {
        return b.size();
    }
    long long max_xor()const
    {
        long long res=0;
        for(int i=N-1;i>=0;i--)
            res^=a[i];
        return res;
    }
    long long kth_xor(const long long &x)const
    {
        long long k=x;
        if(size()!=cnt) k--;
        if(k>(1LL<<size())-1) return -1;
        long long res=0;
        for(int i=0;i<(int)b.size();i++)
            if((k>>i)&1) res^=a[b[i]];
        return res;
    }
    long long rank(const long long &x)const
    {
        long long res=0;
        for(int i=0;i<(int)b.size();i++)
            if((x>>b[i])&1) res+=1LL<<i;
        return res;
    }
    Basis operator + (const Basis &rhs)const
    {
        if(size()<rhs.size())
        {
            Basis c=rhs;
            vector<long long>d=basis();
            for(int i=0;i<(int)d.size();i++)
                c.insert(d[i]);
            return c;
        }
        else
        {
            Basis c=*this;
            vector<long long>d=rhs.basis();
            for(int i=0;i<(int)d.size();i++)
                c.insert(d[i]);
            return c;
        }
    }
    Basis operator += (const Basis &rhs)
    {
        return *this=*this+rhs;
    }
};
const int N=20005;
int n,Q;
long long a[N];
vector<int>G[N];
int dep[N];
int fa[N][15];
Basis f[N][15];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    f[u][0].insert(a[father]);
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1],f[u][i]=f[u][i-1]+f[fa[u][i-1]][i-1];
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
Basis query(int u,int v)
{
    Basis res;
    res.insert(a[u]),res.insert(a[v]);
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) res.insert(f[u][i]),u=fa[u][i];
    if(u==v) return res;
    for(int i=log2(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) res.insert(f[u][i]+f[v][i]),u=fa[u][i],v=fa[v][i];
    res.insert(a[fa[u][0]]);
    return res;
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1,0);
    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",query(x,y).max_xor());
    }
    return 0;
}