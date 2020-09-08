#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=55,M=(1<<18)+5;
int n,m,k,s,t;
int a[N];
bool book[N];
long long C[N][N];
long long sum[N][N];
void init(int n=50)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for(int i=0;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+C[i][j];
	return;
}
int main()
{
	scanf("%d%d%d%d",&n,&k,&s,&t);
	init();
	m=18;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=m-1;i>=0;i--)
	{
		if((s&(1<<i))==1&&(t&(1<<i))==0)
		{
			printf("0");
			return 0;
		}
		if((s&(1<<i))==(t&(1<<i)))
		{
			for(int j=1;j<=n;j++)
				if((s&(1<<i))!=(a[j]&(1<<i))) book[j]=true;
		}
	}
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(!book[i]) v.push_back(a[i]);
	n=0;
	for(int u:v)
		a[++n]=u;
	long long ans=0;
	for(int state=0;state<(1<<m);state++)
	{
		bool flag=false;
		for(int i=0;i<m;i++)
			if((state&(1<<i))&&(s&(1<<i))==(t&(1<<i)))
			{
				flag=true;
				break;
			}
		if(flag) continue;
		map<int,int>cnt;
		for(int i=1;i<=n;i++)
			cnt[a[i]&state]++;
		long long res=0;
		for(auto [val,num]:cnt)
			res+=sum[num][k];
		if(__builtin_popcount(state)&1) ans-=res;
		else ans+=res;
	}
	printf("%lld",ans);
	return 0;
}
