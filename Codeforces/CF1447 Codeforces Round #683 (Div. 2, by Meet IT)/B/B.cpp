#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=15;
int T;
int n,m;
int a[N][N];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int cnt=0;
	long long sum=0;
	vector<int>val;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]<=0) val.emplace_back(a[i][j]),sum+=-a[i][j],cnt++;
			else val.emplace_back(-a[i][j]),sum+=a[i][j];
	sort(val.begin(),val.end(),greater<int>());
	if(cnt&1) sum+=2*val.front();
	printf("%lld\n",sum);
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
