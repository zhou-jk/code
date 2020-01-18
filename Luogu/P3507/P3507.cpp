#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
int n;
int a[N];
long long dp[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
     	dp[i]=max(dp[i-1],a[i]-dp[i-1]);
    printf("%lld",dp[n]);
    return 0;
}
