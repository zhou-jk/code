#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,m;
double k[N];
struct Node
{
    int l,r,sum;
    double Max;
}tree[N<<2];
int add(int i,double maxl)
{
    if(tree[i].Max<=maxl) return 0;
    if(k[tree[i].l]>maxl) return tree[i].sum;
    if(tree[i].l==tree[i].r) return tree[i].Max>maxl;
    if(tree[i*2].Max<=maxl) return add(i*2+1,maxl);
    else return add(i*2,maxl)+tree[i].sum-tree[i*2].sum;
}
void push_up(int i)
{
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    tree[i].sum=tree[i*2].sum+add(i*2+1,tree[i*2].Max);
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void update(int i,int u,pair<int,int> val)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].Max=(double)val.second/val.first;
        tree[i].sum=1;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,val);
    else update(i*2+1,u,val);
    push_up(i);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        k[x]=(double)y*1.0/x;
        update(1,x,make_pair(x,y));
        printf("%d\n",tree[1].sum);
    }
    return 0;
}