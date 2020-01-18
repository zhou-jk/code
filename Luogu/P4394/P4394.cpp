#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100001;
int n;
int a[N];
int tot;
bool dp[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    tot/=2;
    sort(a+1,a+n+1,greater<int>());
    dp[0]=true;
    for(int i=1;i<=n;i++)
        for(int j=tot+a[i];j>=a[i];j--)
            dp[j]|=dp[j-a[i]];
    int ans=0;
    for(int i=tot+1;i<=tot*2;i++)
        if(dp[i]) ans=i;
    printf("%d",ans);
    return 0;
}