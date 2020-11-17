#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;
int s[N],tot;
long long f[N][4][2];
long long dfs(int now,int ret,bool flag)
{
	if(ret<0) return 0;
	if(now==0) return 1;
	if(f[now][ret][flag]!=-1) return f[now][ret][flag];
	long long res=0;
	for(int i=0;i<=9;i++)
		if(!flag||(flag&&i<=s[now])) res+=dfs(now-1,ret-(i!=0),flag&&s[now]==i);
	return f[now][ret][flag]=res;
}
long long calc(long long x)
{
	if(x==0) return 1;
	tot=0;
	while(x) s[++tot]=x%10,x/=10;
	memset(f,-1,sizeof(f));
	return dfs(tot,3,true);
}
int T;
long long l,r;
void dfs()
{
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",calc(r)-calc(l-1));
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		dfs();
	return 0;
}
