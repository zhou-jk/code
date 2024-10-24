#include<iostream>
#include<cstdio>
using namespace std;
int x,n;
void solve()
{
    cin>>x>>n;
    int ans=1;
    for(int i=1;i*i<=x;i++)
        if(x%i==0)
        {
            if(x/i>=n) ans=max(ans,i);
            if(x/(x/i)>=n) ans=max(ans,x/i);
        }
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