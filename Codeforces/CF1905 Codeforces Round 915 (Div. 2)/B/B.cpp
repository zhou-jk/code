#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n;
int deg[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        deg[i]=0;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        deg[x]++,deg[y]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(deg[i]==1) cnt++;
    cout<<(cnt+1)/2<<"\n";
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