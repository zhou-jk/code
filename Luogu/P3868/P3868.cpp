#include<iostream>
#include<cstdio>
using namespace std;
template<typename T>
inline void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
const int N=11;
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
__int128 M=1;
__int128 ans;
int m[N],a[N];
int t[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m[i]);
        M*=m[i];
    }
    for(int i=1;i<=n;i++)
        t[i]=calc(M/m[i],m[i],1);
    for(int i=1;i<=n;i++)
        ans+=a[i]*(M/m[i])*t[i];
    write((ans+M)%M);
    return 0;
}