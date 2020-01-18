#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100001;
struct Node
{
    int a,s;
}a[N];
int n;
int h[N],sum[N],ml[N];
bool cmp(Node x,Node y)
{
    return x.a>y.a;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].s);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].a);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i].a,ml[i]=max(ml[i-1],a[i].s);
    for(int i=n;i>0;i--)
        h[i]=max(h[i+1],a[i].s*2+a[i].a);
    for(int i=1;i<=n;i++)
        printf("%d\n",max(sum[i]+ml[i]*2,sum[i-1]+h[i]));
    return 0;
}