#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n,k;
int a[N];
struct BIT
{
	int C[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	void clear()
	{
		memset(C,0,sizeof(C));
		return;
	}
	void add(int x,int y)
	{
		if(x>n) return;
		for(int i=x;i<=n;i+=lowbit(i))
			C[i]+=y;
		return;
	}
	int getsum(int x)
	{
		int res=0;
		for(int i=x;i>0;i-=lowbit(i))
			res+=C[i];
		return res;
	}
	void modify(int l,int r,int v)
	{
		l=max(l,1);
		r=min(r,n);
		add(l,v);
		add(r+1,-v);
		return;
	}
};
BIT T;
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]<n) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		T.clear();
		for(int i=1;i<=n;i++)
			T.modify(i-a[i],i+a[i],1);
		for(int i=1;i<=n;i++)
			a[i]=T.getsum(i);
		if(check()) break;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
