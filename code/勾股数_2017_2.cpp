//PrayerOJ 1721
#include <stdio.h>
#include <math.h>

int main() {
	long long r,t,a,i;
	scanf("%lld",&r);
	t=sqrt(r/2);
	//printf("%d %d %d %f\n",r,t,r/2,sqrt(double(r/2)));
	a=0;
	for (i=1;i<=t;i++) a+=(long long)sqrt(r-i*i)-i; //?
	printf("%lld",a);
	return 0;
}
