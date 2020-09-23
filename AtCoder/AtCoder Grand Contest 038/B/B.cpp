#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
const int MOD=998244353;
int n;
char s[N];
int a[N];
int cnt[7];
void add(int &x,int &y)
{
	if(x>=1) x--,y++;
	return;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n*3;i++)
		if(s[i]=='R') a[i]=1;
		else if(s[i]=='G') a[i]=2;
		else if(s[i]=='B') a[i]=3;
	long long ans=1;
	for(int i=1;i<=n*3;i++)
	{
		if(cnt[7-a[i]]>=1) ans=ans*cnt[7-a[i]]%MOD,cnt[7-a[i]]--;
		else if(a[i]==1&&cnt[2]+cnt[3]>=1) ans=ans*(cnt[2]+cnt[3])%MOD,add(cnt[2],cnt[4]),add(cnt[3],cnt[5]);
		else if(a[i]==2&&cnt[1]+cnt[3]>=1) ans=ans*(cnt[1]+cnt[3])%MOD,add(cnt[1],cnt[4]),add(cnt[3],cnt[6]);
		else if(a[i]==3&&cnt[1]+cnt[2]>=1) ans=ans*(cnt[1]+cnt[2])%MOD,add(cnt[1],cnt[5]),add(cnt[2],cnt[6]);
		else cnt[a[i]]++;
		//R G B RG RB GB
	}
	for(int i=1;i<=n;i++)
		ans=ans*i%MOD;
	printf("%lld",ans);
	return 0;
}
