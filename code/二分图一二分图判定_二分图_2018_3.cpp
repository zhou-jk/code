//Vjudge Hihocoder 1121
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool chk;
int *vis;
vector<int> *g;

void dfs(int k,int c) {
	vis[k]=c;
	for (int i=0;i<g[k].size();i++) {
		if (vis[g[k][i]]==c) chk=true;
		if (chk) return;
		if (vis[g[k][i]]==-1) dfs(g[k][i],!c);
	}
}

int main() {
	int t,m,n,u,v;
	scanf("%d",&t);
	for (int i=0;i<t;i++) {
		scanf("%d%d",&n,&m);
		vis=new int[n]; g=new vector<int>[n];
		for (int i=0;i<m;i++) {
			scanf("%d%d",&u,&v);
			u--; v--;
			g[u].push_back(v); g[v].push_back(u);
		}
		chk=false;
		memset(vis,-1,n*sizeof *vis);
		for (int i=0;i<n;i++)
			if (vis[i]==-1) {
				dfs(i,0);
		        if (chk) {
					puts("Wrong");
					break;
				}
			}
		if (!chk) puts("Correct");
		delete[] vis; delete[] g;
	}
	return 0;
}