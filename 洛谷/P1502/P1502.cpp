#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
struct Seg
{
    int h,l,r,v;
}line[200001];
bool cmp(Seg a,Seg b)
{
    if(a.h!=b.h) return a.h<b.h;
    else return a.v>b.v;
}
int Y[200001];
struct Node
{
    int l,r;
    int sum,tag;
}tree[400001];
int ans,n,w,h;
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r,tree[i].sum=tree[i].tag=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void push_up(int i)
{
    tree[i].sum=max(tree[i*2].sum,tree[i*2+1].sum);
    return;
}
void push_down(int i)
{
    if(!tree[i].tag) return;
    tree[i*2].tag+=tree[i].tag;
    tree[i*2+1].tag+=tree[i].tag;
    tree[i*2].sum+=tree[i].tag;
    tree[i*2+1].sum+=tree[i].tag;
    tree[i].tag=0;
    return;
}
void update(int i,int l,int r,int k)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].sum+=k;
        tree[i].tag+=k;
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,k);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,k);
    push_up(i);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&w,&h);
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            Y[i]=y,Y[i+n]=y+h-1;
            line[i]=(Seg){x,y,y+h,z};
            line[i+n]=(Seg){x+w-1,y,y+h,-z};
        }
        sort(line+1,line+2*n+1,cmp);
        sort(Y+1,Y+2*n+1);
        int k=unique(Y+1,Y+2*n+1)-Y-1;
        build(1,1,k);
        ans=0;
        for(int i=1;i<=2*n;i++)
        {
            int l=lower_bound(Y+1,Y+k+1,line[i].l)-Y,r=lower_bound(Y+1,Y+k+1,line[i].r)-Y;
            update(1,l,r-1,line[i].v);
            ans=max(ans,tree[1].sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}