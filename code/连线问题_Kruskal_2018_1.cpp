//¼ÆËâ¿Í
#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge{
	int x,y,z;
} edge[50000];
int father[30001],n,m,n_edge_need,answer;

void input() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
}

void init() {
	n_edge_need=n-1;
	for (int i=1;i<=n;i++) father[i]=i;
}

bool cmp_edge(Edge a,Edge b) {
	return a.z<b.z;
}

int get_ancestor(int k) {
	return father[k]==k?k:father[k]=get_ancestor(father[k]);
}

bool need(Edge *edge) {
	return get_ancestor(edge->x)!=get_ancestor(edge->y);
}

void merge(int a,int b) {
	father[get_ancestor(a)]=get_ancestor(b);
}

void use(Edge *edge) {
	answer+=edge->z;
	merge(edge->x,edge->y);
}

void Kruskal() {
	sort(edge,edge+m,cmp_edge);
	for (int i=0;i<m&&n_edge_need;i++)
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
