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
const double PI=acos(-1);
const int N=400005;
int MOD;
struct Complex
{
    double real,imag;
    Complex():real(0),imag(0){} 
    Complex(double xx,double yy):real(xx),imag(yy){}
    Complex operator=(const int &b)
    {
        real=b,imag=0;
        return *this;
    }
    Complex operator+(const Complex &b)const
    {
        return Complex(real+b.real,imag+b.imag);
    }
    Complex operator-(const Complex &b)const
    {
        return Complex(real-b.real,imag-b.imag);
    }
    Complex operator*(const Complex &b)const
    {
        return Complex(real*b.real-imag*b.imag,real*b.imag+imag*b.real);
    }
    friend Complex getinv(const Complex &rhs)
    {
        return Complex(rhs.real,-rhs.imag);
    }
};
Complex W[2][N<<1];
void init_omega(int n=400000)
{
    for(int len=1;len<=n;len<<=1)
        for(int k=0;k<len;k++)
            W[0][len+k]=Complex(cos(2*PI*k/len),sin(2*PI*k/len)),W[1][len+k]=Complex(cos(2*PI*k/len),-sin(2*PI*k/len));
    return;
}
typedef vector<int> Poly;
Poly mtt(const Poly &F,const Poly &G,const function<Complex(const Complex &,const Complex &)> &mul)
{
    int n=F.size()-1,m=G.size()-1;
    vector<Complex> a(n+1),b(n+1),c(m+1),d(m+1);
    for(int i=0;i<=n;i++)
        a[i]=F[i]>>15,b[i]=F[i]&0x7fff;
    for(int i=0;i<=m;i++)
        c[i]=G[i]>>15,d[i]=G[i]&0x7fff;
    m+=n,n=1;
    while(n<=m) n<<=1;
    a.resize(n),b.resize(n),c.resize(n),d.resize(n);
    vector<int>rev(n);
    for(int i=0;i<n;i++)
    {
        rev[i]=rev[i/2]>>1;
        if(i&1) rev[i]|=n/2;
    }
    function<void(vector<Complex> &)> dft=[=](vector<Complex> &F)
    {
        int n=F.size();
        vector<Complex> f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    Complex l=f[k];
                    Complex r=f[k+len/2]*W[0][len+k-i];
                    f[k]=l+r;
                    f[k+len/2]=l-r;
                }
        for(int i=0;i<n;i++)
            F[i]=f[i];
        return;
    };
    dft(a),dft(b),dft(c),dft(d);
    vector<Complex> ac(n),ad(n),bc(n),bd(n);
    for(int i=0;i<n;i++)
        ac[i]=mul(a[i],c[i]),ad[i]=mul(a[i],d[i]),bc[i]=mul(b[i],c[i]),bd[i]=mul(b[i],d[i]);
    function<void(vector<Complex> &)> idft=[=](vector<Complex> &F)
    {
        int n=F.size();
        vector<Complex> f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    Complex l=f[k];
                    Complex r=f[k+len/2]*W[1][len+k-i];
                    f[k]=l+r;
                    f[k+len/2]=l-r;
                }
        for(int i=0;i<n;i++)
            F[i]=f[i];
        return;
    };
    idft(ac),idft(ad),idft(bc),idft(bd);
    Poly AC(m+1),AD(m+1),BC(m+1),BD(m+1);
    for(int i=0;i<=m;i++)
        AC[i]=(long long)round(ac[i].real/n)%MOD,AD[i]=(long long)round(ad[i].real/n)%MOD,BC[i]=(long long)round(bc[i].real/n)%MOD,BD[i]=(long long)round(bd[i].real/n)%MOD;
    Poly res(m+1);
    for(int i=0;i<=m;i++)
        res[i]=(((long long)(AC[i])<<30)+((long long)(AD[i]+BC[i])<<15)+BD[i])%MOD;
    return res;
}
Poly operator*(const Poly &F,const Poly &G)
{
    return mtt(F,G,[=](const Complex &x,const Complex &y){return x*y;});
}
int main()
{
    init_omega();
    int n,m;
    scanf("%d%d%d",&n,&m,&MOD);
    Poly f,g;
    f.resize(n+1),g.resize(m+1);
    for(int i=0;i<=n;i++)
        scanf("%d",&f[i]);
    for(int i=0;i<=m;i++)
        scanf("%d",&g[i]);
    Poly res=f*g;
    for(int u:res)
        printf("%d ",u);
    return 0;
}