#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N];
struct Trie
{
	int ch[N*31][2];
	int tot=1;
	void insert(int s)
	{
		int u=1;
		for(int i=30;i>=0;i--)
		{
			int c=(s>>i)&1;
			if(!ch[u][c]) ch[u][c]=++tot;
			u=ch[u][c];
		}
		return;
	}
	int dfs(int u,int sum)
	{
		if(!ch[u][0]&&!ch[u][1]) return sum+1;
		int res=0;
		if(ch[u][0]) res=max(res,dfs(ch[u][0],sum+(ch[u][1]>0)));
		if(ch[u][1]) res=max(res,dfs(ch[u][1],sum+(ch[u][0]>0)));
		return res;
	}
}T;
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		T.insert(a[i]);
	printf("%d",n-T.dfs(1,0));
	return 0;
}
