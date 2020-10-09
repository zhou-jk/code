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
	int A=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='B'&&s[i+1]=='C') ans+=A,i++;
		else if(s[i]=='A') A++;
		else if(s[i]=='B'||s[i]=='C') A=0;
	printf("%lld",ans);
	return 0;
}
