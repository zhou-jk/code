#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int query(long long x,long long y)
{
	printf("%lld %lld\n",x,y);
	fflush(stdout);
	int k;
	scanf("%d",&k);
	if(k==0) exit(0);
	return k;
}
int main()
{
	scanf("%lld",&n);
	long long x=0,y=0,dx=1,dy=1;
	while(1)
	{
		int k=query(x+dx,y+dy);
		if(k==1) x+=dx,dx=min(dx*2,n-x);
		else if(k==2) y+=dy,dy=min(dy*2,n-y);
		else if(k==3) dx=max(dx/2,1LL),dy=max(dy/2,1LL);
	}
	return 0;
}
