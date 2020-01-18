#define N 20000

#include <cstdio>

using namespace std;

class Heap{
public:
	Heap():t(0){}
	void add(int u) {
		int k=++t;
		while (k>1&&u<heap[k>>1]) {
			heap[k]=heap[k>>1];
			k=k>>1;
		}
		heap[k]=u;
	}
	int use_min() {
		int r=heap[1],k=1,s,u=heap[t--];
		while (k<<1<=t) {
			s=k<<1;
			if (s<t&&heap[s+1]<heap[s]) s++;
			if (heap[s]<u) {
				heap[k]=heap[s];
				k=s;
			}
			else break;
		}
		heap[k]=u;
		return r;
	}
private:
	int heap[N],t;
} heap;
int n,tmp;
long long ans;

void init() {
	freopen("plank.in","r",stdin); freopen("plank.out","w",stdout);
}

void doit() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&tmp);
		heap.add(tmp);
	}
	for (int i=1;i<n;i++) {
		tmp=heap.use_min()+heap.use_min();
		ans+=tmp;
		heap.add(tmp);
	}
}

void output() {
	printf("%lld",ans);
}

int main() {
	init();
	doit();
	output();
	return 0;
}
