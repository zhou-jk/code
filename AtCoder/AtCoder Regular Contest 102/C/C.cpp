#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	long long ans=0;
	for(int a=0;a<k;a++)
	{
		int b=(-a+k)%k;
		int c=(-a+k)%k;
		if((b+c)%k!=0) continue;
		int ca=n/k+(a<=n%k),cb=n/k+(b<=n%k),cc=n/k+(c<=n%k);
		if(a==0) ca--;
		if(b==0) cb--;
		if(c==0) cc--;
		ans+=1LL*ca*cb*cc;
	}
	printf("%lld",ans);
	return 0;
}