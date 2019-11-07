#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n,m,q;
int deep,Index,root1,root2;
int fa[100001],d[100001],f[100001],root[100001];
int a[100001],len;
double size[100001];
map<pair<int,int>,double>book;
vector<long long>v1[100001],v2[100001];
struct Edge
{
    int to,next;
}edge[200001];
int head[100001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void dfs1(int u,int father,int p)
{
    v1[p].push_back(u);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        fa[v]=p;
        dfs1(v,u,p);
    }
    return;
}
void dfs2(int u,int father,int sum,bool w)
{
    if(w!=0) f[u]=max(f[u],sum);
    if(sum>=deep)
    {
        deep=sum;
        if(w==0) root1=u;
        else if(w==1) root2=u;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs2(v,u,sum+1,w);
    }
    return;
}
int main()
{
    memset(fa,-1,sizeof(fa));
    memset(d,-1,sizeof(d));
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(fa[i]!=-1) continue;
        fa[i]=++Index;
        dfs1(i,0,Index);
        root[Index]=i;
    }
    for(int i=1;i<=Index;i++)
    {
        deep=0;
        dfs2(root[i],0,0,0);
        deep=0;
        dfs2(root1,0,0,1);
        d[i]=deep;
        dfs2(root2,0,0,2);
        len=v1[i].size();
        for(int j=0;j<len;j++)
            a[j]=f[v1[i][j]];
        v1[i].clear();
        for(int j=0;j<len;j++)
            v1[i].push_back(a[j]);
        sort(v1[i].begin(),v1[i].end());
        a[len]=0;
        for(int j=len-1;j>=0;j--)
            a[j]=a[j+1]+v1[i][j]+1;
        for(int j=0;j<=len;j++)
            v2[i].push_back(a[j]);
    }
    for(int k=1;k<=q;k++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x=fa[x],y=fa[y];
        if(x==y) printf("-1\n");
        else
        {
            if(book[make_pair(x,y)]>0) printf("%.6f\n",book[make_pair(x,y)]);
            else
            {
                double ans=0;
                if(v1[x].size()<=v1[y].size())
                {
                    for(int i=0;i<v1[x].size();i++)
                    {
                        long long tmp=lower_bound(v1[y].begin(),v1[y].end(),max(d[x],d[y])-v1[x][i]-1)-v1[y].begin();
                        ans+=(v2[y][tmp]+v1[x][i]*(v1[y].size()-tmp))+tmp*max(d[x],d[y]);
                    }
                }
                else
                {
                    for(int i=0;i<v1[y].size();i++)
                    {
                        long long tmp=lower_bound(v1[x].begin(),v1[x].end(),max(d[x],d[y])-v1[y][i]-1)-v1[x].begin();
                        ans+=(v2[x][tmp]+v1[y][i]*(v1[x].size()-tmp))+tmp*max(d[x],d[y]);
                    }
                }
                ans/=(v1[x].size()*v1[y].size());
                printf("%.6lf\n",ans);
                book[make_pair(x,y)]=ans;
            }
        }
    }
    return 0;
}