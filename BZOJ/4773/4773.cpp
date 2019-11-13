#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=301;
struct Edge
{
    int to,val,next;
}edge[N*N];
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
int inq[N],dis[N];
bool spfa(int u,int time,int x)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(dis[v]>=dis[u]+edge[i].val)
        {
            if(inq[v]) return true;
            if(time==x) return false;
            dis[v]=dis[u]+edge[i].val;
            inq[v]=true;
            if(spfa(v,time+1,x)) return true;
            inq[v]=false;
        }
    }
    return false;
}
int n,m;
bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        memset(dis,0,sizeof(dis));
        memset(inq,false,sizeof(inq));
        dis[i]=0;
        inq[i]=true;
        if(spfa(i,1,x)) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
    }
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}