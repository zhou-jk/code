#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,m;
int b[N],cnt;
struct Chairman_Tree
{
    struct Node
    {
        int ls,rs;
        int cnt;
        long long sum;
    }tree[N*22];
    int rt[N],tot;
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].cnt=0;
        tree[now].sum=0;
        return now;
    }
    void push_up(int i)
    {
        tree[i].cnt=tree[tree[i].ls].cnt+tree[tree[i].rs].cnt;
        tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
        return;
    }
    void build(int &i,int l,int r)
    {
        if(!i) i=new_node();
        if(l==r) return;
        int mid=(l+r)/2;
        build(tree[i].ls,l,mid);
        build(tree[i].rs,mid+1,r);
        return;
    }
    int modify(int i,int l,int r,int u)
    {
        int now=new_node();
        tree[now]=tree[i];
        if(l==r)
        {
            tree[now].cnt++;
            tree[now].sum+=b[u];
            return now;
        }
        int mid=(l+r)/2;
        if(u<=mid) tree[now].ls=modify(tree[now].ls,l,mid,u);
        else tree[now].rs=modify(tree[now].rs,mid+1,r,u);
        push_up(now);
        return now;
    }
    long long query(int u,int v,int l,int r,int k)
    {
        if(l==r) return (long long)k*b[l];
        int mid=(l+r)/2;
        if(k<=tree[tree[v].rs].cnt-tree[tree[u].rs].cnt) return query(tree[u].rs,tree[v].rs,mid+1,r,k);
        else return tree[tree[v].rs].sum-tree[tree[u].rs].sum+query(tree[u].ls,tree[v].ls,l,mid,k-(tree[tree[v].rs].cnt-tree[tree[u].rs].cnt));
    }
}T;
struct Cake
{
    int v,c;
}a[N];
long long ans[N];
void solve(int l,int r,int L,int R)
{
    if(l==r)
    {
        ans[l]=-INF;
        for(int i=L;i+m-1<=l&&i<=R;i++)
            ans[l]=max(ans[l],T.query(T.rt[i-1],T.rt[l],1,cnt,m)-2LL*(a[l].c-a[i].c));
        return;
    }
    int mid=(l+r)/2;
    int k=0;
    ans[mid]=-INF;
    for(int i=L;i+m-1<=mid&&i<=R;i++)
    {
        long long v=T.query(T.rt[i-1],T.rt[mid],1,cnt,m)-2LL*(a[mid].c-a[i].c);
        if(v>ans[mid]) ans[mid]=v,k=i;
    }
    if(k==0)
    {
        for(int i=L;i<=mid;i++)
            ans[i]=-INF;
        solve(mid+1,r,k,R);
        return;
    }
    solve(l,mid,L,k);
    solve(mid+1,r,k,R);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].v,&a[i].c);
    sort(a+1,a+n+1,[=](const Cake &x,const Cake &y){return x.c<y.c;});
    for(int i=1;i<=n;i++)
        b[++cnt]=a[i].v;
    sort(b+1,b+cnt+1);
    cnt=unique(b+1,b+cnt+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i].v=lower_bound(b+1,b+cnt+1,a[i].v)-b;
    T.build(T.rt[0],1,cnt);
    for(int i=1;i<=n;i++)
        T.rt[i]=T.modify(T.rt[i-1],1,cnt,a[i].v);
    solve(1,n,1,n);
    long long res=*max_element(ans+1,ans+n+1);
    printf("%lld",res);
    return 0;
}