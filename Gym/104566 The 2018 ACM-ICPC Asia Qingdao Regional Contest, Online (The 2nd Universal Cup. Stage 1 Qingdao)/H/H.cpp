#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
char s[N];
void solve()
{
    string str;
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    long long ans=0;
    for(int q=1;q<=n;q++)
        ans+=(long long)q*(q+1)/2;
    for(int i=1;i<=n;i++)
    {
        if(i>1&&s[i]==s[i-1]) ans+=(long long)(i-1)*(n-i+1);
        if(s[i]=='0') ans+=n-i+1;
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