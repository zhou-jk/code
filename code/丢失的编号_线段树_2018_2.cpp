//Virtual Judge 2018年寒假网赛第一场 F
#define N 80000
#define M (N<<2)
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mid (l[k]+r[k]>>1) 

#include <cstdio> 

int tr[M],l[M],r[M],num[M],s[N],ans[N],t;

void pushup(int k) {
	tr[k]=tr[lc]+tr[rc];
}

void build(int k,int new_l,int new_r) {
	l[k]=new_l; r[k]=new_r;
	if (l[k]==r[k]) {
		tr[k]=1; num[k]=++t;
		return;
	}
	build(lc,l[k],mid); build(rc,mid+1,r[k]);
	pushup(k);
}

int query(int k,int p) {
	tr[k]--;
	if (l[k]==r[k]) return num[k];
	if (tr[lc]>=p) return query(lc,p);
	return query(rc,p-tr[lc]);
}

int main() {
	int n;
	scanf("%d",&n);
	build(1,0,n-1);
	for (int i=1;i<n;i++) scanf("%d",&s[i]);
	for (int i=n-1;i>=0;i--) ans[i]=query(1,s[i]+1);
	for (int i=0;i<n;i++) printf("%d\n",ans[i]);
	return 0;
}
