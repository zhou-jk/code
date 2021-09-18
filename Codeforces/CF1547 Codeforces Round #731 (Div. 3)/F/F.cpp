#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N*2];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int d;
    }tree[(N*2)<<2];
    void push_up(int i)
    {
        tree[i].d=__gcd(tree[i*2].d,tree[i*2+1].d);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].d=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].d;
        if(r<=tree[i*2].r) return query(i*2,l,r);
        else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
        else return __gcd(query(i*2,l,r),query(i*2+1,l,r)); 
    }
}T;
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int d=a[1];
    for(int i=2;i<=n;i++)
        d=__gcd(d,a[i]);
    for(int i=1;i<=n;i++)
        a[i]/=d;
    for(int i=1;i<=n;i++)
        a[i+n]=a[i];
    T.build(1,1,n*2);
    int ans=0;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<i) j++;
        while(j<=n*2&&T.query(1,i,j)>1) j++;
        ans=max(ans,j-i);
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}
