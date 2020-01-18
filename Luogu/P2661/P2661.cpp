#include<cstdio>
#include<iostream>
using namespace std;
const int inf=1061109567;
int f[200001],d[200001],n,ans=inf,last,x;
int find(int v)
{
	if(v==f[v]) return v;
	int t=f[v];
    f[v]=find(f[v]),d[v]+=d[t]; 
    return f[v];
}
bool merge(int u,int v)
{
    int f1=find(u),f2=find(v);
    if(f1!=f2)
	{
		f[f1]=f2;
		return true;
	}
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		f[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(merge(i,x)) d[i]=d[x]+1;
        else ans=min(ans,d[i]+d[x]+1);
    }
    printf("%d",ans);
    return 0;
}