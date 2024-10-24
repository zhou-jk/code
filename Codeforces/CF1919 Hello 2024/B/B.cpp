#include<iostream>
#include<cstdio>
using namespace std;
int n;
string s;
void solve()
{
    cin>>n;
    cin>>s;
    int cp=0,cn=0;
    for(int i=0;i<n;i++)
        if(s[i]=='+') cp++;
        else cn++;
    int ans=max(cp,cn)-min(cp,cn);
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