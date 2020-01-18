//PrayerOJ 1708
#define N 10000
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mid (l+r>>1)
#define oo 1E9

#include <cstdio>
#include <algorithm>

using namespace std;

int tr[N<<2],ans,s[N];

void pushup(int k) {
	tr[k]=min(tr[lc],tr[rc]);
}

void build(int k,int l,int r) {
	if (l==r) {
		tr[k]=s[l];
		return;
	}
	build(lc,l,mid); build(rc,mid+1,r);
	pushup(k);
}

void update(int k,int l,int r,int v,int p) {
	if (l==r) {
		tr[k]=p;
		return;
	}
	if (tr[lc]==v) update(lc,l,mid,v,p);
	else update(rc,mid+1,r,v,p);
	pushup(k);
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&s[i]);
	build(1,0,n-1);
	for (int i=1;i<n;i++) {
		int t1=tr[1];
		update(1,0,n-1,t1,oo);
		int t2=tr[1];
		update(1,0,n-1,t2,t1+t2);
		ans+=t1+t2;
	}
	printf("%d",ans);
	return 0; 
}
