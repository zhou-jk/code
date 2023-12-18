#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300005;
int n;
int a[N],b[N];
int v[N];
bool check(int x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        if(a[i]>=x) sum++;
    for(int i=1;i<=n;i++)
        v[i]=(b[i]>=x)-(a[i]>=x);
    int s=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        s=max(s,0);
        s+=v[i];
        ans=max(ans,s);
    }
    return sum+ans>=(n+1)/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    int l=1,r=max(*max_element(a+1,a+n+1),*max_element(b+1,b+n+1)),ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}