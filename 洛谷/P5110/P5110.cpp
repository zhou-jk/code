#include<iostream>
#include<cstdio>
const int MOD=1000000007;
const int a=233230706,b1=94153035,b2=905847205;
const int N=32768;
long long high1[N],low1[N];
long long high2[N],low2[N];
namespace Mker
{
    unsigned long long SA,SB,SC;
    void init(){scanf("%llu%llu%llu",&SA,&SB,&SC);}
    unsigned long long rand()
    {
        SA^=SA<<32,SA^=SA>>13,SA^=SA<<1;
        unsigned long long t=SA;
        SA=SB,SB=SC,SC^=t^SA;return SC;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    low1[0]=1;
    for(int i=1;i<N;i++)
        low1[i]=low1[i-1]*b1%MOD;
    high1[0]=1;
    high1[1]=low1[N-1]*b1%MOD;
    for(int i=2;i<N;i++)
        high1[i]=high1[i-1]*high1[1]%MOD;
    low2[0]=1;
    for(int i=1;i<N;i++)
        low2[i]=low2[i-1]*b2%MOD;
    high2[0]=1;
    high2[1]=low2[N-1]*b2%MOD;
    for(int i=2;i<N;i++)
        high2[i]=high2[i-1]*high2[1]%MOD;
    Mker::init();
    int ans=0;
    while(T--)
    {
        unsigned long long n=Mker::rand();
        n%=MOD-1;
        ans^=a*(high1[n/N]*low1[n%N]%MOD-high2[n/N]*low2[n%N]%MOD+MOD)%MOD;
    }
    printf("%d",ans);
    return 0;
}