//VOJ POJ 1985
#include <cstdio>
#include <cstring>

struct Edge{
	int v,len,next;
};
class Graph{
public:
	Graph(int n,int m):head(new int[n]),edge(new Edge[m]),tot(0) {
		this->n=n;
		memset(head,-1,n*sizeof *head);
	}
	void add_edge(int u,int v,int len) {
		edge[tot]=Edge{v,len,head[u]};
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
	Tr(int n):Graph(n,(n-1)<<1),d(new int[n]) {
		this->n=n;
	}
	int bfs(int k) {
		int r=1,*q=new int[n];
		q[0]=k;
		memset(d,-1,n*sizeof  *d); d[k]=0;
		for (int l=0;l<r;l++)
			for (int i=head[q[l]];i>=0;i=edge[i].next)
				if (d[edge[i].v]<0) {
					d[edge[i].v]=d[q[l]]+edge[i].len;
					q[r++]=edge[i].v;
				}
		int ret=0;
		for (int i=1;i<n;i++)
			if (d[i]>d[ret]) ret=i;
		return ret;
	}
	int get_diameter() {
		return d[bfs(bfs(0))];
	}
private:
	int n,*d;
};

int main() {
	int n,m,u,v,len;
	char s[2];
	scanf("%d%d",&n,&m);
	Tr tr(n);
	for (int i=0;i<m;i++) {
		scanf("%d%d%d%s",&u,&v,&len,s);
		u--; v--;
		tr.add_edge(u,v,len); tr.add_edge(v,u,len);
	}
	printf("%d",tr.get_diameter());
	return 0;
}