#include<iostream>
#include<cstdio>
#include<set>
#include<stack>
using namespace std;
const int N=200005;
const int SIZE=500;
set<pair<int,int> >now,pre;
struct Node
{
    int u,v,fa,dep;
};
stack<Node>s;
int n,m;
int op[N],x[N],y[N];
struct DSU
{
	int fa[N],dep[N];
    void init(int n)
    {
		for(int i=1;i<=n;i++)
			fa[i]=i,dep[i]=1;
        return;
	}
	int getf(int v)
    {
        if(v==fa[v]) return v;
        else return getf(fa[v]);
    }
	bool merge(int u,int v,bool flag)
    {
		int f1=getf(u),f2=getf(v);
		if(f1==f2) return false;
		if(dep[f1]<dep[f2]) swap(f1,f2);
		if(flag) s.push((Node){f1,f2,fa[f2],dep[f1]});
		fa[f2]=f1;
		dep[f1]=max(dep[f2]+1,dep[f1]);
		return true;
	}
}Dset;
void remove(int u,int v)
{
	if(u>v) swap(u,v);
	pair<int,int> e=make_pair(u,v);
	if(pre.count(e))
		now.insert(e),pre.erase(e);
    return;
}
void add(int u,int v)
{
	if(u>v) swap(u,v);
	pair<int,int> e=make_pair(u,v);
	if(now.count(e)) now.erase(e);
	else now.insert(e);
    return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
        scanf("%d%d%d",&op[i],&x[i],&y[i]);
	int last=0;
	for(int i=1;i<=m;i+=SIZE)
    {
		for(int j=i;j<=min(m,i+SIZE-1);j++)
			if(op[j]==1) remove(x[j],y[j]),remove(x[j]%n+1,y[j]%n+1);
		Dset.init(n);
        for(auto [u,v]:pre)
            Dset.merge(u,v,false);
        while(!s.empty()) s.pop();
		for(int j=i;j<=min(m,i+SIZE-1);j++)
        {
			x[j]=(x[j]+last-1)%n+1,y[j]=(y[j]+last-1)%n+1;
			if(x[j]>y[j]) swap(x[j],y[j]);
			if(op[j]==1) add(x[j],y[j]);
			else
            {
                while(!s.empty())
                {
                    Dset.dep[s.top().u]=s.top().dep;
					Dset.fa[s.top().v]=s.top().fa;
                    s.pop();
                }
                for(auto [u,v]:now)
					Dset.merge(u,v,true);
                last=Dset.getf(x[j])==Dset.getf(y[j]);
				printf("%d",last);
			}
		}
		for(auto it:now)
            pre.insert(it);
		now.clear();
	}
    return 0;
}