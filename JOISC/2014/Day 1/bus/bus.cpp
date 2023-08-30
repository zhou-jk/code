#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005,M=300005;
const int INF=1061109567;
int n,m,q;
struct Edge
{
    int u,v,x,y;
}edge[M];
vector<pair<int,int>>f[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].x,&edge[i].y);
    sort(edge+1,edge+m+1,[](const Edge &a,const Edge &b){return a.y<b.y;});
    for(int i=1,j=1;i<=m;i=j)
    {
        while(j<=m&&edge[i].y==edge[j].y) j++;
        int t=edge[i].y;
        for(int k=i;k<j;k++)
        {
            auto [u,v,x,y]=edge[k];
            if(u==1)
            {
                int fu=x;
                if(!f[v].empty()&&f[v].back().first==t&&f[v].back().second<fu) f[v].pop_back();
                if(f[v].empty()||f[v].back().second<fu) f[v].emplace_back(t,fu);
                continue;
            }
            vector<pair<int,int>>::iterator it=upper_bound(f[u].begin(),f[u].end(),make_pair(x,INF));
            if(it!=f[u].begin())
            {
                int fu=(--it)->second;
                if(!f[v].empty()&&f[v].back().first==t&&f[v].back().second<fu) f[v].pop_back();
                if(f[v].empty()||f[v].back().second<fu) f[v].emplace_back(t,fu);
            }
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        int l;
        scanf("%d",&l);
        vector<pair<int,int>>::iterator it=upper_bound(f[n].begin(),f[n].end(),make_pair(l,INF));
        if(it!=f[n].begin())
        {
            int res=(--it)->second;
            printf("%d\n",res);
        }
        else printf("-1\n");
    }
    return 0;
}