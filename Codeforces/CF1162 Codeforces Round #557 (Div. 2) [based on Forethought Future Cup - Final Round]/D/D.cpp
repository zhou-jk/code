#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
pair<int,int>seg[N];
pair<int,int>b[N];
int tot;
bool check(int k)
{
	tot=0;
	for(int i=1;i<=m;i++)
	{
		pair<int,int>nxt={(seg[i].first+k)%n==0?n:(seg[i].first+k)%n,(seg[i].second+k)%n==0?n:(seg[i].second+k)%n};
		if(nxt.first>nxt.second) swap(nxt.first,nxt.second);
		b[++tot]=nxt;
	}
	sort(b+1,b+tot+1);
	for(int i=1;i<=m;i++)
		if(seg[i]!=b[i]) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		seg[i]={a,b};
	}
	sort(seg+1,seg+m+1);
	if(check(1))
	{
		printf("Yes");
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			if(check(i)||check(n/i))
			{
				printf("Yes");
				return 0;
			}
		}
	printf("No");
	return 0;
}
