//Virtual Judge 2018�꺮��������һ�� A
#include <cstdio>

int calc(int a,int b) {
	return !(a%b)?a/b:a/b+1;
}

int main() {
	int n,m,a;
	scanf("%d%d%d",&n,&m,&a);
	printf("%lld",(long long)calc(n,a)*calc(m,a));
	return 0;
}
