#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<int>s={n},t={n};
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=min(s.back(),t.back())||a[i]>max(s.back(),t.back()))
        {
            if(s.back()<t.back()) s.emplace_back(a[i]);
            else t.emplace_back(a[i]);
        }
        else
        {
            if(s.back()<t.back()) t.emplace_back(a[i]);
            else s.emplace_back(a[i]);
        }
    }
    int ans=0;
    for(int i=1;i+1<(int)s.size();i++)
        if(s[i]<s[i+1]) ans++;
    for(int i=1;i+1<(int)t.size();i++)
        if(t[i]<t[i+1]) ans++;
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