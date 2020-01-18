//¼ÆËâ¿Í
#define N 100

#include <stdio.h>
#include <algorithm>

using std::sort;

struct Edge{
	int a,b,w;
} edge[N*N];
int father[N],n,n_edge,n_edge_need,answer;

void input() {
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			int position=i*n+j;
			edge[position].a=i; edge[position].b=j;
			scanf("%d",&edge[position].w);
		}
}

void init() {
	n_edge=n*n; n_edge_need=n-1;
	for (int i=0;i<n;i++) father[i]=i;
}

bool cmp_edge(Edge a,Edge b) {
	return a.w<b.w;
}

int get_ancestor(int k) {
	return father[k]==k?k:father[k]=get_ancestor(father[k]);
}

bool need(Edge *edge) {
	//printf("%d %d\n",get_ancestor(edge->a),get_ancestor(edge->b));
	return get_ancestor(edge->a)!=get_ancestor(edge->b);
}

void merge(int a,int b) {
	father[get_ancestor(a)]=get_ancestor(b);
}

void use(Edge *edge) {
	answer+=edge->w;
	merge(edge->a,edge->b);
}

void Kruskal() {
	sort(edge,edge+n_edge,cmp_edge);
	for (int i=0;i<n_edge&&n_edge_need;i++)
		if (need(&edge[i])) {
			use(&edge[i]);
			n_edge_need--;
		}
}

void output() {
	printf("%d",answer);
}

int main() {
	input();
	init();
	Kruskal();
	output();
	return 0;
}
