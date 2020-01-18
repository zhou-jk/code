#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=19940417;
const int N=1000005;
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
pair<int,int>a[N];
int n,K,ans;
long long f[N][2];
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=K;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    a[++K]=make_pair(0,0);
    a[++K]=make_pair(n,0);
    sort(a+1,a+K+1);
    K=unique(a+1,a+K+1)-a-1;
    f[1][1]=1;
    for(int i=2;i<=K;i++)
    {
        int p=(a[i].first-a[i-1].first-a[i].second-a[i-1].second)/2;
        ans=max(ans,(a[i].first+a[i].second-a[i-1].first+a[i-1].second)/2);
        if(a[i].second-a[i-1].second==a[i-1].first-a[i].first) f[i][1]=(f[i][1]+(f[i-1][0]+f[i-1][1])%MOD)%MOD;
        else if(a[i].second-a[i-1].second==a[i].first-a[i-1].first) f[i][0]=(f[i][0]+((a[i-1].second?0:f[i-1][1])+f[i-1][0])%MOD)%MOD;
        else if(p<0) f[i][1]=(f[i][1]+f[i-1][0])%MOD;
        else if(p==0) f[i][0]=(f[i][0]+(f[i-1][0]+f[i-1][1])%MOD)%MOD,f[i][1]=(f[i][1]+f[i-1][0])%MOD;
        else
        {
            long long d=ksm(2,p-1);
            if(a[i].second) f[i][0]=(f[i][0]+(f[i-1][1]+2*f[i-1][0])%MOD*d%MOD)%MOD;
            f[i][1]=(f[i][1]+(f[i-1][1]+2*f[i-1][0])%MOD*d%MOD)%MOD;
        }
    }
    printf("%lld %d",f[K][1],ans);
    return 0;
}