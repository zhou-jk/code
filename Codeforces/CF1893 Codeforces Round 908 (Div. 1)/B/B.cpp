#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,k;
int b[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int now=n;
    for(int i=1;i<=min(n,k);i++)
    {
        if(b[now]>n)
        {
            cout<<"No\n";
            return;
        }
        int nxt=now+(n-b[now]);
        if(nxt>n) nxt-=n;
        now=nxt;
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