#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=300005;
int n;
int a[N];
int pre[N],suf[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        pre[i]=max(pre[i-1],a[i]+n-i);
    for(int i=n;i>=1;i--)
        suf[i]=max(suf[i+1],a[i]+i-1);
    int ans=*max_element(a+1,a+n+1)+n-1;
    for(int i=1;i<=n;i++)
        ans=min(ans,max(a[i],max(pre[i-1],suf[i+1])));
    cout<<ans<<"\n";
    return 0;
}