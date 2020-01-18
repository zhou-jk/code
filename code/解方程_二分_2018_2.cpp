//VOJ 2018年寒假网赛第四场 E
#include <cstdio>

int main() {
	int t,y;
	double l,r,mid;
	for (scanf("%d",&t);t;t--) {
		scanf("%d",&y);
		y-=6;
		if (y>8*100*100*100*100+7*100*100*100+2*100*100+3*100||y<0) {
			puts("No solution!");
			continue;
		}
		l=0; r=100;
		while (r-l>1E-8) {
			mid=(l+r)/2;
			if (8*mid*mid*mid*mid+7*mid*mid*mid+2*mid*mid+3*mid>y) r=mid;
			else l=mid;
		}
		printf("%.4lf\n",l);
	}
	return 0;
}
