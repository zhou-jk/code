#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,m;
double a[N];
struct Node
{
	int l,r;
	double sum,num,lazy;
}tree[N<<2];
void push_up(int i)
{
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	tree[i].num=tree[i*2].num+tree[i*2+1].num;
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].sum=a[l];tree[i].num=a[l]*a[l];
		tree[i].lazy=0;return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
void push_down(int i)
{
	if(tree[i].lazy==0) return;
	tree[i*2].lazy+=tree[i].lazy;
	tree[i*2+1].lazy+=tree[i].lazy;
	tree[i*2].num+=tree[i].lazy*tree[i].lazy*(tree[i*2].r-tree[i*2].l+1)+2*tree[i*2].sum*tree[i].lazy;
	tree[i*2+1].num+=tree[i].lazy*tree[i].lazy*(tree[i*2+1].r-tree[i*2+1].l+1)+2*tree[i*2+1].sum*tree[i].lazy;
	tree[i*2].sum+=tree[i].lazy*(tree[i*2].r-tree[i*2].l+1);
	tree[i*2+1].sum+=tree[i].lazy*(tree[i*2+1].r-tree[i*2+1].l+1);
	tree[i].lazy=0;
	return;
}
void update(int i,int l,int r,double val)
{
	if(l>tree[i].r||r<tree[i].l) return;
	if(l<=tree[i].l&&tree[i].r<=r)
	{
		tree[i].lazy+=val;
		double l=tree[i].r-tree[i].l+1;
		tree[i].num+=val*val*l+tree[i].sum*val*2;
		tree[i].sum+=val*l;
		return;
	}
	push_down(i);
	if(l<=tree[i*2].r) update(i*2,l,r,val);
	if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
	push_up(i);
	return;
}
double querysum(int i,int l,int r)
{
	if(l>tree[i].r||r<tree[i].l) return 0;
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
	push_down(i);
	double res=0;
	if(l<=tree[i*2].r) res+=querysum(i*2,l,r);
	if(r>=tree[i*2+1].l) res+=querysum(i*2+1,l,r);
	return res;
}
double querynum(int i,int l,int r)
{
	if(l>tree[i].r||r<tree[i].l) return 0;
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].num;
	push_down(i);
	double res=0;
	if(l<=tree[i*2].r) res+=querynum(i*2,l,r);
	if(r>=tree[i*2+1].l) res+=querynum(i*2+1,l,r);
	return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
	build(1,1,n);
    while(m--)
    {
        int op,x,y;
        double z;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            scanf("%lf",&z);
            update(1,x,y,z);
        }
        else if(op==2) printf("%.4lf\n",querysum(1,x,y)/(y-x+1));
        else if(op==3)
        {
	  	  	double ans1=querysum(1,x,y)/(y-x+1),ans2=querynum(1,x,y)/(y-x+1);
	  	  	printf("%.4lf\n",ans2-ans1*ans1);
        }
    }
	return 0;
}