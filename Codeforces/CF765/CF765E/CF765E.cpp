#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=200001;
int n,root;
struct Edge
{
	int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfs(int u,int father)
{
	set<int>S;
	for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        int res=dfs(v,u);
        if(res==-1) return -1;
        S.insert(res+1);
    }
	if(S.size()>2) return -1;
	else if(S.empty()) return 0;
	if(S.size()==1) return *S.begin();
	else if(S.size()==2&&father==0) return *S.rbegin()+*S.begin();
	else root=u;
	return -1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
	int res=dfs(1,0);
	if(res==-1&&root) res=dfs(root,0);
	printf("%d",res/(res&-res));
    return 0;
}