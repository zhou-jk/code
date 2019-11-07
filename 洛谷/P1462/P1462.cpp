#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
int n,m,b;
int a[10001];
int l=INF,r,mid;
int ans=-1;
struct Edge
{
    int to,val,next;
}edge[100001];
int head[10001],cnt;
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
int dis[10001];
bool book[10001];
bool check(int x)
{
    memset(dis,63,sizeof(dis));
    memset(book,false,sizeof(book));
    dis[1]=0;
    book[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        book[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val&&a[v]<=x)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!book[v])
                {
                    book[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return dis[n]<b;
}
int main()
{
    scanf("%d%d%d",&n,&m,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        l=min(l,a[1]),r=max(r,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(ans==-1) printf("AFK");
    else printf("%d",ans);
    return 0;
}