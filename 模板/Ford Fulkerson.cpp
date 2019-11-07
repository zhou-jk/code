#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1061109567;
int n,m,S,T;
int head[10001],cnt=1; 
struct Edge
{
    int to,val,next;
}edge[200001];
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
bool book[10001];
int dfs(int u,int flow)
{
    book[u]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]||edge[i].val<=0) continue;
        int t=min(flow,edge[i].val),tt;
        if(v==T) 
        {
            edge[i].val-=t,edge[i^1].val+=t;
            return t;
        }
        int w=dfs(v,t);
        if(w>0)
        {
            edge[i].val-=w,edge[i^1].val+=w;
            return w;
        }
    }
    return 0;
}
int ford_fulkerson()
{
    int ans=0;
    while(1)
    {
        memset(book,false,sizeof(book));
        int res=dfs(S,INF);
        if(res==0) break;
        ans+=res;
    }
    return ans;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&S,&T);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,0);
    }
    printf("%d",ford_fulkerson());
    return 0;
}