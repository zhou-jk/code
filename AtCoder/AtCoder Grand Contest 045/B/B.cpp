#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000005;
const int INF=1061109567;
int n;
char s[N];
int a[N];
int sum[N];
int suf[N];
int calc(int Min)
{
	static int b[N];
	int add=0; 
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?'&&suf[i]-add-2>=Min) add+=2;
		b[i]=sum[i]-add;
	}
	int Max=max(*max_element(b+1,b+n+1),0);
	return Max-Min;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='1'||s[i]=='?') a[i]=1;
		else if(s[i]=='0') a[i]=-1;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	suf[n+1]=INF;
	for(int i=n;i>=1;i--)
		suf[i]=min(suf[i+1],sum[i]);
	int m=min(*min_element(sum+1,sum+n+1),0);
	printf("%d",min(calc(m),calc(m-1)));
	return 0;
}
