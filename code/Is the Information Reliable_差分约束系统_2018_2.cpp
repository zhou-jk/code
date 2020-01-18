//VOJ POJ 2983
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N=1000;
vector<int> g[N],len[N];
int q[N],d[N],cnt[N];
bool vis[N];

int main() {
	int n,m,u,v,lent,l,r;
	char s[3],c;
	bool b;
	while (~scanf("%d%d",&n,&m)) {
		for (int i=0;i<n;i++) g[i].clear(),len[i].clear();
		while (m--) {
			gets(s);
			if (getchar()=='P') {
				scanf("%d%d%d",&u,&v,&lent);
				u--; v--;
				g[u].push_back(v); len[u].push_back(lent);
				g[v].push_back(u); len[v].push_back(-lent);
			}
			else {
				scanf("%d%d",&u,&v);
				u--;
				g[u].push_back(v-1); len[u].push_back(1);
			}
		}
		memset(d,0,sizeof d);
		memset(vis,false,sizeof vis);
		memset(cnt,0,sizeof cnt);
		for (int i=0;i<n;i++) {
			q[i]=i;
			vis[i]=true;
		}
		l=0; r=n%N;
		b=false;
		while (vis[q[l]]) {
			vis[q[l]]=false;
			for (int i=0;i<g[q[l]].end()-g[q[l]].begin();i++)
				if (d[q[l]]+len[q[l]][i]>d[g[q[l]][i]]) {
					d[g[q[l]][i]]=d[q[l]]+len[q[l]][i];
					if (!vis[g[q[l]][i]]) {
						if (++cnt[g[q[l]][i]]>=n) {
							puts("Unreliable");
							b=true;
							break;
						}
						vis[g[q[l]][i]]=true;
						q[r]=g[q[l]][i];
						r=(r+1)%N;
					}
				}
			if (b) break;
			l=(l+1)%N;
		}
		if (!b) puts("Reliable");
	}
	return 0; 
}
