#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n,k;
int a[N];
int c[N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    long long ans=0;
    for(int i=1;i<=k;i++)
    {
        int j=0;
        while(j<n&&c[j]>=1) j++;
        ans+=j;
        for(int k=0;k<j;k++)
            c[k]--;
    }
    printf("%lld",ans);
    return 0;
}