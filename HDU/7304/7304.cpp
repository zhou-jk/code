#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3005;
const int MOD=1000000007;
int n;
int x[N];
int p[N];
int b[N],tot;
int f[N][N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    sort(x+1,x+n+1);
    tot=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&x[i]==x[j]) j++;
        b[++tot]=x[i];
    }
    for(int i=1;i<=n;i++)
        p[i]=lower_bound(b+1,b+tot+1,x[i])-b;
    for(int j=1;j<=tot;j++)
        f[1][j]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<p[j];j++)
            f[i][j]=0;
        int sum=0;
        for(int j=p[i-1];j<=tot;j++)
            sum=(sum+f[i-1][j])%MOD;
        for(int j=tot;j>=p[i];j--)
        {
            sum=(sum-f[i-1][j]+MOD)%MOD;
            f[i][j]=(f[i-1][j]+sum)%MOD;
        }

    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=p[i];j<=tot;j++)
            ans=(ans+f[i][j])%MOD;
        cout<<ans<<"\n";
    }
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