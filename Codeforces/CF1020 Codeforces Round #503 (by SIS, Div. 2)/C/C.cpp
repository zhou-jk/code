#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3005;
int n,m;
vector<int>a[N];
long long solve(int u)
{
	long long ans=0;
	int tot=a[0].size();
	vector<int>val;
	for(int i=1;i<=m;i++)
	{
		int j=0,k=a[i].size();
		while(k>=u) ans+=a[i][j],j++,k--,tot++;
		while(j<a[i].size()) val.push_back(a[i][j]),j++;
	}
	sort(val.begin(),val.end());
	for(size_t i=0;i<val.size();i++)
	{
		if(tot>=u) break;
		ans+=val[i],tot++;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int p,c;
		scanf("%d%d",&p,&c);
		if(p==1) c=0;
		a[p].emplace_back(c);
	}
	for(int i=1;i<=m;i++)
		sort(a[i].begin(),a[i].end());
	long long ans=1e18;
	for(int i=1;i<=n;i++)
		ans=min(ans,solve(i));
	printf("%lld",ans);
	return 0;
}
