#include<iostream>
#include<cstdio>
using namespace std;
const int N=1001;
int R,C,n;
struct Seg
{
    struct Node
    {
        int Max,lazy;
    }tree[N*3];
	void update(int i,int l,int r,int L,int R,int val)
    {
		tree[i].Max=max(tree[i].Max,val);
        if(L<=l&&r<=R)
        {
            tree[i].lazy=max(tree[i].lazy,val);
            return;
        }
		int mid=(l+r)/2;
		if(L<=mid) update(i*2,l,mid,L,R,val);
		if(R>mid) update(i*2+1,mid+1,r,L,R,val);
        return;
	}
	int query(int i,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R) return tree[i].Max;
		int mid=(l+r)/2;
        int res=tree[i].lazy;
		if(L<=mid) res=max(res,query(i*2,l,mid,L,R));
		if(R>mid) res=max(res,query(i*2+1,mid+1,r,L,R));
		return res;
	}
};
struct Segment_tree
{
    struct Node
    {
        Seg Max,lazy;
    }tree[N*3];
	void update(int i,int l,int r,int L,int R,int D,int U,int val)
    {
		tree[i].Max.update(1,1,C,D,U,val);
        if(L<=l&&r<=R)
        {
            tree[i].lazy.update(1,1,C,D,U,val);
            return;
        }
		int mid=(l+r)/2;
		if(L<=mid) update(i*2,l,mid,L,R,D,U,val);
		if(R>mid) update(i*2+1,mid+1,r,L,R,D,U,val);
        return;
	}
	int query(int i,int l,int r,int L,int R,int D,int U)
    {
		if(L<=l&&r<=R) return tree[i].Max.query(1,1,C,D,U);
		int mid=(l+r)/2;
        int res=tree[i].lazy.query(1,1,C,D,U);
		if(L<=mid) res=max(res,query(i*2,l,mid,L,R,D,U));
		if(R>mid) res=max(res,query(i*2+1,mid+1,r,L,R,D,U));
		return res;
	}
}T;
int main()
{
    scanf("%d%d%d",&R,&C,&n);
	for(int i=1;i<=n;i++)
	{
        int d,s,w,x,y;
        scanf("%d%d%d%d%d",&d,&s,&w,&x,&y);
		int ql=x+1,qr=x+d,qd=y+1,qu=y+s;
		int ans=T.query(1,1,R,ql,qr,qd,qu);
		T.update(1,1,R,ql,qr,qd,qu,ans+w);
	}
	printf("%d",T.query(1,1,R,1,R,1,C));
	return 0;
}