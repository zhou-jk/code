#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N=1000005;
const int BASE=31;
struct Hash
{
    static const int MOD1=1000000007,MOD2=1000000009;
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
        return Hash((a.x+b.x)%MOD1,(a.y+b.y)%MOD2);
    }
    friend Hash operator - (const Hash &a,const Hash &b)
    {
        return Hash((a.x-b.x+MOD1)%MOD1,(a.y-b.y+MOD2)%MOD2);
    }
    friend Hash operator * (const Hash &a,const Hash &b)
    {
        return Hash((long long)a.x*b.x%MOD1,(long long)a.y*b.y%MOD2);
    }
};
Hash pw[N];
void init(int n=1000000)
{
    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*BASE;
    return;
}
int n,m;
string a[N],b[N];
vector<Hash>hasha[N],hashb[N];
vector<Hash>init_hash(const string &s)
{
    vector<Hash>val(s.size());
    val[0]=s[0]-'a'+1;
    for(int i=1;i<(int)s.size();i++)
        val[i]=val[i-1]*BASE+s[i]-'a'+1;
    return val;
}
Hash get_hash(const vector<Hash> &val,int l,int r)
{
    if(l>r) return 0;
    Hash res=val[r];
    if(l-1>=0) res=res-val[l-1]*pw[r-l+1];
    return res;
}
unordered_map<long long,int>posed,posst;
int tot;
int in[2*N],out[2*N];
vector<pair<int,int>>G[2*N];
vector<int>ansa,ansb;
void dfs(int u)
{
    while(!G[u].empty())
    {
        auto [v,id]=G[u].back();
        G[u].pop_back();
        dfs(v);
        if(id<=n) ansa.emplace_back(id);
        else ansb.emplace_back(id-n);
    }
    return;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        hasha[i].resize(m),hashb[i].resize(m);
    for(int i=1;i<=n;i++)
        hasha[i]=init_hash(a[i]),hashb[i]=init_hash(b[i]);
    for(int len=0;len<m;len++)
    {
        posed.clear(),posst.clear();
        tot=0;
        for(int i=1;i<=n;i++)
        {
            long long pre=get_hash(hasha[i],0,len-1).to_ll(),suf=get_hash(hasha[i],len,m-1).to_ll();
            if(!posst.count(pre)) posst[pre]=++tot,G[tot].clear(),in[tot]=out[tot]=0;
            if(!posed.count(suf)) posed[suf]=++tot,G[tot].clear(),in[tot]=out[tot]=0;
            int s=posst[pre],t=posed[suf];
            out[s]++,in[t]++;
            G[s].emplace_back(t,i);
        }
        for(int i=1;i<=n;i++)
        {
            long long pre=get_hash(hashb[i],0,m-len-1).to_ll(),suf=get_hash(hashb[i],m-len,m-1).to_ll();
            if(!posed.count(pre)) posed[pre]=++tot,G[tot].clear(),in[tot]=out[tot]=0;
            if(!posst.count(suf)) posst[suf]=++tot,G[tot].clear(),in[tot]=out[tot]=0;
            int s=posed[pre],t=posst[suf];
            out[s]++,in[t]++;
            G[s].emplace_back(t,i+n);
        }
        bool flag=true;
        for(int i=1;i<=tot;i++)
            if(in[i]!=out[i])
            {
                flag=false;
                break;
            }
        if(!flag) continue;
        ansa.clear(),ansb.clear();
        dfs(1);
        reverse(ansa.begin(),ansa.end());
        reverse(ansb.begin(),ansb.end());
        if((int)ansa.size()!=n) continue;
        if((int)ansb.size()!=n) continue;
        for(int u:ansa)
            cout<<u<<" ";
        cout<<"\n";
        for(int u:ansb)
            cout<<u<<" ";
        cout<<"\n";
        return;
    }
    cout<<-1<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}