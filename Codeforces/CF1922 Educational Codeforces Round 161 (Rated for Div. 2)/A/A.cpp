#include<iostream>
#include<cstdio>
using namespace std;
int n;
string a,b,c;
void solve()
{
    cin>>n;
    cin>>a>>b>>c;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(islower(a[i])&&toupper(a[i])==b[i])
        {
            cout<<"NO\n";
            return;
        }
        else if(islower(b[i])&&toupper(b[i])==a[i])
        {
            cout<<"NO\n";
            return;
        }
        if(islower(a[i])&&islower(b[i])&&c[i]!=a[i]&&c[i]!=b[i]) flag=true;
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
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