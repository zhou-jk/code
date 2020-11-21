#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int x=0,y=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='R') x++;
		else if(s[i]=='U') y++;
		if(x==y)
		{
			if(s[i]==s[i+1]) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
