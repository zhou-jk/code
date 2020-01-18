//VOJ POJ 1275
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int T=24,L=8; //T:轮班时长 L:工作时长
int a[T],f[T],g[T+1][T+1],d[T+1],cnt[T+1];
bool vis[T+1];

queue<int> q;

bool check(int n) {
	for (int i=1;i<=L;i++) g[i+T-L][i]=a[i-1]-n;
	g[0][T]=n;
	memset(d,128,sizeof d); d[0]=0;
	memset(vis,false,sizeof vis);
	memset(cnt,0,sizeof cnt);
	while (!q.empty()) q.pop();
	q.push(0);
	while (!q.empty()) {
		int tmp=q.front();
		//printf("&%d\n",tmp);
		q.pop();
		vis[tmp]=false;
		for (int i=0;i<=T;i++)
			if (d[tmp]+g[tmp][i]>d[i]) {
				d[i]=d[tmp]+g[tmp][i];
				if (!vis[i]) {
					if (++cnt[i]>T) return false;
					vis[i]=true;
					q.push(i);
				}
			}
	}
	//printf("%d\n",d[T]);
	return d[T]==n;
}

int main() {
	int c,n,t,l,r,mid;
	for (scanf("%d",&c);c;c--) {
		memset(g,128,sizeof g);
		memset(f,0,sizeof f);
		for (int i=0;i<T;i++) scanf("%d",&a[i]);
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d",&t);
			f[t]++;
		}
		for (int i=1;i<=T;i++) g[i-1][i]=0,g[i][i-1]=-f[i-1];
		for (int i=L+1;i<=T;i++) g[i-L][i]=a[i-1];
		l=0; r=n;
		while (l<=r) {
			mid=l+r>>1;
			//printf("%d\n",mid);
			check(mid)?r=mid-1:l=mid+1;
		}
		r==n?puts("No Solution"):printf("%d\n",l);
	}
}
