#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N];
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
priority_queue<int,vector<int>,greater<int>>q;
vector<int>block[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    iota(fa+1,fa+n+1,1);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        merge(x,y);
    }
    for(int i=1;i<=n;i++)
        block[getf(i)].emplace_back(i);
    int ret=(n-1-m)*2;
    if(ret==0)
    {
        printf("0");
        return 0;
    }
    long long ans=0;
    for(int u=1;u<=n;u++)
        if(getf(u)==u)
        {
            sort(block[u].begin(),block[u].end(),[=](const int &x,const int &y){return a[x]<a[y];});
            ret--;
            ans+=a[block[u][0]];
            for(int i=1;i<(int)block[u].size();i++)
                q.emplace(a[block[u][i]]);
        }
    if((int)q.size()<ret)
    {
        printf("Impossible");
        return 0;
    }
    for(int i=1;i<=ret;i++)
        ans+=q.top(),q.pop();
    printf("%lld",ans);
    return 0;
}