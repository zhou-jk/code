#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n,q;
int a[N];
long long sum[N];
int pre[N],suf[N];
struct Operation
{
    int a,b,c;
};
vector<Operation>op;
struct Query
{
    int l,r,id;
};
vector<Query>pos[N];
long long ans[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        long long sum,tag;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[ls].sum+tree[rs].sum;
        return;
    }
    void add(int i,long long v)
    {
        tree[i].tag+=v;
        tree[i].sum+=(tree[i].r-tree[i].l+1)*v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(ls,tree[i].tag);
        add(rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum=tree[i].tag=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,long long v)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[ls].r) modify(ls,l,r,v);
        if(r>=tree[rs].l) modify(rs,l,r,v);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(l>r) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        push_down(i);
        long long res=0;
        if(l<=tree[ls].r) res+=query(ls,l,r);
        if(r>=tree[rs].l) res+=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs
}T1,T2;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=q;i++)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        pos[t].emplace_back((Query){l,r,i});
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(s.empty()) pre[i]=0;
        else pre[i]=s.top();
        s.emplace(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[i]>=a[s.top()]) s.pop();
        if(s.empty()) suf[i]=n+1;
        else suf[i]=s.top();
        s.emplace(i);
    }
    for(int i=1;i<=n;i++)
        if(pre[i]!=0)
        {
            op.emplace_back((Operation){i,pre[i],a[pre[i]]-a[i]});
            if(suf[i]!=n+1) op.emplace_back((Operation){suf[i],pre[i],-(a[pre[i]]-a[i])});
        }
    sort(op.begin(),op.end(),[=](const Operation &x,const Operation &y){return x.a-x.b<y.a-y.b;});
    T1.build(1,1,n);
    T2.build(1,1,n);
    long long sumc=0;
    for(int t=1,i=0;t<=n;t++)
    {
        while(i<(int)op.size()&&op[i].a-op[i].b<=t)
        {
            T1.modify(1,1,op[i].b,op[i].c);
            T2.modify(1,1,op[i].a-1,op[i].c);
            sumc+=op[i].c;
            i++;
        }
        for(auto [l,r,id]:pos[t])
        {
            ans[id]+=sum[r]-sum[l-1];
            ans[id]+=sumc*t-T2.query(1,1,r);
            if(r-t>=0) ans[id]+=T1.query(1,1,r-t);
            else ans[id]+=sumc*(r-t);
            if(l-1>=1)
            {
                ans[id]-=sumc*t-T2.query(1,1,l-1);
                if(l-1-t>=0) ans[id]-=T1.query(1,1,l-1-t);
                else ans[id]-=sumc*(l-1-t);
            }
        }
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}