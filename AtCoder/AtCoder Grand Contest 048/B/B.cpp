#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    vector<int>odd,even;
    for(int i=1;i<=n;i++)
        if(i&1) odd.emplace_back(a[i]-b[i]);
        else even.emplace_back(a[i]-b[i]);
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=b[i];
    sort(odd.begin(),odd.end(),greater<int>());
    sort(even.begin(),even.end(),greater<int>());
    for(int i=0;i<n/2;i++)
        if(odd[i]+even[i]>=0) ans+=odd[i]+even[i];
    printf("%lld",ans);
    return 0;
}