#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,m;
int rt[N],tot;
struct Node
{
    int lc,rc;
    int fa,dep;
}tree[N*40];
void build(int &i,int l,int r)
{
	i=++tot;
	if(l==r)
    {
        tree[i].fa=l;
        return;
    }
	int mid=(l+r)/2;
	build(tree[i].lc,l,mid);
	build(tree[i].rc,mid+1,r);
    return;
}
int update(int i,int l,int r,int pos,int val)
{
    int now=++tot;
    tree[now]=tree[i];
	if(l==r)
    {
        tree[now].fa=val;
        return now;
    }
	int mid=(l+r)/2;
	if(pos<=mid) tree[now].lc=update(tree[i].lc,l,mid,pos,val);
	else tree[now].rc=update(tree[i].rc,mid+1,r,pos,val);
    return now;
}
int queryfa(int i,int l,int r,int pos)
{
	if(l==r) return i;
	int mid=(l+r)/2;
	if(pos<=mid) return queryfa(tree[i].lc,l,mid,pos);
	else return queryfa(tree[i].rc,mid+1,r,pos);
}
void modify(int i,int l,int r,int pos)
{
	if(l==r)
    {
        tree[i].dep++;
        return;
    }
	int mid=(l+r)/2;
	if(pos<=mid) modify(tree[i].lc,l,mid,pos);
	else modify(tree[i].rc,mid+1,r,pos);
    return;
}
int getf(int i,int v)
{
    int f=queryfa(i,1,n,v);
	if(v==f) return v;
    return getf(i,f);
}
int main()
{
    scanf("%d%d",&n,&m);
	build(rt[0],1,n);
	for(int i=1;i<=m;i++)
	{
        int op,k,a,b;
        scanf("%d",&op);
		if(op==1)
		{
			rt[i]=rt[i-1];
            scanf("%d%d",&a,&b);
			int p=getf(rt[i],a),q=getf(rt[i],b);
			if(tree[p].fa==tree[q].fa) continue;
			if(tree[p].dep>tree[q].dep) swap(p,q);
			rt[i]=update(rt[i-1],1,n,tree[p].fa,tree[q].fa);
			if(tree[p].dep==tree[q].dep) modify(rt[i],1,n,tree[q].fa);
		}
		else if(op==2)
		{
            scanf("%d",&k);
            rt[i]=rt[k];
        }
		else if(op==3)
		{
			rt[i]=rt[i-1];
            scanf("%d%d",&a,&b);
		    int p=getf(rt[i],a),q=getf(rt[i],b);
			if(tree[p].fa==tree[q].fa) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}