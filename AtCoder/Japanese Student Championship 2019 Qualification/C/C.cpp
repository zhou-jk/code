#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
char s[N];
int a[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	if(s[1]=='W')
	{
		printf("0");
		return 0;
	}
	a[0]=1;
	for(int i=1;i<=n*2;i++)
		if(s[i]==s[i-1]) a[i]=a[i-1]^1;
		else a[i]=a[i-1];
	int num=0;
	long long ans=1;
	for(int i=1;i<=n*2;i++)
	{
		if(a[i]==1) num++;
		else ans=ans*num%MOD,num--;
		if(num<0)
		{
			printf("0");
			return 0;
		}
	}
	if(num!=0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		ans=ans*i%MOD;
	printf("%lld",ans);
	return 0;
}
