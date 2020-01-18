#define N 1000
#define N_Edge 499500 //n*(n-1)/2

#include <cstdio>
#include <cmath> 
#include <algorithm>

using namespace std;

struct Edge{
	int x,y;
	double l;
} e[N_Edge];
int x[N],y[N],fa[N],t;
double ret;

bool cmp(Edge &a,Edge &b) {
	return a.l<b.l;
}

int get_fa(int k) {
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

int main() {
	freopen("acommu.in","r",stdin); freopen("acommu.out","w",stdout);
	int n,m,a,b,cnt;
	scanf("%d%d",&n,&m);
	cnt=n-1-m;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		fa[i]=i;
		for (int j=0;j<i;j++) {
			long long t1=x[i]-x[j],t2=y[i]-y[j];
			e[t].x=i; e[t].y=j; e[t++].l=sqrt(t1*t1+t2*t2);
		}
	}
	sort(e,e+t,cmp);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&a,&b);
		fa[get_fa(a-1)]=get_fa(b-1);
	}
	for (int i=0;i<t&&cnt;i++) {
		int x=get_fa(e[i].x),y=get_fa(e[i].y);
		if (x!=y) {
			fa[x]=y;
			ret+=e[i].l;
			cnt--;
		}
	}
	printf("%.2lf",ret);
	return 0;
}
