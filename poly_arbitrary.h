#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
using namespace std;
const int N=(1<<19)+5;
const int g=3;
int MOD;
const int MOD1=998244353,MOD2=1004535809,MOD3=469762049;
int ksm(int a,int b,int P=MOD)
{
	int res=1;
	while(b)
	{
		if(b&1) res=1LL*res*a%P;
		a=1LL*a*a%P,b>>=1;
	}
	return res;
}
int getinv(int x,int P=MOD)
{
	return ksm(x,P-2,P);
}
struct Int
{
	int x1,x2,x3;
	Int(int a=0,int b=0,int c=0)
	{
		x1=(a%MOD1+MOD1)%MOD1,x2=(b%MOD2+MOD2)%MOD2,x3=(c%MOD3+MOD3)%MOD3;
		return;
	}
	Int(long long a,long long b,long long c)
	{
		x1=(a%MOD1+MOD1)%MOD1,x2=(b%MOD2+MOD2)%MOD2,x3=(c%MOD3+MOD3)%MOD3;
		return;
	}
	Int operator=(int x)
	{
		*this=(Int){x,x,x};
		return *this;
	}
	Int operator=(long long x)
	{
		*this=(Int){x,x,x};
		return *this;
	}
	Int operator+(const Int &rhs)const
	{
		Int c=(Int){x1+rhs.x1,x2+rhs.x2,x3+rhs.x3};
		return c;
	}
	Int operator-(const Int &rhs)const
	{
		Int c=(Int){x1-rhs.x1,x2-rhs.x2,x3-rhs.x3};
		return c;
	}
	Int operator*(const Int &rhs)const
	{
		Int c=(Int){1LL*x1*rhs.x1,1LL*x2*rhs.x2,1LL*x3*rhs.x3};
		return c;
	}
	Int operator/(const Int &rhs)const
	{
		Int c=(Int){1LL*x1*getinv(rhs.x1,MOD1),1LL*x2*getinv(rhs.x2,MOD2),1LL*x3*getinv(rhs.x3,MOD3)};
		return c;
	}
	Int operator+=(const Int &rhs)
	{
		*this=*this+rhs;
		return *this;
	}
	Int operator-=(const Int &rhs)
	{
		*this=*this-rhs;
		return *this;
	}
	Int operator*=(const Int &rhs)
	{
		*this=*this*rhs;
		return *this;
	}
	Int operator/=(const Int &rhs)
	{
		*this=*this/rhs;
		return *this;
	}
	int to_int(int P=MOD)const
	{
		static const int INV12=getinv(MOD1,MOD2),INV123=getinv(1LL*MOD1*MOD2%MOD3,MOD3);
		int k1=1LL*(x2-x1%MOD2+MOD2)*INV12%MOD2;
		long long x4=x1+1LL*k1*MOD1;
		int k4=(x3-x4%MOD3+MOD3)%MOD3*INV123%MOD3;
		long long x=(x4+1LL*k4%P*(1LL*MOD1*MOD2%P)%P)%P;
		return x;
	}
	friend Int getinv(const Int &rhs)
	{
		Int c=(Int){getinv(rhs.x1,MOD1),getinv(rhs.x2,MOD2),getinv(rhs.x3,MOD3)};
		return c;
	}
	Int operator+(const int &rhs)const
	{
		return *this+(Int){rhs,rhs,rhs};
	}
	Int operator+(const long long &rhs)const
	{
		return *this+(Int){rhs,rhs,rhs};
	}
	Int operator-(const int &rhs)const
	{
		return *this-(Int){rhs,rhs,rhs};
	}
	Int operator-(const long long &rhs)const
	{
		return *this-(Int){rhs,rhs,rhs};
	}
	Int operator*(const int &rhs)const
	{
		return *this*(Int){rhs,rhs,rhs};
	}
	Int operator*(const long long &rhs)const
	{
		return *this*(Int){rhs,rhs,rhs};
	}
	Int operator/(const int &rhs)const
	{
		return *this*getinv((Int){rhs,rhs,rhs});
	}
	Int operator/(const long long &rhs)const
	{
		return *this*getinv((Int){rhs,rhs,rhs});
	}
	friend Int operator+(const int &lhs,const Int &rhs)
	{
		return rhs+lhs;
	}
	friend Int operator+(const long long &lhs,const Int &rhs)
	{
		return rhs+lhs;
	}
	friend Int operator-(const int &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}-rhs;
	}
	friend Int operator-(const long long &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}-rhs;
	}
	friend Int operator*(const int &lhs,const Int &rhs)
	{
		return rhs*lhs;
	}
	friend Int operator*(const long long &lhs,const Int &rhs)
	{
		return rhs*lhs;
	}
	friend Int operator/(const int &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}*getinv(rhs);
	}
	friend Int operator/(const long long &lhs,const Int &rhs)
	{
		return (Int){lhs,lhs,lhs}*getinv(rhs);
	}
};
Int W[2][N<<1];
void init_omega(int n=1<<19)
{
	for(int len=1;len<=n;len<<=1)
	{
		Int w=(Int){ksm(g,(MOD1-1)/len,MOD1),ksm(g,(MOD2-1)/len,MOD2),ksm(g,(MOD3-1)/len,MOD3)},iw=getinv(w);
		W[0][len]=W[1][len]=1;
		for(int k=1;k<len;k++)
			W[0][len+k]=W[0][len+k-1]*w,W[1][len+k]=W[1][len+k-1]*iw;
	}
	return;
}
int inv[N];
void init_inv(int n=1<<19)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	return;
}
typedef vector<int> Poly;
Poly operator+(const Poly &a,const Poly &b)
{
	Poly f=a,g=b;
	int n=max(a.size(),b.size());
	f.resize(n),g.resize(n);
	Poly c(n);
	for(int i=0;i<n;i++)
		c[i]=(f[i]+g[i])%MOD;
	return c;
}
Poly operator-(const Poly &a,const Poly &b)
{
	Poly f=a,g=b;
	int n=max(a.size(),b.size());
	f.resize(n),g.resize(n);
	Poly c(n);
	for(int i=0;i<n;i++)
		c[i]=(f[i]-g[i]+MOD)%MOD;
	return c;
}
Poly ntt(const Poly &F,const Poly &G,const function<Int(const Int &,const Int &)> &mul)
{
	int n=F.size()-1,m=G.size()-1;
	vector<Int> f(n+1),g(m+1);
	for(int i=0;i<=n;i++)
		f[i]=F[i];
	for(int i=0;i<=m;i++)
		g[i]=G[i];
	m+=n,n=1;
	while(n<=m) n<<=1;
	f.resize(n);
	g.resize(n);
	vector<int>rev(n);
	for(int i=0;i<n;i++)
	{
		rev[i]=rev[i/2]>>1;
		if(i&1) rev[i]|=n/2;
	}
	function<void(vector<Int> &)> dft=[=](vector<Int> &F)
	{
		int n=F.size();
		vector<Int> f(n);
		for(int i=0;i<n;i++)
			f[i]=F[rev[i]];
		for(int len=2;len<=n;len<<=1)
			for(int i=0;i<n;i+=len)
				for(int k=i;k<i+len/2;k++)
				{
					Int l=f[k];
					Int r=W[0][len+k-i]*f[k+len/2];
					f[k]=l+r;
					f[k+len/2]=l-r;
				}
		for(int i=0;i<n;i++)
			F[i]=f[i];
		return;
	};
	dft(f);
	dft(g);
	for(int i=0;i<n;i++)
		f[i]=mul(f[i],g[i]);
	function<void(vector<Int> &)> idft=[=](vector<Int> &F)
	{
		int n=F.size();
		vector<Int> f(n);
		for(int i=0;i<n;i++)
			f[i]=F[rev[i]];
		for(int len=2;len<=n;len<<=1)
			for(int i=0;i<n;i+=len)
				for(int k=i;k<i+len/2;k++)
				{
					Int l=f[k];
					Int r=W[1][len+k-i]*f[k+len/2];
					f[k]=l+r;
					f[k+len/2]=l-r;
				}
		Int invn=getinv((Int){n,n,n});
		for(int i=0;i<n;i++)
			F[i]=f[i]*invn;
		return;
	};
	idft(f);
	Poly res(m+1);
	for(int i=0;i<=m;i++)
		res[i]=f[i].to_int();
	return res;
}
Poly operator*(const Poly &F,const Poly &G)
{
	return ntt(F,G,[=](const Int &x,const Int &y){return x*y;});
}
Poly operator*(const Poly &F,const int &x)
{
	Poly f=F;
	int n=f.size()-1;
	for(int i=0;i<=n;i++)
		f[i]=1LL*f[i]*x%MOD;
	return f; 
}
Poly operator*(const int &x,const Poly &F)
{
	Poly f=F;
	int n=f.size()-1;
	for(int i=0;i<=n;i++)
		f[i]=1LL*f[i]*x%MOD;
	return f; 
}
Poly getinv(const Poly &F)
{
	Poly f=F;
	int m=f.size()-1;
	int n=1;
	while(n<=m) n<<=1;
	f.resize(n);
	Poly g={getinv(f[0])};
	for(int m=2;m<=n;m<<=1)
	{
		Poly t(f.begin(),f.begin()+m);
		Poly yyx=g*g;
		yyx.resize(m);
		yyx=yyx*t;
		yyx.resize(m);
		g.resize(m);
		for(int i=0;i<m;i++)
			g[i]=(g[i]*2LL-yyx[i]+MOD)%MOD;
	}
	g.resize(m+1);
	return g;
}
Poly operator/(const Poly &F,const Poly &G)
{
	Poly f=F,g=G;
	int n=f.size()-1,m=g.size()-1;
	if(n<m) return Poly(n-m+1);
	reverse(f.begin(),f.end());
	reverse(g.begin(),g.end());
	f.resize(n-m+1);
	g.resize(n-m+1);
	Poly q=f*getinv(g);
	q.resize(n-m+1);
	reverse(q.begin(),q.end());
	return q;
}
Poly operator%(const Poly &F,const Poly &G)
{
	Poly f=F,g=G,q=f/g;
	int m=g.size()-1;
	g.resize(m);
	q.resize(m);
	Poly c=g*q;
	c.resize(m);
	f.resize(m);
	return f-c;
}
Poly diff_calc(const Poly &F)
{
	Poly f=F;
	int n=f.size()-1;
	Poly g(n);
	for(int i=1;i<=n;i++)
		g[i-1]=1LL*f[i]*i%MOD;
	return g;
}
Poly inte_calc(const Poly &G)
{
	Poly g=G;
	int n=g.size()-1;
	Poly f(n+2);
	for(int i=1;i<=n+1;i++)
		f[i]=1LL*g[i-1]*inv[i]%MOD;
	return f;
}
Poly ln(const Poly &F)
{
	Poly f=F;
	int n=f.size()-1;
	Poly g=diff_calc(f)*getinv(f);
	g.resize(n+1);
	g=inte_calc(g);
	g.resize(n+1);
	return g;
}