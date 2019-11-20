#include<iostream>
#include<cstdio>
using namespace std;
const int N=1001;
int n,c;
int a[N];
long long sum[N];
int ans;
void dfs(int u,int val)
{
    if(sum[u]+val<=ans)return;
    ans=max(ans,val);
    for(int i=u;i>=1;i--)
        if(val+a[i]<=c) dfs(i-1,val+a[i]);
    return;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    while(a[n]>c) n--;
    dfs(n,0);
    printf("%d",ans);
    return 0;
}