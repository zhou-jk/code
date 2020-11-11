#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[3][N];
long long f[N][4];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max({f[i-1][0],f[i-1][1],f[i-1][2]});
		f[i][1]=max({f[i-1][0],f[i-1][2]})+a[1][i];
		f[i][2]=max({f[i-1][0],f[i-1][1]})+a[2][i];
	}
	long long ans=max({f[n][0],f[n][1],f[n][2]});
	printf("%lld",ans);
	return 0;
}
