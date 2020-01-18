#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class DSU
{
  public:
	DSU() {}
	DSU(int _n)
	{
		n = _n;
		fa = new int[n];
		for (int i = 0; i < n; i++)
			fa[i] = i;
	}
	DSU(DSU &b)
	{
		fa = new int[b.n];
		for (int i = 0; i < n; i++)
			fa[i] = b.fa[i];
	}
	~DSU()
	{
		delete[] fa;
	}
	int get_root(int k)
	{
		//printf("%d\n",k);
		return fa[k] == k ? k : fa[k] = get_root(fa[k]);
	}
	void set_fa(int son, int fa)
	{
		this->fa[son] = fa;
	}

  private:
	int *fa, n;
};
class LCA
{
  public:
	int *ans, *vis;
	LCA(int n, int m) : dsu(n)
	{
		vis = new int[n];
		g = new vector<int>[n];
		q = new vector<int>[n];
		id = new vector<int>[n];
		ans = new int[m];
		memset(vis, 0, n * sizeof *vis);
	}
	void solve(int k, int f)
	{
		//printf("%d %d\n",k,f);
		vis[k] = f;
		for (int i = 0; i < g[k].size(); i++) //{
			//printf("%%%d %d\n",k,g[k][i]);
			if (!vis[g[k][i]])
			{
				//printf("#%d %d\n",k,g[k][i]);
				solve(g[k][i], f + 1);
				//printf("@%d %d\n",k,g[k][i]);
				dsu.set_fa(g[k][i], k);
				//printf("*%d %d %d\n",k,g[k][i],dsu.get_root(g[k][i]));
			}
		//}
		//printf("%d %d\n",k,f);
		//printf("!%d\n",g[0][0]);
		for (int i = 0; i < q[k].size(); i++)
			if (vis[q[k][i]])
				ans[id[k][i]] = dsu.get_root(q[k][i]); //printf("&%d %d %d %d %d\n",k,q[k][i],id[k][i],ans[id[k][i]],g[0][0]);
													   //printf("%d\n",g[0][0]);
	}
	void add_edge(int u, int v)
	{
		g[u].push_back(v);
	}
	void add_query(int _id, int u, int v)
	{
		q[u].push_back(v);
		q[v].push_back(u);
		id[u].push_back(_id);
		id[v].push_back(_id);
	}

  private:
	DSU dsu;
	vector<int> *g, *q, *id;
};

int main()
{
	int n, q, num, u, v, a, *b, c;
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	scanf("%d%d%d", &n, &q, &num);
	LCA lca(n, q * 3);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		u--;
		v--;
		//printf("%d %d\n",u,v);
		lca.add_edge(u, v);
		lca.add_edge(v, u);
	}
	b = new int[q];
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d", &a, &b[i], &c);
		a--;
		b[i]--;
		c--;
		//printf("^%d %d %d\n",a,b[i],c);
		lca.add_query(i * 3, a, b[i]);
		lca.add_query(i * 3 + 1, b[i], c);
		lca.add_query(i * 3 + 2, a, c);
	}
	//puts("**");
	lca.solve(0, 1);
	//puts("&&");
	for (int i = 0; i < q; i++)
	{
		int tmp = lca.ans[i * 3];
		//printf("%d\n",tmp);
		if (lca.vis[lca.ans[i * 3 + 1]] > lca.vis[tmp])
			tmp = lca.ans[i * 3 + 1];
		//printf("%d\n",tmp);
		if (lca.vis[lca.ans[i * 3 + 2]] > lca.vis[tmp])
		{
			printf("%d\n", abs(lca.vis[tmp] - lca.vis[lca.ans[i * 3 + 2]]) + abs(lca.vis[tmp] - lca.vis[b[i]]) + 1);
		}
		//printf("%d %d %d %d\n",tmp,b[i],lca.vis[tmp],lca.vis[b[i]]);
		else
			printf("%d\n", abs(lca.vis[tmp] - lca.vis[b[i]]) + 1);
	}
	return 0;
}