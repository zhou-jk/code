#include <cstdio>
#include <algorithm>

using std::min;

const int N=1000;
int num[N][N],f[N][N],n;

int calc(int a,int b)
{
	if (!a) return 30000;
	int ret;
	for (ret=0; !(a%b); ret++) a/=b;
	return ret;
}

int solve(int d)
{
	f[0][0]=calc(num[0][0],d);
	for (int i=1; i<n; i++)
		f[0][i]=f[0][i-1]+calc(num[0][i],d),f[i][0]=f[i-1][0]+calc(num[i][0],d);
	for (int i=1; i<n; i++)
		for (int j=1; j<n; j++)
			f[i][j]=min(f[i][j-1],f[i-1][j])+calc(num[i][j],d);
	return f[n-1][n-1];
}

int main()
{
	freopen("prod.in","r",stdin); freopen("prod.out","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) scanf("%d",&num[i][j]);
	printf("%d",min(solve(2),solve(5)));
	return 0;
}