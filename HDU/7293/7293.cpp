#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=1005;
const int MOD=1000000007;
int n,m;
int C[N][N];
void init(int n=1000)
{
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    return;
}
bitset<N>b[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        b[i].reset();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        b[x][y]=b[y][x]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            {
                int cntu=b[i].count(),cntv=b[j].count();
                if(b[i][j]) cntu--,cntv--;
                bitset<N>s=b[i]&b[j];
                int cnts=s.count();
                if(cnts<4) continue;
                ans=(ans+(long long)C[cnts][4]*(C[cntu-4][2]+C[cntv-4][2]))%MOD;
            }
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