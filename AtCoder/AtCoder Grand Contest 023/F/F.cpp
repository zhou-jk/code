#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int fa[N];
int v[N];
struct Node
{
    int a,b;
    bool operator < (const Node &rhs)const
    {
        return (long long)a*rhs.b>(long long)b*rhs.a;
    }
}c[N];
multiset<pair<Node,int>>S;
int f[N];
int getf(int v)
{
    if(v==f[v]) return v;
    else return f[v]=getf(f[v]);
}
int nxt[N];
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
        scanf("%d",&fa[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        if(v[i]==0) c[i].a++;
        else c[i].b++;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=2;i<=n;i++)
        S.insert({c[i],i});
    long long ans=0;
    while(!S.empty())
    {
        auto [p,v]=*S.begin();
        S.erase(S.begin());
        int u=getf(fa[v]);
        f[v]=f[fa[v]];
        if(u!=1) S.erase(S.find({c[u],u}));
        ans+=(long long)c[u].b*c[v].a;
        c[u].a+=c[v].a,c[u].b+=c[v].b;
        if(u!=1) S.insert({c[u],u});
    }
    printf("%lld",ans);
    return 0;
}