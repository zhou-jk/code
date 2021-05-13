#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=100005;
int n,m;
int a[N];
struct Chairman_Tree
{
    struct Node
    {
        int ls,rs;
        int sum;
    }tree[N*40];
    int rt[N],tot;
    int new_node()
    {
        return ++tot;
    }
    void push_up(int i)
    {
        tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
        return;
    }
    int modify(int i,int l,int r,int u,int v)
    {
        int now=new_node();
        tree[now]=tree[i];
        if(l==r)
        {
            tree[now].sum+=v;
            return now;
        }
        int mid=(l+r)/2;
        if(u<=mid) tree[now].ls=modify(tree[now].ls,l,mid,u,v);
        else tree[now].rs=modify(tree[now].rs,mid+1,r,u,v);
        push_up(now);
        return now;
    }
    int query(int i,int l,int r,int L,int R)
    {
        if(!i) return 0;
        if(L<=l&&r<=R) return tree[i].sum;
        int mid=(l+r)/2;
        int res=0;
        if(L<=mid) res+=query(tree[i].ls,l,mid,L,R);
        if(R>mid) res+=query(tree[i].rs,mid+1,r,L,R);
        return res;
    }
}T;
stack<int>s;
int rt;
int ls[N],rs[N];
void insert(int i)
{
    int j=0;
    while(!s.empty()&&a[i]>a[s.top()]) j=s.top(),s.pop();
    if(s.empty()) rt=i;
    else rs[s.top()]=i;
    ls[i]=j;
    s.emplace(i);
    return;
}
int l[N],r[N];
long long ans;
void dfs(int u)
{
    l[u]=r[u]=u;
    if(ls[u]) dfs(ls[u]),l[u]=l[ls[u]];
    if(rs[u]) dfs(rs[u]),r[u]=r[rs[u]];
    if(u-l[u]<r[u]-u)
    {
        for(int i=l[u];i<=u;i++)
            ans+=T.query(T.rt[r[u]],1,m,1,a[u]/a[i])-T.query(T.rt[u-1],1,m,1,a[u]/a[i]);
    }
    else
    {
        for(int i=u;i<=r[u];i++)
            ans+=T.query(T.rt[u],1,m,1,a[u]/a[i])-T.query(T.rt[l[u]-1],1,m,1,a[u]/a[i]);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    m=1000000000;
    for(int i=1;i<=n;i++)
        T.rt[i]=T.modify(T.rt[i-1],1,m,a[i],1);
    for(int i=1;i<=n;i++)
        insert(i);
    dfs(rt);
    printf("%lld",ans);
    return 0;
}