#include<iostream>
#include<cstdio>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=300005;
int n,Q;
int L[N],R[N];
tuple<bool,int,int,long long>merge(const tuple<bool,int,int,long long> &a,const tuple<bool,int,int,long long> &b)
{
    auto [ba,la,ra,wa]=a;
    auto [bb,lb,rb,wb]=b;
    if(ba&&bb) return {true,la,rb,wa+wb+max(ra-lb,0)};
    else if(ba)
    {
        if(lb<=ra&&ra<=rb) return {true,la,ra,wa+wb};
        else if(ra<lb) return {true,la,lb,wa+wb};
        else return {true,la,rb,wa+wb+ra-rb};
    }
    else if(bb)
    {
        if(la<=lb&&lb<=ra) return {true,lb,rb,wa+wb};
        else if(ra<lb) return {true,ra,rb,wa+wb};
        else return {true,la,rb,wa+wb+la-lb};
    }
    else
    {
        int L=max(la,lb),R=min(ra,rb);
        if(L<=R) return {false,L,R,wa+wb};
        else if(ra<lb) return {true,ra,lb,wa+wb};
        else return {true,la,rb,wa+wb+la-rb};
    }
}
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        tuple<bool,int,int,long long>w;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].w=merge(tree[i*2].w,tree[i*2+1].w);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].w={false,L[l],R[l],0};
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int L,int R)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].w={false,L,R,0};
            return;
        }
        if(u<=tree[i*2].r) modify(i*2,u,L,R);
        else modify(i*2+1,u,L,R);
        push_up(i);
        return;
    }
    tuple<bool,int,int,long long>query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].w;
        if(r<=tree[i*2].r) return query(i*2,l,r);
        else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
        else return merge(query(i*2,l,r),query(i*2+1,l,r));
    }
}T1,T2;
int main()
{
    scanf("%d%d",&n,&Q);
    if(n==1)
    {
        while(Q--)
        {
            int t;
            scanf("%d",&t);
            if(t==2)
            {
                int a,b,c,d;
                scanf("%d%d%d%d",&a,&b,&c,&d);
                if(a==c) printf("%d\n",max(b-d,0));
            }
        }
        return 0;
    }
    for(int i=1;i<n;i++)
        scanf("%d%d",&L[i],&R[i]);
    for(int i=1;i<n;i++)
        L[i]-=i-1,R[i]-=i;
    T1.build(1,1,n-1);
    for(int i=1;i<n;i++)
        L[i]+=i-1,R[i]+=i;
    reverse(L+1,L+n);
    reverse(R+1,R+n);
    for(int i=1;i<n;i++)
        L[i]-=i-1,R[i]-=i;
    T2.build(1,1,n-1);
    while(Q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int p,s,e;
            scanf("%d%d%d",&p,&s,&e);
            s-=p-1,e-=p;
            T1.modify(1,p,s,e);
            s+=p-1,e+=p;
            p=n-p;
            s-=p-1,e-=p;
            T2.modify(1,p,s,e);
        }
        else if(t==2)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a==c)
            {
                printf("%d\n",max(b-d,0));
                continue;
            }
            if(a<c)
            {
                b-=a-1,d-=c-1;
                auto [op,l,r,w]=merge(merge({false,b,b,0},T1.query(1,a,c-1)),{false,d,d,0});
                printf("%lld\n",w);
            }
            if(a>c)
            {
                a=n-a+1,c=n-c+1;
                b-=a-1,d-=c-1;
                auto [op,l,r,w]=merge(merge({false,b,b,0},T2.query(1,a,c-1)),{false,d,d,0});
                printf("%lld\n",w);
            }
        }
    }
    return 0;
}