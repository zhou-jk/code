#include<iostream>
#include<cstdio>
using namespace std;
const int N=505,K=1005;
const int INF=1061109567;
int n,m,x;
char s[N][N];
int f[2][N][K];
void solve()
{
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=1;j<=m;j++)
            s[i][j]=str[j-1];
    }
    for(int i=0;i<=1;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=x;k++)
                f[i][j][k]=-INF;
    f[0][1][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=x;k++)
            {
                f[i&1][j][k]=max(f[(i&1)^1][j][k],f[i&1][j-1][k]);
                if(s[i][j]=='1') f[i&1][j][k]++;
                if(k-1>=0&&s[i][j]=='?') f[i&1][j][k]=max(f[i&1][j][k],max(f[(i&1)^1][j][k-1],f[i&1][j-1][k-1])+1);
            }
    int ans=0;
    for(int k=0;k<=x;k++)
        ans=max(ans,f[n&1][m][k]);
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