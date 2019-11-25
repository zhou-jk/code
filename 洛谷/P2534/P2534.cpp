#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=51;
int a[N];
pair<int,int>b[N];
int pre;
int n;
int ans;
int check()
{
    int tot=0;
    for(int i=1;i<n;i++)
        if(abs(a[i]-a[i+1])!=1) tot++;
    if(a[n]!=n) tot++;
    return tot;
}
void dfs(int step)
{
    if(check()+step>ans) return;
    if(step==ans)
    {
        for(int i=1;i<=n;i++)
            if(a[i]!=i) return;
        printf("%d",ans);
        exit(0);
    }
    for(int i=2;i<=n;i++)
        if(a[i+1]-a[i]!=1)
        {
            for(int j=1;j<=i/2;j++)
                swap(a[j],a[i-j+1]);
            dfs(step+1);
            for(int j=1;j<=i/2;j++)
                swap(a[j],a[i-j+1]);;
        }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        b[i].first=x,b[i].second=i;
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        a[b[i].second]=i;
    for(ans=1;ans<=2*n-2;ans++)
        dfs(0);
    return 0;
}