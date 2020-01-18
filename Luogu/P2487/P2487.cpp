#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tot;
struct Node
{
    int id,x,y;
    bool operator<(const Node& b)const
    {
        return x<b.x||(x==b.x&&y<b.y);
    }
}q[50001],t[50001];
bool cmp(Node a,Node b)
{
    return a.id>b.id;
}
int f[2][50001];
double g[2][50001];
int book[50001];
struct Tree
{
    int f;
    int tag;
    double g;
}tree[50001];
int T;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int f,double g)
{
    for(int i=x;i<=tot;i+=lowbit(i))
    {
        if(tree[i].tag!=T) tree[i].tag=T,tree[i].g=tree[i].f=0;
        if(f>tree[i].f) tree[i].f=f,tree[i].g=g;
        else if(f==tree[i].f) tree[i].g+=g;
    }
    return;
}
pair<int,double> query(int x)
{
    int res=0;
    double sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        if(tree[i].tag==T)
        {
            if(tree[i].f>res) res=tree[i].f,sum=tree[i].g;
            else if(tree[i].f==res) sum+=tree[i].g;
        }
    return make_pair(res,sum);
}
void solve(int l,int r,int k)
{
    if(l==r)
    {
        if(!f[k][l]) g[k][l]=f[k][l]=1;
        return;
    }
    int mid=(l+r)/2;
    int l1=l,l2=mid+1,cnt=0;
    for(int i=l;i<=r;i++)
        if(q[i].id<=mid) t[l1++]=q[i];
        else t[l2++]=q[i];
    memcpy(q+l,t+l,sizeof(Node)*(r-l+1));
    solve(l,mid,k);
    T++;
    sort(q+mid+1,q+r+1);
    for(int i=mid+1,j=l;i<=r;i++)
    {
        int id;
        for(;j<=mid&&q[j].x<=q[i].x;j++)
        {
            id=q[j].id,cnt++;
            add(q[j].y,f[k][id],g[k][id]);
        }
        pair<int,double> t=query(q[i].y);
        int res=t.first;
        double sum=t.second;
        id=q[i].id;
        if(res>0)
        {
            if(res+1>f[k][id]) f[k][id]=res+1,g[k][id]=sum;
            else if(res+1==f[k][id]) g[k][id]+=sum;
        }
    }
    solve(mid+1,r,k);
    l1=l,l2=mid+1;
    int now=l;
    while(l1<=mid||l2<=r)
        if(l2>r||(l1<=mid&&q[l1]<q[l2])) t[now++]=q[l1++];
        else t[now++]=q[l2++];
    memcpy(q+l,t+l,sizeof(Node)*(r-l+1));
    return;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&q[i].x,&q[i].y);
        book[i]=q[i].y;
        m=max(m,q[i].x);
    }
    sort(book+1,book+n+1);
    tot=unique(book+1,book+n+1)-book-1;
    for(int i=1;i<=n;i++)
        q[i].y=lower_bound(book+1,book+tot+1,q[i].y)-book;
    reverse(q+1,q+n+1);
    for(int i=1;i<=n;i++)
        q[i].id=i;
    solve(1,n,0);
    sort(q+1,q+n+1,cmp);
    for(int i=1;i<=n;i++)
        q[i].x=m-q[i].x+1,q[i].y=tot-q[i].y+1,q[i].id=i;
    solve(1,n,1);
    int res=0;
    double sum=0;
    for(int i=1;i<=n;i++)
        if(f[0][i]>res) res=f[0][i],sum=g[0][i]*g[1][n-i+1];
        else if(f[0][i]==res) sum+=g[0][i]*g[1][n-i+1];
    printf("%d\n",res);
    for(int i=n;i>0;i--)
        if(f[0][i]+f[1][n-i+1]-1==res) printf("%.5lf ",(g[0][i]*g[1][n-i+1])/sum);
        else printf("0.00000 ");
    return 0;
}