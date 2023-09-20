#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
string s;
int cnt[26];
void solve()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<26;i++)
        cnt[i]=0;
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    int ans=n-*max_element(cnt,cnt+26);
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