#include<iostream>
#include<cstdio>
using namespace std;
const int N=12;
int n,m;
int a[1<<N][1<<N];
void dfs(int x,int y,int k)
{
	if(k==1)
	{
		a[x][y]=1;
		return;
	}
	dfs(x,y,k-1);
	dfs(x+(1<<(k-1)),y,k-1);
	dfs(x,y+(1<<(k-1)),k-1);
	dfs(x+(1<<(k-1)),y+(1<<(k-1)),k-1);
	for(int i=1;i<=(1<<k)-1;i++)
		a[x+(1<<(k-1))-1][y+i-1]=a[x+i-1][y+(1<<(k-1))-1]=0;
	a[x+(1<<(k-1))-1][y+(1<<(k-1))-1]=1;
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(1,1,max(n,m));
	for(int i=1;i<=(1<<n)-1;i++)
	{
		for(int j=1;j<=(1<<m)-1;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	return 0;
}

