//CodeForces-55D
#include <cstdio>
#include <cstring>

const int LEN=19,N_LCM=48,LCM=2520;
int s[LEN],hash[LCM+1];
long long f[LEN][N_LCM][LCM],n_lcm;

void init()
{
	memset(f,-1,sizeof f);
	for (int i=1; i<=LCM; ++i)
		if (!(LCM%i)) hash[i]=n_lcm++;
}

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

long long dfs(int k,int num,int lcm,bool flag)
{
	if (k==-1) return !(num%lcm);
	if (!flag&&~f[k][hash[lcm]][num]) return f[k][hash[lcm]][num];
	long long ret=0;
	int b=flag?s[k]:9;
	for (int i=0; i<=b; ++i)
		ret+=dfs(k-1,((num*10)+i)%LCM,i?lcm*i/gcd(lcm,i):lcm,flag&&i==b);
	if (!flag) f[k][hash[lcm]][num]=ret;
	return ret;
}

long long solve(long long num)
{
	int len=0;
	while (num) s[len++]=num%10,num/=10;
	return dfs(len-1,0,1,true);
}

int main()
{
	int t;
	init();
	scanf("%d",&t);
	while (t--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}