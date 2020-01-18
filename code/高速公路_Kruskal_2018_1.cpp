//¼ÆËâ¿Í
#define oo 1000000000

#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge{
	int a,b,c;
} edge[50000];
int father[30001],n,m,n_need_edge,ans=oo;

void input() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
}

bool cmp_edge(Edge a,Edge b) {
	return a.c<b.c;
}

void init() {
	sort(edge,edge+m,cmp_edge);
} 

int get_ancestor(int k) {
	return father[k]==k?k:father[k]=get_ancestor(father[k]);
}

bool need(Edge *edge) {
	return get_ancestor(edge->a)!=get_ancestor(edge->b);
}

void use(Edge *edge) {
	father[get_ancestor(edge->a)]=get_ancestor(edge->b);
}

void init_Kruskal() {
	n_need_edge=n-1;
	for (int i=1;i<=n;i++) father[i]=i;
}

int min_len_longest_edge(int left_edge) {
	int i;
	init_Kruskal();
	for (i=left_edge;i<m&&n_need_edge;i++)
		if (need(&edge[i])) {
			use(&edge[i]);
			n_need_edge--;
		}
	if (n_need_edge) return -1;
	return edge[i-1].c;
}

void solve() {
	int len_longest_edge;
	for (int i=0;(len_longest_edge=min_len_longest_edge(i))>-1;i++) 
		if (len_longest_edge-edge[i].c<ans) ans=len_longest_edge-edge[i].c;
	if (ans==oo) ans=-1;
}

void output() {
	printf("%d",ans);
}

int main() {
	input();
	init();
	solve();
	output();
	return 0;
}
