#include<iostream>
#include<cstdio>
using namespace std;
int n,p;
template<typename T>
inline T read(T &x)
{
    x=0;
    bool flag=true;
    char ch;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(!flag) x=-x;
    return x;
}
template<typename T>
inline void write(T x)
{
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
template<typename T>
inline void writeln(T x)
{
    write(x);
    putchar('\n');
    return;
}
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
long long getinv(long long a,long long p)
{
    return ksm(a,p-2);
}
int main()
{
    read(n),read(p);
    for(int i=1;i<=n;i++)
        writeln(getinv(i,p));
    return 0;
}