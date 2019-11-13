#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=3000001;
int n;
int trie[N][26],tot=1;
int dep[N],num[N];
long long ans;
int pre[N],cnt[N],b[N];
int top,S[N];
queue<int> q;
char s[N];
void build(char *s)
{
    int u=1;
    for(int i=0;i<strlen(s);i++)
    {
        int c=s[i]-'a';
        if(!trie[u][c]) trie[u][c]=++tot;
        dep[trie[u][c]]=dep[u]+1;
        u=trie[u][c];
    }
    return;
}
void dfs(int u)
{
    S[++top]=u;
    for(int i=0;i<26;i++)
        if(dep[trie[u][i]]==dep[u]+1) dfs(trie[u][i]);
    top--;
    if(pre[u]!=1) ans-=num[S[dep[u]-dep[pre[u]]+1]]-1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        build(s);
    }
    ans=(long long)(tot-1)*(tot-1);
    for(int i=0;i<26;i++)
        if(trie[1][i])
        {
            pre[trie[1][i]]=1;
            q.push(trie[1][i]);
        }
        else trie[1][i]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++)
            if(trie[u][i])
            {
                pre[trie[u][i]]=trie[pre[u]][i];
                q.push(trie[u][i]);
            }
        else trie[u][i]=trie[pre[u]][i];
    }
    for(int i=1;i<=tot;i++)
        cnt[dep[i]]++;
    for(int i=1;i<=tot;i++)
        cnt[i]+=cnt[i-1];
    for(int i=tot;i;i--)
        b[cnt[dep[i]]--]=i;
    for(int i=tot;i;i--)
        num[pre[b[i]]]+=++num[b[i]];
    num[1]=1;
    dfs(1);
    printf("%lld",ans);
    return 0;
}