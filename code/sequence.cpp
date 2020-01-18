#define N 100000
#include <cstdio>
using namespace std;

struct node{
	int a,b,c;
} q[N+2],tmp;

int a[N],b[N],t;

void add(node u) {
	if (t==N+1) t--;
	int k=++t;
	while (k>1&&u.c<q[k>>1].c) {
		q[k]=q[k>>1];
		k>>=1;
	}
	q[k]=u;
}

int down(int k) {
	int s;
	node u=q[k];
	while (k<<1<=t) {
		s=k<<1;
		if (s<t&&q[s+1].c<q[s].c) s++;
		if (q[s].c<u.c) {
			q[k]=q[s];
			k=s;
		}
		else break;
	}
	q[k]=u;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	for (int i=0;i<n;i++) {
		tmp.a=i; tmp.b=0; tmp.c=a[i]+b[0];
		add(tmp);
	}
	for (int i=0;i<n-1;i++) {
		printf("%d ",q[1].c);
		q[1].b++; q[1].c=a[q[1].a]+b[q[1].b];
		down(1);
	}
	printf("%d",q[1].c);
	return 0;
}
