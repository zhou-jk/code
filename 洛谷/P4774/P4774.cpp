#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
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
	if(x<0) putchar('-'),x=-x;
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
const int N=100001;
int T,n,m;
__int128 a[N],p[N],atk[N],btk[N],c[N];
__int128 P;
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
    if(c%d!=0) return -1;
    __int128 s=b/d;
    x=x*c/d;
    x=(x%s+s)%s;
    return x;
}
__int128 excrt()
{
	__int128 M=p[1],ans=a[1];
	for (int i=1;i<=n;i++)
	{
		__int128 c=((a[i]%p[i])-(ans%p[i])+p[i])%p[i];
        __int128 x=calc(M,p[i],c);
        if(x==-1) return -1;
		ans+=x*M;
		M=M/gcd(M,p[i])*p[i];
		ans=(ans%M+M)%M;
	}
	P=M;
	return ans;
}
__int128 solve()
{
	multiset<__int128>S;
	for (int i=1;i<=m;i++)
		S.insert(atk[i]);
	__int128 tmp=0;
	for(int i=1;i<=n;i++)
	{
		multiset<__int128>::iterator it=(a[i]<(*S.begin()))?S.begin():(--S.upper_bound(a[i]));
		c[i]=*it;
		S.erase(it);
		S.insert(btk[i]);
		tmp=max(tmp,((a[i]-1)/c[i]+1));
    }
	for(int i=1;i<=n;i++)
	{
		__int128 x,y;
		ex_gcd(c[i],p[i],x,y);
		__int128 d=gcd(c[i],p[i]);
		a[i]=calc(c[i],p[i],a[i]);
		if(a[i]==-1) return -1;
		p[i]/=d;
	}
	__int128 ans=excrt();
	if(ans!=-1&&ans<tmp) ans+=((tmp-ans-1)/P+1)*P;
	return ans;
}
int main()
{
	read(T);
	while(T--)
	{
		read(n),read(m);
		for(int i=1;i<=n;i++)
			read(a[i]);
		for(int i=1;i<=n;i++)
			read(p[i]);
		for(int i=1;i<=n;i++)
			read(btk[i]);
		for(int i=1;i<=m;i++)
			read(atk[i]);
		writeln(solve());
	}
	return 0;
}