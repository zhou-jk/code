#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=300005;
int n,d;
int a[N];
int f[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int mx;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].mx=max(tree[ls].mx,tree[rs].mx);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].mx=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mx=v;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l>r) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
        int res=0;
        if(l<=tree[ls].r) res=max(res,query(ls,l,r));
        if(r>=tree[rs].l) res=max(res,query(rs,l,r));
        return res;
    }
    int find_right(int i,int l,int r)
    {
        if(!tree[i].mx) return 0;
        if(tree[i].l==tree[i].r) return tree[i].l;
        int res=0;
        if(r>=tree[rs].l) res=find_right(rs,l,r);
        if(res) return res;
        if(l<=tree[ls].r) return find_right(ls,l,r);
        else return 0;
    }
    int find_left(int i,int l,int r)
    {
        if(!tree[i].mx) return 0;
        if(tree[i].l==tree[i].r) return tree[i].l;
        int res=0;
        if(l<=tree[ls].r) res=find_right(ls,l,r);
        if(res) return res;
        if(r>=tree[rs].l) return find_right(rs,l,r);
        else return 0;
    }
    #undef ls
    #undef rs
}T;
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return fa[v];
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    T.build(1,1,n);
    iota(fa+1,fa+n+1,1);
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&a[id[i]]==a[id[j]]) j++;
        for(int k=i;k<j;k++)
        {
            int pre=T.find_right(1,id[k]-d,id[k]-1);
            f[id[k]]=max(T.query(1,pre?getf(pre):max(id[k]-d,1),id[k]-1)+1,1);
        }
        for(int k=i;k<j;k++)
        {
            T.modify(1,id[k],f[id[k]]);
            int pre=T.find_right(1,id[k]-d,id[k]-1),suf=T.find_left(1,id[k]+1,id[k]+d);
            if(pre) merge(pre,id[k]);
            if(suf) merge(id[k],suf);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}