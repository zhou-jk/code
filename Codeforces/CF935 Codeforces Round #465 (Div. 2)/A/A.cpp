#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int ans=1;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0) n/=i,cnt++;
			ans*=(cnt+1);
		}
	if(n!=1) ans*=2;
	printf("%d",ans-1);
	return 0;
}
