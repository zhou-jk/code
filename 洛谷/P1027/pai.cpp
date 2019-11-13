#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
const int INF=0x3f3f3f3f;
typedef long long LL;
const int mod=1e9+7;
//const double PI=acos(-1);
#define Bug cout<<"---------------------"<<endl
const int maxn=1e5+10;
using namespace std;

int n,A,B;
double cost;

struct node 
{
    int x, y;
    int city;
};

node a[4];
node b[maxn];
int tot;

struct Edge
{
    int to,next;
    double val;
}edge[7005<<1];

int head[3000];
int cnt;
double dis[3000];
int w[maxn];
struct Node
{
    int u;
    double w;
    bool operator>(const Node &b)const
    {
        return w>b.w;
    }
};
void add_edge(int u,int v,double w)
{
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
} 
double count(int x1, int y1, int x2, int y2) 
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
}
void dijkstra()
{
    memset(dis,127,sizeof(dis));
    priority_queue<Node,vector<Node>,greater<Node> > q;
    for(int i=A*4-3;i<=A*4;i++)
    {
        dis[i]=0;
        q.push(());
    }
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                q.push(v);
            }
        } 
    }
}

int main()
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
            a[0]=a[1];a[1]=a[2];a[2]=t;
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
    return 0;
}