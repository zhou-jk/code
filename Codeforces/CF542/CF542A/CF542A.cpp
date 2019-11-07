#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,m,tot;
struct Node
{
    int p,id;
    bool operator < (const Node &b) const
    {
        return p<b.p;
    }
};
struct Seg
{
    int l,r,w,id;
    bool operator < (const Seg &b) const
    {
        return r<b.r;
    }
};
Node a[200001],b[200001];
Seg c[200001];
int rnk[200001],x[800001];
template<typename T>
struct Segment_Tree
{
    T val[3200001];
    void push_up(int i)
    {
        val[i]=max(val[i*2],val[i*2+1]);
        return;
    }
    void update(int i,int l,int r,int u,T v)
    {
        if(l==r)
        {
            val[i]=max(val[i],v);
            return;
        }
        int mid=(l+r)/2;
        if(u<=mid) update(i*2,l,mid,u,v);
        if(u>mid) update(i*2+1,mid+1,r,u,v);
        push_up(i);
        return;
    }
    T query(int i,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R) return val[i];
        T res;
        int mid=(l+r)/2;
        if(L<=mid) res=max(res,query(i*2,l,mid,L,R));
        if(R>mid) res=max(res,query(i*2+1,mid+1,r,L,R));
        return res;
    }
};
Segment_Tree <pair<int,int> > t1,t2;
set<pair<int,int> > Tree;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        a[i]=(Node){l,i},b[i]=(Node){r,i};
        x[++tot]=l,x[++tot]=r;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&c[i].l,&c[i].r,&c[i].w);
        x[++tot]=c[i].l,x[++tot]=c[i].r;
        c[i].id=i;
    }
    sort(x+1,x+tot+1);
    for(int i=1;i<=n;i++)
        a[i].p=lower_bound(x+1,x+tot+1,a[i].p)-x,b[i].p=lower_bound(x+1,x+tot+1,b[i].p)-x;
    for(int i=1;i<=m;i++)
        c[i].l=lower_bound(x+1,x+tot+1,c[i].l)-x,c[i].r=lower_bound(x+1,x+tot+1,c[i].r)-x;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+m+1);
    for(int i=1;i<=n;i++)
        rnk[a[i].id]=i;
    long long ans=0;
    int resl,resr;
    for(int i=1,j=1,k=1;i<=m;i++)
    {
        for(;j<=n&&a[j].p<=c[i].r;j++)
            Tree.insert(make_pair(x[a[j].p],a[j].id));
        for(;k<=n&&b[k].p<=c[i].r;k++)
        {
            int j=rnk[b[k].id];
            Tree.erase(make_pair(x[a[j].p],a[j].id));
            t1.update(1,1,tot,a[j].p,{x[b[k].p]-x[a[j].p],a[j].id});
            t2.update(1,1,tot,a[j].p,{x[b[k].p],a[j].id});
        }
        long long len=0;
        int z=0;
        if(!Tree.empty())
        {
            int t=x[c[i].r]-max(x[c[i].l],Tree.begin()->first);
            if(t>len)
                len=t,z=Tree.begin()->second;
        }
        pair<int,int> p;
        p=t1.query(1,1,tot,c[i].l,c[i].r);
        if(p.first>len) len=p.first,z=p.second;
        p=t2.query(1,1,tot,1,c[i].l);
        if(p.first-x[c[i].l]>len) len=p.first-x[c[i].l],z=p.second;
        if(len*c[i].w>ans)
        {
            ans=len*c[i].w;
            resl=z,resr=c[i].id;
        }
    }
    printf("%lld\n",ans);
    if(ans) printf("%d %d\n",resl,resr);
    return 0;
}