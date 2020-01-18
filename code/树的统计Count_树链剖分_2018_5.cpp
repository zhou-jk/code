//BZOJ-1036
#define son_l (k<<1)
#define son_r ((k<<1)+1)
#define mid ((node[k].l+node[k].r)>>1)

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using std::max;
using std::swap;

const int N_NODE=30000,LEN_OP=6,MIN=-30000;
struct Edge
{
	int v,next;
} edge[(N_NODE-1)<<1];
int head[N_NODE],n_edge;
class Tr
{
public:
	Tr()
	{
		n_id=0;
	}
	void hld()
	{
		dfs1(0,0,0); dfs2(0,0);
	}
	inline int get_id(const int k)
	{
		return node[k].id;
	}
	inline int get_top(const int k)
	{
		return node[k].top;
	}
	inline int get_fa(const int k)
	{
		return node[k].fa;
	}
	inline int get_deep(const int k)
	{
		return node[k].deep;
	}
private:
	struct Node
	{
		Node()
		{
			sz=1;
			son=-1;
		}
		int fa,deep,sz,son,top,id;
	} node[N_NODE];
	int n_id;
	void dfs1(const int k,const int _fa,const int _deep)
	{
		node[k].fa=_fa; node[k].deep=_deep;
		for (int i=head[k]; i!=-1; i=edge[i].next)
		{
			int v=edge[i].v;
			if (v!=node[k].fa)
			{
				dfs1(v,k,node[k].deep+1);
				node[k].sz+=node[v].sz;
				if (node[k].son==-1||node[v].sz>node[node[k].son].sz) node[k].son=v;
			}
		}
	}
	void dfs2(const int k,const int _top)
	{
		node[k].top=_top; node[k].id=n_id++;
		if (node[k].son!=-1) dfs2(node[k].son,node[k].top);
		for (int i=head[k]; i!=-1; i=edge[i].next)
		{
			int v=edge[i].v;
			if (v!=node[k].fa&&v!=node[k].son) dfs2(v,v);
		}
	}
} tr;
class Seg_Tr
{
public:
	inline void update(const int tgt,const int num)
	{
		_update(1,tgt,num);
	}
	void build(const int n_node)
	{
		int num;
		_build(1,0,n_node-1);
		for (int i=0; i<n_node; i++)
		{
			scanf("%d",&num);
			update(tr.get_id(i),num);
		}
	}
	inline int query_max(const int l,const int r)
	{
		return _query_max(1,l,r);
	}
	inline int query_sum(const int l,const int r)
	{
		return _query_sum(1,l,r);
	}
private:
	struct Node
	{
		int max,sum,l,r;
	} node[N_NODE<<2];
	inline void push_up(const int k)
	{
		node[k].sum=node[son_l].sum+node[son_r].sum;
		node[k].max=max(node[son_l].max,node[son_r].max);
	}
	void _build(const int k,const int _l,const int _r)
	{
		node[k].l=_l; node[k].r=_r;
		node[k].sum=node[k].max=0;
		if (node[k].l==node[k].r) return;
		_build(son_l,node[k].l,mid); _build(son_r,mid+1,node[k].r);
	}
	void _update(const int k,const int tgt,const int num)
	{
		if (node[k].l==node[k].r)
		{
			node[k].max=node[k].sum=num;
			return;
		}
		if (tgt<=mid) _update(son_l,tgt,num);
		else _update(son_r,tgt,num);
		push_up(k);
	}
	int _query_max(const int k,const int l,const int r)
	{
		if (node[k].l==l&&node[k].r==r) return node[k].max;
		if (r<=mid) return _query_max(son_l,l,r);
		else if (l>mid) return _query_max(son_r,l,r);
		else return max(_query_max(son_l,l,mid),_query_max(son_r,mid+1,r));
	}
	int _query_sum(const int k,const int l,const int r)
	{
		if (node[k].l==l&&node[k].r==r)
		{
			//printf("%d %d %d\n",l,r,node[k].sum);
			return node[k].sum;
		}
		if (r<=mid)
		{
			//printf("%d %d %d\n",l,r,_query_sum(son_l,l,r));
			return _query_sum(son_l,l,r);
		}
		else if (l>mid)
		{
			//printf("%d %d %d\n",l,r,_query_sum(son_r,l,r));
			return _query_sum(son_r,l,r);
		}
		else
		{
			//printf("%d %d %d\n",l,r,_query_sum(son_l,l,mid)+_query_sum(son_r,mid+1,r));
			return _query_sum(son_l,l,mid)+_query_sum(son_r,mid+1,r);
		}
	}
} seg_tr;
char op[LEN_OP+1];

void init()
{
	memset(head,-1,sizeof head);
}

void add_edge(const int u,const int v)
{
	edge[n_edge]=Edge{v,head[u]};
	head[u]=n_edge++;
}

inline int solve_max(int u,int v)
{
	int ret=MIN,top_u=tr.get_top(u),top_v=tr.get_top(v);
	while (top_u!=top_v)
	{
		if (tr.get_deep(top_u)>tr.get_deep(top_v))
		{
			ret=max(ret,seg_tr.query_max(tr.get_id(top_u),tr.get_id(u)));
			u=tr.get_fa(top_u);
		}
		else
		{
			ret=max(ret,seg_tr.query_max(tr.get_id(top_v),tr.get_id(v)));
			v=tr.get_fa(top_v);
		}
		top_u=tr.get_top(u); top_v=tr.get_top(v);
	}
	if (tr.get_deep(u)>tr.get_deep(v)) swap(u,v);
	ret=max(ret,seg_tr.query_max(tr.get_id(u),tr.get_id(v)));
	return ret;
}

inline int solve_sum(int u,int v)
{
	int ret=0,top_u=tr.get_top(u),top_v=tr.get_top(v);
	while (top_u!=top_v)
	{
		//printf("%d %d %d %d\n",top_u,top_v,tr.get_id(top_u),tr.get_id(top_v));
		if (tr.get_deep(top_u)>tr.get_deep(top_v))
		{
			//puts("#1");
			ret+=seg_tr.query_sum(tr.get_id(top_u),tr.get_id(u));
			u=tr.get_fa(top_u);
		}
		else
		{
			//puts("#2");
			ret+=seg_tr.query_sum(tr.get_id(top_v),tr.get_id(v));
			v=tr.get_fa(top_v);
		}
		top_u=tr.get_top(u); top_v=tr.get_top(v);
	}
	if (tr.get_deep(u)>tr.get_deep(v)) swap(u,v);
	ret+=seg_tr.query_sum(tr.get_id(u),tr.get_id(v));
	return ret;
}

int main()
{
	int n_node,n_qu,u,v,x,y;
	init();
	scanf("%d",&n_node);
	for (int i=1; i<n_node; i++)
	{
		scanf("%d%d",&u,&v);
		u--; v--;
		add_edge(u,v); add_edge(v,u);
	}
	tr.hld();
	seg_tr.build(n_node);
	scanf("%d",&n_qu);
	for (int i=0; i<n_qu; i++)
	{
		scanf("%s%d%d",op,&x,&y);
		if (!strcmp(op,"CHANGE")) seg_tr.update(tr.get_id(x-1),y);
		else if (!strcmp(op,"QMAX")) printf("%d\n",solve_max(x-1,y-1));
		else printf("%d\n",solve_sum(x-1,y-1));
	}
	return 0;
}