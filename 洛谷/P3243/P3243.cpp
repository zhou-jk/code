#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int T,n,m;
struct Edge
{
    int to,next;
}edge[100001];
int head[100001],cnt;
int in[100001],tot,res[100001];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void topsort()
{
    priority_queue<int>q;
    tot=0;
    for(int i=1;i<=n;i++)
        if(!in[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        res[++tot]=u;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head));
        memset(in,0,sizeof(in));
        cnt=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(y,x);
            in[x]++;
        }
        topsort();
        if(tot<n) printf("Impossible!\n");
        else
        {
            for(int i=tot;i>=1;i--)
                printf("%d ",res[i]);
            printf("\n");
        } 
    }
    return 0;
}