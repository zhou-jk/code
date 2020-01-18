//¼ÆËâ¿Í 
#include <cstdio>

int gcd(int a,int b) {
	return !b?a:gcd(b,a%b);
}

int main() {
	int t;
	long long n,m; 
	scanf("%d",&t);
	for (int i=0;i<t;i++) {
		scanf("%lld %lld",&n,&m);
		printf("%lld\n",n*m/gcd(n,m));
	}
	return 0;
}
