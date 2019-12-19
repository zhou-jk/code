#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2000001;
const int MOD=1000000007;
int n,m;
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
int flag[N];
int prime[N],tot;
bool isprime[N];
void init()
{
    flag[1]=1;
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<=m;i++)
    {
        if(isprime[i])
        {
            prime[++tot]=i;
            flag[i]=-1;
        }
        for(int j=1;j<=tot&&i*prime[j]<=m;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
            flag[i*prime[j]]=-flag[i];
        }
    }
    return;
}
long long sum[N],p[N];
int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=m;i++)
        p[i]=ksm(i,n);
    long long ans=0,res=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j+=i)
            sum[j]=((sum[j]+flag[i]*(p[j/i]-p[j/i-1]))%MOD+MOD)%MOD;
        ans=(ans+sum[i])%MOD;
        res=(res+(ans^i))%MOD;
    }
    printf("%lld",res);
    return 0;
}