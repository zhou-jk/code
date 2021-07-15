#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,Q;
int h[N],a[N],b[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int minc;
        int maxc,maxd;
        int tagmin,tagmax;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].minc=min(tree[i*2].minc,tree[i*2+1].minc);
        tree[i].maxc=max(tree[i*2].maxc,tree[i*2+1].maxc);
        tree[i].maxd=max(tree[i*2].maxd,tree[i*2+1].maxd);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tagmin=INF,tree[i].tagmax=-INF;
        if(l==r)
        {
            tree[i].minc=INF;
            tree[i].maxc=-INF;
            tree[i].maxd=-INF;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int h)
    {
        if(tree[i].minc!=INF) tree[i].maxd=max(tree[i].maxd,-tree[i].minc+h);
        if(tree[i].maxc!=-INF) tree[i].maxd=max(tree[i].maxd,tree[i].maxc-h);
        tree[i].tagmin=min(tree[i].tagmin,h);
        tree[i].tagmax=max(tree[i].tagmax,h);
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tagmin!=INF)
        {
            add(i*2,tree[i].tagmin);
            add(i*2+1,tree[i].tagmin);
            tree[i].tagmin=INF;
        }
        if(tree[i].tagmax!=-INF)
        {
            add(i*2,tree[i].tagmax);
            add(i*2+1,tree[i].tagmax);
            tree[i].tagmax=-INF;
        }
        return;
    }
    void modify(int i,int l,int r,int h)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,h);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,h);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,h);
        push_up(i);
        return;
    }
    void modify(int i,int u,int c)
    {
        if(tree[i].l==tree[i].r)
        {
            if(c==0) tree[i].minc=INF,tree[i].maxc=-INF;
            else tree[i].minc=tree[i].maxc=c;
            return;
        }
        push_down(i);
        if(u<=tree[i*2].r) modify(i*2,u,c);
        else modify(i*2+1,u,c);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].maxd;
        push_down(i);
        int res=-INF;
        if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
        return res;
    }
}T;
vector<pair<int,int>>q[N];
vector<pair<int,int>>pos[N];
int ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&h[i],&a[i],&b[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[r].emplace_back(l,i);
    }
    for(int i=1;i<=n;i++)
    {
        if(i+a[i]<=n) pos[i+a[i]].emplace_back(i,h[i]);
        if(i+b[i]+1<=n) pos[i+b[i]+1].emplace_back(i,0);
    }
    T.build(1,1,n);
    for(int j=1;j<=n;j++)
    {
        for(auto [i,hi]:pos[j])
            T.modify(1,i,hi);
        if(j-a[j]>=1) T.modify(1,j-b[j],j-a[j],h[j]);
        for(auto [l,i]:q[j])
            ans[i]=T.query(1,l,j);
    }
    for(int i=1;i<=Q;i++)
        if(ans[i]<=-INF) printf("-1\n");
        else printf("%d\n",ans[i]);
    return 0;
}