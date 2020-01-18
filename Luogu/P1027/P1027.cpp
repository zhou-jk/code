#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
const int N=100001;
const int INF=1061109567;
using namespace std;
struct Edge
{
    int to,next;
    double val;
}edge[7001<<1];
int head[3001],cnt;
void add_edge(int u,int v,double w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int T,n,A,B;
double cost;
struct node 
{
    int x,y,city;
}a[4],b[N];
int tot;
inline double count(int x1,int y1,int x2,int y2) 
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
}
struct Node
{
    int u;
    double w;
    bool operator>(const Node &b)const 
    {
        return w>b.w;
    }
};
double dis[3001];
int w[N];
void dijkstra()
{
    memset(dis,127,sizeof(dis));
    priority_queue<Node,vector<Node>,greater<Node> >q;
    for(int i=A*4-3;i<=A*4;i++)
    {
        dis[i]=0;
        q.push((Node){i,0});
    }
    while(!q.empty())
    {
        int u=q.top().u;
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                q.push((Node){v,dis[v]});
            }
        } 
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cnt=tot=0;
        memset(head,0,sizeof(head)); 
        scanf("%d%lf%d%d",&n,&cost,&A,&B);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d%d%d%d",&a[0].x,&a[0].y,&a[1].x,&a[1].y,&a[2].x,&a[2].y,&w[i]);
            while((a[0].x-a[1].x)*(a[2].x-a[1].x)!=(a[0].y-a[1].y)*(a[1].y-a[2].y))
            {
                node t=a[0];
                a[0]=a[1],a[1]=a[2],a[2]=t;
            }
            a[3].x=a[2].x+(a[0].x-a[1].x);
            a[3].y=a[2].y+(a[0].y-a[1].y);
            for(int k=0;k<4;k++)
                a[k].city=i,b[++tot]=a[k];
        }
        for(int i=1;i<=tot;i++)
            for(int j=i+1;j<=tot;j++)
            {
                double val;
                if(b[i].city==b[j].city) val=count(b[i].x,b[i].y,b[j].x,b[j].y)*w[b[i].city];
                else val=count(b[i].x,b[i].y,b[j].x,b[j].y)*cost;
                add_edge(i,j,val);
                add_edge(j,i,val);
            }
        dijkstra();
        printf("%.1f\n",*min_element(dis+B*4-3,dis+B*4));
    }
    return 0;
}