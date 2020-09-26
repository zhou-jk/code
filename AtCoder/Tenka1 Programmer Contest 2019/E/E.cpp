#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=10005;
int n;
int a[N];
bool isprime[N];
int prime[N],tot;
void init(int n=10000)
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
	return;
}
bool check(int p)
{
	if(a[0]%p!=0) return false;
	static int sum[N];
	for(int i=0;i<=p-2;i++)
		sum[i]=0;
	for(int i=0;i<=n;i++)
		sum[i%(p-1)]=(sum[i%(p-1)]+a[i])%p;
	for(int i=0;i<=p-2;i++)
		if(sum[i]) return false;
	return true;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=n;i>=0;i--)
		scanf("%d",&a[i]);
	int k=a[0];
	for(int i=1;i<=n;i++)
		k=__gcd(k,a[i]);
	k=abs(k);
	vector<int>res;
	for(int i=1;i<=tot&&prime[i]<=sqrt(k);i++)
		if(k%prime[i]==0)
		{
			res.push_back(prime[i]);
			while(k%prime[i]==0) k/=prime[i];
		}
	if(k>1) res.push_back(k);
	for(int i=1;i<=tot&&prime[i]<=n;i++)
	{
		int p=prime[i];
		if(check(p)) res.push_back(p);
	}
	sort(res.begin(),res.end());
	res.erase(unique(res.begin(),res.end()),res.end());
	for(int p:res)
		printf("%d\n",p);
	return 0;
}
