#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q;
int Case;
double x[301];
struct Seg
{
    double l,r,h;
    int d;
}line[301];
bool cmp(Seg a,Seg b)
{
    return a.h<b.h;
}
struct Node
{
    int l,r,cnt;
    double sum;
}tree[1201];
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r,tree[i].cnt=0,tree[i].sum=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void push_up(int i)
{
    if(tree[i].cnt) tree[i].sum=x[tree[i].r+1]-x[tree[i].l];
    else tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void update(int i,int l,int r,int k)
{
    if(r<tree[i].l||l>tree[i].r) return;
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].cnt+=k;
        push_up(i);
        return;
    }
    if(l<=tree[i*2].r) update(i*2,l,r,k);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,k);
    push_up(i);
    return;
}
int main()
{
    while(1)
    {
        int n=0,m=0;
        scanf("%d",&q);
        if(q==0) return 0;
        for(int i=1;i<=q;i++)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            x[++n]=x1,x[++n]=x2;
            m++,line[m].l=x1,line[m].r=x2,line[m].h=y1,line[m].d=1;
            m++,line[m].l=x1,line[m].r=x2,line[m].h=y2,line[m].d=-1;
        }
        sort(x+1,x+1+n);
        sort(line+1,line+m+1,cmp);
        int k=unique(x+1,x+n+1)-x-1;
        build(1,1,k-1);
        double ans=0;
        for(int i=1;i<m;i++)
        {
            int l=lower_bound(x+1,x+k+1,line[i].l)-x,r=lower_bound(x+1,x+k+1,line[i].r)-x;
            r--;
            if(l<=r) update(1,l,r,line[i].d);
            ans+=tree[1].sum*(line[i+1].h-line[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++Case,ans);
    }
    return 0;
}