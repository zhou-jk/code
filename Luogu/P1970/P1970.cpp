#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
int a[N];
int dp[N],f[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[1]=f[1]=1;
    for(int i=2;i<=n;i++)
        if(a[i]>a[i-1]) dp[i]=max(dp[i-1],f[i-1]+1),f[i]=f[i-1];
        else if(a[i]<a[i-1]) dp[i]=dp[i-1],f[i]=max(dp[i-1]+1,f[i-1]);
        else dp[i]=dp[i-1],f[i]=f[i-1];
    printf("%d",max(dp[n],f[n]));
    return 0;
}