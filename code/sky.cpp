#define N 1000
#define M 10000

#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge{
	int x,y,l;
} e[M];
int fa[N],ans,t;

bool cmp(Edge &a,Edge &b) {
		return a.l<b.l;
}

int get_fa(int k) {
	//printf("^^%d\n",k);
	//if (k>999) printf("$%d ",k);
	//if (fa[k]>999) printf("%d\n",k);
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

int main() {
	int m,n,k,need;
	freopen("sky.in","r",stdin); freopen("sky.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	need=n-k;
	for (int i=0;i<m;i++) {
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].l);
		e[i].x--; e[i].y--;
    }
	sort(e,e+m,cmp);
	for (int i=0;i<n;i++) {
		//if (i>999) printf("%d\n",i);
		fa[i]=i;
    }
	for (int i=0;i<m;i++) {
		//printf("%d\n",i);
		int x=get_fa(e[i].x),y=get_fa(e[i].y);
		if (x!=y) {
			//if (x>999) printf("%d\n",x);
			fa[x]=y;
			ans+=e[i].l; t++;
		}
		if (t==need) {
			printf("%d",ans);
			return 0;
		}
	}
	printf("No Answer");
	return 0;
}
