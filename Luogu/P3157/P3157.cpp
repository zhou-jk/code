#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100001;
int n,m;
int a[N],b[N];
long long ans;
int rt[N],tot;
struct Segment_Tree
{
    struct Node
    {
        int lc,rc;
        long long sum;
    }tree[N<<7];
    void push_up(int i)
    {
        tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
        return;
    }
    void update(int &i,int l,int r,int u)
    {
        if(!i) i=++tot;
        if(l==r)
        {
            tree[i].sum++;
            return;
        }
        int mid=(l+r)/2;
        if(u<=mid) update(tree[i].lc,l,mid,u);
        else update(tree[i].rc,mid+1,r,u);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r,int L,int R)
    {
        if(r<L||l>R) return 0;
        if(L<=l&&r<=R) return tree[i].sum;
        int mid=(l+r)/2;
        long long res=0;
        if(L<=mid) res+=query(tree[i].lc,l,mid,L,R);
        if(R>mid) res+=query(tree[i].rc,mid+1,r,L,R);
        return res;
    }
}T;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int y)
{
    if(x==0) return;
    for(int i=x;i<=n;i+=lowbit(i))
        T.update(rt[i],1,n,y);
    return;
}
long long getsum(int x,int l,int r)
{
    if(x==0) return 0;
    long long res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=T.query(rt[i],1,n,l,r);
    return res;
}
long long query(int l,int r,int L,int R)
{
    return getsum(r,L,R)-getsum(l-1,L,R);
}
struct Binary_Indexed_Tree
{
    long long C[N];
    void clear()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        if(x==0) return;
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    long long getsum(int x)
    {
        if(x==0) return 0;
        long long res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    long long query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}BIT;
long long pre[N],nxt[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]=BIT.query(a[i]+1,n);
        BIT.add(a[i],1);
    }
    BIT.clear();
    for(int i=n;i>=1;i--)
    {
        nxt[i]=BIT.getsum(a[i]-1);
        BIT.add(a[i],1);
    }
    for(int i=1;i<=n;i++)
        ans+=pre[i];
    while(m--)
    {
        int u;
        printf("%lld\n",ans);
        scanf("%d",&u);
        int v=b[u];
        ans-=(pre[v]+nxt[v])-(query(0,v,u+1,n)+query(v,n,1,u-1));
        add(v,u);
    }
    return 0;
}
