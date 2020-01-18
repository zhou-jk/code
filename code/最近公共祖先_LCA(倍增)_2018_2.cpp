//PrayerOJ 1463
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

class LCA{
public:
	static const int N=100000,LOG2_N=ceil(log(N)/log(2));
	void init(int _n) {
		log2_n=ceil(log(n=_n)/log(2));
		cnt=0;
	}
	inline void dfs(int k,int fa) {
		t_in[k]=cnt++;
		f[k][0]=fa;
		for (int i=0;i<g[k].size();i++)
			if (fa!=g[k][i]) dfs(g[k][i],k);
		t_out[k]=cnt++;
	}
	void pre() {
		dfs(0,0);
		for (int j=1;j<log2_n;j++)
			for (int i=0;i<n;i++) f[i][j]=f[f[i][j-1]][j-1];
	}
	inline void add_edge(int u,int v) {
		g[u].push_back(v);
	}
	inline bool is_ancestor(int x,int y) {
		return t_in[x]<=t_in[y]&&t_out[x]>=t_out[y];
	}
	inline int query(int u,int v) {
		if (is_ancestor(u,v)) return u;
		if (is_ancestor(v,u)) return v;
		for (int i=log2_n-1;i>=0;i--)
			if (!is_ancestor(f[u][i],v)) u=f[u][i];
		return f[u][0];
	}
private:
	int n,log2_n;
	int t_in[N],t_out[N],f[N][LOG2_N],cnt;
	vector<int> g[N],q[N];
} lca; //不能定义在main()函数内

int main() {
	int n,m,u,v;
	scanf("%d",&n);
	lca.init(n);
	for (int i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		lca.add_edge(u-1,v-1); lca.add_edge(v-1,u-1);
	}
	lca.pre();
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		printf("%d\n",lca.query(u-1,v-1)+1);
	}
	return 0;
}