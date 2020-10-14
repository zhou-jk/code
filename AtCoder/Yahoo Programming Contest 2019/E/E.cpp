#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=300;
const int MOD=998244353;
int n,m;
bitset<N>a[N];
struct Basis
{
	bitset<N> d[N];
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
	void insert(bitset<N> t)
	{
		for(int i=m-1;i>=0;i--)
			if(t[i])
			{
				if(d[i].count()) t^=d[i];
				else
				{
					for(int j=0;j<i;j++)
						if(t[j]) t^=d[j];
					for(int j=i+1;j<=m-1;j++)
						if(d[j][i]) d[j]^=t;
					d[i]=t;
					cnt++;
					return;
				}
			}
		return;
	}
}lb;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			a[i][j]=x;
		}
	for(int i=0;i<n;i++)
		lb.insert(a[i]);
	int r=lb.size();
	long long ans=(ksm(2,n)-ksm(2,n-r)+MOD)%MOD*ksm(2,m-1)%MOD;
	printf("%lld",ans);
	return 0;
}
