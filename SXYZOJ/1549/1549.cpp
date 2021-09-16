#include<iostream>
#include<cstdio>
#include<queue>
#include<numeric>
using namespace std;
const int N=200005;
int n;
int f[N];
int getf(int v)
{
    if(v==f[v]) return v;
    else return f[v]=getf(f[v]);
}
struct Node
{
    int fa,siz;
    long long val;
}a[N];
bool vis[N];
priority_queue<pair<double,int>,vector<pair<double,int>>>q;
int main()
{
    scanf("%d",&n);
    iota(f+1,f+n+1,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].val);
        a[i].siz=1;
        if(i!=1) q.emplace(a[i].val,i);
    }
    for(int i=2;i<=n;i++)
        scanf("%d",&a[i].fa);
    long long ans=0;
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        int fa=getf(a[u].fa);
        ans+=a[u].val*a[fa].siz;
        a[fa].val+=a[u].val,a[fa].siz+=a[u].siz;
        f[u]=fa;
        if(fa!=1) q.emplace((double)a[fa].val/a[fa].siz,fa);
    }
    printf("%lld",ans);
    return 0;
}