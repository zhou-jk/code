#include<cstdio>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
using namespace std;
namespace Polynomial
{
const int g=3;
const int MOD=998244353;
int n;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
vector<int>W[2];
void init_omega(int n)
{
    for(int len=1;len<=n;len<<=1)
    {
        int w=qpow(g,(MOD-1)/len),iw=getinv(w);
        W[0][len]=W[1][len]=1;
        for(int k=1;k<len;k++)
            W[0][len+k]=1LL*W[0][len+k-1]*w%MOD,W[1][len+k]=1LL*W[1][len+k-1]*iw%MOD;
    }
    return;
}
vector<int>inv;
void init_inv(int n)
{
    inv[1]=1;
    for(int i=2;i<=n;i++)
        inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    return;
}
void init(int _n)
{
    n=_n;
    W[0].resize(n*8+1);
    W[1].resize(n*8+1);
    init_omega(n*4);
    inv.resize(n*4+1);
    init_inv(n*4);
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
Poly operator+(const Poly &F,const int &x)
{
    Poly f=F;
    f[0]+=x;
    if(f[0]>=MOD) f[0]-=MOD;
    return f;
}
Poly operator+(const int &x,const Poly &F)
{
    Poly f=F;
    f[0]+=x;
    if(f[0]>=MOD) f[0]-=MOD;
    return f;
}
Poly operator-(const Poly &F,const int &x)
{
    Poly f=F;
    f[0]-=x;
    if(f[0]<0) f[0]+=MOD;
    return f;
}
Poly operator-(const int &x,const Poly &F)
{
    Poly f=F;
    int n=f.size()-1;
    for(int i=0;i<=n;i++)
        f[i]=MOD-f[i];
    f[0]+=x;
    if(f[0]>=MOD) f[0]-=MOD;
    return f;
}
Poly ntt(const Poly &F,const Poly &G,const function<int(int,int)> &mul)
{
    Poly f=F,g=G;
    int n=f.size()-1,m=g.size()-1;
    m+=n,n=1;
    while(n<=m) n<<=1;
    f.resize(n);
    g.resize(n);
    vector<int>rev(n);
    for(int i=0;i<n;i++)
    {
        rev[i]=rev[i>>1]>>1;
        if(i&1) rev[i]|=n>>1;
    }
    static const int BIT=15;
    function<void(Poly &)> dft=[=](Poly &F)
    {
        int n=F.size();
        vector<unsigned long long>f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
        {
            if(len&(1<<BIT))
            {
                for(int i=0;i<n;i++)
                    f[i]%=MOD;
            }
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    unsigned long long l=f[k];
                    int r=W[0][len+k-i]*f[k+len/2]%MOD;
                    f[k]=l+r;
                    f[k+len/2]=l+MOD-r;
                }
        }
        for(int i=0;i<n;i++)
            F[i]=f[i]%MOD;
        return;
    };
    dft(f);
    dft(g);
    for(int i=0;i<n;i++)
        f[i]=mul(f[i],g[i]);
    function<void(Poly &)> idft=[=](Poly &F)
    {
        int n=F.size();
        vector<unsigned long long>f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
        {
            if(len&(1<<BIT))
            {
                for(int i=0;i<n;i++)
                    f[i]%=MOD;
            }
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    unsigned long long l=f[k];
                    int r=W[1][len+k-i]*f[k+len/2]%MOD;
                    f[k]=l+r;
                    f[k+len/2]=l+MOD-r;
                }
        }
        for(int i=0;i<n;i++)
            F[i]=f[i]%MOD;
        int invn=getinv(n);
        for(int i=0;i<n;i++)
            F[i]=1LL*F[i]*invn%MOD;
        return;
    };
    idft(f);
    f.resize(m+1);
    return f;
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
    Poly g={getinv(f[0])};
    for(int m=2;m<=n;m<<=1)
    {
        Poly t(f.begin(),f.begin()+m);
        g=ntt(t,g,[=](const int &x,const int &y){return (2*y-1LL*y*y%MOD*x%MOD+MOD)%MOD;});
        g.resize(m);
    }
    g.resize(m+1);
    return g;
}
int w;
struct Complex
{
    int real,imag;
    bool operator ==(const Complex &b)const
    {
        return real==b.real&&imag==b.imag;
    }
    Complex operator *(const Complex &b)const
    {
        Complex res;
        res.real=(1LL*real*b.real+1LL*w*imag%MOD*b.imag)%MOD;
        res.imag=(1LL*real*b.imag+1LL*imag*b.real)%MOD;
        return res;
    }
    friend Complex qpow(Complex a,int b)
    {
        Complex res=(Complex){1,0};
        while(b)
        {
            if(b&1) res=res*a;
            a=a*a,b>>=1;
        }
        return res;
    }
};
int cipolla(int n)
{
    static mt19937 myrand(time(NULL));
    if(n==0) return 0;
    function<bool(int)>check=[=](const int &n){return qpow(n,(MOD-1)/2)==1;};
    if(!check(n)) return -1;
    int a=myrand()%(MOD-1)+1;
    while(check((1LL*a*a-n+MOD)%MOD)) a=myrand()%(MOD-1)+1;
    w=(1LL*a*a-n+MOD)%MOD;
    Complex res=qpow((Complex){a,1},(MOD+1)/2);
    return res.real;
}
Poly sqrt(const Poly &F)
{
    Poly f=F;
    int m=f.size()-1;
    int n=1;
    while(n<=m) n<<=1;
    f.resize(n);
    int g0=cipolla(f[0]);
    Poly g={min(g0,MOD-g0)};
    int inv2=getinv(2);
    for(int m=2;m<=n;m<<=1)
    {
        Poly t(f.begin(),f.begin()+m);
        g.resize(m);
        g=g*inv2+ntt(t,getinv(g),[=](const int &x,const int &y){return 1LL*inv2*x%MOD*y%MOD;});
        g.resize(m);
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
        Poly s=g;
        g.resize(m);
        g=s*(t-ln(g)+(Poly){1});
        g.resize(m);
    }
    g.resize(m+1);
    return g;
}
Poly qpow(const Poly &F,const int &k)
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
    int mu=f[pos],invm=getinv(mu);
    for(int i=0;i<=n-pos;i++)
        f[i]=1LL*f[i+pos]*invm%MOD;
    for(int i=n-pos+1;i<=n;i++)
        f[i]=0;
    g[pos]=0;
    if(1LL*pos*k<=n||pos==0) 
    {
        g=exp(k*ln(f));
        int v=qpow(mu,k);
        for(int i=n;i>=pos*k;i--)
            g[i]=1LL*g[i-pos*k]*v%MOD;
        for(int i=pos*k-1;i>=0;i--)
            g[i]=0;
    }
    return g;
}
int poly_calc(const Poly &F,const int &x)
{
    Poly f=F;
    int n=f.size()-1;
    int fc=1,res=0;
    for(int i=0;i<=n;i++)
        res=(res+1LL*f[i]*fc)%MOD,fc=1LL*fc*x%MOD;
    return res;
}
Poly poly_eval(const Poly &F,const Poly &a)
{
    Poly f=F;
    int m=a.size();
    vector<Poly>g(m<<2);
    function<void(int,int,int)> init_poly_eval=[&](int i,int l,int r)
    {
        if(l==r)
        {
            g[i]=(Poly){MOD-a[l],1};
            return;
        }
        int mid=(l+r)/2;
        init_poly_eval(i*2,l,mid);
        init_poly_eval(i*2+1,mid+1,r);
        g[i]=g[i*2]*g[i*2+1];
        return;
    };
    init_poly_eval(1,0,m-1);
    Poly res(m);
    function<void(int,int,int,const Poly &)> solve_poly_eval=[&](int i,int l,int r,const Poly &f)
    {
        if(l==r)
        {
            res[l]=f[0];
            return;
        }
        int mid=(l+r)/2;
        solve_poly_eval(i*2,l,mid,f%g[i*2]);
        solve_poly_eval(i*2+1,mid+1,r,f%g[i*2+1]);
        return;
    };
    solve_poly_eval(1,0,m-1,f);
    return res;
}
struct Point
{
    int x,y;
};
Poly poly_inte(const vector<Point> &p)
{
    int n=p.size()-1;
    vector<Poly>g(n<<2);
    function<void(int,int,int)> init_poly_eval=[&](int i,int l,int r)
    {
        if(l==r)
        {
            g[i]=(Poly){MOD-p[l].x,1};
            return;
        }
        int mid=(l+r)/2;
        init_poly_eval(i*2,l,mid);
        init_poly_eval(i*2+1,mid+1,r);
        g[i]=g[i*2]*g[i*2+1];
        return;
    };
    init_poly_eval(1,0,n);
    Poly x(n+1);
    for(int i=0;i<=n;i++)
        x[i]=p[i].x;
    Poly F=poly_eval(diff_calc(g[1]),x);
    vector<int> a(n+1);
    for(int i=0;i<=n;i++)
        a[i]=1LL*p[i].y*getinv(F[i])%MOD;
    vector<Poly>res(n<<2);
    function<void(int,int,int)> solve_poly_inte=[&](int i,int l,int r)
    {
        if(l==r)
        {
            res[i]={a[l]};
            return;
        }
        int mid=(l+r)/2;
        solve_poly_inte(i*2,l,mid);
        solve_poly_inte(i*2+1,mid+1,r);
        res[i]=res[i*2]*g[i*2+1]+res[i*2+1]*g[i*2];
        return;
    };
    solve_poly_inte(1,0,n);
    return res[1];
}
Poly operator|(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    function<void(Poly &)> fwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                    F[k+len/2]=(F[k+len/2]+F[k])%MOD;
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=1LL*f[i]*g[i]%MOD;
    function<void(Poly &)> ifwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                    F[k+len/2]=(F[k+len/2]-F[k]+MOD)%MOD;
        return;
    };
    ifwt(f);
    return f;
}
Poly operator&(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    function<void(Poly &)> fwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                    F[k]=(F[k]+F[k+len/2])%MOD;
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=1LL*f[i]*g[i]%MOD;
    function<void(Poly &)> ifwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                    F[k]=(F[k]-F[k+len/2]+MOD)%MOD;
        return;
    };
    ifwt(f);
    return f;
}
Poly operator^(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    function<void(Poly &)> fwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    int l=F[k],r=F[k+len/2];
                    F[k]=(l+r)%MOD;
                    F[k+len/2]=(l-r+MOD)%MOD;
                }
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=(long long)f[i]*g[i]%MOD;
    function<void(Poly &)> ifwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    int l=F[k],r=F[k+len/2];
                    F[k]=(l+r)%MOD;
                    F[k+len/2]=(l-r+MOD)%MOD;
                }
        int invn=getinv(n);
        for(int i=0;i<(int)F.size();i++)
            F[i]=(long long)F[i]*invn%MOD;
        return;
    };
    ifwt(f);
    return f;
}
}
using Polynomial::init;
using Polynomial::Poly;
using Polynomial::operator+;
using Polynomial::operator-;
using Polynomial::operator*;
using Polynomial::operator/;
using Polynomial::operator%;
using Polynomial::operator^;
using Polynomial::operator|;
using Polynomial::getinv;
using Polynomial::sqrt;
using Polynomial::diff_calc;
using Polynomial::inte_calc;
using Polynomial::ln;
using Polynomial::exp;
using Polynomial::qpow;
using Polynomial::poly_calc;
using Polynomial::poly_eval;
using Polynomial::poly_inte;