#include <cstdio>
#include <cstring>

const int MAX=10000000,N=3000000; //MAX:询问上限 N:质数个数
bool is_prime[MAX+1],is_ans[MAX+1];
int prime[N],sum[MAX+1],tot;

int main() {
	freopen("prime.in","r",stdin); freopen("prime.out","w",stdout);
	int tmp,q,l,r;
	memset(is_prime,true,sizeof is_prime); memset(is_ans,true,sizeof is_ans);
	for (int i=2;i<=MAX;i++) {
		if (is_prime[i]) prime[tot++]=i;
		sum[i]=sum[i-1]+is_ans[i];
		for (int j=0;j<tot&&(tmp=i*prime[j])<=MAX;j++) {
			is_prime[tmp]=false; is_ans[tmp]=is_prime[i];
			if (!(i%prime[j])) break;
		}
	}
	for (scanf("%d",&q);q;q--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}