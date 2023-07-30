#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
const int INF=1061109567;
int n,m;
int d[N],p[N];
int son[N*4][3],tot;
int f[N];
long long dfs(int u)
{
    if(!son[u][0]) return f[u];
    long long f1=dfs(son[u][0]),f2=dfs(son[u][1]),f3=dfs(son[u][2]);
    return f1+f2+f3-max({f1,f2,f3});
}
bool check(int x)
{
    fill(f+1,f+n+1,1);
    for(int i=1;i<=m;i++)
        if(d[i]>=x) f[p[i]]=0;
        else f[p[i]]=INF;
    int cnt=0;
    for(int i=m+1;i<=n;i++)
        if(d[i]>=x) cnt++;
    return dfs(tot)<=cnt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&d[i],&p[i]);
    for(int i=m+1;i<=n;i++)
        scanf("%d",&d[i]);
    vector<int>p(n);
    iota(p.begin(),p.end(),1);
    tot=n;
    while((int)p.size()>1)
    {
        vector<int>pn;
        int i=0;
        for(i=0;i+2<(int)p.size();i+=3)
        {
            int now=++tot;
            son[now][0]=p[i];
            son[now][1]=p[i+1];
            son[now][2]=p[i+2];
            pn.emplace_back(now);
        }
        vector<int>ret;
        for(int j=i;j<(int)p.size();j++)
            ret.emplace_back(p[j]);
        p=ret;
        for(int u:pn)
            p.emplace_back(u);
    }
    int l=1,r=*max_element(d+1,d+n+1),ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}