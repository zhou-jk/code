#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
const int MOD=1000000007;
int n,k;
int f[N][N][3];
void init(int n=1000)
{
    f[1][0][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<i;j++)
        {
            if(j-1>=0) f[i][j][1]=(f[i-1][j-1][0]+f[i-1][j-1][1])%MOD;
            f[i][j][1]=(f[i][j][1]+f[i-1][j][2])%MOD;
            if(j-1>=0) f[i][j][2]=(f[i-1][j-1][0]+f[i-1][j-1][2])%MOD;
            f[i][j][2]=(f[i][j][2]+f[i-1][j][1])%MOD;
            f[i][j][0]=((long long)(f[i-1][j+1][1]+f[i-1][j+1][2])*j+(long long)f[i-1][j+1][0]*(j+1)+(long long)f[i-1][j][0]*(i-2-j)+(long long)(f[i-1][j][1]+f[i-1][j][2])*(i-1-j))%MOD;
        }
    return; 
}
void solve()
{
    cin>>n>>k;
    int ans=((long long)f[n][k][0]+f[n][k][1]+f[n][k][2])%MOD;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
