#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2000005;
const int MOD=200003;
const double Pi=acos(-1);
struct Complex
{
	double x,y;
	Complex(double xx=0,double yy=0)
	{
		x=xx,y=yy;
		return;
	}
	Complex operator+(Complex const &b)const
	{
		return (Complex){x+b.x,y+b.y};
	}
	Complex operator-(Complex const &b)const
	{
		return (Complex){x-b.x,y-b.y};
	}
	Complex operator*(Complex const &b)const
	{
		return (Complex){x*b.x-y*b.y,x*b.y+y*b.x};
	}
};
Complex W[N<<1];
void dft(vector<Complex> &f,int len)
{
	if(len==1) return;
	vector<Complex> fl,fr;
	fl.resize(len/2),fr.resize(len/2);
	for(int k=0;k<len/2;k++)
		fl[k]=f[k*2],fr[k]=f[k*2+1];
	dft(fl,len/2);
	dft(fr,len/2);
	Complex w=W[len],buf=(Complex){1,0};
	for(int k=0;k<len/2;k++)
	{
		f[k]=fl[k]+buf*fr[k];
		f[k+len/2]=fl[k]-buf*fr[k];
		buf=buf*w;
	}
	return;
}
void idft(vector<Complex> &f,int len)
{
	if(len==1) return;
	vector<Complex> fl,fr;
	fl.resize(len/2),fr.resize(len/2);
	for(int k=0;k<len/2;k++)
		fl[k]=f[k*2],fr[k]=f[k*2+1];
	idft(fl,len/2);
	idft(fr,len/2);
	Complex w=(Complex){W[len].x,-W[len].y},buf=(Complex){1,0};
	for(int k=0;k<len/2;k++)
	{
		f[k]=fl[k]+buf*fr[k];
		f[k+len/2]=fl[k]-buf*fr[k];
		buf=buf*w;
	}
	return;
}
typedef vector<long long> poly;
poly fft(const poly &F,const poly &G)
{
	vector<Complex> f,g;
	int n=F.size()-1,m=G.size()-1;
	f.resize(n+1),g.resize(m+1);
	for(int i=0;i<=n;i++)
		f[i].x=F[i];
	for(int i=0;i<=m;i++)
		g[i].x=G[i];
	for(m+=n,n=1;n<=m;n<<=1);
	for(int i=1;i<=n;i++)
		W[i]=(Complex){cos(2*Pi/i),sin(2*Pi/i)};
	f.resize(n);
	g.resize(n);
	dft(f,n);
	dft(g,n);
	for(int i=0;i<n;i++)
		f[i]=f[i]*g[i];
	idft(f,n);
	poly res;
	res.resize(m+1);
	for(int i=0;i<=m;i++)
		res[i]=(long long)(f[i].x/n+0.5);
	return res;
}
const int G=2;
int n;
int a[N];
long long powG[N],logG[N];
void init()
{
	powG[0]=1;
	logG[1]=0;
	for(int i=1;i<=MOD-2;i++)
	{
		powG[i]=powG[i-1]*G%MOD;
		logG[powG[i]]=i;
	}
	return;
}
int cnt[N];
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]) cnt[logG[a[i]]]++;
	}
	poly f;
	f.resize(MOD-1);
	for(int i=0;i<=MOD-2;i++)
		f[i]=cnt[i];
	f=fft(f,f);
	long long ans=0;
	for(int i=0;i<f.size();i++)
		ans+=f[i]*powG[i%(MOD-1)];
	for(int i=0;i<=MOD-2;i++)
		ans-=cnt[i]*(powG[i]*powG[i]%MOD);
	printf("%lld",ans/2);
	return 0;
}

