#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int a[N],b[N],c[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        c[i]=b[i]-a[i];
    for(int i=1;i<=n;i++)
        if(c[i]<0)
        {
            cout<<"NO\n";
            return;
        }
    if(n==1)
    {
        cout<<"YES\n";
        return;
    }
    if(c[1]==0)
    {
        cout<<"NO\n";
        return;
    }
    if(n==2)
    {
        if(c[2]==0) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=c[i];
    if(cnt>=n-1) cout<<"YES\n";
    else cout<<"NO\n";
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
