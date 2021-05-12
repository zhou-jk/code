#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=50005;
int n,m;
struct Basis
{
    static const int N=63;
    long long a[N];
    Basis()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        return;
    }
    void clear()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        return;
    }
    void insert(long long t)
    {
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
        return;
    }
    long long max_xor(long long x)
    {
        for(int i=N-1;i>=0;i--)
            if((x^a[i])>x) x^=a[i];
        return x;
    }
}lb;
vector<pair<int,long long>>G[N];
long long dis[N];
bool vis[N];
void dfs(int u)
{
    vis[u]=true;
    for(auto [v,w]:G[u])
        if(vis[v]) lb.insert(dis[u]^dis[v]^w);
        else
        {
            dis[v]=dis[u]^w;
            dfs(v);
        }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    dfs(1);
    printf("%lld",lb.max_xor(dis[n]));
    return 0;
}