#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
int a[N],b[N];
vector<int>pos[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(b+1,b+m+1);
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]!=a[y]?a[x]<a[y]:x>y;});
    for(int i=0;i<=n;i++)
        pos[i].clear();
    for(int i=1,j=1;i<=m;i++)
    {
        while(j<=n&&a[id[j]]<=b[i]) j++;
        pos[id[j-1]].emplace_back(b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        reverse(pos[i].begin(),pos[i].end());
        for(int v:pos[i])
            cout<<v<<" ";
        cout<<a[i]<<" ";
    }
    reverse(pos[0].begin(),pos[0].end());
    for(int v:pos[0])
        cout<<v<<" ";
    cout<<"\n";
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