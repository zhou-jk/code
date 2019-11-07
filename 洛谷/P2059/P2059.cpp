#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[51];
double f[51][51];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	f[1][1]=100;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=m;k++)
            {
				int t=(a[k]-1)%i+1;
				if(t!=j) f[i][j]+=1.0/m*f[i-1][((j+i-t)%i-1)%(i-1)+1];
			}
	for(int i=1;i<=n;i++)
		printf("%.2lf%% ",f[n][i]);
	return 0;
}