#define N 10000
#define M 10000

#include <cstdio>
#include <algorithm>

using namespace std;

int a[M],b[M],fa[N];

int get_fa(int k) {
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

int main() {
	freopen("sub.in","r",stdin); freopen("sub.out","w",stdout);
	int n,m1,m2,k,cnt;
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i=0;i<m1;i++) {
		scanf("%d%d",&a[i],&b[i]);
		a[i]--; b[i]--;
	}
	for (int i=0;i<n;i++) fa[i]=i;
	cnt=n-1;
	for (int i=0;i<m1&&cnt;i++) {
		int x=get_fa(a[i]),y=get_fa(b[i]);
		if (x!=y) {
			fa[x]=y;
			cnt--;
	    }
	}
	printf("%d",cnt);
	return 0;
}
