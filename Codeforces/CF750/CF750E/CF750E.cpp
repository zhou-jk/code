#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200001;
const int INF=1061109567;
int n,q;
char s[N];
struct Matrix
{
	int mat[5][5];
    Matrix()
    {
        memset(mat,63,sizeof(mat));
        return;
    }
    Matrix operator=(const char &c)
    {
        for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				mat[i][j]=(i==j)?0:INF;
		if(c=='2') mat[0][1]=0,mat[0][0]=1;
		if(c=='0') mat[1][2]=0,mat[1][1]=1;
		if(c=='1') mat[2][3]=0,mat[2][2]=1;
		if(c=='7') mat[3][4]=0,mat[3][3]=1;
		if(c=='6') mat[3][3]=1,mat[4][4]=1;
        return *this;
    }
	Matrix operator*(const Matrix &b)const
    {
		Matrix res;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				for(int k=0;k<5;k++)
					res.mat[i][j]=min(res.mat[i][j],mat[i][k]+b.mat[k][j]);
		return res;
	}
};
struct Node
{
    int l,r;
    Matrix sum;
}tree[N<<2];
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
        tree[i].sum=s[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
Matrix query(int i,int L,int R)
{
	if(L<=tree[i].l&&tree[i].r<=R) return tree[i].sum;
    if(R<=tree[i*2].r) return query(i*2,L,R);
    else if(L>=tree[i*2+1].l) return query(i*2+1,L,R);
    else return query(i*2,L,R)*query(i*2+1,L,R);
}
int main()
{
    scanf("%d%d%s",&n,&q,s+1);
	build(1,1,n);
	while(q--)
    {
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=query(1,l,r).mat[0][4];
		if(ans>=INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}