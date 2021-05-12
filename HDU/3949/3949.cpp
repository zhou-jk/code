#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n;
long long a[N];
struct Basis
{
	static const int M=60;
	long long d[M+5];
	int cnt;
	void clear()
	{
		cnt=0;
		return;
	}
	int size()
	{
		return cnt;
	}
	void insert(long long t)
	{
		for(int i=M;i>=0;i--)
			if(t&(1LL<<i))
			{
				if(d[i]) t^=d[i];
				else
				{
					for(int j=0;j<i;j++)
						if(t&(1LL<<j)) t^=d[j];
					for(int j=i+1;j<=M;j++)
						if(d[j]&(1LL<<i)) d[j]^=t;
					d[i]=t;
					cnt++;
					return;
				}
			}
		return;
	}
	long long querymax()
	{
		long long res=0;
		for(int i=M;i>=0;i--)
			res^=d[i];
		return res;
	}
}lb;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		lb.insert(a[i]);
	printf("%lld",lb.querymax());
	return 0;
}