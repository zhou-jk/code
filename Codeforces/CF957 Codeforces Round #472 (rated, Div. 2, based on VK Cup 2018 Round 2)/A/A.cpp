#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]!='?'&&s[i]==s[i-1])
		{
			printf("No");
			return 0;
		}
	if(s[1]=='?'||s[n]=='?')
	{
		printf("Yes");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?'&&s[i-1]=='?')
		{
			printf("Yes");
			return 0;
		}
		if(s[i]=='?'&&s[i-1]==s[i+1])
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");	
	return 0;
}
