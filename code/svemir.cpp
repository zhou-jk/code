#define N 100000
#define M 300000 //N*3 

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int a[N],b[N],c[N],x[M],y[M],l[M],pl[M],pa[N],pb[N],pc[N],fa[N],t;
long long ans;

bool cmp_a(int x,int y) {
	return a[x]<a[y];
}

bool cmp_b(int x,int y) {
	return b[x]<b[y];
}

bool cmp_c(int x,int y) {
	return c[x]<c[y];
}

bool cmp_l(int x,int y) {
	return l[x]<l[y];
}

int get_fa(int k) {
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

int main() {
	int n;
	freopen("svemir.in","r",stdin); freopen("svemir.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		pa[i]=pb[i]=pc[i]=fa[i]=i;
    }
    sort(pa,pa+n,cmp_a);
    int t1=n-1;
    for (int i=0;i<t1;i++) {
    	x[i]=pa[i]; y[i]=pa[i+1]; l[i]=a[pa[i+1]]-a[pa[i]];
	}
	sort(pb,pb+n,cmp_b);
	for (int i=0;i<t1;i++) {
		int k=t1+i;
		x[k]=pb[i]; y[k]=pb[i+1]; l[k]=b[pb[i+1]]-b[pb[i]];
	}
	sort(pc,pc+n,cmp_c);
	int t2=t1<<1;
	for (int i=0;i<t1;i++) {
		int k=t2+i;
		x[k]=pc[i]; y[k]=pc[i+1]; l[k]=c[pc[i+1]]-c[pc[i]];
	}
	t2+=t1;
	for (int i=0;i<t2;i++) pl[i]=i;
	sort(pl,pl+t2,cmp_l);
	for (int i=0;i<n;i++) fa[i]=i;
	for (int i=0;i<t2&&t<t1;i++) {
		int k1=get_fa(x[pl[i]]),k2=get_fa(y[pl[i]]);
		//printf("%d %d %d %d %d\n",pl[i],x[pl[i]],y[pl[i]],k1,k2);
		if (k1!=k2) {
			fa[k1]=k2;
			ans+=l[pl[i]];
			//printf("%d\n",l[pl[i]]);
			t++;
		}
	}
	printf("%lld",ans);
	return 0;
}
