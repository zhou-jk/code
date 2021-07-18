#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int N=500005;
int n,Q;
int a[N];
int L[N],R[N];
int ans[N];
vector<pair<int,int>>ask[N],p[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int c,ab,abc;
        int lazy;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].c=max(tree[i*2].c,tree[i*2+1].c);
        tree[i].abc=max(tree[i*2].abc,tree[i*2+1].abc);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].c=tree[i].abc=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int v)
    {
        tree[i].lazy=max(tree[i].lazy,v);
        tree[i].ab=max(tree[i].ab,v);
        tree[i].abc=max(tree[i].abc,tree[i].c+tree[i].ab);
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].lazy) return;
        add(i*2,tree[i].lazy);
        add(i*2+1,tree[i].lazy);
        tree[i].lazy=0;
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].abc;
        push_down(i);
        int res=0;
        if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
        return res;
    }
}T;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        ask[l].emplace_back(r,i);
    }
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(!s.empty()) L[i]=s.top();
        s.emplace(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(!s.empty()) R[i]=s.top();
        s.emplace(i);
    }
    T.build(1,1,n);
    for(int i=1;i<=n;i++)
        if(L[i]) p[L[i]].emplace_back(L[i],i);
    for(int i=n;i>=1;i--)
    {
        for(auto [r,id]:p[i])
            T.modify(1,id*2-r,n,a[id]+a[r]);
        if(R[i]) T.modify(1,R[i]*2-i,n,a[i]+a[R[i]]);
        for(auto [r,id]:ask[i])
            ans[id]=T.query(1,i,r);
    }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}