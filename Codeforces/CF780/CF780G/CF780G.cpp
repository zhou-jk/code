#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int N=100002;
const int MOD=1000000007;
int n,h,w;
struct Seg
{
    int l,r,h,m,ans;
}a[N];
bool cmp(Seg a,Seg b)
{
    return a.h<b.h;
}
struct Node
{
    int l,r;
    stack<int>s;
}tree[N<<2];
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].s.push(1);
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void update(int i,int l,int r,int d)
{
    if(r<tree[i].l||l>tree[i].r) return;
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        while(a[tree[i].s.top()].m<a[d].m) tree[i].s.pop();
        tree[i].s.push(d);
        return;
    }
    if(l<=tree[i*2].r) update(i*2,l,r,d);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,d);
    return;
}
int query(int i,int u,int d)
{
    while(a[tree[i].s.top()].m<d) tree[i].s.pop();
    int ans=tree[i].s.top();
    if(tree[i].l==tree[i].r) return ans;
    if(u<=tree[i*2].r) return max(ans,query(i*2,u,d));
    else return max(ans,query(i*2+1,u,d));
}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++)
    {
        int s;
        scanf("%d%d%d%d",&a[i].h,&a[i].l,&a[i].r,&s);
        a[i].m=min(a[i].h+s,h+1);
    }
    n++,a[n].h=0,a[n].l=1,a[n].r=w,a[n].m=1e9+1;
    sort(a+1,a+n+1,cmp);
    a[1].ans=1;
    build(1,1,w);
    for(int i=2;i<=n;i++)
    {
        if(a[i].l==1) a[i].ans=2*a[query(1,a[i].r+1,a[i].h)].ans%MOD;
        else if(a[i].r==w) a[i].ans=2*a[query(1,a[i].l-1,a[i].h)].ans%MOD;
        else a[i].ans=(a[query(1,a[i].l-1,a[i].h)].ans+a[query(1,a[i].r+1,a[i].h)].ans)%MOD;
        update(1,a[i].l,a[i].r,i);
    }
    long long res=0;
    for(int i=1;i<=w;i++)
        res=(res+a[query(1,i,h+1)].ans)%MOD;
    printf("%lld",res);
    return 0;
}