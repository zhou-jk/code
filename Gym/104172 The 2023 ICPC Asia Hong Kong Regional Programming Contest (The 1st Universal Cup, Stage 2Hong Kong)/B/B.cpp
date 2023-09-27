#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
const int MOD=998244353;
int n,m;
int p[N][N],q[N][N];
int sp[N][N],sq[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>q[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sp[i][j]=(sp[i][j-1]+p[i][j])%MOD;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sq[i][j]=(sq[i-1][j]+q[i][j])%MOD;
    int ans=2;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        {
            int a=(long long)sp[i][j-1]*sq[i-1][j]%MOD,b=(long long)(1-sp[i+1][j-1]+MOD)*(1-sq[i-1][j+1]+MOD)%MOD;
            ans=(ans+(long long)a*b)%MOD;
        }
    cout<<ans;
    return 0;
}