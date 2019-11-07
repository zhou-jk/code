#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1061109567;
inline int read()
{
	char ch;
	bool flag=true;
	int ret=0;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') flag=false;
	while(ch>='0'&&ch<='9')
		ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
	return flag?ret:-ret;
}
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(int x)
{
	write(x);
	putchar('\n');
	return;
}
int N,K,Q;
int a[300001];
int dp[300001];
struct Matrix
{
	int c[6][6];
    Matrix()
    {
        for(int i=1;i<=K;i++)
			for(int j=1;j<=K;j++)
				c[i][j]=INF;
        return;
    }
	Matrix operator =(const int &b)
	{
		memset(c,63,sizeof(c));
		for(int i=1;i<=K;i++)
        	c[i][1]=b;
		for(int i=1;i<K;i++)
	    	c[i][i+1]=0;
		return *this;
	}
	Matrix operator *(const Matrix &b)const
	{
		Matrix res;
		for(int i=1;i<=K;i++)
			for(int j=1;j<=K;j++)
				for(int k=1;k<=K;k++)
					res.c[i][j]=min(res.c[i][j],c[i][k]+b.c[k][j]);
		return res;
	}
	Matrix operator +(const Matrix &b)const
	{
		Matrix res;
		for(int j=1;j<=K;j++)
			for(int k=1;k<=K;k++)
				res.c[1][j]=min(res.c[1][j],c[1][k]+b.c[k][j]);
		return res;
	}
};
struct Node
{
	int l,r;
	Matrix sum;
}tree[1200001];
void push_up(int i)
{
	tree[i].sum=tree[i*2].sum*tree[i*2+1].sum;
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
void update(int i,int u,int k)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].sum=k;
		return;
	}
	if(u<=tree[i*2].r) update(i*2,u,k);
	else update(i*2+1,u,k);
	push_up(i);
	return;
}
Matrix query(int i,int l,int r)
{
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
	if(r<=tree[i*2].r) return query(i*2,l,r);
	else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
	else return query(i*2,l,r)*query(i*2+1,l,r);
}
int main()
{
	N=read(),K=read();
	for(int i=1;i<=N;i++)
	{
		char ch;
		for(ch=getchar();ch!='.'&&ch!='#';ch=getchar());
		a[i]=ch=='#';
	}
	build(1,1,N);
	Q=read();
	while(Q--)
    {
		char ch;
		for(ch=getchar();ch!='1'&&ch!='2';ch=getchar());
		if(ch=='1')
		{
			int l=read(),r=read();
			dp[l]=a[l];
			for(int i=l+1;i<=l+K-1&&i<=r;i++)
			{
				dp[i]=INF;
				for(int j=1;j<=K;j++)
					if(i-j>=l) dp[i]=min(dp[i],dp[i-j]+a[i]);
			}
			if(r<=l+K-1)
			{
				writeln(dp[r]);
				continue;
			}
			Matrix res;
			for(int i=1;i<=K;i++)
				res.c[1][i]=dp[l+K-i];
			res=res+query(1,l+K,r);
			writeln(res.c[1][1]);
		}
		else if(ch=='2')
		{
			int u=read(),val=read();
			if((val&1)!=a[u])
			{
				update(1,u,val&1);
				a[u]=val&1;
			}
		}
	}
	return 0;
}