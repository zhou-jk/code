#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
int n;
int p[N];
int c[N];
int solve(int s)
{
	memset(c,0,sizeof(c));
	for(int i=s;;i=p[i])
	{
		c[i]++;
		if(c[i]>=2) return i;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		printf("%d ",solve(i));
	return 0;
}
