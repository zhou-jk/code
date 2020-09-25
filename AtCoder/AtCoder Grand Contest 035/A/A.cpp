#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int cnt[N],num[N],tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[1]==a[n]&&a[1]==0)
	{
		printf("Yes");
		return 0;
	}
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]) tot++,num[tot]=a[i],cnt[tot]=1;
		else cnt[tot]++;
		if(tot>3)
		{
			printf("No");
			return 0;
		}
	}
	if(n%3!=0)
	{
		printf("No");
		return 0;
	}
	if(tot==3)
	{
		if((num[1]^num[2]^num[3])==0&&cnt[1]==cnt[2]&&cnt[2]==cnt[3]) printf("Yes");
		else printf("No");
	}
	else if(tot==2)
	{
		if(a[1]==0&&cnt[1]==n/3) printf("Yes");
		else printf("No");
	}
	else printf("No");
	return 0;
}
