#include<iostream>
#include<cstdio>
using namespace std;
const int N=205;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if(2*k>n+1)
	{
		printf("-1");
		return 0;
	}
	int l=n/2,r=2*n-1;
	for(int i=3*n-1;i>=2*n;i--)
	{
		printf("%d %d %d\n",l+k,r+k,i+k);
		r-=2;
		if(r<n) r=2*n-2;
		l++;
		if(l==n) l=0;
	}
	return 0;
}
