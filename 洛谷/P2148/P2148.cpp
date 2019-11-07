#include<iostream>
#include<cstdio>
using namespace std;
int T,n;
int sg(int x,int y)
{
	int a=x,b=y,res=0;
	while(1)
	{
		if(a&1&&b&1) return res;
		if(a&1) a++;
        if(b&1) b++;
		a>>=1,b>>=1,res++;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ans^=sg(x,y);
		}
		if(ans) printf("YES\n");
        else printf("NO\n");
	}
    return 0;
}