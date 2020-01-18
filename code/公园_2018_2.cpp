//Virtual Judge 2018年寒假网赛第一场 E
#define M 2048 //2^(N+1)
#define lc (k<<1)
#define rc ((k<<1)|1)

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int f[M],a[M],m,ans;

void dfs(int k) {
	if (lc<m) {
		dfs(lc);
		f[k]=f[lc];
	}
	if (rc<m) {
		dfs(rc);
		f[k]=max(f[rc],f[k]);
	}
	f[k]+=a[k];
	if (lc<m&&rc<m) ans+=abs(f[lc]-f[rc]);
}

int main() {
	int n;
	scanf("%d",&n);
	m=1<<n+1;
	for (int i=2;i<m;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
