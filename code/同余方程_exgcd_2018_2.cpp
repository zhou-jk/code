//¼ÆËâ¿Í
#include <cstdio>

int exgcd(int a,int b,int &x,int &y) {
	if (!b) {
		x=1; y=0;
		return a;
	}
	int r=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return r;
}

int main() {
	int a,b,x,y,g,t1,t2;
	scanf("%d %d",&a,&b);
	g=exgcd(a,b,x,y);
	t1=x/g; t2=b/g;
	while (t1<0) t1+=t2;
	while (t1-t2>0) t1-=t2;
	printf("%d",t1);
	return 0;
}
