#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
const int MOD=1000000007;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int n,m;
int a[N];
int f[N][N*N][2];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=a[n+1]=1;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=(n+1)*n/2;j++)
            f[i][j][0]=f[i][j][1]=0;
    f[0][0][0]=0,f[0][0][1]=1;
    for(int i=0;i<=n;i++)
        if(a[i]==1||a[i]==2)
            for(int k=0;k<=(n+1)*n/2;k++)
                for(int o=0;o<=1;o++)
                    if(f[i][k][o])
                        for(int j=i+1;j<=n+1;j++)
                        {
                            if(a[j]==1||a[j]==2)
                            {
                                int d=(j-i)*(j-i-1)/2;
                                f[j][k+d][o^1]=(f[j][k+d][o^1]+f[i][k][o])%MOD;
                            }
                            if(a[j]==1) break;
                        }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]==1) cnt++;
    int ans=0;
    for(int i=1;i<=(n+1)*n/2;i++)
        if(cnt%2==0) ans=(ans+(long long)(f[n+1][i][0]-f[n+1][i][1]+MOD)*qpow(i,m))%MOD;
        else ans=(ans+(long long)(f[n+1][i][1]-f[n+1][i][0]+MOD)*qpow(i,m))%MOD;
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