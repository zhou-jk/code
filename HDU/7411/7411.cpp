#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n;
int v[N],w[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>w[i];
    sort(v+1,v+n+1);
    sort(w+1,w+n+1);
    for(int i=1;i<=n;i++)
        if(w[i]>v[i])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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