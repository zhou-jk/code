#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50001;
int n;
int q[N],head=1,tail;
long long dp[N];
struct Node
{
    int x,y;
}a[N];
bool cmp(Node a,Node b)
{
    if(a.x!=b.x) return a.x>b.x;
    else return a.y>b.y;
}
double slope(int i,int j)
{
    return (double)(dp[i]-dp[j])/(a[j+1].x-a[i+1].x);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    int m=0;
    for(int i=1;i<=n;i++)
        if(a[i].y>a[m].y) a[++m]=a[i];
    n=m;
    q[++tail]=0;
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&slope(q[head],q[head+1])<=a[i].y) head++;
        dp[i]=dp[q[head]]+(long long)a[q[head]+1].x*a[i].y;
        while(head<tail&&slope(q[tail-1],q[tail])>=slope(q[tail],i)) tail--;
        q[++tail]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}