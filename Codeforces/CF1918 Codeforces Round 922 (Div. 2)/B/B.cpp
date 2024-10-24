#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    for(int i=1;i<=n;i++)
        cout<<a[id[i]]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)
        cout<<b[id[i]]<<" ";
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