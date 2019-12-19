#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
const int N=500001;
int n,m,q;
int a[N];
struct Matrix
{
    int c[3][3];
    Matrix()
    {
        for(int i=0;i<=2;i++)
            for(int j=0;j<=2;j++)
                c[i][j]=-INF;
        return;
    }
    Matrix operator *(const Matrix &b)const
    {
        Matrix res;
        for(int i=0;i<=2;i++)
            for(int j=0;j<=2;j++)
                for(int k=0;k<=2;k++)
                    res.c[i][j]=max(res.c[i][j],c[i][k]+b.c[k][j]);
        return res;
    }
    
};
struct Node
{
    int l,r;
    Matrix sum;
}tree[N<<2];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum*tree[i*2+1].sum;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].sum.c[0][0]=tree[i].sum.c[0][2]=tree[i].sum.c[1][0]=tree[i].sum.c[1][2]=a[l];
        tree[i].sum.c[0][1]=tree[i].sum.c[2][0]=tree[i].sum.c[2][1]=-INF;
        tree[i].sum.c[1][1]=tree[i].sum.c[2][2]=0;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int u,int v)
{
    if(u<tree[i].l||u>tree[i].r) return;
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum.c[0][0]=tree[i].sum.c[0][2]=tree[i].sum.c[1][0]=tree[i].sum.c[1][2]=v;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,v);
    else update(i*2+1,u,v);
    push_up(i);
    return;
}
Matrix query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    if(r<=tree[i*2].r) return query(i*2,l,r);
    else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
    else return query(i*2,l,r)*query(i*2+1,l,r); 
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--)
    {
        scanf("%d",&q);
        if(q==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(l>r) swap(l,r);
            Matrix res=query(1,l,r);
            printf("%d\n",max(res.c[1][0],res.c[1][2]));
        }
        else if(q==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            update(1,x,y);
        }
    }
    return 0;
}