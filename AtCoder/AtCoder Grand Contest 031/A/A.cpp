#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n;
char s[N];
int cnt[26];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		cnt[s[i]-'a']++;
	long long ans=1;
	for(int i=0;i<26;i++)
		ans=ans*(cnt[i]+1)%MOD;
	ans--;
	printf("%lld",ans);
	return 0;
}
