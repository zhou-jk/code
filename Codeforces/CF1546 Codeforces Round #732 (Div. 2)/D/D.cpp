#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=998244353;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return ksm(x,MOD-2);
}
int fac[N],ifac[N];
void init(int n=100000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    ifac[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        ifac[i-1]=1LL*ifac[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    else return 1LL*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int n;
char s[N];
void solve()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    int c0=0,c1=0;
    for(int i=1;i<n;i++)
        if(s[i]=='0') c0++;
        else if(s[i]=='1'&&s[i+1]=='1') c1++,i++;
    if(s[n]=='0') c0++;
    int ans=C(c0+c1,c0);
    printf("%d\n",ans);
    return;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}