#include<iostream>
#include<cstdio>
#include<cmath>
#include<tuple>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=100005,M=50005;
const int MOD=998244353;
int n,m;
map<int,int>book[N];
vector<pair<int,int>>pos[N];
int get(int x,int y)
{
	vector<pair<int,int>>::iterator t=lower_bound(pos[x].begin(),pos[x].end(),make_pair(y,-1));
	if(t==pos[x].end()) return -1;
	if(t->first==y) return t->second;
	else return -1;
}
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
long long dp[N][2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(book[a].count(b))
		{
			if(book[a][b]==c) continue;
			else
			{
				printf("0");
				return 0;
			}
		}
		book[a][b]=c;
		pos[a].emplace_back(b,c);
		if(a!=b&&abs(b-a)>2)
		{
			book[b][a]=c;
			pos[b].emplace_back(a,c);
		}
	}
	for(int i=1;i<=n;i++)
		sort(pos[i].begin(),pos[i].end());
	int v=get(1,1);
	if(v==-1) dp[1][0]=dp[1][1]=1;
	else dp[1][v]=1;
	if(n==1)
	{
		printf("%lld",(dp[1][0]+dp[1][1])%MOD);
		return 0;
	}
	for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
			for(int p1=0;p1<=1;p1++)
				for(int p2=0;p2<=1;p2++)
				{
					if(j^k^p1^p2) continue;
					if(get(2,1)!=-1&&get(2,1)!=p1) continue;
					if(get(1,2)!=-1&&get(1,2)!=p2) continue;
					if(get(2,2)!=-1&&get(2,2)!=j) continue;
					dp[2][j]=(dp[2][j]+dp[1][k])%MOD;
				}
	for(int i=3;i<=n;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				for(int p1=0;p1<=1;p1++)
					for(int p2=0;p2<=1;p2++)
						for(int p3=0;p3<=1;p3++)
							for(int p4=0;p4<=1;p4++)
							{
								if(j^k^p1^p2) continue;
								if(get(i,i-1)!=-1&&get(i,i-1)!=p1) continue;
								if(get(i-1,i)!=-1&&get(i-1,i)!=p2) continue;
								if(get(i,i)!=-1&&get(i,i)!=j) continue;
								if(get(i,i-2)!=-1&&get(i,i-2)!=p3) continue;
								if(get(i-2,i)!=-1&&get(i-2,i)!=p4) continue;
								if(p3^p4^k) continue;
								int num=(i-3)-(upper_bound(pos[i].begin(),pos[i].end(),make_pair(i-3,1))-pos[i].begin());
								dp[i][j]=(dp[i][j]+dp[i-1][k]*ksm(2,num)%MOD)%MOD;
							}
	printf("%lld",(dp[n][0]+dp[n][1])%MOD);
	return 0;
}
