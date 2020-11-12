#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
bool f[N][6];
vector<int>res;
void print(int n,int x)
{
	if(n==1)
	{
		res.emplace_back(x);
		return ;
	}
	res.emplace_back(x);
	if(a[n]>a[n-1])
	{
		for(int y=1;y<x;y++)
			if(f[n-1][y]) return print(n-1,y);
	}
	if(a[n]<a[n-1])
	{
		for(int y=x+1;y<=5;y++)
			if(f[n-1][y]) return print(n-1,y);
	}
	if(a[n]==a[n-1])
	{
		for(int y=1;y<=5;y++)
			if(y!=x&&f[n-1][y]) return print(n-1,y);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int x=1;x<=5;x++)
		f[1][x]=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			for(int x=1,flag=0;x<=5;x++) f[i][x]=flag,flag|=f[i-1][x];
		}
		else if(a[i]<a[i-1])
		{
			for(int x=5,flag=0;x>=1;x--) f[i][x]=flag,flag|=f[i-1][x];
		}
		else if(a[i]==a[i-1])
		{
			int cnt=0;
			for(int x=1;x<=5;x++) cnt+=f[i-1][x];
			for(int x=1;x<=5;x++) f[i][x]=(cnt-f[i-1][x])>0;
		}
	}
	for(int i=1;i<=5;i++)
		if(f[n][i])
		{
			print(n,i);
			reverse(res.begin(),res.end());
			for(int u:res)
				printf("%d ",u);
			return 0;
		}
	printf("-1");
	return 0;
}
