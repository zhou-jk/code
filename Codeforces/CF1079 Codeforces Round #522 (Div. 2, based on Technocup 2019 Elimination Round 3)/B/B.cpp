#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int n;
int a,b;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	a=(n+20-1)/20;
	if(n%a==0)
	{
		b=n/a;
		printf("%d %d\n",a,b);
		int now=0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
				printf("%c",s[++now]);
			printf("\n");
		}
		return 0;
	}
	b=n/a+1;
	printf("%d %d\n",a,b);
	int cnt=0;
	bool flag=false;
	for(int i=1;i<=a;i++)
	{
		if(!flag&&(n-cnt)%(b-1)==0) b--,flag=true;
		for(int j=1;j<=b;j++)
			printf("%c",s[++cnt]);
		if(flag) printf("*");
		printf("\n");
	}
	return 0;
}
