#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
int tot=2;
long long a[N];
struct Node
{
	int op,x,y,k;
};
vector<Node>res;
void _add(int x,int y,int k)
{
	a[k]=a[x]+a[y];
	res.push_back((Node){0,x,y,k});
	return;
}
void _comp(int x,int y,int k)
{
	a[k]=a[x]<a[y];
	res.push_back((Node){1,x,y,k});
	return;
}
int getmin(int x,int y)
{
	int k=++tot;
	_comp(k,x,k);
	_comp(k,y,++tot);
	_add(k,tot,k);
	_add(x,y,tot);
	_comp(k,tot,k);
	return k;
}
int pos2[N];
int get1(int x,int y)
{
	int k=++tot;
	_add(x,y,k);
	_add(k,k,k);
	_comp(x,k,k);
	return k;
}
void get2()
{
	pos2[0]=get1(0,1);
	for(int i=1;i<=30;i++)
	{
		pos2[i]=++tot;
		_add(pos2[i-1],pos2[i-1],pos2[i]);
	}
	return;
}
int Pw(int p,int b)
{
	int r=++tot;
	_add(r,p,r);
	for(int i=1;i<=b;i++)
		_add(r,r,r);
	return r;
}
void divide(vector<int>&res,int p)
{
	int cur=++tot;
	res.resize(61);
	for(int i=30;i>=0;i--)
	{
		int tmp1=++tot;
		_add(cur,pos2[i],tmp1);
		int tmp2=++tot;
		_add(p,pos2[0],tmp2);
		res[i]=++tot;
		_comp(tmp1,tmp2,res[i]);
		_add(cur,Pw(res[i],i),cur);
	}
	return;
}
void mul(const vector<int>&A,const vector<int>&B)
{
	int res=2;
	for(int i=0;i<=30;i++)
		for(int j=0;j<=30;j++)
		{
			int c=getmin(A[i],B[j]);
			_add(res,Pw(c,i+j),res);
		}
	return;
}
int main()
{
	a[0]=2,a[1]=3;
	get2();
	vector<int>A,B;
	divide(A,0);
	divide(B,1);
	mul(A,B);
	printf("%u\n",res.size());
	for(Node u:res)
		if(u.op==0) printf("+ %d %d %d\n",u.x,u.y,u.k);
		else printf("< %d %d %d\n",u.x,u.y,u.k);
	return 0;
}
