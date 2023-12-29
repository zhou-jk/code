#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,k;
int a[N][N];
void solve()
{
    cin>>n>>k;
    if(n==k)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(i==j) cout<<1<<" ";
                else cout<<0<<" ";
            cout<<"\n";
        }
        return;
    }
    bool rev=false;
    if(k>n*n/2) rev=true,k=n*n-k;
    if(k%2!=0||k==2)
    {
        cout<<"No\n";
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    if(k%4==0)
    {
        int i=1,j=1;
        for(int t=1;t<=k/4;t++)
        {
            a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=1;
            j+=2;
            if(j+1>=n) i+=2,j=1;
        }
    }
    else if(k%4==2)
    {
        a[1][1]=1,a[1][2]=1,a[1][3]=0;
        a[2][1]=1,a[2][2]=0,a[2][3]=1;
        a[3][1]=0,a[3][2]=1,a[3][3]=1;
        int i=1,j=5;
        for(int t=1;t<=(k-6)/4;t++)
        {
            a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=1;
            j+=2;
            if(j+1>=n)
            {
                i+=2;
                if(i+1<=4) j=5;
                else j=1;
            }
        }
    }
    if(rev)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]^=1;
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
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