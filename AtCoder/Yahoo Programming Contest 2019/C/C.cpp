#include<iostream>
#include<cstdio>
using namespace std;
int K,A,B;
int main()
{
	scanf("%d%d%d",&K,&A,&B);
	long long ans=0;
	if(B-A>2)
	{
		K-=A-1;
		ans+=A;
		if(K%2==1) ans++;
		K/=2;
		ans+=1LL*K*(B-A);
	}
	else ans+=1+K;
	printf("%lld",ans);
	return 0;
}
