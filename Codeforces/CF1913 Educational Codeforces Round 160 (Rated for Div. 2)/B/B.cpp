#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
char s[N];
void solve()
{
    string str;
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    int s0=0,s1=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='0') s0++;
        else s1++;
    int c0=0,c1=0;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') c0++;
        else c1++;
        if(c0<=s1&&c1<=s0) ans=min(ans,s1-c0+s0-c1);
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