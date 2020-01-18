#define N 10001

#include <cstdio>
#include <algorithm>

using namespace std;

struct Gas_Station{
	int d,w;
} gs[N];

int n,l,p;
class Heap{
public:
	Heap():t(0){}
	void add(int u) {
		int k=++t;
		while (k>1&&u>heap[k>>1]) {
			heap[k]=heap[k>>1];
			k=k>>1;
		}
		heap[k]=u;
	}
	int use_max() {
		int r=heap[1],k=1,s,u=heap[t--];
		while (k<<1<=t) {
			s=k<<1;
			if (s<t&&heap[s+1]>heap[s]) s++;
			if (heap[s]>u) {
				heap[k]=heap[s];
				k=s;
			}
			else break;
		}
		heap[k]=u;
		return r;
	}
	int get_size() {
		return t;
	}
private:
	int heap[N],t;
} heap;

bool cmp(Gas_Station a,Gas_Station b) {
	return a.d<b.d;
}

void input() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d",&gs[i].d,&gs[i].w);
	scanf("%d %d",&l,&p);
}

void init() {
	freopen("exp.in","r",stdin); freopen("exp.out","w",stdout);
	input();
	for (int i=0;i<n;i++) gs[i].d=l-gs[i].d;
	sort(gs,gs+n,cmp);
	gs[n].d=l;
}

void doit() {
	int i,ans=0;
	for (i=0;i<=n;) {
		while (gs[i].d>p) {
			if (!heap.get_size()) {
		    	printf("-1");
		    	return;
			}
			p+=heap.use_max();
			ans++;
		}
		for (;i<=n&&gs[i].d<=p;i++) heap.add(gs[i].w);
	}
	printf("%d",ans);
}

int main() {
	init();
	doit();
	return 0;
}
