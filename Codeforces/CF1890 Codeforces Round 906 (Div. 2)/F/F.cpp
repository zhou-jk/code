#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n;
int ans[N];
bool vis[N];
vector<int>s[N];
vector<int>stk;
int dfs(int u)
{
    if(ans[u]) return ans[u];
    if(vis[u])
    {
        while(!stk.empty()&&stk.back()!=u)
        {
            vis[stk.back()]=false;
            s[stk.back()].pop_back();
            stk.pop_back();
        }
        vis[u]=false;
        s[u].pop_back();
        stk.pop_back();
    }
    vis[u]=true;
    stk.emplace_back(u);
    if(s[u].empty()) return u;
    else return dfs(s[u].back());
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        s[i].resize(k);
        for(int j=0;j<k;j++)
            cin>>s[i][j];
    }
    for(int i=1;i<=n;i++)
        if(!ans[i])
        {
            int res=dfs(i);
            for(int u:stk)
                ans[u]=res;
            stk.clear();
        }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}