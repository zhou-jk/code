#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=(1<<18)+5;
const int MOD=1000000007;
int H,L;
int n;
int p[N];
long long tag[N];
void jump(int u,long long fac)
{
	if(!u) return;
	tag[u]=(tag[u]+fac)%MOD;
	jump(u/2,fac*(u/2)%MOD);
	return;
}
void add(int u,long long fac)
{
	if(u>n) return;
	if(u>=L)
	{
		jump(L+p[u]-1,fac*(L+p[u]-1)%MOD);
		return;
	}
	add(u*2,fac*(u*2)%MOD),add(u*2+1,fac*(u*2+1)%MOD);
	return;
}
long long ans;
void getans(int u,long long fac,int pre)
{
	if(!u) return;
	ans=(ans+(tag[u]-tag[pre]*u%MOD+MOD)*fac%MOD)%MOD;
	getans(u/2,fac*u%MOD,u);
	return;
}
void solve(int u,long long fac)
{
	if(u>n) return;
	if(u>=L)
	{
		getans(L+p[u]-1,fac*u%MOD,0);
		return;
	}
	solve(u*2,fac*u%MOD),solve(u*2+1,fac*u%MOD);
	return;
}
void clear(int u)
{
	if(!u) return;
	tag[u]=0;
	clear(u/2);
	return;
}
void remove(int u)
{
	if(u>n) return;
	if(u>=L)
	{
		clear(L+p[u]-1);
		return;
	}
	remove(u*2),remove(u*2+1);
	return;
}
void dfs(int u)
{
	if(u>n) return;
	add(u*2,u*2),solve(u*2+1,u);
	remove(u*2);
	dfs(u*2),dfs(u*2+1);
	return;
}
int main()
{
	scanf("%d",&H);
	n=(1<<H)-1;
	L=1<<(H-1);
	for(int i=1;i<=L;i++)
		scanf("%d",&p[L+i-1]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
