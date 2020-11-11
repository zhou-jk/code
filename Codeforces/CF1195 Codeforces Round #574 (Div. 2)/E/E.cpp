#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=3005;
int n,m,a,b;
long long g[N*N];
int x,y,z;
int h[N][N];
int pre[N][N];
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	scanf("%d%d%d%d",&g[0],&x,&y,&z);
	for(int i=1;i<=n*m;i++)
		g[i]=(g[i-1]*x+y)%z;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			h[i][j]=g[(i-1)*m+j-1];
	for(int i=1;i<=n;i++)
	{
		deque<int>q;
		for(int j=1;j<=m;j++)
		{
			while(!q.empty()&&j-q.front()+1>b) q.pop_front();
			while(!q.empty()&&h[i][q.back()]>=h[i][j]) q.pop_back();
			q.push_back(j);
			pre[i][j]=h[i][q.front()];
		}
	}
	long long ans=0;
	for(int j=b;j<=m;j++)
	{
		deque<int>q;
		for(int i=1;i<=n;i++)
		{
			while(!q.empty()&&i-q.front()+1>a) q.pop_front();
			while(!q.empty()&&pre[q.back()][j]>=pre[i][j]) q.pop_back();
			q.push_back(i);
			if(i>=a) ans+=pre[q.front()][j];
		}
	}
	printf("%lld",ans);
	return 0;
}
