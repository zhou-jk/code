#include <cstdio>

const int LEN=63;
long long ans[LEN+1];
int s[LEN+1],vis[LEN+1];

int main()
{
	freopen("homework.in","r",stdin); freopen("homework.out","w",stdout);
	int a,b,k,tmp=0,i;
	scanf("%d%d%d",&a,&b,&k);
	for (i=0; !vis[tmp]; ++i)
	{
		vis[tmp]=i+1; s[i]=tmp;
		int tmp1=ans[i]=tmp*a+b;
		//printf("%d\n",tmp);
		tmp=0;
		for (; tmp1; tmp1>>=1) tmp+=tmp1&1;
	}
	//printf("%d\n",i);
	if (k>=i)
	{
		k-=vis[tmp];
		k%=i-vis[tmp]+1;
		printf("%lld",ans[vis[tmp]+k-1]);
	}
	else printf("%lld",ans[k-1]);
	return 0;
}