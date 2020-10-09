#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,a,b,c,d;
char s[N];
int main()
{
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d); //a->c b->d
	scanf("%s",s+1);
	if(a<b&&c>d)
	{
		bool flag=false;
		for(int i=b;i<=d;i++)
			if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.')
			{
				flag=true;
				break;
			}
		if(!flag)
		{
			printf("No");
			return 0;
		}
		for(int i=a+1;i<=c;i++)
			if(s[i-1]=='#'&&s[i]=='#')
			{
				printf("No");
				return 0;
			}
		printf("Yes");
		return 0;
	}
	else
	{
		for(int i=b+1;i<=d;i++)
			if(s[i-1]=='#'&&s[i]=='#')
			{
				printf("No");
				return 0;
			}
		for(int i=a+1;i<=c;i++)
			if(s[i-1]=='#'&&s[i]=='#')
			{
				printf("No");
				return 0;
			}
		printf("Yes");
		return 0;
	}
	return 0;
}
