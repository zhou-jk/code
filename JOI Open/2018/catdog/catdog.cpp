#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include"catdog.h"
using namespace std;
const int N=100005;
const int MAX=100000;
const int INF=1061109567;
int n;
vector<int>G[N];
int a[N];
int fa[N],son[N];
int siz[N];
void dfs1(int u,int father)
{
    fa[u]=father;
    siz[u]=1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
    return;
}
int dfn[N],Index,id[N];
int top[N],down[N];
void dfs2(int u,int father)
{
    dfn[u]=++Index;
    top[u]=father;
    id[Index]=u;
    if(!son[u])
    {
        down[u]=u;
        return;
    }
    dfs2(son[u],father);
    down[u]=down[son[u]];
    for(int v:G[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
int f[N][2],g[N][2];
void dfs(int u,int father)
{
    f[u][0]=f[u][1]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        f[u][0]+=min(f[v][0],f[v][1]+1);
        f[u][1]+=min(f[v][0]+1,f[v][1]);
    }
    if(a[u]==1) f[u][1]+=MAX;
    else if(a[u]==2) f[u][0]+=MAX;
    return;
}
struct Matrix
{
    int mat[2][2];
    friend Matrix operator*(const Matrix &a,const Matrix &b)
    {
        Matrix c;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                c.mat[i][j]=INF;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    c.mat[i][j]=min(c.mat[i][j],a.mat[i][k]+b.mat[k][j]);
        return c;
    }
};
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        Matrix sum;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[rs].sum*tree[ls].sum;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum.mat[0][0]=g[id[l]][0],tree[i].sum.mat[0][1]=g[id[l]][0]+1;
            tree[i].sum.mat[1][0]=g[id[l]][1]+1,tree[i].sum.mat[1][1]=g[id[l]][1];
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum.mat[0][0]=g[id[u]][0],tree[i].sum.mat[0][1]=g[id[u]][0]+1;
            tree[i].sum.mat[1][0]=g[id[u]][1]+1,tree[i].sum.mat[1][1]=g[id[u]][1];
            return;
        }
        if(u<=tree[ls].r) modify(ls,u);
        else modify(rs,u);
        push_up(i);
        return;
    }
    Matrix query(int i,int u)
    {
        if(tree[i].l==tree[i].r) return tree[i].sum;
        if(u<=tree[ls].r) return query(ls,u);
        else return query(rs,u);
    }
    Matrix query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return query(rs,l,r)*query(ls,l,r);
    }
    #undef ls
    #undef rs
}T;
void modify(int u,int v)
{
    if(a[u]==1) g[u][1]-=MAX;
    else if(a[u]==2) g[u][0]-=MAX;
    a[u]=v;
    if(a[u]==1) g[u][1]+=MAX;
    else if(a[u]==2) g[u][0]+=MAX;
    while(u)
    {
        Matrix pre=T.query(1,dfn[top[u]],dfn[down[u]]);
        Matrix gg=T.query(1,dfn[fa[top[u]]]);
        T.modify(1,dfn[u]);
        Matrix suf=T.query(1,dfn[top[u]],dfn[down[u]]);
        u=fa[top[u]];
        if(!u) break;
        g[u][0]=min(gg.mat[0][0],gg.mat[0][1]),g[u][1]=min(gg.mat[1][0],gg.mat[1][1]);
        g[u][0]-=min(pre.mat[0][0],pre.mat[1][0]),g[u][1]-=min(pre.mat[0][1],pre.mat[1][1]);
        g[u][0]+=min(suf.mat[0][0],suf.mat[1][0]),g[u][1]+=min(suf.mat[0][1],suf.mat[1][1]);
    }
    return;
}
void initialize(int N,vector<int>A,vector<int>B)
{
    n=N;
    for(int i=0;i<n-1;i++)
        G[A[i]].emplace_back(B[i]),G[B[i]].emplace_back(A[i]);
    fill(a+1,a+n+1,3);
    dfs1(1,0);
    dfs2(1,1);
    dfs(1,0);
    for(int u=1;u<=n;u++)
    {
        for(int v:G[u])
        {
            if(v==fa[u]||v==son[u]) continue;
            g[u][0]+=min(f[v][0],f[v][1]+1);
            g[u][1]+=min(f[v][0]+1,f[v][1]);
        }
        if(a[u]==1) g[u][1]+=MAX;
        else if(a[u]==2) g[u][0]+=MAX;
    }
    T.build(1,1,Index);
    return;
}
int get_ans()
{
    Matrix ans=T.query(1,dfn[top[1]],dfn[down[1]]);
    return min({ans.mat[0][0],ans.mat[0][1],ans.mat[1][0],ans.mat[1][1]});
}
int cat(int v)
{
    modify(v,1);
    return get_ans();
}
int dog(int v)
{
    modify(v,2);
    return get_ans();
}
int neighbor(int v)
{
    modify(v,3);
    return get_ans();
}
