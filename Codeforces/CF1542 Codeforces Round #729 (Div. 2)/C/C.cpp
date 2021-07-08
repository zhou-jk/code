#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
int T;
long long n;
__int128 lcm(__int128 a,__int128 b)
{
    return a/__gcd(a,b)*b;
}
void solve()
{
    scanf("%lld",&n);
    __int128 fac=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        fac=lcm(fac,i);
        if(fac>n) break;
        ans=(ans+1LL*(n/fac-n/lcm(fac,i+1))*(i+1)%MOD)%MOD;
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}