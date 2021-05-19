#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=40;
int n;
char s[N];
map<pair<string,string>,int>vis;
void dfs1(int u,string r,string b)
{
    if(u>n)
    {
        vis[{r,b}]++;
        return;
    }
    dfs1(u+1,r+s[u],b);
    dfs1(u+1,r,b+s[u]);
    return;
}
long long ans;
void dfs2(int u,string r,string b)
{
    if(u<=n)
    {
        ans+=vis[{r,b}];
        return;
    }
    dfs2(u-1,r+s[u],b);
    dfs2(u-1,r,b+s[u]);
    return;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    dfs1(1,"","");
    dfs2(2*n,"","");
    printf("%lld",ans);
    return 0;
}