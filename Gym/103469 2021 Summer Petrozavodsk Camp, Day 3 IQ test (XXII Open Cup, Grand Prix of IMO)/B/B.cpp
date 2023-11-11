#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=998244353;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
int n,m,k,w,q;
int C[6][6];
void init(int n=5)
{
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    return;
}
int a[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int siz;
        int sum[6]; 
        int cnt[6][6];
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        c.siz=a.siz+b.siz;
        int pwx[6];
        pwx[0]=1;
        for(int i=1;i<=k;i++)
            pwx[i]=(long long)pwx[i-1]*a.siz%MOD;
        for(int i=0;i<=k;i++)
        {
            c.sum[i]=a.sum[i];
            for(int j=0;j<=i;j++)
                c.sum[i]=(c.sum[i]+(long long)b.sum[j]*pwx[i-j]%MOD*C[i][j])%MOD;
        }
        for(int i=0;i<w;i++)
            for(int t=0;t<w;t++)
                c.cnt[i][t]=a.cnt[i][t]+b.cnt[i][(t-a.siz%w+w)%w];
        return c;
    }
    void push_up(int i)
    {
        tree[i]=merge(tree[ls],tree[rs]);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            for(int j=0;j<=k;j++)
                tree[i].sum[j]=0;
            for(int j=0;j<w;j++)
                for(int t=0;t<w;t++)
                    tree[i].cnt[j][t]=0;
            tree[i].siz=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            int pwx[6];
            pwx[0]=1;
            for(int j=1;j<=k;j++)
                if(v>0) pwx[j]=(long long)pwx[j-1]*(tree[i].siz+1)%MOD;
                else if(v<0) pwx[j]=(long long)pwx[j-1]*tree[i].siz%MOD;
            for(int j=0;j<=k;j++)
            {
                tree[i].sum[j]=(tree[i].sum[j]+(long long)u*pwx[j]%MOD*v)%MOD;
                if(tree[i].sum[j]<0) tree[i].sum[j]+=MOD;
            }
            if(v>0) tree[i].cnt[u%w][(tree[i].siz+1)%w]+=v;
            else if(v<0) tree[i].cnt[u%w][tree[i].siz%w]+=v;
            tree[i].siz+=v;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    Node query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k>>w;
    int invw=getinv(w);
    int pw[5];
    for(int i=0;i<w;i++)
    {
        pw[i]=1%w;
        for(int j=1;j<=k;j++)
            pw[i]=pw[i]*i%w;
    }
    m=100000;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    init();
    T.build(1,0,m);
    for(int i=1;i<=n;i++)
        T.modify(1,a[i],1);
    cin>>q;
    while(q--)
    {
        int pos,x;
        cin>>pos>>x;
        T.modify(1,a[pos],-1);
        a[pos]=x;
        T.modify(1,a[pos],1);
        Segment_Tree::Node res=T.query(1,0,m);
        int sum=res.sum[k],sumw=0;
        for(int i=0;i<w;i++)
            for(int t=0;t<w;t++)
                sumw=(sumw+(long long)i*pw[t]%w*res.cnt[i][t])%MOD;
        int ans=((long long)sum-sumw+MOD)%MOD*invw%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}
