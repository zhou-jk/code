#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,M=400005;
const double Pi=acos(-1);
const int MOD=1000000007;
typedef vector<int> Poly;
struct Complex
{
    double x,y;
    Complex(double xx=0,double yy=0)
    {
        x=xx,y=yy;
        return;
    }
    Complex operator+(const Complex &b)const
    {
        return (Complex){x+b.x,y+b.y};
    }
    Complex operator-(const Complex &b)const
    {
        return (Complex){x-b.x,y-b.y};
    }
    Complex operator*(const Complex &b)const
    {
        return (Complex){x*b.x-y*b.y,x*b.y+y*b.x};
    }
};
Complex W[M<<1];
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
Poly fft(const Poly &F,const Poly &G)
{
    vector<Complex> f(F.size()),g(G.size());
    int n=F.size()-1,m=G.size()-1;
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
    Poly res(m+1);
    for(int i=0;i<=m;i++)
        res[i]=(int)(f[i].x/n+0.5);
    return res;
}
Poly operator*(const Poly &f,const Poly &g)
{
    return fft(f,g);
}
int l,t;
int n,m;
int v[N];
bool s[M+M];
long long dp[M+M];
int main()
{
    scanf("%d%d",&l,&t);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    m=*max_element(v+1,v+n+1);
    Poly f(m+1),g(m+1);
    for(int i=1;i<=n;i++)
        f[v[i]]++,g[m-v[i]]++;
    Poly A=f*f,B=f*g;
    for(int i=1;i<=n;i++)
        A[v[i]+v[i]]--;
    for(int i=1;i<=m+m;i++)
        if(A[i]>0) s[i]=true;
    for(int i=m;i<=m+m;i++)
        if(B[i]>0) s[i-m]=true;
    for(int i=1;i<=m+m;i++)
        for(int j=i+i;j<=m+m;j+=i)
            if(s[j]) s[i]=true;
    for(int i=1;i<=m+m;i++)
        dp[i]=(long long)i*t/(2*l);
    for(int i=1;i<=m+m;i++)
        for(int j=i+i;j<=m+m;j+=i)
            dp[j]-=dp[i];
    long long ans=0;
    for(int i=1;i<=m+m;i++)
        if(s[i]) ans=(ans+dp[i]),cerr<<"find"<<i<<dp[i]<<"\n";
    printf("%d",ans);
    return 0;
}