#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
const long long INF=4557430888798830399;
int n,k;
int p[N];
int w[N][N];
long long f[N][N][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        for(int j=1;j<=p[i];j++)
            cin>>w[i][j];
        sum+=p[i];
    }
    if(sum<=k)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=w[i][p[i]];
        cout<<ans;
        return 0;
    }
    for(int j=0;j<=k;j++)
        f[0][j][0]=f[0][j][1]=-INF;
    f[0][0][0]=f[0][0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
            f[i][j][0]=f[i-1][j][0];
            f[i][j][1]=f[i-1][j][1];
            if(j>=p[i])
            {
                f[i][j][0]=max(f[i][j][0],f[i-1][j-p[i]][0]+w[i][p[i]]);
                f[i][j][1]=max(f[i][j][1],f[i-1][j-p[i]][1]+w[i][p[i]]);
            }
            for(int l=1;l<p[i];l++)
                if(j>=l) f[i][j][1]=max(f[i][j][1],f[i-1][j-l][0]+w[i][l]);
        }
    long long ans=max(f[n][k][0],f[n][k][1]);
    cout<<ans;
    return 0;
}