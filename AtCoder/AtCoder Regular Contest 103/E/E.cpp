#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n;
char s[N];
void add_edge(int u,int v)
{
	printf("%d %d\n",u,v);
	return;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[1]=='0'||s[n]=='1')
	{
		printf("-1");
		return 0;
	}
	for(int i=2;i<=n-1;i++)
		if(s[i]!=s[n-i])
		{
			printf("-1");
			return 0;
		}
	int rt=1,tot=1;
	for(int i=1,j=1;i<=n-1;i=j)
	{
		j=i+1;
		while(j<=n-1&&s[j]=='0') j++;
		int pre=rt;
		rt=++tot;
		add_edge(rt,pre);
		for(int k=1;k<=j-i-1;k++)
			add_edge(rt,++tot);
	}
	return 0;
}
