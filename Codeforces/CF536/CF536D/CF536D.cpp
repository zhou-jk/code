#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005,M=100005;
const long long INF=4557430888798830399;
int n,m,s,t;
int a[N];
struct Edge
{
	int to,val,next;
}edge[M<<1];
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
vector<long long> vx,vy;
int R,C;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
long long diss[N],dist[N];
bool book[N];
void dijkstra(int s,long long *dis)
{
	memset(book,false,sizeof(book));
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second; 
		q.pop();
		if(book[u]) continue;
		book[u]=true;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].val)
			{
				dis[v]=dis[u]+edge[i].val;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	return;
}
long long sumx[N][N],sumy[N][N];
long long numx[N][N],numy[N][N];
long long sum[N][N];
long long num[N][N];
long long getnumx(int x,int l,int r){return numx[x][r]-numx[x][l-1];}
long long getnumy(int y,int l,int r){return numy[r][y]-numy[l-1][y];}
long long getsumx(int x,int l,int r){return sumx[x][r]-sumx[x][l-1];}
long long getsumy(int y,int l,int r){return sumy[r][y]-sumy[l-1][y];}
long long dp[N][N][2];
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	dijkstra(s,diss);
	dijkstra(t,dist);
	for(int i=1;i<=n;i++)
		vx.push_back(diss[i]),vy.push_back(dist[i]);
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	int R=vx.size(),C=vy.size();
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(vx.begin(),vx.end(),diss[i])-vx.begin()+1,y=lower_bound(vy.begin(),vy.end(),dist[i])-vy.begin()+1;
		num[x][y]++;
		sum[x][y]+=a[i];
	}
	for(int i=1;i<=R+1;i++)
		for(int j=1;j<=C+1;j++)
			sumx[i][j]=sumx[i][j-1]+sum[i][j],numx[i][j]=numx[i][j-1]+num[i][j];
	for(int j=1;j<=C+1;j++)
		for(int i=1;i<=R+1;i++)
			sumy[i][j]=sumy[i-1][j]+sum[i][j],numy[i][j]=numy[i-1][j]+num[i][j];    
	for(int i=R;i>=0;i--)
		for(int j=C;j>=0;j--)
		{
			if(i!=R)
			{
				if(getnumx(i+1,j+1,C)==0) dp[i][j][0]=dp[i+1][j][0];
				else dp[i][j][0]=max(dp[i+1][j][0],dp[i+1][j][1])+getsumx(i+1,j+1,C);
			}
			if(j!=C)
			{
				if(getnumy(j+1,i+1,R)==0) dp[i][j][1]=dp[i][j+1][1];
				else dp[i][j][1]=min(dp[i][j+1][0],dp[i][j+1][1])-getsumy(j+1,i+1,R);
			}
		}
	if(dp[0][0][0]>0) printf("Break a heart");
	if(dp[0][0][0]<0) printf("Cry");
	if(dp[0][0][0]==0) printf("Flowers");
	return 0;
}
