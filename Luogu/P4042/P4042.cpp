#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200001;
int n;
struct Edge
{
	int to,next;
}e[N*5],edge[N*5];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int Head[N],Cnt;
void Add_edge(int u,int v)
{
    Cnt++;
    e[Cnt].to=v;
    e[Cnt].next=Head[u];
    Head[u]=Cnt;
    return;
}
queue<int>q;
long long dp[N],f[N];
bool vis[N];
void spfa()
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=true;
        q.push(i);
    }
	while(!q.empty())
	{
		int u=q.front();
        q.pop();
        vis[u]=false;
		long long sum=f[u];
		for(int i=Head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            sum+=dp[v];
        }
		if(sum<dp[u])
		{
			dp[u]=sum;
			for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld%lld%d",&f[i],&dp[i],&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			add_edge(x,i);
            Add_edge(i,x);
		}
	}
	spfa();
    printf("%lld",dp[1]);
	return 0;
}