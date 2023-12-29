#include<iostream>
#include<cstdio>
#include<set>
#include<tuple>
using namespace std;
const int N=100005;
int n;
int a[N];
long long p[N],z[N];
struct Chairman_Tree
{
    struct Node
    {
        int ls,rs;
        int sum;
    }tree[N<<5];
    int rt[N],tot;
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].sum=0;
        return now;
    }
    void clear()
    {
        tot=0;
        for(int i=1;i<=n;i++)
            rt[i]=0;
        return;
    }
    void push_up(int i)
    {
        tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
        return;
    }
    void build(int &i,int l,int r)
    {
        i=new_node();
        if(l==r)
        {
            tree[i].sum=0;
            return;
        }
        int mid=(l+r)/2;
        build(tree[i].ls,l,mid);
        build(tree[i].rs,mid+1,r);
        return;
    }
    int modify(int i,int l,int r,int u,int v)
    {
        int now=++tot;
        tree[now]=tree[i];
        if(l==r)
        {
            tree[now].sum+=v;
            return now;
        }
        int mid=(l+r)/2;
        if(u<=mid) tree[now].ls=modify(tree[i].ls,l,mid,u,v);
        else tree[now].rs=modify(tree[i].rs,mid+1,r,u,v);
        push_up(now);
        return now;
    }
    int query(int i,int l,int r,int L,int R)
    {
        if(L>R) return 0;
        if(!i) return 0;
        if(L>R) return 0;
        if(L<=l&&r<=R) return tree[i].sum;
        int mid=(l+r)/2;
        int res=0;
        if(L<=mid) res+=query(tree[i].ls,l,mid,L,R);
        if(R>mid) res+=query(tree[i].rs,mid+1,r,L,R);
        return res;
    }
}T;
set<tuple<int,int,long long>>seg;
multiset<long long,greater<long long>>S;
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    T.clear();
    T.build(T.rt[0],1,n);
    for(int i=1;i<=n;i++)
        T.rt[i]=T.modify(T.rt[i-1],1,n,a[i],1);
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=T.query(T.rt[i-1],1,n,a[i]+1,n);
    z[0]=ans;
    seg.clear();
    seg.insert(make_tuple(1,n,ans));
    S.insert(ans);
    for(int i=1;i<=n;i++)
    {
        p[i]^=z[i-1];
        set<tuple<int,int,long long>>::iterator it=seg.lower_bound(make_tuple(p[i],n+1,0));
        it--;
        auto [l1,r2,sum]=*it;
        S.erase(S.lower_bound(sum));
        seg.erase(it);
        int r1=p[i]-1,l2=p[i]+1;
        if(l1<=r1) sum-=T.query(T.rt[r1],1,n,a[p[i]]+1,n)-T.query(T.rt[l1-1],1,n,a[p[i]]+1,n);
        if(l2<=r2) sum-=T.query(T.rt[r2],1,n,1,a[p[i]]-1)-T.query(T.rt[l2-1],1,n,1,a[p[i]]-1);
        long long res1=0,res2=0;
        if(r2-l2+1<r1-l1+1)
        {
            if(l2<=r2)
            {
                if(l1<=r1)
                {
                    for(int i=l2;i<=r2;i++)
                        sum-=T.query(T.rt[r1],1,n,a[i]+1,n)-T.query(T.rt[l1-1],1,n,a[i]+1,n);
                }
                for(int i=l2;i<=r2;i++)
                    res2+=T.query(T.rt[i-1],1,n,a[i]+1,n)-T.query(T.rt[l2-1],1,n,a[i]+1,n);
            }
            res1=sum-res2;
        }
        else
        {
            if(l1<=r1)
            {
                if(l2<=r2)
                {
                    for(int i=l1;i<=r1;i++)
                        sum-=T.query(T.rt[r2],1,n,1,a[i]-1)-T.query(T.rt[l2-1],1,n,1,a[i]-1);
                }
                for(int i=l1;i<=r1;i++)
                    res1+=T.query(T.rt[i-1],1,n,a[i]+1,n)-T.query(T.rt[l1-1],1,n,a[i]+1,n);
            }
            res2=sum-res1;
        }
        if(l1<=r1) seg.insert(make_tuple(l1,r1,res1)),S.insert(res1);
        if(l2<=r2) seg.insert(make_tuple(l2,r2,res2)),S.insert(res2);
        if(!S.empty()) z[i]=*S.begin();
    }
    for(int i=0;i<n;i++)
        if(i<n-1) printf("%lld ",z[i]);
        else printf("%lld\n",z[i]);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}