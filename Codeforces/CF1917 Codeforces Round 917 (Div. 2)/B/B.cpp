#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
char s[N];
void solve()
{
    cin>>n;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    bool vis[26]={};
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[s[i]-'a']) ans+=n-i+1;
        vis[s[i]-'a']=true;
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