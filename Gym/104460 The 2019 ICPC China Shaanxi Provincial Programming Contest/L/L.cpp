#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
int l,r;
int calc(int x)
{
    if(x==0) return 0;
    int res=1;
    while(x)
        res=(long long)res*(x%10)%MOD,x/=10;
    return res;
}
void solve()
{
    cin>>l>>r;
    int ans=1;
    if(r-l+1>=10) ans=0;
    else
    {
        for(int i=l;i<=r;i++)
            ans=(long long)ans*calc(i)%MOD;
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