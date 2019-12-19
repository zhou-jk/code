#include<iostream>
#include<cstdio>
using namespace std;
const int N=100000;
const int MOD=8388608;
int T,n,k;
long long C[N+1][24];
void init()
{
    for(int i=0;i<=N;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=min(23,i);j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    return;
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        long long ans=0;
        for(int i=1;i<=min(k,23);i++)
            ans=(ans+C[n][i]*i%MOD*(1<<(i-1))%MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}