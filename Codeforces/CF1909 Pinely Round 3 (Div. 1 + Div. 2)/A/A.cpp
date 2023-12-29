#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
void solve()
{
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<0) res|=1<<0;
        if(x>0) res|=1<<1;
        if(y<0) res|=1<<2;
        if(y>0) res|=1<<3; 
    }
    int c=__builtin_popcount(res);
    if(c>3) cout<<"NO\n";
    else cout<<"YES\n";
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