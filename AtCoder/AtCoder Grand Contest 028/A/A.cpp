#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
char s[N],t[N];
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
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	long long L=lcm(n,m);
	long long la=L/n,lb=L/m;
	long long d=lcm(la,lb);
	for(long long i=1;i<=L;i+=d)
		if(s[(i-1)/la+1]!=t[(i-1)/lb+1])
		{
			printf("-1");
			return 0;
		}
	printf("%lld",L);
	return 0;
}