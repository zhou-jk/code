#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,st[100001][17];
int query(int l,int r)
{
	int k=log2(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&st[i][0]);
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n-m+1;i++)
		printf("%d\n",query(i,i+m-1));
	return 0;
}