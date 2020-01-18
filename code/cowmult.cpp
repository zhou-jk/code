#include <cstdio>

const int LEN=10;
char a[LEN+1],b[LEN+1];

int main()
{
	freopen("cowmult.in","r",stdin); freopen("cowmult.out","w",stdout);
	int ans=0;
	scanf("%s%s",a,b);
	for (int i=0; a[i]; ++i)
		for (int j=0; b[j]; ++j) ans+=(a[i]^48)*(b[j]^48);
	printf("%d",ans);
	return 0;
}