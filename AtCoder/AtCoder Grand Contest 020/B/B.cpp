#include<iostream>
#include<cstdio>
using namespace std;
const int K=100005;
int k;
int a[K];
int main()
{
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    long long l=2,r=2;
    for(int i=k;i>=1;i--)
        l=(l-1)/a[i]*a[i]+a[i],r=(r/a[i]+1)*a[i]-1;
    if(l>r)
    {
        printf("-1");
        return 0;
    }
    printf("%lld %lld",l,r);
    return 0;
}