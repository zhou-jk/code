//Virtual Judge 2018年寒假网赛第三场 A
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int a,b,s;
	scanf("%d%d%d",&a,&b,&s);
	a=abs(a); b=abs(b);
	if ((a+b)%2==s%2&&s>=a+b) printf("YES");
	else printf("NO");
	return 0;
}
