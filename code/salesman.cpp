#define N 100000
#define FILE salesman
#include <cstdio>
#include <algorithm>

using namespace std;

int n,s[N],a[N];
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
	int get_max() {
		return heap[1];
	}
	int get_size() {
		return t;
	}
private:
	int heap[N],t;
};

void init() {
	freopen("salesman.in","r",stdin); freopen("salesman.out","w",stdout);
}

void input() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&s[i]);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
}

void doit() {
	Heap heap;
	int k,ans=0,w[N];
	struct {
		int w,k;
	} f[N+1];
	for (int i=0;i<n;i++) {
		w[i]=(s[i]<<1)+a[i];
		if (w[i]>ans) {
			ans=w[i]; k=i;
		}
	}
	printf("%d\n",ans);
	for (int i=n-1;i>=k;i--)
		if (w[i]>f[i+1].w) {
			f[i].w=w[i]; f[i].k=i;
		}
		else f[i]=f[i+1];
	for (int i=0;i<k;i++) heap.add(a[i]);
	for (int i=1;i<n;i++) {
		int t=f[k+1].w-(s[k]<<1);
		if (!heap.get_size()||t>heap.get_max()) {
			ans+=t;
			for (int j=k+1;j<f[k+1].k;j++) heap.add(a[j]);
			k=f[k+1].k;
		}
		else ans+=heap.use_max();
		printf("%d\n",ans);
	}
}

int main() {
	init();
	input();
    doit();
	return 0;
}
