#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100001;
int n,m,tot;
int U[N],C[N];
struct Edge
{
    int to,val,next;
}edge[N<<2];
int head[N],cnt;
int in[N];
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
queue<int>q;
void topsort()
{
    for(int i=1;i<=n;i++)
        if(!in[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        bool flag=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            flag=false;
            in[v]--;
            if(C[u]>0) C[v]+=C[u]*edge[i].val;
            if(!in[v])
            {
                C[v]-=U[v];
                q.push(v);
            }
        }
        if(flag&&C[u]>0) tot++;
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&C[i],&U[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        in[y]++;
    }
    topsort();
    if(tot==0)
    {
        printf("NULL");
        return 0;
    }
    for(int u=1;u<=n;u++)
        if(!head[u]&&C[u]>0) printf("%d %d\n",u,C[u]);
    return 0;
}