//AC
#define N 50001

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> g[N],cost[N];
int q[N],d[N],m;
bool vis[N];

int main() {
	int n,u,v,len,l,r,t;
	scanf("%d",&n);
    for (int i=1;i<=n;i++) {
			scanf("%d%d%d",&u,&v,&len);
			g[u-1].push_back(v); cost[u-1].push_back(len);
			if (v>m) m=v;
	}
	for (int i=1;i<=m;i++)
		g[i].push_back(i-1),cost[i].push_back(-1);
	for (int i=0;i<m;i++)
		g[i].push_back(i+1),cost[i].push_back(0);
	memset(d,128,sizeof d); d[0]=0;
	l=t=0; r=1;
	vis[0]=true;
	while (vis[t]) {
		vis[t]=false;
		for (int i=0;i<g[t].end()-g[t].begin();i++)
			if (d[t]+cost[t][i]>d[g[t][i]]) {
				d[g[t][i]]=d[t]+cost[t][i];
				if (!vis[g[t][i]]) {
					vis[g[t][i]]=true;
					q[r]=g[t][i];
					r=(r+1)%N;
				}
			}
		l=(l+1)%N;
		t=q[l];
	}
	printf("%d",d[m]);
	return 0;
}
