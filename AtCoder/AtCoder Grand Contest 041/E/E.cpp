#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=50005,M=100005;
int n,m,T;
int x[M],y[M];
namespace Subtask1
{
bitset<N>f[N];
bool ans[M];
void print(int u)
{
	static bool book[N];
	book[u]=true;
	for(int i=m;i>=1;i--)
		if(!book[x[i]]) book[x[i]]=book[y[i]],ans[i]=1;
		else book[y[i]]=book[x[i]],ans[i]=0;
	for(int i=1;i<=m;i++)
		if(ans[i]) printf("v");
		else printf("^");
	return;
}
int main()
{
	for(int i=1;i<=n;i++)
		f[i][i]=true;
	for(int i=m;i>=1;i--)
		f[x[i]]=f[y[i]]=f[x[i]]|f[y[i]];
	bitset<N>res;
	for(int i=1;i<=n;i++)
		res[i]=1;
	for(int i=1;i<=n;i++)
		res&=f[i];
	if(res.count()==0) printf("-1");
	else print(res._Find_first());
	return 0;
}
}
namespace Subtask2
{
int siz[N],to[N];
bool ans[M];
int main()
{
	if(n<=2)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		to[i]=i,siz[i]=1;
	for(int i=m;i>=1;i--)
	{
		if(siz[to[x[i]]]>=n-1)
		{
			ans[i]=1;
			swap(x[i],y[i]);
		}
		siz[to[y[i]]]--;
		to[y[i]]=to[x[i]];
		siz[to[y[i]]]++;
	}
	for(int i=1;i<=m;i++)
		if(ans[i]) printf("v");
		else printf("^");
	return 0;
}
}
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x[i],&y[i]);
	if(T==1) return Subtask1::main();
	else if(T==2) return Subtask2::main();
	return 0;
}

