#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
char s[N];
void solve()
{
    cin>>n;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    vector<int>sub;
    for(int i=1;i<=n;i++)
    {
        while(!sub.empty()&&s[sub.back()]<s[i]) sub.pop_back();
        sub.emplace_back(i);
    }
    int l=sub.size();
    int ans=l;
    for(int j=0;j<l;j++)
        if(s[sub[0]]==s[sub[j]]) ans--;
        else break;
    for(int i=0;i<l/2;i++)
        swap(s[sub[i]],s[sub[l-i-1]]);
    if(!is_sorted(s+1,s+n+1))
    {
        cout<<-1<<"\n";
        return;
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