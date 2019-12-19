#include<iostream>
#include<cstdio>
using namespace std;
const int N=200001;
int n,m;
int a[N];
struct Node
{
    int l,r;
    int lcol,rcol,col;
    int lmax,rmax,sum;
}tree[N<<2];
void push_up(int i)
{
    if(tree[i*2].col!=tree[i*2+1].col||tree[i*2].col==-1||tree[i*2+1].col==-1) tree[i].col=-1;
    else tree[i].col=tree[i*2].col;
    tree[i].lcol=tree[i*2].lcol;
    tree[i].rcol=tree[i*2+1].rcol;
    if(tree[i*2].col!=-1&&tree[i*2].col==tree[i*2+1].lcol) tree[i].lmax=(tree[i*2].r-tree[i*2].l+1)+tree[i*2+1].lmax;
    else tree[i].lmax=tree[i*2].lmax;
    if(tree[i*2+1].col!=-1&&tree[i*2+1].col==tree[i*2].rcol) tree[i].rmax=(tree[i*2+1].r-tree[i*2+1].l+1)+tree[i*2].rmax;
    else tree[i].rmax=tree[i*2+1].rmax;
    tree[i].sum=max(tree[i*2].sum,tree[i*2+1].sum);
    if(tree[i*2].rcol==tree[i*2+1].lcol) tree[i].sum=max(tree[i].sum,tree[i*2].rmax+tree[i*2+1].lmax);
    return;
}
void push_down(int i)
{
    if(tree[i].col==-1) return;
    tree[i*2].col=tree[i*2].lcol=tree[i*2].rcol=tree[i].col;
    tree[i*2].sum=tree[i*2].lmax=tree[i*2].rmax=tree[i*2].r-tree[i*2].l+1;
    tree[i*2+1].col=tree[i*2+1].lcol=tree[i*2+1].rcol=tree[i].col;
    tree[i*2+1].sum=tree[i*2+1].lmax=tree[i*2+1].rmax=tree[i*2+1].r-tree[i*2+1].l+1;
    tree[i].col=-1;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].lcol=tree[i].rcol=tree[i].col=a[l];
        tree[i].lmax=tree[i].rmax=1;
        tree[i].sum=1;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int L,int R,int c)
{
    if(R<tree[i].l||L>tree[i].r) return;
    if(L<=tree[i].l&&tree[i].r<=R)
    {
        tree[i].col=tree[i].lcol=tree[i].rcol=c;
        tree[i].sum=tree[i].lmax=tree[i].rmax=tree[i].r-tree[i].l+1;
        return;
    }
    push_down(i);
    update(i*2,L,R,c);
    update(i*2+1,L,R,c);
    push_up(i);
    return;
}
int query(int i,int L,int R)
{
    if(L<=tree[i].l&&tree[i].r<=R) return tree[i].sum;
    push_down(i);
    if(R<=tree[i*2].r) return query(i*2,L,R);
    else if(L>=tree[i*2+1].l) return query(i*2+1,L,R);
    else
    {
        int res=max(query(i*2,L,R),query(i*2+1,L,R));
        if(tree[i*2].rcol==tree[i*2+1].lcol) res=max(res,min(tree[i*2].r-tree[i*2].l+1,tree[i*2].rmax)+min(tree[i*2+1].r-tree[i*2+1].l+1,tree[i*2+1].lmax));
        return res;
    }
}
int querycol(int i,int u)
{
    if(tree[i].l==tree[i].r) return tree[i].col;
    if(tree[i].l<=u&&u<=tree[i].r&&tree[i].col!=-1) return tree[i].col;
    push_down(i);
    if(u<=tree[i*2].r) return querycol(i*2,u);
    else return querycol(i*2+1,u);
}
int querylmax(int i,int L,int R)
{
    if(tree[i].l<=L&&R<=tree[i].r&&tree[i].l+tree[i].lmax-1>=L) return tree[i].l+tree[i].lmax-L;
    push_down(i);
    if(R<=tree[i*2].r) return querylmax(i*2,L,R);
    else if(L>=tree[i*2+1].l) return querylmax(i*2+1,L,R);
    else if(tree[i*2].rcol==tree[i*2+1].lcol&&tree[i*2].r-tree[i*2].rmax+1<=L) return querylmax(i*2,L,tree[i*2].r)+querylmax(i*2+1,tree[i*2+1].l,R);
    else return querylmax(i*2,L,tree[i*2].r);
}
int queryrmax(int i,int L,int R)
{
    if(tree[i].l<=L&&R<=tree[i].r&&tree[i].r-tree[i].rmax+1<=R) return R-tree[i].r+tree[i].rmax;
    push_down(i);
    if(R<=tree[i*2].r) return queryrmax(i*2,L,R);
    else if(L>=tree[i*2+1].l) return queryrmax(i*2+1,L,R);
    else if(tree[i*2+1].lcol==tree[i*2].rcol&&tree[i*2].r+1+tree[i*2+1].lmax-1>=R) return queryrmax(i*2,L,tree[i*2].r)+queryrmax(i*2+1,tree[i*2+1].l,R);
    else return queryrmax(i*2+1,tree[i*2+1].l,R);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--)
    {
        char op;
        int l,r,u;
        cin>>op;
        scanf("%d%d%d",&l,&r,&u);
        if(op=='R') update(1,l,r,u);
        else if(op=='Q')
        {
            if(u)
            {
                int lc=querycol(1,l),rc=querycol(1,r);
                if(lc==rc) printf("%d\n",max(query(1,l,r),min(querylmax(1,l,r)+queryrmax(1,l,r),r-l+1)));
                else printf("%d\n",query(1,l,r));
            }
            else printf("%d\n",query(1,l,r));
        }
    }
    return 0;
}