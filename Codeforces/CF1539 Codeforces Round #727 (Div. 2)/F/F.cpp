#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
int a[N];
int sum[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int tag;
        int mx,mi;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
        tree[i].mi=min(tree[i*2].mi,tree[i*2+1].mi);
        return;
    }
    void build(int i,int l,int r,int op)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        if(l==r)
        {
            if(tree[i].l%2==op) tree[i].mi=tree[i].mx=sum[l];
            else tree[i].mi=INF,tree[i].mx=-INF;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid,op);
        build(i*2+1,mid+1,r,op);
        push_up(i);
        return;
    }
    void add(int i,int v)
    {
        if(tree[i].mx==-INF||tree[i].mi==INF) return;
        tree[i].tag+=v;
        tree[i].mx+=v,tree[i].mi+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(i*2,tree[i].tag);
        add(i*2+1,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    int querymx(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
        push_down(i);
        int res=-INF;
        if(l<=tree[i*2].r) res=max(res,querymx(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,querymx(i*2+1,l,r));
        return res;
    }
    int querymi(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mi;
        push_down(i);
        int res=INF;
        if(l<=tree[i*2].r) res=min(res,querymi(i*2,l,r));
        if(r>=tree[i*2+1].l) res=min(res,querymi(i*2+1,l,r));
        return res;
    }
}T[2];
vector<int>pos[N];
int ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+1;
    T[0].build(1,0,n,0);
    T[1].build(1,0,n,1);
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    for(int v=1;v<=n;v++)
    {
        for(int i:pos[v])
        {
            T[0].modify(1,i,n,-1);
            T[1].modify(1,i,n,-1);
            int v;
            v=(T[1].querymx(1,i,n)-T[0].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,i,n)-T[1].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[1].querymx(1,0,i-1)-T[0].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,0,i-1)-T[1].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            T[0].modify(1,i,n,1);
            T[1].modify(1,i,n,1);
            v=(T[1].querymx(1,i,n)-T[1].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[1].querymx(1,0,i-1)-T[1].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,i,n)-T[0].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,0,i-1)-T[0].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
        }
        for(int i:pos[v])
        {
            T[0].modify(1,i,n,-2);
            T[1].modify(1,i,n,-2);
        }
        for(int i:pos[v])
        {
            T[0].modify(1,i,n,1);
            T[1].modify(1,i,n,1);
            int v;
            v=(T[1].querymx(1,i,n)-T[0].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,i,n)-T[1].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[1].querymx(1,0,i-1)-T[0].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,0,i-1)-T[1].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            T[0].modify(1,i,n,-1);
            T[1].modify(1,i,n,-1);
            T[0].modify(1,i,n,2);
            T[1].modify(1,i,n,2);
            v=(T[1].querymx(1,i,n)-T[1].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[1].querymx(1,0,i-1)-T[1].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,i,n)-T[0].querymi(1,0,i-1))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            v=(T[0].querymx(1,0,i-1)-T[0].querymi(1,i,n))/2;
            if(v<=INF) ans[i]=max(ans[i],v);
            T[0].modify(1,i,n,-2);
            T[1].modify(1,i,n,-2);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}