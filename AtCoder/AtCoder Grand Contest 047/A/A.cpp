#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=200005;
int n;
long long a[N];
map<pair<int,int>,int>book;
int main()
{
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		double x;
		scanf("%lf",&x);
		a[i]=x*1e9;
		int cnt2=0,cnt5=0;
		while(a[i]%2==0) cnt2++,a[i]/=2;
		while(a[i]%5==0) cnt5++,a[i]/=5;
		for(auto [x,num]:book)
			if(x.first+cnt2>=18&&x.second+cnt5>=18) ans+=num;
		book[make_pair(cnt2,cnt5)]++;
	}
	printf("%lld",ans);
	return 0;
}
