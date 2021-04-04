#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B') cnt++;
		else if(s[i]=='W') ans+=cnt;
	}
	printf("%lld",ans);
	return 0;
}