#define N 100000
#define M (N<<2)
#define LEN 11

#include <cstdio>
#include <cstring>

int a[N],b[N],x[N],tr[LEN][M],l[LEN][M],r[LEN][M];

void update(int len,int k,int new_l,int new_r,int p,int v) {
	l[len][k]=new_l; r[len][k]=new_r;
	if (l[len][k]==r[len][k]) {
		tr[len][k]=v;
		return;
	}
}

void query()

int main() {
	scanf("%d %d",&n,&k);
	int t=n-1;
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	memcpy(b,a,sizeof a);
	sort(b,b+n);
	for (int i=0;i<n;i++) x[i]=lower_bound(b,b+n,a[i])-b;
	for (int i=1;i<=k;i++)
		for(int j=1;j<n;j++) {
			f[j][i]=query(i-1,0,0,t,)
		}
	return 0;
}
