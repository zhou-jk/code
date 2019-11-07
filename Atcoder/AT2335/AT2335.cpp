#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100001;
int n;
long long ans[N];
struct Node
{
    int id;
    long long val;
}a[N];
bool cmp(Node x,Node y)
{
    if(x.val!=y.val) return x.val>y.val;
    else return x.id<y.id;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i].val),a[i].id=i;
    sort(a+1,a+n+1,cmp);
    int p=1;
    for(int i=2;i<=n;i++)
    {
        while(a[i].val==a[i-1].val) i++;
        ans[a[p].id]+=(a[p].val-a[i].val)*(i-1);
        if(a[i].id>a[p].id) a[p].val=a[i].val;
        else p=i;
    }
    ans[a[p].id]+=a[p].val*n;
    for(int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);
    return 0;
}