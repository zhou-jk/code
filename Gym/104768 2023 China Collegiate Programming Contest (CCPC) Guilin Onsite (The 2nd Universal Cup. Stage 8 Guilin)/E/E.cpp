#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N];
int b[N],tot;
int cnt[N];
struct Matrix
{
    int n,m;
    unsigned int row[18];
    unsigned int column[18];
    Matrix(int _n=0,int _m=0):n(_n),m(_m)
    {
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
    }
    void init(int _n,int _m)
    {
        n=_n,m=_m;
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        return;
    }
    void set(int i,int j)
    {
        row[i]|=1<<j;
        column[j]|=1<<i;
        return;
    }
    void reset(int i,int j)
    {
        row[i]&=~(1<<j);
        column[j]&=~(1<<i);
        return;
    }
    bool test(int i,int j)
    {
        return (row[i]>>j)&1;
    }
    friend Matrix operator*(const Matrix &a,const Matrix &b)
    {
        assert(a.m==b.n);
        Matrix c(a.n,b.m);
        for(int i=0;i<a.n;i++)
            for(int j=0;j<b.m;j++)
                if(a.row[i]&b.column[j]) c.set(i,j);
        return c;
    }
};
Matrix construct(int c)
{
    Matrix res(18,18);
    for(int j=0;j<2;j++)
        for(int x=0;x<3;x++)
            for(int y=0;y<3;y++)
            {
                int vali=j*9+x*3+y;
                for(int k=j;k<2;k++)
                {
                    int ret=c-x-y;
                    if(k&&!j) ret-=2;
                    if(ret<0) continue;
                    int valj=k*9+y*3+ret%3;
                    res.set(valj,vali);
                }
            }
    return res;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        Matrix sum;
    }tree[N*4];
    void push_up(int i)
    {
        tree[i].sum=tree[ls].sum*tree[rs].sum;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum.init(18,18);
            tree[i].sum.set(9,9);
            tree[i].sum.set(0,0);
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum=construct(v);
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
}T;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    tot=0;
    for(int i=1;i<=n;i++)
        b[++tot]=a[i],b[++tot]=a[i]+1;
    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    T.build(1,1,tot);
    fill(cnt+1,cnt+tot+1,0);
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
        T.modify(1,a[i],cnt[a[i]]);
        if(i%3!=2)
        {
            cout<<0;
            continue;
        }
        Matrix res(18,1);
        res.set(0,0);
        res=T.tree[1].sum*res;
        if(res.test(9,0)) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
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
