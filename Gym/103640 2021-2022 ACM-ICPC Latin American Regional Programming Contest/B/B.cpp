#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
const double PI=acos(-1);
const int N=400005;
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
typedef vector<long long> Poly;
Poly fft(const Poly &F,const Poly &G,const function<Complex(const Complex &,const Complex &)> &mul)
{
    if(F.empty()||G.empty()) return {};
    int n=F.size()-1,m=G.size()-1;
    vector<Complex> f(n+1),g(m+1);
    for(int i=0;i<=n;i++)
        f[i]=F[i];
    for(int i=0;i<=m;i++)
        g[i]=G[i];
    m+=n,n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
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
    dft(f),dft(g);
    for(int i=0;i<n;i++)
        f[i]=mul(f[i],g[i]);
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
    idft(f);
    Poly res(m+1);
    for(int i=0;i<=m;i++)
        res[i]=(long long)round(f[i].real/n);
    return res;
}
Poly operator*(const Poly &F,const Poly &G)
{
    return fft(F,G,[=](const Complex &x,const Complex &y){return x*y;});
}
int n;
int a[N],b[N];
vector<long long>solve()
{
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int l=1,r=n;
    vector<int>v;
    for(int i=1;i<=n;i++)
        if(a[i]<=0&&b[i]<=0) l++,v.emplace_back(a[i]*b[i]);
    for(int i=n;i>l;i--)
        if(a[i]>=0&&b[i]>=0) r--,v.emplace_back(a[i]*b[i]);
    sort(v.begin(),v.end(),greater<int>());
    vector<long long>res(n,0);
    if(!v.empty())
    {
        res[0]=v[0];
        for(int i=1;i<(int)v.size();i++)
            res[i]=res[i-1]+v[i];
    }
    Poly f,g;
    for(int i=l;i<=r;i++)
        f.emplace_back(a[i]),g.emplace_back(b[i]); 
    if(a[l]<0) reverse(f.begin(),f.end());
    else reverse(g.begin(),g.end());
    int m=f.size();
    Poly h=f*g;
    for(int i=n-m;i<n;i++)
    {
        res[i]=h[i-n+m];
        if(n!=m) res[i]+=res[n-m-1];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init_omega();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    vector<long long>mx=solve();
    for(int i=1;i<=n;i++)
        b[i]=-b[i];
    vector<long long>mn=solve();
    for(int i=0;i<n;i++)
        mn[i]=-mn[i];
    for(int i=0;i<n;i++)
        cout<<mn[i]<<" "<<mx[i]<<"\n"; 
    return 0;
}

