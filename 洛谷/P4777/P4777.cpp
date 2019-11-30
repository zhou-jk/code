#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
template<typename T>
inline void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
__int128 gcd(__int128 a,__int128 b)
{
    return b==0?a:gcd(b,a%b);
}
__int128 ex_gcd(__int128 a,__int128 b,__int128 &x,__int128 &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    __int128 d=ex_gcd(b,a%b,x,y);
    __int128 tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
__int128 calc(__int128 a,__int128 b,__int128 c)
{
    __int128 x,y;
    __int128 d=ex_gcd(a,b,x,y);
    __int128 s=b/d;
    x=x*c/d;
    x=(x%s+s)%s;
    return x;
}
int n;
__int128 M=1,ans;
long long m[N],a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&m[i],&a[i]);
    M=m[1],ans=a[1];
    for(int i=2;i<=n;i++)
    {
        __int128 c=((a[i]%m[i])-(ans%m[i])+m[i])%m[i];
        __int128 k=calc(M,m[i],c);
        ans+=k*M;
        M=M/gcd(M,m[i])*m[i];
    }
    write(ans);
    return 0;
}