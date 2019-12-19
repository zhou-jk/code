#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline char gc()
{
    static const int SIZE=1<<23;
    static char buf[SIZE],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
template<typename T>
inline T read(T &x)
{
    char ch;
    bool flag=true;
    x=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(!flag) x=-x;
    return x;
}
template<typename T>
inline void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
template<typename T>
inline void writeln(T x)
{
    write(x);
    putchar('\n');
    return;
}
const int N=200001;
const int MOD=1000000000;
int n,q;
inline int add(long long x)
{
    while(x>=MOD) x-=MOD;
    return x;
}
struct Matrix
{
    int mat[3][3];
    inline Matrix()
    {
        memset(mat,0,sizeof(mat));
        return;
    }
    inline Matrix operator + (const Matrix sum)
    {
        Matrix res;
        for(register int i=1;i<=2;i++)
            for(register int j=1;j<=2;j++)
                res.mat[i][j]=add(res.mat[i][j]+add(mat[i][j]+sum.mat[i][j]));
        return res;
    }
    inline Matrix operator * (const Matrix sum)
    {
        Matrix res;
        for(register int i=1;i<=2;i++)
            for(register int j=1;j<=2;j++)
                for(register int k=1;k<=2;k++)
                    res.mat[i][j]=add(res.mat[i][j]+((long long)mat[i][k]*sum.mat[k][j])%MOD);
        return res;
    }
    inline Matrix operator ^ (const Matrix sum)
    {
        Matrix res;res.mat[1][1]=res.mat[1][2]=0;
        for(register int j=1;j<=2;j++)
            for(register int k=1;k<=2;k++)
                res.mat[1][j]=add(res.mat[1][j]+((long long)mat[1][k]*sum.mat[k][j])%MOD);
        return res;
    }
    inline Matrix operator & (const Matrix sum)
    {
        Matrix res;
        for(register int j=1;j<=2;j++)
            res.mat[1][j]=add(res.mat[1][j]+add(mat[1][j]+sum.mat[1][j]));
        return res;
    }
}fac[N];
long long fib[N];
long long sum1[N],sum2[N];
int a[N];
namespace Segment_Tree
{
    struct Node
    {
        int l,r,len,lazy;
        Matrix sum;
    }tree[N<<2];
    inline Matrix push_up(Matrix x,Matrix y,int len)
    {
        if(len) y=y^fac[len];
        x=x&y;
        return x;
    }
    inline void push_down(int i)
    {
        tree[i*2].lazy=add(tree[i*2].lazy+tree[i].lazy);
        tree[i*2+1].lazy=add(tree[i*2+1].lazy+tree[i].lazy);
        tree[i].lazy=0;
        return;
    }
    inline Matrix calc_lazy(Matrix x,int i)
    {
        if(tree[i].lazy==0) return x;
        x.mat[1][1]=add(x.mat[1][1]+((long long)tree[i].lazy*sum1[tree[i].len])%MOD);
        x.mat[1][2]=add(x.mat[1][2]+((long long)tree[i].lazy*sum2[tree[i].len])%MOD);
        return x;
    }
    inline void build(int i,int l,int r)
    {
        tree[i].l=l;tree[i].r=r;tree[i].lazy=0;
        tree[i].len=tree[i].r-tree[i].l+1;
        if(l==r)
        {
            tree[i].sum.mat[1][1]=tree[i].sum.mat[1][2]=a[l];
            tree[i].sum.mat[2][1]=tree[i].sum.mat[2][2]=0;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        tree[i].sum=push_up(tree[i*2].sum,tree[i*2+1].sum,tree[i*2].len);
        return;
    }
    inline void update(int i,int u,int val)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum.mat[1][1]=tree[i].sum.mat[1][2]=val;
            tree[i].lazy=0;
            return;
        }
        push_down(i);
        if(u<=tree[i*2].r) update(i*2,u,val);
        else update(i*2+1,u,val);
        tree[i].sum=push_up(calc_lazy(tree[i*2].sum,i*2),calc_lazy(tree[i*2+1].sum,i*2+1),tree[i*2].len);
        return;
    }
    inline Matrix query(int i,int l,int r,int u)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return calc_lazy(tree[i].sum,i)*fac[u];
        push_down(i);
        Matrix res;
        if(r<=tree[i*2].r) res=query(i*2,l,r,u);
        else if(l>=tree[i*2+1].l) res=query(i*2+1,l,r,u);
        else res=query(i*2,l,tree[i*2].r,u)+query(i*2+1,tree[i*2+1].l,r,u+tree[i*2].r-l+1);
        tree[i].sum=push_up(calc_lazy(tree[i*2].sum,i*2),calc_lazy(tree[i*2+1].sum,i*2+1),tree[i*2].len);
        return res;
    }
    inline void update(int i,int l,int r,int val)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            tree[i].lazy=add(tree[i].lazy+val);
            return;
        }
        push_down(i);
        if(l<=tree[i*2].r) update(i*2,l,r,val);
        if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
        tree[i].sum=push_up(calc_lazy(tree[i*2].sum,i*2),calc_lazy(tree[i*2+1].sum,i*2+1),tree[i*2].len);
        return;
    }
}
int main()
{
    read(n),read(q);
    fac[0].mat[1][1]=fac[0].mat[2][2]=1;
    fac[0].mat[1][2]=fac[0].mat[2][1]=0;
    Matrix delta;
    delta.mat[1][1]=0,delta.mat[1][2]=delta.mat[2][1]=delta.mat[2][2]=1;
    for(register int i=1;i<=n;i++)
        fac[i]=fac[i-1]*delta;
    for(register int i=1;i<=n;i++)
        read(a[i]);
    fib[1]=fib[2]=1;
    for(register int i=3;i<=n;i++)
        fib[i]=add(fib[i-1]+fib[i-2]);
    sum1[1]=sum2[1]=1;
    for(register int i=2;i<=n;i++)
        sum1[i]=add(sum1[i-1]+fib[i]),sum2[i]=add(sum2[i-1]+fib[i+1]);
    Segment_Tree::build(1,1,n);
    while(q--)
    {
        int op;
        read(op);
        if(op==1)
        {
            int pos,val;
            read(pos),read(val);
            Segment_Tree::update(1,pos,val);
        }
        else if(op==2)
        {
            int l,r;
            read(l),read(r);
            writeln(Segment_Tree::query(1,l,r,0).mat[1][1]);
        }
        else if(op==3)
        {
            int l,r,val;
            read(l),read(r),read(val);
            Segment_Tree::update(1,l,r,val);
        }
    }
    return 0;
}