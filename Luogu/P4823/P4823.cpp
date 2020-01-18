#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5001;
int n,h;
int dp[N];
struct Node
{
    int a,b;
}p[N];
bool cmp(Node x,Node y)
{
    return x.a+x.b<y.a+y.b;
}
int main()
{
    memset(dp,-63,sizeof(dp));
    scanf("%d",&n);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].a,&p[i].b);
        dp[0]+=p[i].a;
    }
    scanf("%d",&h);
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=i;j>=1;j--)
            if(dp[j-1]+p[i].b>=h) dp[j]=max(dp[j],dp[j-1]-p[i].a);
    for(int i=n;i>=0;i--)
        if(dp[i]>=0)
        {
            printf("%d",i);
            return 0;
        }
    return 0;
}