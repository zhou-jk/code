#include<iostream>
#include<cstdio>
#include<random>
#include<ctime>
using namespace std;
const int N=100005;
const long long M=2250000000000;
int n;
pair<int,int>vec[N];
mt19937 myrand(time(NULL));
unsigned int rand(unsigned int l,unsigned int r)
{
	return myrand()%(r-l+1)+l;
}
int val[N];
bool check()
{
	long long x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		x+=val[i]*vec[i].first,y+=val[i]*vec[i].second;
		if(x*x+y*y>M) x-=val[i]*vec[i].first*2,y-=val[i]*vec[i].second*2,val[i]=-val[i];
	}
	return x*x+y*y<=M;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[i]={x,y};
	}
	while(true)
	{
		for(int i=1;i<=n;i++)
			val[i]=myrand()%2==0?-1:1;
		if(check())
		{
			for(int i=1;i<=n;i++)
				printf("%d ",val[i]);
			return 0;
		}
	}
	return 0;
}
