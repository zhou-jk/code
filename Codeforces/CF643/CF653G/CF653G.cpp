#include<iostream>
#include<cstdio>
using namespace std;
int n,m,p;
int a[150001];
struct Node
{
    int cnt,a[6],b[6];
    Node()
    {
        cnt=0;
        return;
    }
    Node operator =(const int &y)
    {
        cnt=1,a[1]=y;
        return *this;
    }
    Node operator +(const Node &y)const
    {
        Node res=*this;
	    for(int i=1;i<=y.cnt;i++)
        {
		    bool flag=false;
		    for(int j=1;j<=res.cnt;j++)
		        if(res.a[j]==y.a[i])
                {
                    res.b[j]+=y.b[i];
                    flag=true;
                    break;
                }
		    if(flag) continue;
		    if(res.cnt<p)
            {
                res.cnt++;
			    res.a[res.cnt]=y.a[i];
			    res.b[res.cnt]=y.b[i];
			    continue;
		    }
            int k=1;
		    for(int j=2;j<=res.cnt;j++)
                if(res.b[j]<res.b[k]) k=j;
		    if(y.b[i]<res.b[k])
                for(int j=1;j<=res.cnt;j++)
                    res.b[j]-=y.b[i];
		    else
            {
			    int tmp=res.b[k];
			    res.a[k]=y.a[i];
                res.b[k]=y.b[i];
			    for(int j=1;j<=res.cnt;j++)
                    res.b[j]-=tmp;
		    }
	    }
	    return res;
    }
    Node operator +=(const Node &y)
    {
        *this=*this+y;
        return *this;
    }
};
struct 
{
    int l,r;
    int lazy;
    Node sum;
}tree[600001];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void push_down(int i)
{
    if(!tree[i].lazy) return;
	tree[i*2].lazy=tree[i*2+1].lazy=tree[i].lazy;
    tree[i*2].sum=tree[i*2+1].sum=tree[i].lazy;
	tree[i*2].sum.b[1]=tree[i*2].r-tree[i*2].l+1;
    tree[i*2+1].sum.b[1]=tree[i*2+1].r-tree[i*2+1].l+1;
    tree[i].lazy=0;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
	if(l==r)
    {
        tree[i].sum=a[l];
        tree[i].sum.b[1]=1;
        return;
    }
	int mid=(l+r)/2;
	build(i*2,l,mid);
    build(i*2+1,mid+1,r);
	push_up(i);
    return;
}
void update(int i,int l,int r,int v)
{
	if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].sum=v;
        tree[i].lazy=v;
        tree[i].sum.b[1]=tree[i].r-tree[i].l+1;
		return;
	}
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,v);
	if(r>=tree[i*2+1].l) update(i*2+1,l,r,v);
	push_up(i);
    return;
}
Node query(int i,int l,int r)
{
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    push_down(i);
    Node res;
	if(l<=tree[i*2].r) res+=query(i*2,l,r);
	if(r>=tree[i*2+1].l) res+=query(i*2+1,l,r);
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    p=100/p;
	for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);
			update(1,l,r,v);
        }
        else if(op==2)
		{
            int l,r;
            scanf("%d%d",&l,&r);
			Node ans=query(1,l,r);
            printf("%d ",ans.cnt);
			for(int i=1;i<=ans.cnt;i++)
                printf("%d ",ans.a[i]);
            printf("\n");
		}
	}
	return 0;
}