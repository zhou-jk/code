#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N];
int b[N<<1],q;
struct Ask
{
    bool op;
    int l,r,k;
    int x,y;
}ask[N];
int rt[N],tot;
struct Chairman_Tree
{
    struct Node
    {
        int sum;
        int lc,rc;
    }tree[N<<7];
    void update(int &i,int l,int r,int k,int val)
    {
        if(!i) i=++tot;
        tree[i].sum+=val;
        if(l==r) return;
        int mid=(l+r)/2;
        if(k<=mid) update(tree[i].lc,l,mid,k,val);
        else update(tree[i].rc,mid+1,r,k,val);
        return;
    }
    int query(int *u,int c1,int *v,int c2,int l,int r,int k)
    {
        if(l==r) return b[l];
        int sum=0;
        for(int i=1;i<=c2;i++)
            sum+=tree[tree[v[i]].lc].sum;
        for(int i=1;i<=c1;i++)
            sum-=tree[tree[u[i]].lc].sum;
        int mid=(l+r)/2;
        if(k<=sum)
        {
            for(int i=1;i<=c2;i++)
                v[i]=tree[v[i]].lc;
            for(int i=1;i<=c1;i++)
                u[i]=tree[u[i]].lc;
            return query(u,c1,v,c2,l,mid,k);
        }
        else
        {
            for(int i=1;i<=c2;i++)
                v[i]=tree[v[i]].rc;
            for(int i=1;i<=c1;i++)
                u[i]=tree[u[i]].rc;
            return query(u,c1,v,c2,mid+1,r,k-sum);
        }
    }
}T;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        T.update(rt[i],1,q,a[x],y);
    return;
}
int query(int l,int r,int k)
{
    static int X[N],Y[N];
    int C1=0,C2=0;
    for(int i=l-1;i>0;i-=lowbit(i))
        X[++C1]=rt[i];
    for(int i=r;i>0;i-=lowbit(i))
        Y[++C2]=rt[i];
    return T.query(X,C1,Y,C2,1,q,k);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[++q]=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        char ch;
        for(ch=getchar();ch!='Q'&&ch!='C';ch=getchar());
        ask[i].op=(ch=='Q');
        if(ask[i].op) scanf("%d%d%d",&ask[i].l,&ask[i].r,&ask[i].k);
        else scanf("%d%d",&ask[i].x,&ask[i].y),b[++q]=ask[i].y;
    }
    sort(b+1,b+q+1);
    q=unique(b+1,b+q+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+q+1,a[i])-b;
    for(int i=1;i<=m;i++)
        if(!ask[i].op) ask[i].y=lower_bound(b+1,b+q+1,ask[i].y)-b;
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=1;i<=m;i++)
        if(ask[i].op) printf("%d\n",query(ask[i].l,ask[i].r,ask[i].k));
        else
        {
            add(ask[i].x,-1);
            a[ask[i].x]=ask[i].y;
            add(ask[i].x,1);
        }
    return 0;
}