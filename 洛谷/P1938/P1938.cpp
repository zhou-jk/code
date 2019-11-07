#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int d,p,c,f,s;
struct Edge
{
    int to,val,next;
}edge[601];
int head[1001],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
bool book[1001];
int num[1001],dis[1001];
queue<int>q;
int main()
{
    scanf("%d%d%d%d%d",&d,&p,&c,&f,&s);
    for(int i=1;i<=p;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y,d);
    }
    for(int i=1;i<=f;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,d-z);
    }
    q.push(s);
    book[s]=1;
    dis[s]=d;
    num[s]++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        book[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]<dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!book[v])
                {
                    book[v]=true;
                    q.push(v);
                    num[v]++;
                    if(num[v]>c)
                    {
                        printf("-1");
                        return 0;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=c;i++)
        ans=max(ans,dis[i]);
    printf("%d",ans);
    return 0;
}