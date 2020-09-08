#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n;
char s[N];
char a[N];
int len[N],l[N];
int m;
int sum[N][2];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1,j=1;i<=n;i=j)
	{
		while(j<=n&&s[i]==s[j]) j++;
		m++,a[m]=s[i],len[m]=j-i;
	}
	for(int i=1;i<=m;i++)
	{
		sum[i][0]+=sum[i-1][0];
		sum[i][1]+=sum[i-1][1];
		sum[i][a[i]-'0']+=len[i];
		l[i]=l[i-1]+len[i];
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]=='1')
		{
			if(len[i]&1)
			{
				ans+=(sum[i][0]+l[i]%2)/2;
				ans+=sum[m][0]-sum[i][0];
				int t=len[i]/2;
				ans+=sum[i][0]*t;
				ans+=(sum[m][0]-sum[i][0])*t;
			}
			else
			{
				int t=len[i]/2;
				ans+=sum[i][0]*t;
				ans+=(sum[m][0]-sum[i][0])*t;
			}
		}
	}
	for(int i=0;i<=sum[m][1];i++)
	{
		int s=sum[m][1]-i;
		ans+=(s+1)/2;
	}
	printf("%lld",ans);
	return 0;
}

