#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200005;
int n,k;
int p[N];
int a[N];
pair<int,int> Min[N][20],Max[N][20];
void init()
{
	for(int i=1;i<=n;i++)
		Min[i][0]=Max[i][0]=make_pair(p[i],i);
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
	return;
}
int querymin(int l,int r)
{
	int k=log2(r-l+1);
	return min(Min[l][k],Min[r-(1<<k)+1][k]).second;
}
int querymax(int l,int r)
{
	int k=log2(r-l+1);
	return max(Max[l][k],Max[r-(1<<k)+1][k]).second;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		a[i]=p[i-1]>p[i];
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	init();
	int ans=0;
	bool flag=false;
	for(int r=k;r<=n;r++)
	{
		int l=r-k+1;
		if(a[l]==a[r])
		{
			flag=true;
			continue;
		}
		if(l==1)
		{
			ans++;
			continue;
		}
		if(querymin(l-1,r-1)==l-1&&querymax(l,r)==r) continue;
		ans++;
	}
	if(flag) ans++;
	printf("%d",ans);
	return 0;
}
