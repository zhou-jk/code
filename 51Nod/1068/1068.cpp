#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=3;
template<typename T>
inline T read(T &x)
{
	x=0;
	char ch;
	bool flag=false;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') flag=true;
	while(ch>='0'&&ch<='9')
		x=((x<<1)+(x<<3)+(ch^48))%MOD,ch=getchar();
	if(flag) x=-x;
	return x;
}
int T,n;
int main()
{
    scanf("%d",&T);
    while(T--)
	{
		read(n);
		if(n==0) printf("B\n");
		else printf("A\n");
    }
    return 0;
}
