#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1000001;
int n,m;
vector<int> G[N];
int col[N],a[N],ans;
void merge(int x,int y)
{
    for(int i=0;i<G[x].size();i++)
        ans-=(a[G[x][i]-1]==y)+(a[G[x][i]+1]==y);
    for(int i=0;i<G[x].size();i++)
        a[G[x][i]]=y,G[y].push_back(G[x][i]);
    G[x].clear();
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        col[a[i]]=a[i];
        G[a[i]].push_back(i);
        if(a[i]!=a[i-1]) ans++;
    }
    while(m--)
    {
        int op,x,y;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            if(x==y) continue;
            if(G[col[x]].size()>G[col[y]].size()) swap(col[x],col[y]);
            merge(col[x],col[y]);
        }
        else if(op==2) printf("%d\n",ans);
    }
    return 0;
}