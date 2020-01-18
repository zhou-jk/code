//¼ÆËâ¿Í
#include <cstdio>

using namespace std;

bool is_prime[8000001];
int n,ans;

int main() {
	scanf("%d",&n);
	for (int i=2;i*i<=n;i++)
		if (!is_prime[i])
			for (int j=i*i;j<=n;j+=i) is_prime[j]=true;
	for (int i=2;i<=n/2;i++)
		ans+=!is_prime[i]&&!is_prime[n-i];
	printf("%d",ans);
	return 0;
}
