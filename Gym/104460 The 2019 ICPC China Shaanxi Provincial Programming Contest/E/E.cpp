#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,k;
char s[N];
bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='1') cnt++,i=i+x-1;
    return cnt<=k;
}
void solve()
{
    cin>>n>>k;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
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