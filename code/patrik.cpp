#include <cstdio>

const int N=500000;
int q[N],s[N];

int main()
{
	freopen("patrik.in","r",stdin); freopen("patrik.out","w",stdout);
	int l=0,r=0,n,num;
	long long ans=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&num);
		while (l<r&&num>q[r-1]) r--,ans+=s[r];
		q[r]=num; s[r++]=1;
		while (l<r-1&&q[r-1]==q[r-2]) r--,s[r-1]+=s[r];
		ans+=s[r-1]-1;
		if (l<r-1) ans+=1;
	}
	printf("%lld",ans);
	return 0;
}