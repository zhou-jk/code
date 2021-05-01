#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int x[N],y[N];
int id[N];
struct Union_Set
{
    int n;
    int fa[N],siz[N];
    Union_Set(int _n=0)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            fa[i]=i,siz[i]=1;
        return;
    }
    void reset(int _n=0)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            fa[i]=i,siz[i]=1;
        return;
    }
    int getf(int v)
    {
        if(v==fa[v]) return v;
        else return fa[v]=getf(fa[v]);
    }
    int getsize(int v)
    {
        return siz[getf(v)];
    }
    bool merge(int u,int v)
    {
        int f1=getf(u),f2=getf(v);
        if(f1!=f2)
        {
            fa[f2]=f1;
            siz[f1]+=siz[f2];
            return true;
        }
        else return false;
    }
}F;
stack<int>S;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[=](const int &a,const int &b){return x[a]!=x[b]?x[a]<x[b]:y[a]<y[b];});
    F.reset(n);
    for(int i=1;i<=n;i++)
    {
        if(S.empty()||y[id[i]]<y[S.top()]) S.emplace(id[i]);
        else
        {
            int u=S.top();
            while(!S.empty()&&y[id[i]]>y[S.top()])
            {
                F.merge(id[i],S.top());
                S.pop();
            }
            S.emplace(u);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",F.getsize(i));
    return 0;
}