#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=505,M=10005;
int n;
int r[N],c[N];
long long a[N][N];
bool isprime[M];
int prime[M],tot;
void init(int n=10000)
{
	fill(isprime+1,isprime+n+1,true);
	isprime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
	return;
}
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	init();
	scanf("%d",&n);
	if(n==2)
	{
		printf("4 7\n");
		printf("23 10\n");
		return 0;
	}
	int now=0;
	for(int i=1;i<=n;i+=2)
		r[i]=prime[++now];
	for(int i=n-(n%2==1);i>=1;i-=2)
		r[i]=prime[++now];
	for(int i=1;i<=n;i+=2)
		c[i]=prime[++now];
	for(int i=n-(n%2==1);i>=1;i-=2)
		c[i]=prime[++now];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2==0) a[i][j]=1LL*r[(i-j)/2+(n+1)/2]*c[(i+j)/2];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2==1)
			{
				a[i][j]=1;
				if(i-1>=1) a[i][j]=lcm(a[i][j],a[i-1][j]);
				if(i+1<=n) a[i][j]=lcm(a[i][j],a[i+1][j]);
				if(j-1>=1) a[i][j]=lcm(a[i][j],a[i][j-1]);
				if(j+1<=n) a[i][j]=lcm(a[i][j],a[i][j+1]);
				a[i][j]++;
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",a[i][j]);
		printf("\n");
	}
	return 0;
}