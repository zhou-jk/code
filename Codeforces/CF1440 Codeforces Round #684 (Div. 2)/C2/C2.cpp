#include<iostream>
#include<cstdio>
#include<tuple>
#include<vector>
using namespace std;
const int N=105;
int T;
int n,m;
int a[N][N];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]);
	vector<tuple<int,int,int,int,int,int>>res;
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=m-2;j++)
			if(a[i][j]) res.emplace_back(i,j,i+1,j,i,j+1),a[i][j]^=1,a[i+1][j]^=1,a[i][j+1]^=1;
	for(int i=1;i<=n-2;i++)
		if(a[i][m])
		{
			if(a[i][m-1]) res.emplace_back(i,m,i,m-1,i+1,m),a[i][m]^=1,a[i][m-1]^=1,a[i+1][m]^=1;
			else if(a[i+1][m])
			{
				res.emplace_back(i,m,i+1,m-1,i,m-1),a[i][m]^=1,a[i+1][m-1]^=1,a[i][m-1]^=1;
				res.emplace_back(i+1,m,i+1,m-1,i,m-1),a[i+1][m]^=1,a[i+1][m-1]^=1,a[i][m-1]^=1;
			}
			else res.emplace_back(i,m,i+1,m-1,i+1,m),a[i][m]^=1,a[i+1][m-1]^=1,a[i+1][m]^=1;
		}
		else if(a[i][m-1]) res.emplace_back(i+1,m,i+1,m-1,i,m-1),a[i+1][m]^=1,a[i+1][m-1]^=1,a[i][m-1]^=1;
	for(int j=1;j<=m-2;j++)
		if(a[n][j])
		{
			if(a[n-1][j]) res.emplace_back(n,j,n-1,j,n,j+1),a[n][j]^=1,a[n-1][j]^=1,a[n][j+1]^=1;
			else if(a[n][j+1])
			{
				res.emplace_back(n,j,n-1,j,n-1,j+1),a[n][j]^=1,a[n-1][j]^=1,a[n-1][j+1]^=1;
				res.emplace_back(n,j+1,n-1,j,n-1,j+1),a[n][j+1]^=1,a[n-1][j]^=1,a[n-1][j+1]^=1;
			}
			else res.emplace_back(n,j,n-1,j+1,n,j+1),a[n][j]^=1,a[n-1][j+1]^=1,a[n][j+1]^=1;
		}
		else if(a[n-1][j]) res.emplace_back(n,j+1,n-1,j,n-1,j+1),a[n][j+1]^=1,a[n-1][j]^=1,a[n-1][j+1]^=1;
	int cnt=a[n][m]+a[n-1][m]+a[n][m-1]+a[n-1][m-1];
	if(cnt==4)
	{
		res.emplace_back(n,m,n-1,m,n,m-1);
		res.emplace_back(n,m,n-1,m-1,n,m-1);
		res.emplace_back(n,m,n-1,m,n-1,m-1);
		res.emplace_back(n,m-1,n-1,m,n-1,m-1);
	}
	else if(cnt==3)
	{
		vector<pair<int,int>>pos;
		if(a[n][m]) pos.emplace_back(n,m);
		if(a[n-1][m]) pos.emplace_back(n-1,m);
		if(a[n][m-1]) pos.emplace_back(n,m-1);
		if(a[n-1][m-1]) pos.emplace_back(n-1,m-1);
		res.emplace_back(pos[0].first,pos[0].second,pos[1].first,pos[1].second,pos[2].first,pos[2].second);
	}
	else if(cnt==2)
	{
		vector<pair<int,int>>one,zero;
		if(a[n][m]) one.emplace_back(n,m);
		else zero.emplace_back(n,m);
		if(a[n-1][m]) one.emplace_back(n-1,m);
		else zero.emplace_back(n-1,m);
		if(a[n][m-1]) one.emplace_back(n,m-1);
		else zero.emplace_back(n,m-1);
		if(a[n-1][m-1]) one.emplace_back(n-1,m-1);
		else zero.emplace_back(n-1,m-1);
		res.emplace_back(one[0].first,one[0].second,zero[0].first,zero[0].second,zero[1].first,zero[1].second);
		res.emplace_back(one[1].first,one[1].second,zero[0].first,zero[0].second,zero[1].first,zero[1].second);
	}
	else if(cnt==1)
	{
		vector<pair<int,int>>one,zero;
		if(a[n][m]) one.emplace_back(n,m);
		else zero.emplace_back(n,m);
		if(a[n-1][m]) one.emplace_back(n-1,m);
		else zero.emplace_back(n-1,m);
		if(a[n][m-1]) one.emplace_back(n,m-1);
		else zero.emplace_back(n,m-1);
		if(a[n-1][m-1]) one.emplace_back(n-1,m-1);
		else zero.emplace_back(n-1,m-1);
		res.emplace_back(one[0].first,one[0].second,zero[0].first,zero[0].second,zero[1].first,zero[1].second);
		res.emplace_back(zero[0].first,zero[0].second,one[0].first,one[0].second,zero[2].first,zero[2].second);
		res.emplace_back(zero[1].first,zero[1].second,one[0].first,one[0].second,zero[2].first,zero[2].second);
	}
	int k=res.size();
	printf("%d\n",k);
	for(auto [x1,y1,x2,y2,x3,y3]:res)
		printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
