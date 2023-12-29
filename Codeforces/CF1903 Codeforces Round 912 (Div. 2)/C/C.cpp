#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
long long suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    suf[n+1]=0;
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];
    long long sum=0;
    for(int i=n;i>=1;i--)
        if(sum+a[i]>suf[i+1]+sum+a[i]) sum+=a[i];
        else sum+=suf[i+1]+a[i];
    cout<<sum<<"\n";
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