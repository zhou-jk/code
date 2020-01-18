//PrayerOJ 1463
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N=100000,M=100000;
class DSU{
public:
	DSU() {
		for (int i=0;i<N;i++) fa[i]=i;
	}
	int get_root(int k) {
		return k==fa[k]?k:get_root(fa[k]);
	}
	void set_fa(int son,int _fa) {
		fa[son]=_fa;
	}
private:
	int fa[N];
};
class LCA{
public:
	LCA() {
		memset(vis,false,sizeof vis);
	}
	void solve(int k) {
		vis[k]=true;
		for (int i=0;i<g[k].size();i++)
			if (!vis[g[k][i]]) {
				solve(g[k][i]);
				dsu.set_fa(g[k][i],k);
			}
		for (int i=0;i<q[k].size();i++)
			if (vis[q[k][i]]) ans[id[k][i]]=dsu.get_root(q[k][i]);
	}
	void add_edge(int u,int v) {
		g[u].push_back(v); g[v].push_back(u);
	}
	void add_query(int _id,int u,int v) {
		q[u].push_back(v); q[v].push_back(u);
		id[u].push_back(_id); id[v].push_back(_id);
	}
	int get_ans(int k) {
		return ans[k];
	}
private:
	DSU dsu;
	bool vis[N];
	vector<int> g[N],q[N],id[N];
	int ans[M];
} lca; //不能定义在main()函数内

int main() {
	int n,m,u,v;
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		lca.add_edge(u-1,v-1);
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		lca.add_query(i,u-1,v-1);
	}
	lca.solve(0);
	for (int i=0;i<m;i++) printf("%d\n",lca.get_ans(i)+1);
	return 0;
}
