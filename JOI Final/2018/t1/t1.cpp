#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k;
int t[N];
int a[N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    long long ans=n;
    for(int i=1;i<n;i++)
        a[i]=t[i+1]-t[i]-1,ans+=a[i];
    sort(a+1,a+n,greater<int>());
    for(int i=1;i<k;i++)
        ans-=a[i];
    printf("%lld",ans);
    return 0;
}