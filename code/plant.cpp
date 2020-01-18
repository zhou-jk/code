#define lc (k<<1)
#define rc ((k<<1)|1)
#define mid ((l[k]+r[k])>>1)

#include <cstdio>
#include <cstring>

const int N=100000,N_=N<<2;
int tr[N_],l[N_],r[N_],lazy[N_];

void push_up(int k) {
	tr[k]=tr[lc]+tr[rc];
}

void push_down(int k) {
	lazy[lc]+=lazy[k]; lazy[rc]+=lazy[k];
	tr[lc]+=lazy[k]; tr[rc]+=lazy[k];
	lazy[k]=0;
}

void build(int k,int _l,int _r) {
	l[k]=_l; r[k]=_r;
	if (_l==_r) return;
	build(lc,_l,mid); build(rc,mid+1,_r);
}

void update(int k,int l_,int r_) {
	if (l_==l[k]&&r_==r[k]) {
		tr[k]++; lazy[k]++;
		return;
	}
	push_down(k);
	if (r_<=mid) update(lc,l_,r_);
	else if (l_>mid) update(rc,l_,r_);
	else update(lc,l_,mid),update(rc,mid+1,r_);
}

int query(int k,int p) {
	int ret;
	if (l[k]==r[k]) {
		ret=tr[k];
		tr[k]=0;
		return ret;
	}
	push_down(k);
	if (p<=mid)  ret=query(lc,p);
	else ret=query(rc,p);
	push_up(k);
	return ret;
}

int main() {
	freopen("plant.in","r",stdin); freopen("plant.out","w",stdout);
	int n,x,y;
	scanf("%d",&n);
	build(1,1,N);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x,&y);
		printf("%d\n",query(1,x)+query(1,y));
		if (x<y-1) update(1,x+1,y-1);
	}
	return 0;
}