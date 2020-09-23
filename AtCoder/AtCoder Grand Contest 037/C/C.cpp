#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
priority_queue<pair<int,int>,vector<pair<int,int> > >q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		q.push(make_pair(b[i],i));
	a[0]=a[n],b[0]=b[n];
	a[n+1]=a[1],b[n+1]=b[1];
	long long ans=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(a[u]==b[u]) continue;
		int x=b[u-1]+b[u+1];
		if(a[u]>b[u])
		{
			printf("-1");
			return 0;
		}
		if(b[u]-a[u]<x)
		{
			printf("-1");
			return 0;
		}
		int t=(b[u]-a[u])/x;
		ans+=t;
		b[u]-=t*x;
		if(u==1) b[n+1]=b[1];
		if(u==n) b[0]=b[n];
		if(a[u]!=b[u]) q.push(make_pair(b[u],u));
	}
	printf("%lld",ans);
	return 0;
}
