//VOJ 2018年寒假网赛第四场 B
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1000000;
int p[N];

int main() {
	int n,ans=N;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	p[0]=1; p[++n]=1000000;
	for (int i=0;i<n;i++) ans=min(ans,max(p[i]-1,N-p[i+1]));
	printf("%d",ans);
	return 0;
}
