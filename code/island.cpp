#define M 200
#define LEN 62

#include <cstdio>

using namespace std;

int fa[2*M],ans[LEN],t;

int get_fa(int k) {
	if (fa[k]!=k) fa[k]=get_fa(fa[k]);
	return fa[k];
}

void merge(int x,int y) {
	fa[get_fa(x)]=get_fa(y);
}

bool same(int x,int y) {
	return get_fa(x)==get_fa(y);
}

void pow(int *r,int base,int exp) {
	int t=0,j;
	r[0]=1; r[1]=1;
	for (int i=0;i<exp;i++) {
		for (j=1;j<=r[0];j++) {
			r[j]=r[j]*base+t;
			t=r[j]/10;
			r[j]%=10;
		}
		j--;
		while (t) {
			j++;
			r[j]=t%10;
			t/=10;
		}
		r[0]=j;
	}
}

void printf(int *num) {
	for (int i=num[0];i;i--) printf("%d",num[i]);
}

int main() {
	int n,m,a,b,c,d;
	freopen("island.in","r",stdin); freopen("island.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<2*m;i++) fa[i]=i;
	for (int i=0;i<n;i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--; c--;
		merge(a+b*m,c+!d*m); merge(a+!b*m,c+d*m);
	}
	for (int i=0;i<m;i++)
		if (same(i,i+m)) {
			printf("NO ANSWER");
			return 0;
		}
	for (int i=0;i<2*m;i++)
		if (fa[i]==i) t++;
	t>>=1;
	ans[0]=1; ans[1]=1;
	pow(ans,2,t);
	printf(ans);
	return 0;
}
