#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int l,r,x,y;
int main()
{
	scanf("%d%d%d%d",&l,&r,&x,&y);
	if(y%x!=0)
	{
		printf("0");
		return 0;
	}
	int k=y/x;
	int ans=0;
	auto check=[=](int i,int j)
	{
		if(__gcd(i,j)!=1) return false;
		return l<=1LL*x*i&&1LL*x*i<=r&&l<=1LL*x*j&&1LL*x*j<=r&&1LL*x*i*x*j==1LL*x*y;
	};
	for(int i=1;i<=sqrt(k);i++)
		if(k%i==0)
		{
			if(check(i,k/i)) ans++;
			if(i*i!=k&&check(k/i,i)) ans++;
		}
	printf("%d",ans);
	return 0;
}
