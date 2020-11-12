#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n,k;
int a[N];
int Max[N],Min[N];
int main()
{
	scanf("%d%d",&n,&k);
	memset(Min,63,sizeof(Min));
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		Max[a[i]]=max(Max[a[i]],i);
		Min[a[i]]=min(Min[a[i]],i);
	}	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i-1>=1&&Min[i]>Max[i-1]) ans++;
		if(i+1<=n&&Min[i]>Max[i+1]) ans++;
		if(Min[i]>Max[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
