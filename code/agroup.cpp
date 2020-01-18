#define N 1000
#define T 499500 //N*(N-1)/2

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge{
	int x,y;
	double l;
} e[T];
int x[N],y[N],fa[N],t;
double ans[N];

bool cmp(Edge &a,Edge &b) {
	return a.l<b.l;
}

int get_fa(int k) {
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

int main() {
	freopen("agroup.in","r",stdin); freopen("agroup.out","w",stdout);
	int n,k,cnt;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		for (int j=0;j<i;j++) {
			long long t1=x[i]-x[j],t2=y[i]-y[j];
			e[t].x=i; e[t].y=j; e[t++].l=sqrt(t1*t1+t2*t2);
		}
	}
	sort(e,e+t,cmp);
	for (int i=0;i<n;i++) fa[i]=i;
	cnt=n-1;
	for (int i=0;i<t&&cnt;i++) {
		int x=get_fa(e[i].x),y=get_fa(e[i].y);
		if (x!=y) {
			fa[x]=y;
			ans[cnt--]=e[i].l;
	    }
	}
	printf("%.2lf",ans[k-1]);
	return 0;
}
