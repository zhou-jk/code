#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000005;
int n,m;
string s[N];
int len[N];
struct Trie
{
    static const int C=26; 
    int trie[N][C],tot;
    int siz[N],ed[N];
    Trie()
    {
        tot=1;
        memset(trie,0,sizeof(trie));
    }
    int get(char c)
    {
        return c-'a';
    }
    void insert(const string &s)
    {
        int len=s.size();
        int u=1;
        for(int i=0;i<len;i++)
        {
            int c=get(s[i]);
            if(!trie[u][c]) trie[u][c]=++tot;
            u=trie[u][c];
        }
        ed[u]++;
        return;
    }
    void dfs(int u)
    {
        if(!u) return;
        siz[u]=ed[u];
        for(int c=0;c<C;c++)
            dfs(trie[u][c]),siz[u]+=siz[trie[u][c]];
        return;
    }
    long long query(const string &s)
    {
        int len=s.size();
        int u=1;
        long long res=0;
        for(int i=0;i<len;i++)
        {
            int c=get(s[i]);
            res+=(long long)2*i*(siz[u]-siz[trie[u][c]]);
            if(!trie[u][c]) return res;
            u=trie[u][c];
        }
        res+=(long long)2*len*siz[u];
        return res;
    }
}T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        string t=s[i];
        len[i]=s[i].size();
        m+=len[i];
        reverse(t.begin(),t.end());
        T.insert(t);
    }
    T.dfs(1);
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=(long long)len[i]*n+m-T.query(s[i]);
    cout<<ans;
    return 0;
}