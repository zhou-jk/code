#include<bits/stdc++.h>
using namespace std;
constexpr int N=1505;
constexpr int MOD=1000000007;
typedef vector<int> Poly;
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
int n,m,q;
Poly b;
Poly p[N];
int zero[N];
Poly pre[N],preb[N],ipre[N];
Poly operator *(const Poly &a,const Poly &b)
{
    int n=a.size(),m=b.size();
    Poly c(n+m-1,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            c[i+j]=(c[i+j]+(long long)a[i]*b[j])%MOD;
    return c;
} 
Poly getinv(const Poly &f)
{
    Poly g(f.size(),0);
    g[0]=getinv(f[0]);
    for(int i=1;i<(int)g.size();i++)
    {
        for(int j=0;j<i;j++)
            g[i]=(g[i]+(long long)f[i-j]*g[j])%MOD;
        g[i]=(long long)(MOD-g[i])*g[0]%MOD;
    }
    return g;
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>q;
    b.resize(m+1);
    for(int i=0;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        p[i].resize(m+1);
        for(int j=0;j<=m;j++)
            cin>>p[i][j];
    }
    pre[0]=Poly(m+1,0),ipre[0]=Poly(m+1,0);
    pre[0][0]=ipre[0][0]=1;
    Poly bt=b;
    reverse(bt.begin(),bt.end()); 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            p[i][j]%=MOD;
        int c=0;
        for(int j=0;j<=m;j++)
            if(p[i][j]==0) c++;
            else break;
        for(int j=0;j<=m-c;j++)
            p[i][j]=p[i][j+c];
        for(int j=m-c+1;j<=m;j++)
            p[i][j]=0;
        zero[i]=zero[i-1]+c;
        pre[i]=pre[i-1]*p[i];
        pre[i].resize(m+1);
        preb[i]=pre[i]*bt;
        preb[i].resize(m+1);
        ipre[i]=getinv(pre[i]);
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int k=m-(zero[r]-zero[l-1]);
        int ans=0;
        for(int i=0;i<=k;i++)
            ans=(ans+(long long)preb[r][i]*ipre[l-1][k-i])%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}