#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,M=35;
const int INF=1000000001;
int n,T;
struct Node
{
	int a,b;
}s[N];
int f[N][M];
vector<int>d;
long long sum[N];
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].a,&s[i].b);
		if(s[i].a==0)
		{
			d.push_back(s[i].b);
			n--,i--;
		}
	}
	sort(s+1,s+n+1,[=](const Node &x,const Node &y){return (double)x.a/(x.b+1)>(double)y.a/(y.b+1);});
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,30);j++)
		{
			if(f[i-1][j]<INF) f[i][j]=f[i-1][j];
			if(j>=1)
			{
				if(f[i-1][j-1]+(1+1LL*s[i].a*(f[i-1][j-1]+1)+s[i].b)<INF) f[i][j]=min(f[i][j],f[i-1][j-1]+(1+s[i].a*(f[i-1][j-1]+1)+s[i].b));
			}
		}
	sort(d.begin(),d.end());
	for(int i=1;i<=d.size();i++)
		sum[i]=sum[i-1]+d[i-1]+1;
	int res=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=min(i,30);j++)
			if(f[i][j]<=T)
			{
				int t=T-f[i][j];
				int l=1,r=d.size(),ans=0;
				while(l<=r)
				{
					int mid=(l+r)/2;
					auto check=[=](int x){return sum[x]<=t;};
					if(check(mid)) ans=mid,l=mid+1;
					else r=mid-1;
				}
				res=max(res,j+ans);
			}
	printf("%d",res);
	return 0;
}

