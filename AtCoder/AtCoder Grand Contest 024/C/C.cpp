#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N];
int pre[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]>=i||a[i]>a[i-1]+1)
        {
            printf("-1");
            return 0;
        }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(pre[i-a[i]+1]) ans+=i-max(pre[i-a[i]+1],i-a[i]);
        else ans+=a[i];
        pre[i-a[i]+1]=i;
    }
    printf("%lld",ans);
    return 0;
}