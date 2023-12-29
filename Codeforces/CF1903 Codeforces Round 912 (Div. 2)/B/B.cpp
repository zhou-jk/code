#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int n;
int a[N][N],c[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        int v=(1<<30)-1;
        for(int j=1;j<=n;j++)
            if(j!=i) v&=a[i][j];
        c[i]=v;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&(c[i]|c[j])!=a[i][j])
            {
                cout<<"NO\n";
                return;
            }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<c[i]<<" ";
    cout<<"\n";
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