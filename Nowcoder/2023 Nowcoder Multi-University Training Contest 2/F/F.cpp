#include<iostream>
#include<cstdio>
using namespace std;
int n,r,g,b;
void solve()
{
    cin>>n>>r>>g>>b;
    if(n%2==1&&(r+g+b)%2==1) cout<<"Bob\n";
    else cout<<"Alice\n";
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