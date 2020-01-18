#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
const int N=500001;
int n;
char str[N];
int fa[N];
int len[N];
long long res[N],ans;
stack<int>s;
vector<int>son[N];
void dfs(int u)
{
    int tmp=0;
    if(str[u]==')')
    {
        if(!s.empty())
        {
            tmp=s.top();
            len[u]=len[fa[s.top()]]+1;
            s.pop();
        }
    }
    else if(str[u]=='(') s.push(u); 
    res[u]=res[fa[u]]+len[u];
    for(auto v:son[u])
        dfs(v);
    if(tmp!=0) s.push(tmp);
    else if(!s.empty()) s.pop(); 
    return;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        fa[i]=x;
        son[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        ans^=res[i]*i;
    printf("%lld",ans);
    return 0;
}