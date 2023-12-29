#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int suf[N];
int p[N];
int ans[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    iota(p+1,p+n+1,1);
    sort(p+1,p+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    long long sum=0;
    for(int i=1,j=1;i<=n;i++)
    {
        if(j==i) sum+=a[p[j]],j++;
        while(j<=n&&sum>=a[p[j]]) sum+=a[p[j]],j++;
        ans[p[i]]=j-2;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
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