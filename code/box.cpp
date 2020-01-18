#define N 100000

#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp1(int a,int b) {
	return a>b;
}

bool cmp2(int a,int b) {
	return a<b; 
}

class Heap{
public:
	Heap(bool (*new_cmp)(int,int)):t(0),cmp(new_cmp) {}
	void add(int u) {
		int k=++t;
		while (k>1&&(*cmp)(u,heap[k>>1])) {
			heap[k]=heap[k>>1];
			k=k>>1;
		}
		heap[k]=u;
	}
	int use() {
		int r=heap[1],k=1,s,u=heap[t--];
		while (k<<1<=t) {
			s=k<<1;
			if (s<t&&(*cmp)(heap[s+1],heap[s])) s++;
			if ((*cmp)(heap[s],u)) {
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
	bool (*cmp)(int,int);
} heap1(cmp2),heap2(cmp1);

void init() {
	freopen("box.in","r",stdin); freopen("box.out","w",stdout);
}

void doit() {
	int n,x,ans;
	for (scanf("%d",&n);n;n--) {
		scanf("%d",&x);
		if (x==-1) {
			ans=heap1.use();
			printf("%d\n",ans);
			heap2.add(ans);
		}
		else {
			heap2.add(x);
			heap1.add(heap2.use());
		}
	}
}

int main() {
	init();
	doit();
	return 0;
}
