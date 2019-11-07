#include<iostream>
#include<cstdio>
using namespace std;
int L,n,m;
int a[50001];
bool check(int x)
{
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i]-a[i-1];
        if(ans<x) cnt++;
        else ans=0;
    }
    return cnt<=m;
}
int main()
{
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=L,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}