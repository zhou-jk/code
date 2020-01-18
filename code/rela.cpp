#define N 20000

#include <cstdio>

using namespace std;

int fa[N],n;

int get_fa(int k) {
	if (fa[k]!=k) fa[k]=get_fa(fa[k]);
	return fa[k];
}

void init() {
	freopen("rela.in","r",stdin); freopen("rela.out","w",stdout);
}

void doit() {
	int n,m,q,a,b;
	scanf("%d %d %d",&n,&m,&q);
	for (int i=0;i<n;i++) fa[i]=i;
	for (int i=0;i<m;i++) {
		scanf("%d %d",&a,&b);
		fa[get_fa(a)]=get_fa(b);
	}
	for (int i=0;i<q;i++) {
		scanf("%d %d",&a,&b);
		if (get_fa(a)==get_fa(b)) printf("Yes\n");
		else printf("No\n");
	}
}

int main() {
	init();
	doit();
	return 0;
}
