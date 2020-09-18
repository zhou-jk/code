#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500005;
int n;
char s[N];
int a[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1,j=1;i<=n;i=j)
	{
		while(j<=n&&s[i]==s[j]) j++;
		if(s[i]=='<')
		{
			int l=-1;
			a[i-1]=max(a[i-1],++l);
			for(int k=i;k<j;k++)
				a[k]=max(a[k],++l);
		}
		else if(s[i]=='>')
		{
			int l=-1;
			for(int k=j-1;k>=i;k--)
				a[k]=max(a[k],++l);
			a[i-1]=max(a[i-1],++l);
		}
	}
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans+=a[i];
	printf("%lld",ans);
	return 0;
}
