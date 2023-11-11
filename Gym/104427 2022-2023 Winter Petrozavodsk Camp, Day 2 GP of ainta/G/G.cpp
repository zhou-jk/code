#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
int n,m;
int a[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=1;j<=m;j++)
            if(str[j-1]=='W') a[i][j]=0;
            else a[i][j]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i-1][j]^=1,a[i+1][j]^=1,a[i][j-1]^=1,a[i][j+1]^=1;
    cout<<1<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(a[i][j]==0) cout<<2;
            else cout<<3;
        cout<<"\n";
    }
    return 0;
}