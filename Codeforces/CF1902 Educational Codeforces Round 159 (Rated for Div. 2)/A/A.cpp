#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char s[N];
void solve()
{
    cin>>n;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    for(int i=1;i<=n;i++)
        if(s[i]!='1')
        {
            cout<<"YES\n";
            return;
        }
    cout<<"NO\n";
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