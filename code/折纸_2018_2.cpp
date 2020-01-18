//VOJ 2018年寒假网赛第七场 B
#include <cstdio>
#include <algorithm>

using namespace std;

long long ans;

int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	while (b) {
		ans+=a/b;
		a%=b;
		swap(a,b);
	}
	printf("%lld",ans);
	return 0;
}