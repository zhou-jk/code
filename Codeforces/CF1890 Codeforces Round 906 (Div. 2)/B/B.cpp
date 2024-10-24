#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=55;
int n,m;
char s[N],t[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=m;i++)
        cin>>t[i];
    bool flag=true;
    for(int i=1;i<m;i++)
        if(t[i]==t[i+1])
        {
            flag=false;
            break;
        }
    for(int i=1;i<n;i++)
        if(s[i]==s[i+1])
        {
            if(!flag||t[1]==s[i]||t[m]==s[i+1])
            {
                cout<<"No\n";
                return;
            }
        }
    cout<<"Yes\n";
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