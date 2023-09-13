#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
long long a[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(m--)
    {
        int op,l,r;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>l>>r>>x;
            for(int i=l;i<=r;i++)
                if(a[i]<x) a[i]=x-a[i];
                else a[i]=x+a[i];
        }
        else
        {
            cin>>l>>r;
            long long ans=0;
            for(int i=l;i<=r;i++)
                ans+=a[i];
            cout<<ans<<"\n";
        }
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