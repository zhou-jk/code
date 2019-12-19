#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
struct Matrix
{
	long long a[1300][1300];
	int x,y;
	Matrix()
	{
		memset(a,0,sizeof(a));
		x=y=0;
		return;
	}
	Matrix operator*(const Matrix &b)const
	{
		Matrix res;
		for(int i=0;i<x;i++)
			for(int j=0;j<b.y;j++)
				for(int k=0;k<y;k++)
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]%MOD)%MOD;
		res.x=x,res.y=b.y;
		return res;
	}
	Matrix operator*=(const Matrix &b)
	{
		*this=*this * b;
		return *this; 
	}
	friend Matrix ksm(Matrix m,int b)
	{
		Matrix res;
		for(int i=0;i<m.x;i++)
			res.a[i][i]=1;
		res.x=res.y=m.x;
		while(b)
		{
			if(b&1) res*=m;
			m*=m,b>>=1;
		}
		return res;
	}
};
int n;
Matrix ans,res;
bool check(int i,int j,int k,int l)
{
	for(int m=0;m<=i;m++)
		if((j&(1<<m))&&(k&(1<<m)))
		{
			if(m==0&&(l&(1<<m))) return false;
			if(m==i&&(l&(1<<(m-1)))) return false;
			if(m>0&&m<i&&(l&(1<<m))&&(l&(1<<(m-1)))) return false;
		}
	return true;
}
int main()
{
	ans.x=1,ans.y=2;
	ans.a[0][0]=0,ans.a[0][1]=1;
	for(int i=0;i<7;i++)
	{
		res.x=res.y=(1<<(i+1));
		for(int j=0;j<res.y;j++)
			for(int k=0;k<res.x;k++)
			{
				int cnt=0;
				for(int l=0;l<(1<<i);l++)
				{
					if(i==0&&j==1&&k==1) continue;
					if(check(i,j,k,l)) cnt++;
				}
				res.a[k][j]=cnt;
			}
		int x;
		scanf("%d",&x);
		ans*=ksm(res,x);
		for(int j=0;j<ans.y;j++)
			ans.a[0][j+(1<<(i+1))]=ans.a[0][j],ans.a[0][j]=0;
		ans.y*=2;
	}
	printf("%lld",ans.a[0][ans.y-1]);
	return 0;
}