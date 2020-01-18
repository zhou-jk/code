//VOJ POJ 1655
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge{
	int v,next;
};
class Graph{
public:
	Graph(int n,int m):head(new int[n]),edge(new Edge[m]),tot(0) {
		this->n=n;
		memset(head,-1,n*sizeof *head);
		//printf("%d\n",sizeof *head);
	}
	~Graph() {
		delete[] head; delete[] edge;
	}
	void add_edge(int u,int v) {
		edge[tot]=Edge{v,head[u]};
		head[u]=tot++;
	}
protected:
	Edge *edge;
	int *head;
private:
	int n,tot;
};
class Tr:public Graph{
public:
	Tr(int n):Graph(n,(n-1)<<1),size_tree(new int[n]) {
		this->n=n;
	}
	~Tr(){
		delete[] size_tree;
	}
	void dfs(int k,int fa) {
		//printf("%d %d\n",k,fa);
		int max_subtree_size=0;
		size_tree[k]=1;
		for (int i=head[k];i>=0;i=edge[i].next)
			if (edge[i].v!=fa) {
				dfs(edge[i].v,k);
				size_tree[k]+=size_tree[edge[i].v];
				max_subtree_size=max(max_subtree_size,size_tree[edge[i].v]);
			}
		max_subtree_size=max(max_subtree_size,n-size_tree[k]);
		if (max_subtree_size<=n>>1&&k<ans_node) ans_node=k,ans_subtree_size=max_subtree_size;
	}
	void solve_smallest_center() {
		ans_node=n;
		dfs(0,0);
	}
	int ans_node,ans_subtree_size;
private:
	int n,*size_tree;
};

int main() {
	int t,n,u,v;
	for (scanf("%d",&t);t;t--) {
		scanf("%d",&n);
		Tr tr(n);
		for (int i=1;i<n;i++) {
			scanf("%d%d",&u,&v);
			u--; v--;
			tr.add_edge(u,v); tr.add_edge(v,u);
		}
		tr.solve_smallest_center();
		printf("%d %d\n",tr.ans_node+1,tr.ans_subtree_size);
	}
	return 0;
}