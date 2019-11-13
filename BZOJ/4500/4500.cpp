#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=4001;
const int E=10001;
struct Edge
{
    int to,val,next;
}edge[E];
int T,n,m,k;
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
int dis[N],num[N];
bool vis[N];
bool spfa(int s)
{
	queue<int>q;
	vis[s]=true;
    dis[s]=0;
    num[s]++;
    q.push(s);
    while(!q.empty())
    {
		int u=q.front();
        q.pop();
        vis[u]=false;
		for (int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!vis[v])
                {
                    vis[v]=true;
                    num[v]++;
                    if(num[v]>=1000) return true;
                    q.push(v);
                }
            }
		}
	}
	return false;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
		cnt=0;
        memset(head,0,sizeof(head));
        memset(vis,false,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(y+n,x,z);
            add_edge(x,y+n,-z);
		}
        memset(dis,63,sizeof(dis));
        memset(num,0,sizeof(num));
		bool flag=true;
        for(int i=1;i<=n+m;i++)
            if(dis[i]==dis[0]&&spfa(i))
            {
                flag=false;
                printf("No\n");
                break;
		    }
        if(flag) printf("Yes\n");
	}
	return 0;
}