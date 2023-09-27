#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,m,k;
int a[N],b[N];
int l[N];
int pos[N];
bool vis[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int mx,sum;
    }tree[N*4];
    void push_up(int i)
    {
        tree[i].mx=max(tree[ls].mx,tree[rs].mx);
        tree[i].sum=tree[ls].sum+tree[rs].sum;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].mx=0;
        if(l==r)
        {
            tree[i].mx=a[l];
            tree[i].sum=1;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v,int w)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mx=v;
            tree[i].sum=w;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v,w);
        else modify(rs,u,v,w);
        push_up(i);
        return; 
    }
    int querypre(int i,int u,int v)
    {
        if(tree[i].mx<=v) return 0;
        if(tree[i].l==tree[i].r) return tree[i].l;
        if(u<=tree[ls].r) return querypre(ls,u,v);
        else
        {
            if(tree[rs].mx<=v) return querypre(ls,u,v);
            int lst=querypre(rs,u,v);
            if(lst!=0) return lst;
            else return querypre(ls,u,v);
        }
    }
    int querysuf(int i,int u,int v)
    {
        if(tree[i].mx<=v) return n+1;
        if(tree[i].l==tree[i].r) return tree[i].l;
        if(u>=tree[rs].l) return querysuf(rs,u,v);
        else
        {
            if(tree[ls].mx<=v) return querysuf(rs,u,v);
            int lst=querysuf(ls,u,v);
            if(lst!=n+1) return lst;
            else return querysuf(rs,u,v);
        }
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        int res=0;
        if(l<=tree[ls].r) res+=query(ls,l,r);
        if(r>=tree[rs].l) res+=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs 
}T;
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=k;i++)
        cin>>l[i];
    for(int i=1;i<=n;i++)
        pos[a[i]]=i,vis[i]=false;
    for(int i=1;i<=m;i++)
        vis[b[i]]=true;
    for(int i=1;i<=m;i++)
        if(pos[b[i]]<pos[b[i-1]])
        {
            cout<<"NO\n";
            return;
        }
    multiset<int,greater<int>>s;
    for(int i=1;i<=k;i++)
        s.insert(l[i]);
    T.build(1,1,n);
    for(int i=1;i<=n;i++)
        if(vis[a[i]]) T.modify(1,i,a[i],1);
    for(int i=n;i>=1;i--)
        if(!vis[i])
        {
            int p=pos[i];
            int l=T.querypre(1,p,i),r=T.querysuf(1,p,i);
            int sum=T.query(1,l+1,r-1);
            auto it=s.lower_bound(sum);
            if(it==s.end())
            {
                cout<<"NO\n";
                return;
            }
            s.erase(it);
            T.modify(1,p,-INF,0);
        }
    cout<<"YES\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}