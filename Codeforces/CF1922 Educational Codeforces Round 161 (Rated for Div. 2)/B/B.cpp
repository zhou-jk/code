#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n;
int a[N];
int c[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
        c[i]=0;
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    long long ans=0;
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        if(c[i]>=2) ans+=(long long)c[i]*(c[i]-1)/2*sum;
        if(c[i]>=3) ans+=(long long)c[i]*(c[i]-1)*(c[i]-2)/6;
        sum+=c[i];
    }
    cout<<ans<<"\n";
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