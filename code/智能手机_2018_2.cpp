//VOJ 2018年寒假网赛第五场 B
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=100000;
int a[N+1],h[N+1];
long long ans;

int main() {
	int n,m,k,b;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		h[a[i]]=i;
	}
	for (int i=0;i<m;i++) {
		scanf("%d",&b);
		ans+=(h[b]-1)/k+1;
		if (h[b]>1) {
			int tmp=a[h[b]-1];
			swap(a[h[b]],a[h[b]-1]); swap(h[b],h[tmp]);
		}
	}
	printf("%lld",ans);
	return 0;
}
