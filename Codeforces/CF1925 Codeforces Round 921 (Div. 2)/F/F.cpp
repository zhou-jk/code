#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=999999893;
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
struct Ext
{
    int a,b;
    Ext(int _a=0,int _b=0):a(_a),b(_b){}
    friend Ext operator+(const Ext &a,const Ext &b)
    {
        return Ext((a.a+b.a)%MOD,(a.b+b.b)%MOD);
    }
    friend Ext operator-(const Ext &a,const Ext &b)
    {
        return Ext((a.a-b.a+MOD)%MOD,(a.b-b.b+MOD)%MOD);
    }
    friend Ext operator*(const Ext &a,const Ext &b)
    {
        return Ext(((long long)a.a*b.a+(long long)a.b*b.b*2)%MOD,((long long)a.a*b.b+(long long)a.b*b.a)%MOD);
    }
    friend Ext operator/(const Ext &x, const Ext &y)
    {
        return Ext(((long long)x.a*y.a-(long long)x.b*y.b*2%MOD+MOD)%MOD*getinv(((long long)y.a*y.a-(long long)y.b*y.b*2%MOD+MOD)%MOD)%MOD,((long long)x.b*y.a-(long long)x.a*y.b%MOD+MOD)%MOD*getinv(((long long)y.a*y.a-(long long)y.b*y.b*2%MOD+MOD)%MOD)%MOD);
    }
};
Ext qpow(Ext a,int b)
{
    Ext res(1,0);
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a,b>>=1;
    }
    return res;
}
int n;
void solve()
{
    cin>>n;
    Ext a=Ext(1,0)-qpow(Ext(0,1),n-1),b=Ext(1,MOD-1);
    Ext x=a*Ext(2,0)/b,y=x+Ext(0,2);
    Ext res=x/y;
    cout<<res.b<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}