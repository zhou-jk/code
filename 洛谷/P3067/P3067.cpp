#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20,M=100000001;
int n;
struct Node
{
    int val,now;
}a[M+1],b[M+1];
int v[N+1];
int cnta,cntb;
bool book[(1<<N)+1];
bool cmp1(Node x,Node y)
{
    return x.val<y.val;
}
bool cmp2(Node x,Node y)
{
    return x.val>y.val;
}
void dfs(int step,int limit,int now,int sum)
{
    if (step>limit)
    {
        if(limit==n/2) cnta++,a[cnta].val=sum,a[cnta].now=now;
        else cntb++,b[cntb].val=sum,b[cntb].now=now;
        return;
    }
    dfs(step+1,limit,now,sum);
    dfs(step+1,limit,now|(1<<(step-1)),sum+v[step]);
    dfs(step+1,limit,now|(1<<(step-1)),sum-v[step]);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    dfs(1,n/2,0,0);
    dfs(n/2+1,n,0,0);
    sort(a+1,a+1+cnta,cmp1);
    sort(b+1,b+1+cntb,cmp2);
    int ans=0;
    for(int i=1,j=1;i<=cnta&&j<=cntb;i++)
    {
        while(j<=cntb&&-b[j].val<a[i].val) j++;
        for(int k=j;a[i].val+b[k].val==0;k++)
            if(!book[a[i].now|b[k].now]) book[a[i].now|b[k].now]=true,ans++;
    }
    printf("%d",ans-1);
    return 0;
}