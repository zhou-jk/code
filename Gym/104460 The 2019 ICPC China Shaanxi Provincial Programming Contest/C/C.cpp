#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int s[N];
void solve()
{
    string str;
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++)
        s[i]=str[i-1]-'0';
    int cnt[10]={};
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cnt[s[i]]++;
        if(s[i]==0) ans+=i-cnt[0];
        else if(s[i]==6) ans+=i-cnt[9];
        else if(s[i]==8) ans+=i-cnt[8];
        else if(s[i]==9) ans+=i-cnt[6];
    }
    if((cnt[6]&&cnt[9])||cnt[0]||cnt[8]) ans++;
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