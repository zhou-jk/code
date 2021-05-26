#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=105;
int n;
int u[N],v[N];
vector<int>G[N];
long long c[N];
int mx[N];
int dep[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    c[dep[u]]++;
    int tot=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        tot++;
    }
    mx[dep[u]]=max(mx[dep[u]],tot);
    return;
}
pair<int,long long>solven(int s)
{
    for(int i=1;i<=n;i++)
        mx[i]=-1,c[i]=0;
    dfs(s,0);
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(c[i]) cnt++;
    for(int i=1;i<n;i++)
        if(c[i]&&c[i+1]) c[i+1]=c[i]*mx[i];
    long long ans=1;
    for(int i=n;i>=1;i--)
        if(c[i])
        {
            ans=c[i];
            break;
        }
    return {cnt,ans};
}
pair<int,long long>solvee(int s,int t)
{
    for(int i=1;i<=n;i++)
        mx[i]=-1,c[i]=0;
    {
        dep[s]=1;
        c[dep[s]]++;
        int tot=0;
        for(int v:G[s])
        {
            if(v==t) continue;
            dfs(v,s);
            tot++;
        }
        mx[dep[s]]=max(mx[dep[s]],tot);
    }
    {
        dep[t]=1;
        c[dep[t]]++;
        int tot=0;
        for(int v:G[t])
        {
            if(v==s) continue;
            dfs(v,t);
            tot++;
        }
        mx[dep[t]]=max(mx[dep[t]],tot);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(c[i]) cnt++;
    for(int i=1;i<n;i++)
        if(c[i]&&c[i+1]) c[i+1]=c[i]*mx[i];
    long long ans=1;
    for(int i=n;i>=1;i--)
        if(c[i])
        {
            ans=c[i];
            break;
        }
    return {cnt,ans};
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].emplace_back(v[i]);
        G[v[i]].emplace_back(u[i]);
    }
    pair<int,long long>res={n+1,0LL};
    for(int i=1;i<=n;i++)
        res=min(res,solven(i));
    for(int i=1;i<n;i++)
        res=min(res,solvee(u[i],v[i]));
    printf("%d %lld",res.first,res.second);
    return 0;
}