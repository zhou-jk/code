#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,n;
const long long Pw[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
long long calc(long long x,int len)
{
	long long res=0;
	for(int i=1;i<=len;i++)
		res+=Pw[i]*x;
	return res;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int len=floor(log10(n));
		int ans=len*9;
		for(int i=1;i<=9;i++)
			if(calc(i,len+1)<=n) ans++;
		printf("%d\n",ans);			
	}
	return 0;
}