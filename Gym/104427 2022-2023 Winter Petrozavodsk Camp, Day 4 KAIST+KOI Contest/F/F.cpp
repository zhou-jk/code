#include<iostream>
#include<cstdio>
#include<cstring>
#include<array>
using namespace std;
const int N=100005;
int n,q;
int x[N],y[N];
int cntx[10],cntr[10];
int s[N][10];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int len;
        array<int,10>cnt;
        friend Node operator+(const Node &a,const Node &b)
        {
            Node c;
            c.l=a.l,c.r=b.r;
            if(b.len==b.r-b.l+1) c.len=b.len+a.len;
            else c.len=b.len;
            for(int j=0;j<=9;j++)
                c.cnt[j]=a.cnt[j]+b.cnt[j];
            return c;
        }
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i]=tree[ls]+tree[rs];
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            if(y[l-1]>=y[l]) tree[i].len=1;
            else tree[i].len=0;
            for(int j=0;j<=9;j++)
                tree[i].cnt[j]=0;
            tree[i].cnt[y[l]]++;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    int find_kth(int i,int c,int k)
    {
        if(k>tree[i].cnt[c]) return n+1;
        if(tree[i].l==tree[i].r) return tree[i].l;
        if(k<=tree[ls].cnt[c]) return find_kth(ls,c,k);
        else return find_kth(rs,c,k-tree[ls].cnt[c]);
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            if(y[u-1]>=v) tree[i].len=1;
            else tree[i].len=0;
            tree[i].cnt[y[u]]--;
            tree[i].cnt[v]++;
            y[u]=v;
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
        else return query(ls,l,r)+query(rs,l,r);
    }
    #undef ls
    #undef rs 
}T;
bool check(int t)
{
    array<int,10> len{};
    if(1<=t-1) len=T.query(1,1,t-1).cnt;
    for(int j=y[t]+1;j<=9;j++)
    {
        if(cntx[j]-len[j]>0) return true;
    }
    return false;
}
int pos,t;
void calc()
{
    pos=n;
    for(int j=0;j<=9;j++)
        pos=min(pos,T.find_kth(1,j,cntx[j]+1)-1);
    if(pos==n) t=n+1;
    else
    {
        if(check(pos+1)) t=pos+1;
        else if(pos==0) t=0;
        else if(check(pos)) t=pos;
        else t=pos-1-T.query(1,1,pos).len;
    }
    array<int,10>sum{};
    if(1<=t-1) sum=T.query(1,1,t-1).cnt;
    for(int j=0;j<=9;j++)
        cntr[j]=cntx[j]-sum[j];
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string sx,sy;
    cin>>sx>>sy;
    n=sx.size();
    for(int i=1;i<=n;i++)
        x[i]=sx[i-1]-'0',y[i]=sy[i-1]-'0';
    y[0]=-1;
    for(int i=1;i<=n;i++)
        cntx[x[i]]++;
    T.build(1,1,n);
    calc();
    cin>>q;
    while(q--)
    {
        int op,i,x;
        cin>>op;
        if(op==1)
        {
            cin>>i>>x;
            T.modify(1,i,x);
            if(i+1<=n) T.modify(1,i+1,y[i+1]);
            calc();
        }
        else
        {
            cin>>i;
            if(i<t)
            {
                cout<<y[i]<<"\n";
                continue;
            }
            if(t==0)
            {
                cout<<-1<<"\n";
                continue;
            }
            int v=-1;
            for(int j=y[t]+1;j<=9;j++)
                if(cntr[j]>0)
                {
                    v=j;
                    break;
                }
            if(i==t)
            {
                cout<<v<<"\n";
                continue;
            }
            int sum=0;
            for(int j=0;j<=9;j++)
            {
                sum+=cntr[j];
                if(j==v) sum--;
                if(sum>=i-t)
                {
                    cout<<j<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}