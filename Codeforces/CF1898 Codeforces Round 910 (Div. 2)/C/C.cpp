#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=25;
int n,m,k;
int r[N][N],c[N][N];
void solve()
{
    cin>>n>>m>>k;
    if(k<n-1+m-1)
    {
        cout<<"NO\n";
        return;
    }
    if((k-(n-1)-(m-1))%2!=0)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    c[1][1]=0;
    r[1][1]=r[2][1]=c[1][1]^1,c[1][2]=c[1][1];
    if((k-(n-1)-(m-1))%4==2) c[2][1]=c[1][1];
    else c[2][1]=c[1][1]^1;
    for(int i=3;i<=n-1;i++)
        c[i][1]=c[i-1][1]^1;
    c[1][1]=c[1][2]=r[1][1]^1;
    r[n][1]=c[n-1][1]^1;
    for(int j=2;j<=m-1;j++)
        r[n][j]=r[n][j-1]^1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-1;j++)
            if(r[i][j]) cout<<"R ";
            else cout<<"B ";
        cout<<"\n";
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=m;j++)
            if(c[i][j]) cout<<"R ";
            else cout<<"B ";
        cout<<"\n";
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
