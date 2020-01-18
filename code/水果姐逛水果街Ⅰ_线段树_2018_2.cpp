//PrayerOJ 1649
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mid (l[k]+r[k]>>1) 

#include <cstdio>
#include <algorithm>

using namespace std;

const int N=200000<<2;
struct Node{
	int max,min,ans1,ans2;
} tr[N];
int l[N],r[N];

void pushup(int k) {
	tr[k].min=min(tr[lc].min,tr[rc].min); tr[k].max=max(tr[lc].max,tr[rc].max);
	tr[k].max=max(tr[lc].max,tr[rc].max); tr[k].min=min(tr[lc].min,tr[rc].min);
	tr[k].ans1=max(tr[rc].max-tr[lc].min,max(tr[lc].ans1,tr[rc].ans1));
	tr[k].ans2=max(tr[lc].max-tr[rc].min,max(tr[lc].ans2,tr[rc].ans2));
}

void build(int k,int new_l,int new_r) {
	l[k]=new_l; r[k]=new_r;
	if (l[k]==r[k]) {
		scanf("%d",&tr[k].max);
		tr[k].min=tr[k].max;
		tr[k].ans1=tr[k].ans2=0;
		return;
	}
	build(lc,l[k],mid); build(rc,mid+1,r[k]);
	pushup(k);
}

Node query(int k,int x,int y) {
	if (l[k]==x&&r[k]==y) return tr[k];
	if (y<=mid) return query(lc,x,y);
	else if (x>mid) return query(rc,x,y);
	else {
		Node re,t1=query(lc,x,mid),t2=query(rc,mid+1,y);
		re.max=max(t1.max,t2.max); re.min=min(t1.min,t2.min);
		re.ans1=max(t2.max-t1.min,max(t1.ans1,t2.ans1)); re.ans2=max(t1.max-t2.min,max(t1.ans2,t2.ans2));
		return re;
	}
}

int main() {
	int n,m,x,y;
	scanf("%d",&n);
	build(1,1,n);
	for (scanf("%d",&m);m;m--) {
		scanf("%d%d",&x,&y);
		if (x<y) printf("%d\n",query(1,x,y).ans1);
		else printf("%d\n",query(1,y,x).ans2);
	}
	return 0; 
}
