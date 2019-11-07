#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1e9;
struct Edge
{
    int to,next;
}edge[200001];
int head[100001],cnt;
int l[100001],r[100001];
int t,T;
int n,m;
int res1=INF,res2=-INF;
int ans[100001];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void dfs(int u,int color)
{
    if(ans[u])
    {
        if(ans[u]!=color)
        {
            printf("IMPOSSIBLE");
            exit(0);
        }
        return;
    }
    ans[u]=color;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v,3-color);
    }
    return;
}
int main()
{
    scanf("%d%d",&t,&T);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        res2=max(res2,l[i]);
        res1=min(res1,r[i]);
    }
    res1=min(res1,T-res2);
    res2=max(res2,t-res1);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!(l[i]<=res1&&res1<=r[i])&&!(l[i]<=res2&&res2<=r[i])) 
        {
            printf("IMPOSSIBLE");
            return 0;
        }
        if((l[i]<=res1&&res1<=r[i])&&!(l[i]<=res2&&res2<=r[i])) dfs(i,1);
        if((l[i]<=res2&&res2<=r[i])&&!(l[i]<=res1&&res1<=r[i])) dfs(i,2);
    }
    for(int i=1;i<=n;i++)
        if(!ans[i]) dfs(i,1);
    printf("POSSIBLE\n");
    printf("%d %d\n",res1,res2);
    for(int i=1;i<=n;i++)
        printf("%d",ans[i]);
    return 0;
}