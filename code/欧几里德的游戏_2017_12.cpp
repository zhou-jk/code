//PrayerOJ 1720
#include <stdio.h>

int main() {
    int c,m,n,t,f;
	scanf("%d",&c);
	for (int i=1;i<=c;i++) {
		scanf("%d %d",&m,&n);
		if (m<n) {
			t=m; m=n; n=t;
		}
		f=1; 
		while (m/n==1&&m%n>0) {
			t=m%n; m=n; n=t; f=++f%2; 
		}
		if (f) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}
