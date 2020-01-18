#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=50;
int a[N],b[N],s[N],f[N][N][2];

int main()
{
	freopen("power.in","r",stdin); freopen("power.out","w",stdout);
	int n,c;
	scanf("%d%d",&n,&c);
	c--;
	for (int i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
	s[0]=b[0];
	for (int i=1; i<n; i++) s[i]=s[i-1]+b[i];
	memset(f,63,sizeof f);
	f[0][0][0]=f[0][0][1]=0;
	for (int i=1; i<=c; i++) f[i][0][0]=f[i-1][0][0]+(s[n-1]-s[c]+s[c-i])*(a[c-i+1]-a[c-i]);
	for (int i=1; i<n-c; i++) f[0][i][1]=f[0][i-1][1]+(s[n-1]-s[c+i-1]+s[c-1])*(a[c+i]-a[c+i-1]);
	for (int i=1; i<=c; i++)
		for (int j=1; j<n-c; j++)
		{
			f[i][j][0]=min(f[i-1][j][0]+(s[n-1]-s[c+j]+s[c-i])*(a[c-i+1]-a[c-i]),
			               f[i-1][j][1]+(s[n-1]-s[c+j]+s[c-i])*(a[c+j]-a[c-i]));
			f[i][j][1]=min(f[i][j-1][1]+(s[n-1]-s[c+j-1]+s[c-i-1])*(a[c+j]-a[c+j-1]),
			               f[i][j-1][0]+(s[n-1]-s[c+j-1]+s[c-i-1])*(a[c+j]-a[c-i]));
		}
	printf("%d",min(f[c][n-1-c][0],f[c][n-1-c][1]));
	return 0;
}