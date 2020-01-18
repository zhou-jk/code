#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[40][40],cnt,x,y;
int main()
{
	scanf("%d",&n);
	while(cnt<=n*n)
	{
		if(cnt==0) a[x=1][y=(n+1)/2]=++cnt;
		else if(x==1&&y!=n) a[x=n][++y]=++cnt;
		else if(x!=1&&y==n) a[--x][y=1]=++cnt;
		else if(x==1&&y==n) a[++x][y]=++cnt;
		else if(!a[x-1][y+1]) a[--x][++y]=++cnt;
		else a[++x][y]=++cnt;
	}
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
	return 0;
}