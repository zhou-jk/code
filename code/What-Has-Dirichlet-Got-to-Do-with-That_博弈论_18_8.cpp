//CodeForces-39E
#include <cstdio>
#include <vector>

using std::vector;

const int M=30;
vector<int> f[M+1];
int c;

void init()
{
	long long j;
	int k;
	for (int i=0; i*i<c; ++i)
		for (j=i*i,k=2; j<c&&k<=M; j*=i,++k) f[k].push_back(0);
	for (int i=0; i<f[2].size(); ++i) f[1].push_back(0);
}

int dfs(int a,int b)
{
	//printf("%d %d\n",a,b);
	if (b==1&&a>=f[2].size()) return (c-a)&1?1:-1;
	if (a>=f[b].size()) return -1;
	if (f[b][a]) return f[b][a];
	return f[b][a]=dfs(a+1,b)>0||dfs(a,b+1)>0?-1:1;
}

int main()
{
	int a,b;
	scanf("%d%d%d",&a,&b,&c);
	init();
	if ((a==1&&b==1&&c==2)||(a==1&&b>1&&f[b].size()<=2)) puts("Missing");
	else puts(dfs(a,b)>0?"Stas":"Masha");
	return 0;
}