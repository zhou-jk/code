#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
const int N=1001,M=20001;
int n,ml,md;
struct Edge
{
    int to,val,next;
}edge[M+N];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int num[N],dis[N];
bool book[N];
bool spfa(int s)
{
    memset(dis,63,sizeof(dis));
    memset(num,0,sizeof(num));
    dis[s]=0;
    queue<int>q;
    q.push(s);
    book[s]=true;
    num[s]++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        book[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!book[v])
                {
                    book[v]=true;
                    num[v]++;
                    if(num[v]>=n) return true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d%d",&n,&ml,&md);
    for(int i=1;i<=ml;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
    }
    for(int i=1;i<=md;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(y,x,-z);
    }
    for(int i=1;i<=n;i++)
        add_edge(0,i,0);
    if(spfa(0))
    {
        printf("-1");
        return 0;
    }
    spfa(1);
    if(dis[n]>=INF)
    {
        printf("-2");
        return 0;
    }
    printf("%d",dis[n]);
    return 0; 
}