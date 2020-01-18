#include <cstdio>

struct Node{
	int match,head;
};
struct Edge{
	int v,next;
};
class Graph{
public:
	Graph(int N_node,int N_edge) {
		nod=new Node[N_node]; e=new Edge[N_edge];
	}
	void add_edge(int k) {
		
	}
private:
	int n_edge;
	Node *nod;
	Edge *e;
};

int main() {
	scanf("%d%d",&n,&m);
	Graph g(n,m*2);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);

	}
	return 0;
}