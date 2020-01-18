#include <cstdio>
#include <cmath>

const int N=100000,N_PRIME=9592,N_LUCKYNUM=(1<<11)-2;
int prime[N_PRIME],l,r,n_luckynum;
bool is_prime[N];
long long a,b,luckynum[N_LUCKYNUM],q[N_LUCKYNUM+1];

inline void push(long long num)
{
	q[r++]=num;
	for (int i=0; i<n_luckynum; ++i)
		if (!(num%luckynum[i])) return;
	luckynum[n_luckynum++]=num;
}

long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n,n_prime=0,tmp;
	long long ans=0;
	scanf("%lld%lld",&a,&b);
	--a;
	n=sqrt(b);
	for (int i=2; i<=n; ++i)
	{
		if (!is_prime[i]) prime[n_prime++]=i;
		for (int j=0; j<n_prime&&i*prime[j]<=n; ++j)
		{
			is_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	q[r++]=0;
	while (l<r)
	{
		printf("%lld %lld\n",q[l]*10+6,q[l]*10+8);
		if (q[l]*10+6<=b) push(q[l]*10+6);
		if (q[l]*10+8>b) break;
		push(q[l]*10+8);
		l++;
	}
	for (int i=0; i<n_luckynum; ++i)
	{
		(ans+=b/luckynum[i])-=a/luckynum[i];
		for (int j=i+1; j<n_luckynum; ++j)
		{
			tmp=luckynum[i]/gcd(luckynum[i],luckynum[j])*luckynum[j];
			(ans-=b/tmp)+=a/tmp;
		}
	}
	printf("%lld",ans);
	return 0;
}