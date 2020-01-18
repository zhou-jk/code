#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N=100;
bool map[N+1][N+1];
int s[N+1][N+1],len1[N],len2[N],t,ans;

int main() {
	freopen("brick.in","r",stdin); freopen("brick.out","w",stdout);
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&x,&y);
		map[x][y]=true;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
			s[i][j]=s[i][j-1]+s[i-1][j]+map[i][j]-s[i-1][j-1];
	for (int i=1;i<=floor(sqrt(m));i++)
		if (!(m%i)&&m/i<=n) len1[t]=i,len2[t++]=m/i;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<t;k++) {
				if (i+len1[k]<=n&&j+len2[k]<=n)
					ans=max(ans,s[i+len1[k]][j+len2[k]]-s[i+len1[k]][j]-s[i][j+len2[k]]+s[i][j]);
				if (i+len2[k]<=n&&j+len1[k]<=n)
					ans=max(ans,s[i+len2[k]][j+len1[k]]-s[i+len2[k]][j]-s[i][j+len1[k]]+s[i][j]);
			}
	printf("%d",m-ans);
	return 0;
}
