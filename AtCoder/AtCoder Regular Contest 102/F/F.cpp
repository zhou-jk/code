#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=300005;
int n;
int p[N];
struct BIT
{
	int C[N];
	void clear()
	{
		memset(C,0,sizeof(C));
		return;
	}
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x,int y)
	{
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
	int query(int l,int r)
	{
		return getsum(r)-getsum(l-1);
	}
}T;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		if(p[i]%2!=i%2)
		{
			printf("No");
			return 0;
		}
	long long cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=T.query(p[i]+1,n),T.add(p[i],1);
	T.clear();
	long long cnt1=0;
	for(int i=1;i<=n;i+=2)
		cnt1+=T.query(p[i]+1,n),T.add(p[i],1);
	T.clear();
	long long cnt2=0;
	for(int i=2;i<=n;i+=2)
		cnt2+=T.query(p[i]+1,n),T.add(p[i],1);
	if(cnt%3==0&&3*(cnt1+cnt2)==cnt) printf("Yes");
	else printf("No");
	return 0;
}