#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int const oo=100000000;
int f[33][33][53];
void dfs(int n,int m,int k){
	if (f[n][m][k]!=oo) return ;
	if (k>n*m) return;
	if (k==n*m) {
		f[n][m][k]=0;
		return;
    }
	for(int i=1;i<=n-1;i++)
		for(int t=0;t<=k;t++) {
			dfs(i,m,t); dfs(n-i,m,k-t);
			f[n][m][k]=min(f[n][m][k],f[i][m][t]+f[n-i][m][k-t]+m*m);
	    }
    for(int j=1;j<=m-1;j++)
		for(int t=0;t<=k;t++) {
			dfs(n,j,t); dfs(n,m-j,k-t);
			f[n][m][k]=min(f[n][m][k],f[n][j][t]+f[n][m-j][k-t]+n*n);
        }
}
int main(){
	freopen("chocolate.in","r",stdin); freopen("chocolate.out","w",stdout);
	for(int i=0;i<=30;i++)
		for (int j=0;j<=30;j++)
			for(int k=0;k<=50;k++)
				if (k==0) f[i][j][k]=0;
					else f[i][j][k]=oo;
	for(int i=0;i<=30;i++)
		for(int j=0;j<=30;j++)
			for(int k=0;k<=50 && k<=i*j;k++)
				dfs(i,j,k);
	int cas;
	scanf("%d",&cas);
	while (cas--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",f[n][m][k]);
    }
	return 0;
}
