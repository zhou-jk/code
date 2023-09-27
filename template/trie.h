#include<iostream>
#include<cstdio>
using namespace std;
const int N=3000005;
struct Trie
{
    static const int C=128; 
    int trie[N][C],tot;
    int ed[N],siz[N];
    void clear(int u)
    {
        if(!u) return;
        siz[u]=ed[u]=0;
        for(int c=0;c<C;c++)
            clear(trie[u][c]),trie[u][c]=0;
        return;
    }
    void clear()
    {
        clear(1);
        tot=1;
        return;
    }
    int get(char c)
    {
        return (int)c;
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
    int query(const string &s)
    {
        int len=s.size();
        int u=1;
        for(int i=0;i<len;i++)
        {
            int c=get(s[i]);
            if(!trie[u][c]) return 0;
            u=trie[u][c];
        }
        return siz[u];
    }
    void dfs(int u)
    {
        if(!u) return;
        siz[u]=ed[u];
        for(int c=0;c<C;c++)
            dfs(trie[u][c]),siz[u]+=siz[trie[u][c]];
        return;
    }
};