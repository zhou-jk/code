#define N 5000
#define M 10000 //N<<1

#include <cstdio>
#include <algorithm>

using namespace std;

int a[N],b[N],p[N],k[M],fa[M],d[M],t=1;

int find(int u) {
	int l=0,r=t-1;
	while (l<=r) {
		int mid=l+r>>1;
		if (k[mid]>u) r=mid-1;
		else l=mid+1;
	}
	return r;
}

int get_fa(int k) {
	if (fa[k]!=k) {
		int tmp=get_fa(fa[k]);
		d[k]=d[k]+d[fa[k]]&1;
		fa[k]=tmp;
	}
	return fa[k];
}

void merge(int x,int y,int p) {
	d[fa[x]]=d[x]+p&1;
	fa[fa[x]]=y;
}

int main() {
	int l,n,m;
	char w[5];
	freopen("parity.in","r",stdin); freopen("parity.out","w",stdout);
	scanf("%d%d",&l,&n);
	m=n<<1;
	for (int i=0;i<n;i++) {
		scanf("%d%d%s",&a[i],&b[i],w);
		if (w[0]=='o') p[i]=1;
		a[i]--;
		k[i<<1]=a[i]; k[(i<<1)+1]=b[i];
		//printf("%d %d %d\n",i<<1,k[i<<1],a[i]);
	}
	sort(k,k+m);
	for (int i=1;i<m;i++)
		if (k[i]!=k[i-1]) k[t++]=k[i];
	//printf("%d\n",k[0]);
	for (int i=0;i<t;i++) fa[i]=i;
	for (int i=0;i<n;i++) {
		int x=find(a[i]),y=find(b[i]);
		//printf("%d %d %d %d\n",x,k[x],y,k[y]);
		if (get_fa(x)==get_fa(y)) {
			if ((d[x]+d[y]&1)!=p[i]) {
				printf("%d",i);
				return 0;
			}
		}
		else merge(x,y,p[i]);
	}
	printf("%d",n);
	return 0;
}
