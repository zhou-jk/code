#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
int n,m;
vector<int>a;
vector<vector<char>>s;
vector<vector<int>>id;
vector<vector<int>>GG;
vector<int>dfn,low;
vector<bool>vis;
int Index;
stack<int>stk;
vector<vector<int>>block;
vector<int>bel;
int tot;
void tarjan(int u)
{
    dfn[u]=low[u]=Index++;
    vis[u]=true;
    stk.emplace(u);
    for(int v:GG[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        vector<int>pos;
        while(stk.top()!=u)
        {
            pos.emplace_back(stk.top());
            bel[stk.top()]=tot;
            vis[stk.top()]=false;
            stk.pop();
        }
        pos.emplace_back(u);
        bel[u]=tot;
        vis[u]=false;
        stk.pop();
        block.emplace_back(pos);
        tot++;
    }
    return;
}
vector<vector<int>>G;
vector<int>in;
vector<int>getpos()
{
    vector<bool>pre(tot,false),book(tot,false);
    for(int j=0;j<m;j++)
        if(a[j]>0)
        {
            int c=0;
            for(int i=n-1;i>=0;i--)
                if(s[i][j]=='#')
                {
                    c++;
                    if(c==a[j])
                    {
                        pre[bel[id[i][j]]]=book[bel[id[i][j]]]=true;
                        break;
                    }
                }
        }
    vector<int>deg=in;
    queue<int>q;
    for(int i=0;i<tot;i++)
        if(deg[i]==0) q.emplace(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:G[u])
        {
            if(pre[u])
            {
                if(book[v]) book[v]=false;
                pre[v]=true;
            }
            deg[v]--;
            if(deg[v]==0) q.emplace(v);
        }
    }
    vector<int>pos;
    vector<bool>used(tot,false);
    for(int j=0;j<m;j++)
        for(int i=0;i<n;i++)
            if(s[i][j]=='#'&&book[bel[id[i][j]]]&&!used[bel[id[i][j]]])
            {
                used[bel[id[i][j]]]=true;
                pos.emplace_back(bel[id[i][j]]);
                break;
            }
    return pos;
}
pair<vector<int>,vector<int>> getlr(const vector<int> &pos)
{
    int k=pos.size();
    vector<int>l(tot,k),r(tot,-1);
    for(int i=0;i<k;i++)
        l[pos[i]]=r[pos[i]]=i;
    vector<int>book(tot,false);
    function<void(int)>dfs=[&](int u)
    {
        if(book[u]) return;
        book[u]=true;
        for(int v:G[u])
        {
            dfs(v);
            l[u]=min(l[u],l[v]);
            r[u]=max(r[u],r[v]);
        }
        return;
    };
    for(int i=0;i<tot;i++)
        dfs(i);
    return {l,r};
}
int seg_cover(const int &l,const int &r,const vector<pair<int,int>> &segment)
{
    vector<pair<int,int>>seg=segment;
    sort(seg.begin(),seg.end());
    int now=l-1,nxt=-1;
    int res=0;
    int i=0;
    while(now<r)
    {
        while(i<(int)seg.size()&&seg[i].first<=now+1) nxt=max(nxt,seg[i].second),i++;
        now=nxt,res++;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    s.resize(n);
    for(int i=0;i<n;i++)
        s[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int ch=getchar();
            while(ch!='.'&&ch!='#') ch=getchar();
            s[i][j]=ch;
        }
    id.resize(n);
    for(int i=0;i<n;i++)
        id[i].resize(m);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='#') id[i][j]=cnt++;
    a.resize(m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    GG.resize(cnt);
    for(int j=0;j<m;j++)
    {
        int pre=n,now=n,nxt=n;
        for(int i=n-1;i>=0;i--)
        {
            if(j-1>=0&&s[i][j-1]=='#') pre=i;
            if(j+1<m&&s[i][j+1]=='#') nxt=i;
            if(s[i][j]=='#')
            {
                if(j-1>=0&&pre<n) GG[id[i][j]].emplace_back(id[pre][j-1]);
                if(j+1<m&&nxt<n) GG[id[i][j]].emplace_back(id[nxt][j+1]);
                if(now<n) GG[id[i][j]].emplace_back(id[now][j]);
                now=i;
                if(i>0&&s[i-1][j]=='#') GG[id[i][j]].emplace_back(id[i-1][j]);
            }
        }
    }
    Index=0;
    dfn.resize(cnt),low.resize(cnt);
    vis.resize(cnt);
    bel.resize(cnt);
    for(int i=0;i<cnt;i++)
        if(!dfn[i]) tarjan(i);
    G.resize(tot);
    in.resize(tot);
    for(int u=0;u<cnt;u++)
        for(int v:GG[u])
        {
            int x=bel[u],y=bel[v];
            if(x==y) continue;
            G[x].emplace_back(y);
            in[y]++;
        }
    vector<int>pos=getpos();
    int k=pos.size();
    auto [l,r]=getlr(pos);
    vector<pair<int,int>>seg;
    for(int i=0;i<tot;i++)
        if(0<=l[i]&&l[i]<=r[i]&&r[i]<k) seg.emplace_back(l[i],r[i]);
    int ans=seg_cover(0,k-1,seg);
    printf("%d",ans);
    return 0;
}