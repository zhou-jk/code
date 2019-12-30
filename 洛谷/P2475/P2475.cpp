#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n,root;
int ans[N];
struct tree
{
	int lc,rc,fa;
}tree[N];
void solve(int u,int t)
{
	if((!tree[u].rc&&!tree[u].lc)||(!tree[u].rc&&tree[u].lc&&(tree[tree[u].lc].lc)))
	{
		tree[tree[u].fa].lc=tree[u].lc;
		if(tree[u].lc) tree[tree[u].lc].fa=tree[u].fa;
		ans[t]=u;
		if(!tree[u].fa) root=tree[u].lc;
		return;
	}
	solve(tree[u].lc,t);
	swap(tree[u].lc,tree[u].rc);
    return;
}
int main()
{
	root=1;
    scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int f;
		scanf("%d",&f);
		f++;
		if(f<100)
		{
			tree[f].lc=i+1,tree[i+1].fa=f;
		}
		else 
		{
			f-=100;
			tree[f].rc=i+1,tree[i+1].fa=f;
		}
	}
	tree[1].fa=0;
	for(int i=n+1;i;i--)
		solve(root,i);
	for(int i=1;i<=n+1;i++)
		printf("%d ",ans[i]-1);
	return 0;
}