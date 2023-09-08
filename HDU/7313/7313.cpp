#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
int n;
int a[N];
vector<tuple<int,int,int>>G[N];
int b[N],m;
int c[N];
int st[N][20];
int lg2[N];
int query(int l,int r)
{
    int k=lg2[r-l+1];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
struct Segment_Tree
{
    struct Node
    {
        int ls,rs;
        int mx1,mx2;
    }tree[N*25];
    int tot,rt[N];
    Segment_Tree():tot(0){}
    void clear()
    {
        tot=0;
        for(int i=1;i<=n;i++)
            rt[i]=0;
        return;
    }
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].mx1=tree[now].mx2=0;
        return now;
    }
    void push_up(int i,int l,int r)
    {
        int mid=(l+r)/2;
        tree[i].mx1=max(tree[tree[i].ls].mx1,tree[tree[i].rs].mx1);
        tree[i].mx2=max(tree[i].ls?tree[tree[i].ls].mx2:query(l,mid),tree[i].rs?tree[tree[i].rs].mx2:query(mid+1,r));
        return;
    }
    void add(int &i,int l,int r,int u,int v)
    {
        if(!i)
        {
            i=new_node();
            if(l==r) tree[i].mx1=0,tree[i].mx2=c[l];
        }
        if(l==r)
        {
            tree[i].mx1+=v,tree[i].mx2-=v;
            return;
        }
        int mid=(l+r)/2;
        if(u<=mid) add(tree[i].ls,l,mid,u,v);
        else add(tree[i].rs,mid+1,r,u,v);
        push_up(i,l,r);
        return;
    }
    int merge(int u,int v,int l,int r)
    {
        if(!u) return v;
        if(!v) return u;
        if(l==r)
        {
            tree[u].mx1+=tree[v].mx1;
            tree[u].mx2-=c[l]-tree[v].mx2;
            return u;
        }
        int mid=(l+r)/2;
        tree[u].ls=merge(tree[u].ls,tree[v].ls,l,mid);
        tree[u].rs=merge(tree[u].rs,tree[v].rs,mid+1,r);
        push_up(u,l,r);
        return u;
    }
    int lower_bound_t1(int i,int l,int r,int y)
    {
        if(!i||tree[i].mx1<y) return 0;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=lower_bound_t1(tree[i].rs,mid+1,r,y);
        if(res>0) return res;
        else return lower_bound_t1(tree[i].ls,l,mid,y);
    }
    int lower_bound_t2(int i,int l,int r,int y)
    {
        if((!i?query(l,r):tree[i].mx2)<y) return 0;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=lower_bound_t2(tree[i].rs,mid+1,r,y);
        if(res>0) return res;
        else return lower_bound_t2(tree[i].ls,l,mid,y);
    }
    
}T;
int ans[N];
void dfs(int u,int father)
{
    for(auto [v,w,i]:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        ans[i]=b[max(T.lower_bound_t1(T.rt[v],1,m,w),T.lower_bound_t2(T.rt[v],1,m,w))];
        T.rt[u]=T.merge(T.rt[u],T.rt[v],1,m);
    }
    T.add(T.rt[u],1,m,a[u],1);
    return;
}
void init(int n=1000000)
{
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].emplace_back(y,z,i);
        G[y].emplace_back(x,z,i);
    }
    m=0;
    for(int i=1;i<=n;i++)
        b[++m]=a[i];
    sort(b+1,b+m+1);
    m=unique(b+1,b+m+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    for(int i=1;i<=m;i++)
        c[i]=0;
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    for(int i=1;i<=m;i++)
        st[i][0]=c[i];
    for(int j=1;(1<<j)<=m;j++)
        for(int i=1;i+(1<<j)-1<=m;i++)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    T.clear();
    dfs(1,0);
    for(int i=1;i<n;i++)
        cout<<ans[i]<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}