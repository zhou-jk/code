#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000005;
int n;
int X[N<<1],cnt;
int x[N],y[N],c[N];
vector<int> g[N<<1];
struct Node
{
    int l, r;
    pair<long long,int>Max;
    long long lazy;
}tree[N<<2];
void push_up(int i)
{
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    return;
}
void push_down(int i)
{
    if(!tree[i].lazy) return;
    tree[i*2].Max.first+=tree[i].lazy;
    tree[i*2].lazy+=tree[i].lazy;
    tree[i*2+1].Max.first+=tree[i].lazy;
    tree[i*2+1].lazy+=tree[i].lazy;
    tree[i].lazy=0;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].Max=make_pair(0,l);
    tree[i].lazy=0;
    if(l==r)
    {
        tree[i].Max=make_pair(X[l],l);
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int l,int r,long long val)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].Max.first+=val;
        tree[i].lazy+=val;
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,val);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
    push_up(i);
    return;
}
pair<long long,int> query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
    push_down(i);
    if(r<=tree[i*2].r) return query(i*2,l,r);
    else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
    else return max(query(i*2,l,r),query(i*2+1,l,r));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&c[i]);
        if(x[i]>y[i]) swap(x[i],y[i]);
        X[++cnt]=x[i],X[++cnt]=y[i];
    }
    sort(X+1,X+cnt+1);
    cnt=unique(X+1,X+cnt+1)-X-1;
    build(1,1,cnt);
    for(int i=1;i<=n;i++)
    {
        x[i]=lower_bound(X+1,X+cnt+1,x[i])-X,y[i]=lower_bound(X+1,X+cnt+1,y[i])-X;
        g[y[i]].push_back(i);
    }
    long long ans=0,ansx=2e9,ansy=2e9;
    for(int i=1;i<=cnt;i++)
    {
        for(auto v:g[i])
            update(1,1,x[v],c[v]);
        pair<long long,int> res=query(1,1,i);
        long long mx=res.first;
        int pos=res.second;
        mx-=X[i];
        if(mx>ans)
        {
            ans=mx;
            ansx=X[pos],ansy=X[i];
        }
    }
    printf("%lld\n",ans);
    printf("%lld %lld %lld %lld",ansx,ansx,ansy,ansy);
    return 0;
}