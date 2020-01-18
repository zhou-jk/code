#include <cstdio>
#include <algorithm>
#include <cstring>

using std::max;

const int N=700;
int a[N][N],dis[N];

const int L=1000000;
char LZH[L];
char *SSS,*TTT;
inline char gc(){
	if (SSS==TTT) TTT=(SSS=LZH)+fread(LZH,1,L,stdin);
	return *SSS++;
}
inline int read(){
	int x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}

int main()
{
	freopen("lscs.in","r",stdin);
	freopen("lscs.out","w",stdout);
	int n;
	n=read();
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j) a[i][j]=read();
	for (int i=0;i<n;++i)
		if (a[i][i])
		{
			printf("1\n%d 0 0",i+1);
			return 0;
		}
	for (int i=1;i<n;++i)
		for (int j=0;j<i;++j)
			if (a[i][j]!=a[j][i])
			{
				printf("2\n%d %d 0",i+1,j+1);
				return 0;
			}
	memset(dis,)
	for (int i=0;i<n;++i)
	{

	}
	putchar('0');
	return 0;
}
