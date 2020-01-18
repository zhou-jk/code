#include<iostream>
#include<cstdio>
#include<algorithm>
struct Node
{
    int l,w;
}a[5001];
int n,dp[5001],top=0;
using namespace std;
bool cmp(Node a,Node b)
{
    return a.l>b.l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].w);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
	{
        if(a[i].w>dp[top]) dp[++top]=a[i].w; 
        else *lower_bound(dp+1,dp+top+1,a[i].w)=a[i].w;
    }
    printf("%d",top);
    return 0;
}