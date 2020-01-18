//¼ÆËâ¿Í
#include <cstdio>

int gcd(int a,int b) {
	return !b?a:gcd(b,a%b);
}

int main() {
	int t,n,a,b;
	for (scanf("%d",&t);t;t--) {
		scanf("%d %d %d",&n,&a,&b);
		if (n/gcd(a,b)%2) printf("huaye\n");
		else printf("suantou\n");
	}
	return 0;
}
