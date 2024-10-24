#include<iostream>
#include<cstdio>
using namespace std;
const int N=2505;
const int MOD=998244353;
int n,k;
int f[N][N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        f[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            f[i][j]=0;
    for(int l=0;l<=n;l++)
        for(int i=1;i<=k;i++)
            for(int j=1;i+j-1<=k&&i*j<=l;j++)
                f[l][i]=(f[l][i]+f[l-i*j][j])%MOD;
    int ans=0;
    for(int i=1;i<=k;i++)
        ans=(ans+f[n][i])%MOD;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}