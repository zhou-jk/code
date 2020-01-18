#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=998244353;
const int N=100000;
int o;
long long n,m,r;
long long fac[N+1],invfac[N+1],inv[N+1];
long long dp[63][63][63],f[10002];
long long lowbit(long long x)
{
    return x&-x;
}
int count(long long x)
{
	int tot=0;
    for(long long i=x;i;i-=lowbit(i))
        tot++;
	return tot;
}
struct Node
{
	long long x,y,z;
	int a,b,c;
}p[10002];
bool cmp(Node a,Node b)
{
    if(a.x!=b.x) return a.x<b.x;
    else if(a.y!=b.y) return a.y<b.y;
    else return a.z<b.z;
}
long long C(int n,int m)
{
	return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}
void init()
{
    inv[1]=fac[0]=invfac[0]=1;
	for(int i=1;i<=N;i++)
    {
		if(i!=1) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac[i]=fac[i-1]*i%MOD;
		invfac[i]=invfac[i-1]*inv[i]%MOD;
	}
    return;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&r);
    int l1=count(n),l2=count(m),l3=count(r);
	scanf("%d",&o);
    for(int i=1;i<=o;i++)
    {
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if((x&n)!=x||(y&m)!=y||(z&r)!=z)
        {
            i--,o--;
            continue;
        }
        p[i]=(Node){x,y,z,count(x),count(y),count(z)};
	}
    p[0]=(Node){0,0,0,0,0,0};
    p[++o]=(Node){n,m,r,l1,l2,l3};
	sort(p,p+o+1,cmp);
	init();
	dp[0][0][0]=1;
    for(int i=0;i<=l1;i++)
        for(int j=0;j<=l2;j++)
            for(int k=0;k<=l3;k++)
            {
                for(int l=1;l<=i;l++)
                    dp[i][j][k]=(dp[i][j][k]+dp[i-l][j][k]*C(i,l)%MOD)%MOD;
                for(int l=1;l<=j;l++)
                    dp[i][j][k]=(dp[i][j][k]+dp[i][j-l][k]*C(j,l)%MOD)%MOD;
                for(int l=1;l<=k;l++)
                    dp[i][j][k]=(dp[i][j][k]+dp[i][j][k-l]*C(k,l)%MOD)%MOD;
            }
	f[0]=1;
    for(int i=0;i<=o;i++)
        for(int j=i+1;j<=o;j++)
            if((p[i].x&p[j].x)==p[i].x&&(p[i].y&p[j].y)==p[i].y&&(p[i].z&p[j].z)==p[i].z) f[j]=(f[j]+MOD-f[i]*dp[p[j].a-p[i].a][p[j].b-p[i].b][p[j].c-p[i].c]%MOD)%MOD;
	printf("%lld",MOD-f[o]);
	return 0;
}