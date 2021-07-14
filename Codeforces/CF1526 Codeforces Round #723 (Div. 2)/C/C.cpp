#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
int a[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        long long Min,tag;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
        return;
    }
    void add(int i,long long v)
    {
        tree[i].Min+=v;
        tree[i].tag+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(i*2,tree[i].tag);
        add(i*2+1,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].Min=0;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
        push_down(i);
        int res=INF;
        if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
        return res;
    }
}T;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    T.build(1,1,n);
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]>a[y];});
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=id[i];
        T.modify(1,p,n,a[p]);
        if(T.query(1,1,n)>=0) ans++;
        else T.modify(1,p,n,-a[p]);
    }
    printf("%d",ans);
    return 0;
}