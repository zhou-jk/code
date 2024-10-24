#include<bits/stdc++.h>
using namespace std;
constexpr int N=1000005;
struct Hash
{
    static constexpr int MOD1=1000000007,MOD2=1000000009;
    static constexpr int BASE=23;
    int x,y;
    Hash():x(0),y(0){}
    Hash(int v):x(v),y(v){}
    Hash(int _x,int _y):x(_x),y(_y){}
    long long to_ll()const
    {
        return (((long long)x)<<31)+y;
    }
    friend bool operator == (const Hash &a,const Hash &b)
    {
        return a.x==b.x&&a.y==b.y;
    }
    friend Hash operator + (const Hash &a,const Hash &b)
    {
        int x=a.x+b.x,y=a.y+b.y;
        if(x>=MOD1) x-=MOD1;
        if(y>=MOD2) y-=MOD2;
        return Hash(x,y);
    }
    friend Hash operator - (const Hash &a,const Hash &b)
    {
        int x=a.x-b.x,y=a.y-b.y;
        if(x<0) x+=MOD1;
        if(y<0) y+=MOD2;
        return Hash(x,y);
    }
    friend Hash operator * (const Hash &a,const Hash &b)
    {
        return Hash((long long)a.x*b.x%MOD1,(long long)a.y*b.y%MOD2);
    }
};
Hash pw[N];
void init_hash(int n)
{
    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*Hash::BASE;
    return;
}
vector<Hash>hsh[N];
vector<Hash>get_hash(const string &s)
{
    vector<Hash>val(s.size());
    val[0]=s[0]-'a'+1;
    for(int i=1;i<(int)s.size();i++)
        val[i]=val[i-1]*Hash::BASE+s[i]-'a'+1;
    return val;
}
Hash calc_hash(const vector<Hash> &val,int l,int r)
{
    if(l>r) return 0;
    Hash res=val[r];
    if(l-1>=0) res=res-val[l-1]*pw[r-l+1];
    return res;
}
struct Trie
{
    static const int C=128; 
    int trie[N][C],tot;
    int ed[N],siz[N];
    Trie():tot(1)
    {
        memset(trie[1],0,sizeof(trie[1]));
        ed[1]=siz[1]=0;
    }
    void clear()
    {
        tot=1;
        memset(trie[1],0,sizeof(trie[1]));
        ed[1]=siz[1]=0;
        return;
    }
    int new_node()
    {
        int now=++tot;
        memset(trie[now],0,sizeof(trie[now]));
        ed[now]=siz[now]=0;
        return now;
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
            if(!trie[u][c]) trie[u][c]=new_node();
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
vector<int> prefix_function(const string &s)
{
    int n=s.size();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}
vector<int> find_occurrences(string text,string pattern)
{
    string cur=pattern+"#"+text;
    int len1=text.size(),len2=pattern.size();
    vector<int>pi=prefix_function(cur);
    vector<int>pos;
    for(int i=len2+1;i<=len1+len2;i++)
        if(pi[i]==len2) pos.push_back(i-2*len2);
    return pos;
}
vector<int> z_function(const string &s)
{
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r&&z[i-l]<r-i+1) z[i]=z[i-l];
        else
        {
            z[i]=max(0,r-i+1);
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        }
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}
vector<int>manacher(const string &s)
{
    int n=s.size();
    vector<int>p(n);
    int l=0,r=-1;
    for(int i=0;i<n;i++)
    {
        int k=1;
        if(i<=r) k=min(p[l+r-i],r-i+1);
        while(0<=i-k&&i+k<n&&s[i-k]==s[i+k]) k++;
        p[i]=k;
        k--;
        if(i+k>r) l=i-k,r=i+k;
    }
    return p;
}
vector<int>suffix_array(const string &s)
{
    int n=s.size();
    vector<int>rk(n),sa(n);
    for(int i=0;i<n;i++)
        sa[i]=i;
    sort(sa.begin(),sa.end(),[&](const int &x,const int &y){return s[x]<s[y];});
    rk[sa[0]]=0;
    for(int i=1;i<n;i++)
        if(s[sa[i]]==s[sa[i-1]]) rk[sa[i]]=rk[sa[i-1]];
        else rk[sa[i]]=rk[sa[i-1]]+1;
    int m=rk[sa[n-1]]+1;
    for(int w=1;w<n;w<<=1)
    {
        vector<int>id;
        for(int i=n-w;i<n;i++)
            id.emplace_back(i);
        for(int i=0;i<n;i++)
            if(sa[i]>=w) id.emplace_back(sa[i]-w);
        vector<int>cnt(m,0);
        for(int i=0;i<n;i++)
            cnt[rk[i]]++;
        for(int i=1;i<m;i++)
            cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--)
            sa[--cnt[rk[id[i]]]]=id[i];
        vector<int>oldrk=rk;
        rk[sa[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(oldrk[sa[i]]==oldrk[sa[i-1]]&&(sa[i]+w>=n?-1:oldrk[sa[i]+w])==(sa[i-1]+w>=n?-1:oldrk[sa[i-1]+w])) rk[sa[i]]=rk[sa[i-1]];
            else rk[sa[i]]=rk[sa[i-1]]+1;
        }
        m=rk[sa[n-1]]+1;
        if(m==n) break;
    }
    return sa;
}
vector<int> get_rank(const vector<int> &sa)
{
    vector<int>rk(sa.size());
    for(int i=0;i<(int)sa.size();i++)
        rk[sa[i]]=i;
    return rk;
}
vector<int> get_height(const string &s)
{
    int n=s.size();
    vector<int>sa=suffix_array(s),rk=get_rank(sa);
    vector<int>height(n);
    for(int i=0,k=0;i<n;i++)
    {
        if(rk[i]==0)
        {
            height[rk[i]]=k=0;
            continue;
        }
        if(k>0) k--;
        int j=sa[rk[i]-1]; 
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
    return height;
}
struct SAM
{
    struct state
    {
        int len,link;
        int siz;
        int next[26];
    };
    state st[N*2];
    int tot,last;
    SAM()
    {
        st[0].len=0;
        st[0].link=-1;
        tot=last=0;
    }
    void clear()
    {
        st[0].len=0;
        st[0].siz=0;
        st[0].link=-1;
        tot=last=0;
        return;
    }
    int new_node()
    {
        int now=++tot;
        st[now].len=0,st[now].link=-1;
        st[now].siz=0;
        memset(st[now].next,0,sizeof(st[now].next));
        return now;
    }
    int convert(char c)
    {
        return c-'a';
    }
    void extend(char ch)
    {
        int c=convert(ch);
        int cur=new_node();
        st[cur].len=st[last].len+1;
        st[cur].siz=1;
        int p=last;
        while(p!=-1&&!st[p].next[c])
            st[p].next[c]=cur,p=st[p].link;
        if(p==-1) st[cur].link=0;
        else
        {
            int q=st[p].next[c];
            if(st[p].len+1==st[q].len) st[cur].link=q;
            else
            {
                int clone=new_node();
                st[clone]=st[q];
                st[clone].siz=0;
                st[clone].len=st[p].len+1;
                while(p!=-1&&st[p].next[c]==q)
                    st[p].next[c]=clone,p=st[p].link;
                st[q].link=st[cur].link=clone;
            }
        }
        last=cur;
        return;
    }
    void build(const string &s)
    {
        clear();
        for(char ch:s)
            extend(ch);
        return;
    }
    void dfs(int u)
    {
        for(int v:G[u])
        {
            dfs(v);
            st[u].siz+=st[v].siz;
        }
        return;
    }
    vector<int>G[N*2];
    void rebuild()
    {
        for(int i=1;i<=tot;i++)
            G[st[i].link].emplace_back(i);
        dfs(0);
        return;
    }
};