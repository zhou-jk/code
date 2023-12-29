#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n,k;
int a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==1&&!is_sorted(a+1,a+n+1)) cout<<"NO\n";
    else cout<<"YES\n";
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