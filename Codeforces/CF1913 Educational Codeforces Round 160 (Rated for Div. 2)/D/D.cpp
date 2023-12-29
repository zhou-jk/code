#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=300005;
const int INF=1061109567;
const int MOD=998244353;
int n;
int p[N];
int f[N],sum[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    stack<int>s;
    int ss=0;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&p[s.top()]>=p[i])
        {
            ss=(ss-f[s.top()]+MOD)%MOD;
            s.pop();
        }
        if(s.empty()) f[i]=(sum[i-1]+1)%MOD;
        else f[i]=(sum[i-1]-sum[s.top()]+MOD)%MOD;
        f[i]=(f[i]+ss)%MOD;
        sum[i]=(sum[i-1]+f[i])%MOD;
        s.emplace(i);
        ss=(ss+f[i])%MOD;
    }
    int ans=0;
    while(!s.empty())
    {
        if(s.top()>=1) ans=(ans+f[s.top()])%MOD;
        s.pop();
    }
    cout<<ans<<"\n";
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