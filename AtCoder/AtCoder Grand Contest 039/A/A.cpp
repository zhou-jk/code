#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=205;
int n,k;
char s[N];
vector<int>len;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	for(int i=1,j=1;i<=n;i=j)
	{
		j=i;
		while(j<=n&&s[i]==s[j]) j++;
		len.push_back(j-i);
	}
	if(k==1)
	{
		int res=0;
		for(int L:len)
			res+=L/2;
		printf("%d",res);
		return 0;
	}
	if(s[1]==s[n])
	{
		int l=len.front(),r=len.back();
		if(len.size()==1)
		{
			long long ans=1LL*n*k/2;
			printf("%lld",ans);
			return 0;
		}
		len.erase(len.begin());
		len.pop_back();
		len.push_back(l+r);
		int res=0;
		for(int L:len)
			res+=L/2;
		long long ans=0;
		if(k>=2) ans+=1LL*res*(k-2);
		len.pop_back();
		len.insert(len.begin(),l);
		for(int L:len)
			ans+=L/2;
		len.erase(len.begin());
		len.push_back(l+r);
		len.push_back(r);
		for(int L:len)
			ans+=L/2;
		printf("%lld",ans);
		return 0;
	}
	int res=0;
	for(int L:len)
		res+=L/2;
	long long ans=1LL*res*k;
	printf("%lld",ans);
	return 0;
}
