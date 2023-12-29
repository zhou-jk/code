#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n,x;
int a[N],b[N];
int res[N];
void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    sort(b+1,b+n+1);
    for(int i=1;i<=x;i++)
        if(a[id[n-x+i]]<=b[i])
        {
            cout<<"NO\n";
            return;
        }
        else res[id[n-x+i]]=b[i];
    for(int i=x+1;i<=n;i++)
        if(a[id[i-x]]>b[i])
        {
            cout<<"NO\n";
            return;
        }
        else res[id[i-x]]=b[i];
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
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