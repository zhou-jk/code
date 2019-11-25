#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=150001,M=3000001;
int n,m;
int dp[M];
struct Node
{
    int x,y;
}a[N];
bool cmp(Node a,Node b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        m=max(m,a[i].y);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=0,j=1;i<=m;i++)
    {
        dp[i]=max(dp[i],dp[i-1]);
        while(a[j].x==i&&j<=n)
            dp[a[j].y]=max(dp[a[j].y],dp[a[j].x-1]+a[j].y-a[j].x+1),j++;
    }
    printf("%d",*max_element(dp,dp+m+1));
    return 0;
}