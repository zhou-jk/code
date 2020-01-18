#define M 5000
#define A 50000

#include <cstdio>
#include <cstring>

int a[M],d[A],q[A];
bool vis[A];

int main() {
	freopen("sum.in","r",stdin); freopen("sum.out","w",stdout);
	int m,k,x,l,r;
	scanf("%d",&m);
	for (int i=0;i<m;i++) scanf("%d",&a[i]);
	memset(d,127,sizeof d); d[0]=0;
	l=0; r=1; q[0]=0;
	vis[0]=true;
	while (vis[q[l]]) {
		vis[q[l]]=false;
		for (int i=1;i<m;i++) {
			int t=(q[l]+a[i])%a[0];
			if (d[q[l]]+a[i]<d[t]) {
				d[t]=d[q[l]]+a[i];
				if (!vis[t]) {
					vis[t]=true;
					q[r]=t;
					r=(r+1)%A;
				}
			}
		}
		l=(l+1)%A;
	}
	for (scanf("%d",&k);k;k--) {
		scanf("%d",&x);
		if (d[x%a[0]]<=x) puts("TAK");
		else puts("NIE");
	}
	return 0;
}
