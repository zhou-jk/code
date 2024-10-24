#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,r;
void solve()
{
    cin>>a>>b>>r;
    long long x=0;
    long long ans=0;
    for(int i=60;i>=0;i--)
        if(((a>>i)&1)!=((b>>i)&1))
        {
            if((a>>i)&1)
            {
                if(ans>0&&(x|(1ll<<i))<=r) ans-=1ll<<i,x|=1ll<<i;
                else ans+=1ll<<i;
            }
            else
            {
                if(ans<0&&(x|(1ll<<i))<=r) ans+=1ll<<i,x|=1ll<<i;
                else ans-=1ll<<i;
            }
        }
    ans=abs(ans);
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