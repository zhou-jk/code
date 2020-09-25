#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=25;
const long long INF=4557430888798830399;
int n;
int a[N];
map<pair<int,int>,long long>f[N][N];
long long dfs(int l,int r,int p,int q)
{
	if(l>r) return 0;
	if(f[l][r].count({p,q})) return f[l][r][{p,q}];
	long long res=INF;
	for(int i=l;i<=r;i++)
		res=min(res,dfs(l,i-1,p,p+q)+dfs(i+1,r,p+q,q)+1LL*(p+q)*a[i]);
	return f[l][r][{p,q}]=res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%lld",dfs(2,n-1,1,1)+a[1]+a[n]);
	return 0;
}

