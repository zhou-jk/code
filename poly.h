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
const int N=200005;
const int g=3;
const int MOD=1004535809;
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=1LL*res*a%MOD;
		a=1LL*a*a%MOD,b>>=1;
	}
	return res;
}
int W[2][N<<1];
typedef vector<int> Poly;
Poly operator+(const Poly &a,const Poly &b)
{
	Poly f=a,g=b;
	int n=max(a.size(),b.size());
	f.resize(n),g.resize(n);
	Poly c(n);
	for(int i=0;i<n;i++)
	{
		c[i]=f[i]+g[i];
		if(c[i]>=MOD) c[i]-=MOD;
	}
	return c;
}
Poly operator-(const Poly &a,const Poly &b)
{
	Poly f=a,g=b;
	int n=max(a.size(),b.size());
	f.resize(n),g.resize(n);
	Poly c(n);
	for(int i=0;i<n;i++)
	{
		c[i]=f[i]-g[i];
		if(c[i]<0) c[i]+=MOD;
	}
	return c;
}
Poly ntt(const Poly &F,const Poly &G,const function<int(int,int)> &mul)
{
	Poly f=F,g=G;
	int n=f.size()-1,m=g.size()-1;
	m+=n,n=1;
	while(n<=m) n<<=1;
	for(int i=1;i<=n;i<<=1)
		W[0][i]=ksm(::g,(MOD-1)/i),W[1][i]=ksm(W[0][i],MOD-2);
	f.resize(n);
	g.resize(n);
	vector<int>rev(n);
	for(int i=0;i<n;i++)
	{
		rev[i]=rev[i/2]>>1;
		if(i&1) rev[i]|=n/2;
	}
	function<void(Poly &)> dft=[=](Poly &F)
	{
		int n=F.size();
		Poly f(n);
		for(int i=0;i<n;i++)
			f[i]=F[rev[i]];
		for(int len=2;len<=n;len<<=1)
		{
			int w=W[0][len];
			for(int i=0;i<n;i+=len)
			{
				int buf=1;
				for(int k=i;k<i+len/2;k++)
				{
					int l=f[k],r=1LL*buf*f[k+len/2]%MOD;
					f[k]=l+r;
					if(f[k]>=MOD) f[k]-=MOD;
					f[k+len/2]=l-r;
					if(f[k+len/2]<0) f[k+len/2]+=MOD;
					buf=1LL*buf*w%MOD;
				}
			}
		}
		F=f;
		return;
	};
	dft(f);
	dft(g);
	for(int i=0;i<n;i++)
		f[i]=mul(f[i],g[i]);
	function<void(Poly &)> idft=[=](Poly &F)
	{
		int n=F.size();
		Poly f(n);
		for(int i=0;i<n;i++)
			f[i]=F[rev[i]];
		for(int len=2;len<=n;len<<=1)
		{
			int w=W[1][len];
			for(int i=0;i<n;i+=len)
			{
				int buf=1;
				for(int k=i;k<i+len/2;k++)
				{
					int l=f[k],r=1LL*buf*f[k+len/2]%MOD;
					f[k]=l+r;
					if(f[k]>=MOD) f[k]-=MOD;
					f[k+len/2]=l-r;
					if(f[k+len/2]<0) f[k+len/2]+=MOD;
					buf=1LL*buf*w%MOD;
				}
			}
		}
		F=f;
		return;
	};
	idft(f);
	Poly res(m+1);
	int invn=ksm(n,MOD-2);
	for(int i=0;i<=m;i++)
		res[i]=1LL*f[i]*invn%MOD;
	return res;
}
Poly operator*(const Poly &F,const Poly &G)
{
	return ntt(F,G,[=](const int &x,const int &y){return 1LL*x*y%MOD;});
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
	Poly g={ksm(f[0],MOD-2)};
	for(int m=2;m<=n;m<<=1)
	{
		Poly t(f.begin(),f.begin()+m);
		g=ntt(t,g,[=](const int &x,const int &y){return (2*y-1LL*y*y%MOD*x%MOD+MOD)%MOD;});
		g.resize(m);
	}
	g.resize(m+1);
	return g;
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
	vector<int>inv(n+2);
	inv[1]=1;
	for(int i=2;i<=n+1;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=0;i<=n;i++)
		f[i+1]=1LL*g[i]*inv[i+1]%MOD;
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
Poly exp(const Poly &F)
{
	Poly f=F;
	int m=f.size()-1;
	int n=1;
	while(n<=m) n<<=1;
	f.resize(n);
	Poly g={1};
	for(int m=2;m<=n;m<<=1)
	{
		Poly t(f.begin(),f.begin()+m);
		g.resize(m);
		Poly s=t-ln(g)+(Poly){1};
		g=g*s;
		g.resize(m);
	}
	g.resize(m+1);
	return g;
}
bool isbig;
Poly ksm(const Poly &F,const int &k1,const int &k2)
{
	Poly f=F;
	int n=f.size()-1;
	Poly g(n+1);
	int pos=-1;
	for(int i=0;i<=n;i++)
		if(f[i]>0)
		{
			g[i]=f[i];
			pos=i;
			break;
		}
	if(pos==-1) return g;
	int mu=f[pos],invm=ksm(mu,MOD-2);
	for(int i=0;i<=n-pos;i++)
		f[i]=1LL*f[i+pos]*invm%MOD;
	for(int i=n-pos+1;i<=n;i++)
		f[i]=0;
	g[pos]=0;
	if((!isbig&&1LL*pos*k1<=n)||pos==0) 
	{
		g=exp(k2*ln(f));
		int v=ksm(mu,k1);
		for(int i=n;i>=pos*k1;i--)
			g[i]=1LL*g[i-pos*k1]*v%MOD;
		for(int i=pos*k1-1;i>=0;i--)
			g[i]=0;
	}
	return g;
}
pair<int,int>read(const int &p1,const int &p2)
{
	char ch;
	bool flag=true;
	pair<int,int>x={0,0};
	for(ch=getchar();!isdigit(ch);ch=getchar())
		if(ch=='-') flag=false;
	while(isdigit(ch))
	{
		if(1LL*x.first*10+ch-'0'>=MOD-1) isbig=true;
		x.first=(1LL*x.first*10+ch-'0')%p1;
		x.second=(1LL*x.second*10+ch-'0')%p2;
		ch=getchar();
	}
	if(!flag) x={p1-x.first,p2-x.second};
	return x;
}
int main()
{
	int n,t;
	scanf("%d",&n);
	pair<int,int> k=read(MOD-1,MOD);
	scanf("%d",&t);
	Poly a(n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(t==0)
	{
		Poly f(n,1);
		Poly g=a*ksm(f,k.first,k.second);
		g.resize(n);
		for(int i=0;i<n;i++)
			printf("%d ",g[i]);
	}
	else if(t==1)
	{
		Poly f={1,MOD-1};
		f.resize(n);
		Poly g=a*ksm(f,k.first,k.second);
		g.resize(n);
		for(int i=0;i<n;i++)
			printf("%d ",g[i]);
	}
	return 0;
}
