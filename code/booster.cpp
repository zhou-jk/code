#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

const int N=1000000;
vector<int> g[N],len[N];
int s,ans;

int dfs(int k,int lent) {
	int tmp=0;
	for (int i=0;i<g[k].end()-g[k].begin();i++) tmp=max(tmp,dfs(g[k][i],len[k][i]));
	if (tmp>s) {
		puts("No solution");
		exit(0);
	}
	if (tmp+)
}

int main() {
	int n,k,v,lent;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (scanf("%d",&k);k;k--) {
			scanf("%d%d",&v,&lent);
			g[i].push_back(v-1); len[i].push_back(lent);
		}
	scanf("%d",&s);
	return 0;
}
