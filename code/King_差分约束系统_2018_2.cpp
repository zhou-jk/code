//VOJ POJ 1364 
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N=101;
int n,g[N][N],d[N],cnt[N];
queue<int> q;
bool vis[N];

bool spfa() {
	memset(d,0,sizeof d);
	memset(cnt,0,sizeof cnt);
	while (!q.empty()) q.pop();
	for (int i=0;i<=n;i++) {
		q.push(i);
		vis[i]=true;
	}
	while (!q.empty()) {
		int tmp=q.front();
		q.pop();
		vis[tmp]=false;
		for (int i=0;i<=n;i++)
			if (d[tmp]+g[tmp][i]<d[i]) {
				d[i]=d[tmp]+g[tmp][i];
				if (!vis[i]) {
					if (++cnt[i]>n) return false; 
					vis[i]=true;
					q.push(i);
				}
			}
		}
	return true; 
}

int main() {
	int m,u,v,len;
	char o[3];
	while (~scanf("%d",&n)&&n) {
		memset(g,63,sizeof g);
		for (scanf("%d",&m);m;m--) {
			scanf("%d%d%s%d",&u,&v,o,&len);
			v+=u; u--;
			o[0]=='g'?g[u][v]=-1-len:g[v][u]=len-1;
		}
		spfa()?puts("lamentable kingdom"):puts("successful conspiracy");
	}
	return 0;
}
