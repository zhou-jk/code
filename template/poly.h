#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<ctime>
#include<chrono>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
using namespace std;
namespace Polynomial
{
constexpr int MOD=998244353;
int add(int a,int b)
{
    a+=b;
    return a>=MOD?a-MOD:a;
}
int sub(int a,int b)
{
    return a>=b?a-b:a+MOD-b;
}
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
typedef vector<int> Poly;
int gw[(1<<21)+1];
vector<int>inv;
void init(int _n)
{
    static int n=1;
    if(_n<n) return;
    int t=1;
    while((1<<t)<_n) t++;
    t=min(t-1,21);
    gw[0]=1,gw[1<<t]=qpow(31,1<<(21-t));
    for(int i=t;i>0;i--)
        gw[1<<(i-1)]=(long long)gw[1<<i]*gw[1<<i]%MOD;
    for(int i=1;i<(1<<t);i++)
        gw[i]=(long long)gw[i&(i-1)]*gw[i&-i]%MOD;
    inv.resize(_n+1);
    inv[1]=1;
    for(int i=2;i<=_n;i++)
        inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
    n=_n;
    return;
}
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
constexpr int BIT=10;
void dft(Poly &F,int _n)
{
    int n=1;
    while(n<_n) n<<=1;
    init(n);
    F.resize(n);
    vector<unsigned long long>f(n);
    for(int i=0;i<n;i++)
        f[i]=F[i];
    for(int len=n;len>1;len>>=1)
    {
        if((len>>BIT)&1)
        {
            for(int i=0;i<n;i++)
                f[i]%=MOD;
        }
        for(int i=0,*w=gw;i<n;i+=len,w++)
            for(int k=i;k<i+(len>>1);k++)
            {
                unsigned long long l=f[k];
                int r=(*w)*f[k+(len>>1)]%MOD;
                f[k]=l+r;
                f[k+(len>>1)]=l+MOD-r;
            }
    }
    for(int i=0;i<n;i++)
        F[i]=f[i]%MOD;
    return;
}
void idft(Poly &F,int _n)
{
    int n=1;
    while(n<_n) n<<=1;
    init(n);
    F.resize(n);
    vector<unsigned long long>f(n);
    for(int i=0;i<n;i++)
        f[i]=F[i];
    for(int len=2;len<=n;len<<=1)
    {
        if((len>>BIT)&1)
        {
            for(int i=0;i<n;i++)
                f[i]%=MOD;
        }
        for(int i=0,*w=gw;i<n;i+=len,w++)
            for(int k=i;k<i+(len>>1);k++)
            {
                unsigned long long l=f[k];
                int r=f[k+(len>>1)]%MOD;
                f[k]=l+r;
                f[k+(len>>1)]=(l+MOD-r)*(*w)%MOD;
            }
    }
    int invn=getinv(n);
    for(int i=0;i<n;i++)
        F[i]=f[i]%MOD*invn%MOD;
    reverse(F.begin()+1,F.end());
    return;
}
Poly ntt(const Poly &F,const Poly &G,const function<int(int,int)> &mul)
{
    Poly f=F,g=G;
    int n=f.size()-1,m=g.size()-1;
    m+=n,n=1;
    while(n<=m) n<<=1;
    f.resize(n);
    g.resize(n);
    dft(f,n);
    dft(g,n);
    for(int i=0;i<n;i++)
        f[i]=mul(f[i],g[i]);
    idft(f,n);
    f.resize(m+1);
    return f;
}
Poly operator*(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int n=f.size()-1,m=g.size()-1;
    m+=n,n=1;
    while(n<=m) n<<=1;
    f.resize(n);
    g.resize(n);
    dft(f,n);
    dft(g,n);
    for(int i=0;i<n;i++)
        f[i]=(long long)f[i]*g[i]%MOD;
    idft(f,n);
    f.resize(m+1);
    return f;
}
Poly operator*(const Poly &F,const int &x)
{
    Poly f=F;
    int n=f.size()-1;
    for(int i=0;i<=n;i++)
        f[i]=(long long)f[i]*x%MOD;
    return f; 
}
Poly operator*(const int &x,const Poly &F)
{
    Poly f=F;
    int n=f.size()-1;
    for(int i=0;i<=n;i++)
        f[i]=(long long)f[i]*x%MOD;
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
        g=ntt(t,g,[&](const int &x,const int &y){return (2*y-(long long)y*y%MOD*x%MOD+MOD)%MOD;});
        g.resize(m);
    }
    g.resize(m+1);
    return g;
}
struct Complex
{
    static int w;
    int real,imag;
    Complex(){}
    Complex(int _real,int _imag):real(_real),imag(_imag){}
    Complex operator *(const Complex &b)const
    {
        Complex res;
        res.real=((long long)real*b.real+(long long)w*imag%MOD*b.imag)%MOD;
        res.imag=((long long)real*b.imag+(long long)imag*b.real)%MOD;
        return res;
    }
    friend Complex qpow(Complex a,int b)
    {
        Complex res=Complex(1,0);
        while(b)
        {
            if(b&1) res=res*a;
            a=a*a,b>>=1;
        }
        return res;
    }
};
int Complex::w;
int cipolla(int n)
{
    static mt19937 myrand(chrono::system_clock::now().time_since_epoch().count());
    if(n==0) return 0;
    function<bool(int)>check=[&](int x){return qpow(x,(MOD-1)/2)==1;};
    if(!check(n)) return -1;
    int a=myrand()%(MOD-1)+1;
    while(check(((long long)a*a-n+MOD)%MOD)) a=myrand()%(MOD-1)+1;
    Complex::w=((long long)a*a-n+MOD)%MOD;
    Complex res=qpow(Complex(a,1),(MOD+1)/2);
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
        g=g*inv2+ntt(t,getinv(g),[&](const int &x,const int &y){return (long long)inv2*x%MOD*y%MOD;});
        g.resize(m);
    }
    g.resize(m+1);
    return g;
}
Poly operator/(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int n=f.size()-1,m=g.size()-1;
    if(n<m) return Poly(n-m+1,0);
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
Poly poly_derivatives(const Poly &F)
{
    Poly f=F;
    int n=f.size()-1;
    Poly g(n);
    for(int i=1;i<=n;i++)
        g[i-1]=(long long)f[i]*i%MOD;
    return g;
}
Poly poly_integration(const Poly &G)
{
    Poly g=G;
    int n=g.size()-1;
    init(n+2);
    Poly f(n+2);
    for(int i=1;i<=n+1;i++)
        f[i]=(long long)g[i-1]*inv[i]%MOD;
    return f;
}
Poly ln(const Poly &F)
{
    Poly f=F;
    int n=f.size()-1;
    Poly g=poly_derivatives(f)*getinv(f);
    g.resize(n+1);
    g=poly_integration(g);
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
        g=s*(t-ln(g)+Poly(1,1));
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
        f[i]=(long long)f[i+pos]*invm%MOD;
    for(int i=n-pos+1;i<=n;i++)
        f[i]=0;
    g[pos]=0;
    if((long long)pos*k<=n||pos==0) 
    {
        g=exp(k*ln(f));
        int v=qpow(mu,k);
        for(int i=n;i>=pos*k;i--)
            g[i]=(long long)g[i-pos*k]*v%MOD;
        for(int i=pos*k-1;i>=0;i--)
            g[i]=0;
    }
    return g;
}
Poly qpow(const Poly &F,const string &k)
{
    bool isbig=false;
    int k1=0,k2=0;
    for(int i=0;i<(int)k.size();i++)
    {
        if(10ll*k1+k[i]-'0'>=MOD-1) isbig=true;
        k1=(10ll*k1+k[i]-'0')%(MOD-1);
        k2=(10ll*k2+k[i]-'0')%MOD;
    }
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
        f[i]=(long long)f[i+pos]*invm%MOD;
    for(int i=n-pos+1;i<=n;i++)
        f[i]=0;
    g[pos]=0;
    if((!isbig&&(long long)pos*k1<=n)||pos==0) 
    {
        g=exp(k2*ln(f));
        int v=qpow(mu,k1);
        for(int i=n;i>=pos*k1;i--)
            g[i]=(long long)g[i-pos*k1]*v%MOD;
        for(int i=pos*k1-1;i>=0;i--)
            g[i]=0;
    }
    return g;
}
Poly mul_t(const Poly &g,const Poly &f)
{
    assert(g.size()<=f.size());
    int m=g.size()-1;
    Poly gt=g;
    reverse(gt.begin(),gt.end());
    Poly h=gt*f;
    Poly res(f.size());
    for(int i=0;i<(int)f.size();i++)
        res[i]=h[m+i];
    return res;
}
Poly poly_multiple_point_evaluation(const Poly &F,const Poly &A)
{
    Poly f=F,a=A;
    int m=max(f.size()-1,a.size());
    f.resize(m+1),a.resize(m);
    vector<Poly>g(m<<2);
    function<void(int,int,int)> poly_multiple_point_evaluation_init=[&](int i,int l,int r)->void
    {
        if(l==r)
        {
            g[i].resize(2);
            g[i][0]=1,g[i][1]=a[l]==0?0:MOD-a[l];
            return;
        }
        int mid=(l+r)/2;
        poly_multiple_point_evaluation_init(i*2,l,mid);
        poly_multiple_point_evaluation_init(i*2+1,mid+1,r);
        g[i]=g[i*2]*g[i*2+1];
        return;
    };
    poly_multiple_point_evaluation_init(1,0,m-1);
    Poly v(A.size());
    function<void(int,int,int,const Poly&)>poly_multiple_point_evaluation_solve=[&](int i,int l,int r,const Poly &h)->void
    {
        if(l>=(int)A.size()) return;
        if(l==r)
        {
            v[l]=h[0];
            return;
        }
        int mid=(l+r)/2;
        Poly hl=mul_t(g[i*2+1],h),hr=mul_t(g[i*2],h);
        hl.resize(mid-l+1),hr.resize(r-mid);
        poly_multiple_point_evaluation_solve(i*2,l,mid,hl);
        poly_multiple_point_evaluation_solve(i*2+1,mid+1,r,hr);
        return;
    };
    Poly h=mul_t(getinv(g[1]),f);
    h.resize(m);
    poly_multiple_point_evaluation_solve(1,0,m-1,h);
    return v;
}
int poly_calc(const Poly &F,const int &x)
{
    Poly f=F;
    int n=f.size()-1;
    int fc=1,res=0;
    for(int i=0;i<=n;i++)
        res=(res+(long long)f[i]*fc)%MOD,fc=(long long)fc*x%MOD;
    return res;
}
Poly poly_interpolation(const vector<pair<int,int>> &p)
{
    int n=p.size()-1;
    vector<Poly>g(n<<2);
    function<void(int,int,int)> init_poly_eval=[&](int i,int l,int r)
    {
        if(l==r)
        {
            g[i].resize(2);
            g[i][0]=MOD-p[l].first,g[i][1]=1;
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
        x[i]=p[i].first;
    Poly F=poly_multiple_point_evaluation(poly_derivatives(g[1]),x);
    vector<int> a(n+1);
    for(int i=0;i<=n;i++)
        a[i]=(long long)p[i].second*getinv(F[i])%MOD;
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
Poly or_convolution(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    auto fwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                    F[k+(len>>1)]=add(F[k+(len>>1)],F[k]);
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=(long long)f[i]*g[i]%MOD;
    auto ifwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                    F[k+(len>>1)]=sub(F[k+(len>>1)],F[k]);
        return;
    };
    ifwt(f);
    return f;
}
Poly and_convolution(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    function<void(Poly &)> fwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                    F[k]=add(F[k],F[k+(len>>1)]);
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=(long long)f[i]*g[i]%MOD;
    function<void(Poly &)> ifwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                    F[k]=sub(F[k],F[k+(len>>1)]);
        return;
    };
    ifwt(f);
    return f;
}
Poly xor_convolution(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    function<void(Poly &)> fwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                {
                    int l=F[k],r=F[k+(len>>1)];
                    F[k]=add(l,r);
                    F[k+(len>>1)]=sub(l,r);
                }
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=(long long)f[i]*g[i]%MOD;
    function<void(Poly &)> ifwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                {
                    int l=F[k],r=F[k+(len>>1)];
                    F[k]=add(l,r);
                    F[k+(len>>1)]=sub(l,r);
                }
        int invn=getinv(n);
        for(int i=0;i<(int)F.size();i++)
            F[i]=(long long)F[i]*invn%MOD;
        return;
    };
    ifwt(f);
    return f;
}
Poly subset_convolution(const Poly &F,const Poly &G)
{
    int m=max(F.size()-1,G.size()-1),n=1,c=1;
    while(n<=m) n<<=1,c++;
    vector<Poly> f(c+1,Poly(n,0)),g(c+1,Poly(n,0));
    for(int i=0;i<(int)F.size();i++)
        f[__builtin_popcount(i)][i]=F[i];
    for(int i=0;i<(int)G.size();i++)
        g[__builtin_popcount(i)][i]=G[i];
    function<void(Poly &)> fwt=[&](Poly &F)
    {
        int n=F.size();
        vector<unsigned long long>f(n);
        for(int i=0;i<n;i++)
            f[i]=F[i];
        for(int len=2;len<=n;len<<=1)
        {
            if((len>>BIT)&1)
            {
                for(int i=0;i<n;i++)
                    f[i]%=MOD;
            }
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                {
                    unsigned long long l=F[k];
                    int r=F[k+(len>>1)]%MOD;
                    F[k]=l+r;
                    F[k+(len>>1)]=l+MOD-r;
                }
        }
        for(int i=0;i<n;i++)
            F[i]=f[i]%MOD;
        return;
    };
    for(int i=0;i<=c;i++)
        fwt(f[i]),fwt(g[i]);
    vector<Poly> h(c+1,Poly(n,0));
    for(int i=0;i<=c;i++)
        for(int j=0;j<=i;j++)
        {
            int k=i-j;
            for(int s=0;s<n;s++)
                h[i][s]=(h[i][s]+(long long)f[j][s]*g[k][s])%MOD;
        }
    function<void(Poly &)> ifwt=[&](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+(len>>1);k++)
                {
                    int l=F[k],r=F[k+(len>>1)];
                    F[k]=add(l,r);
                    F[k+(len>>1)]=sub(l,r);
                }
        int invn=getinv(n);
        for(int i=0;i<(int)F.size();i++)
            F[i]=(long long)F[i]*invn%MOD;
        return;
    };
    for(int i=0;i<=c;i++)
        ifwt(h[i]);
    Poly res(n);
    for(int i=0;i<n;i++)
        res[i]=h[__builtin_popcount(i)][i];
    return res;
}
Poly cyclic_convolution(const Poly &a,const Poly &b)
{
    assert(a.size()==b.size());
    int n=a.size();
    Poly c=a*b;
    for(int i=n;i<(int)c.size();i++)
        c[i-n]=add(c[i],c[i-n]);
    c.resize(n);
    return c;
}
}
using namespace Polynomial;