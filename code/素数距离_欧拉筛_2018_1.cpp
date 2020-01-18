//¼ÆËâ¿Í
#include <cstdio>

using namespace std;

bool ip[8000001];
int p[1000000],l,r,t,s,a,b,c,d,min=10000000,max;

int main() {
	scanf("%d %d",&l,&r);
	for (int i=2;i<=r;i++) {
		if (!ip[i]) p[t++]=i;
		for (int j=0;j<t&&i*p[j]<=r;j++) {
			ip[i*p[j]]=true;
			if (!(i%p[j])) break;
		}
	}
	for (int i=1;i<t;i++) 
		if (p[i-1]>=l) {
			s++;
			if (p[i]-p[i-1]<min) {
		 		a=p[i-1]; b=p[i]; min=b-a;
			}
			if (p[i]-p[i-1]>max) {
		 		c=p[i-1]; d=p[i]; max=d-c;
			}
		}
	if (s<2) printf("There are no adjacent primes.");
	else printf("%d,%d are closest, %d,%d are most distant.",a,b,c,d);
	return 0;
}
