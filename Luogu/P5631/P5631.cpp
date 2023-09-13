#include<iostream>
#include<cstdio>
#include<tuple>
#include<stack>
#include<vector>
using namespace std;
const int N=1000005,K=100005;
int n,m,k;
int fa[N],siz[N],h[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return getf(fa[v]);
}
stack<tuple<int,int,int>>stk;
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        if(h[f1]>h[f2]) swap(f1,f2);
        stk.emplace(f1,f2,h[f1]==h[f2]);
        if(h[f1]==h[f2]) h[f2]++;
        siz[f2]+=siz[f1];
        fa[f1]=f2;
    }
    return;
}
bool ans[K];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        vector<pair<int,int>>p;
    }tree[K<<2];
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].p.clear();
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        return;
    }
    void add(int i,int l,int r,pair<int,int> e)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            tree[i].p.emplace_back(e);
            return;
        }
        if(l<=tree[ls].r) add(ls,l,r,e);
        if(r>=tree[rs].l) add(rs,l,r,e);
        return;
    }
    void solve(int i)
    {
        auto pre=make_tuple(-1,-1,-1);
        if(!stk.empty()) pre=stk.top();
        bool flag=false;
        for(auto [u,v]:tree[i].p)
        {
            merge(u,v);
            if(siz[getf(1)]==n)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            for(int k=tree[i].l;k<=tree[i].r;k++)
                ans[k]=true;
        }
        else
        {
            if(tree[i].l==tree[i].r) ans[tree[i].l]=false;
            else
            {
                solve(ls);
                solve(rs);
            }
        }
        while(!stk.empty()&&stk.top()!=pre)
        {
            auto [f1,f2,t]=stk.top();
            stk.pop();
            fa[f1]=f1;
            siz[f2]-=siz[f1];
            if(t) h[f2]--;
        }
        return;
    }
    #undef ls
    #undef rs
}T;
int main()
{
    scanf("%d%d",&n,&m);
    k=100000;
    T.build(1,1,k);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(1<=z-1) T.add(1,1,z-1,make_pair(x,y));
        if(z+1<=k) T.add(1,z+1,k,make_pair(x,y));
    }
    for(int i=1;i<=n;i++)
        fa[i]=i,h[i]=1,siz[i]=1;
    T.solve(1);
    for(int i=1;i<=k;i++)
        if(ans[i])
        {
            printf("%d",i);
            return 0;
        }
    printf("%d",k+1);
    return 0;
}