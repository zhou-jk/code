#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int in[100001],out[100001];
struct Edge
{
    int to,next;
}edge[200001];
int head[100001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int f[100001];
long long dfs(int u)
{
    if(f[u]) return f[u];
    long long res=0;
    if(out[u]==0&&in[u]!=0) res++;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        res+=dfs(v);
    }
    f[u]=res;
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        out[x]++;
        in[y]++;
        add_edge(x,y);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(in[i]==0) ans+=dfs(i);
    printf("%lld",ans);
    return 0;
}