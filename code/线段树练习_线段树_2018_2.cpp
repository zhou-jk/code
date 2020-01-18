//PrayerOJ 1640
#define N 100000
#define M (N<<2)
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mid (l[k]+r[k]>>1)

#include <cstdio>

int tr[M],l[M],r[M];

void pushup(int k) {
	tr[k]=tr[lc]+tr[rc];
}

void build(int k,int new_l,int new_r) {
	l[k]=new_l; r[k]=new_r;
	if (l[k]==r[k]) {
		scanf("%d",&tr[k]);
		return;
	}
	build(lc,l[k],mid); build(rc,mid+1,r[k]);
	pushup(k);
}

void update(int k,int p,int v) {
	if (l[k]==r[k]) {
		tr[k]+=v;
		return;
	}
	if (p<=mid) update(lc,p,v);
	else update(rc,p,v);
	pushup(k);
}

int query(int k,int x,int y) {
	if (x==l[k]&&y==r[k]) return tr[k];
	if (y<=mid) return query(lc,x,y);
	if (x>mid) return query(rc,x,y);
	return query(lc,x,mid)+query(rc,mid+1,y);
}

int main() {
	int n,m,a,b,c;
	scanf("%d",&n);
	build(1,1,n);
	for (scanf("%d",&m);m;m--) {
		scanf("%d%d%d",&a,&b,&c);
		if (a==1) update(1,b,c);
		else printf("%d\n",query(1,b,c));
	}
	return 0;
}
