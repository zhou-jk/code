#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
const int N=200005;
int n;
int a[N];
long long sum[N];
unordered_map<long long,int>pre;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    long long ans=0;
    pre[0]++;
    for(int i=1;i<=n;i++)
        ans+=pre[sum[i]],pre[sum[i]]++;
    printf("%lld",ans);
    return 0;
}