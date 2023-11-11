#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
char s[N],t[N];
int a[N];
void solve()
{
    cin>>n;
    cin>>s;
    cin>>t;
    for(int i=0;i<n;i++)
        if(s[i]==t[i]) a[i]=1;
        else a[i]=0;
    int cnt=0;
    for(int i=0,j=0;i<n;i=j)
    {
        while(j<n&&a[i]==a[j]) j++;
        if(a[i]) continue;
        cnt++;
    }
    long long ans=0;
    if(cnt==0) ans=(long long)n*(n-1)/2+n;
    else if(cnt==1) ans=2*(n-1);
    else if(cnt==2) ans=6;
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