#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
vector<int>G[N];
int f[N],g[N];
void dfs1(int u,int father)
{
    vector<int>tf;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        tf.emplace_back(f[v]);
    }
    if(tf.empty())
    {
        f[u]=g[u]=1;
        return;
    }
    sort(tf.begin(),tf.end(),greater<int>());
    f[u]=tf[0];
    for(int i=1;i<(int)tf.size();i++)
        f[u]=max(f[u],tf[i]+i);
    for(int i=1;i<(int)tf.size();i++)
        g[u]=max(g[u],tf[i]+i);
    g[u]+=tf[0]-1;
    for(int v:G[u])
    {
        if(v==father) continue;
        g[u]=max(g[u],g[v]);
    }
    return;
}
int ans[N];
void dfs2(int u,int father,int pf,int pg)
{
    vector<int>tf;
    for(int v:G[u])
    {
        if(v==father) continue;
        tf.emplace_back(f[v]);
    }
    if(father) tf.emplace_back(pf);
    sort(tf.begin(),tf.end(),greater<int>());
    if(tf.empty()) return;
    for(int i=1;i<(int)tf.size();i++)
        ans[u]=max(ans[u],tf[i]+i);
    ans[u]+=tf[0]-1;
    for(int v:G[u])
    {
        if(v==father) continue;
        ans[u]=max(ans[u],g[v]);
    }
    ans[u]=max(ans[u],pg);
    vector<pair<int,int>>tp;
    for(int v:G[u])
    {
        if(v==father) continue;
        tp.emplace_back(f[v],v);
    }
    if(father) tp.emplace_back(pf,father);
    sort(tp.begin(),tp.end(),greater<pair<int,int>>());
    if(tp.empty()) return;
    int t=tp.size();
    vector<int>pref(t),suff(t);
    pref[0]=tp[0].first;
    for(int i=1;i<t;i++)
        pref[i]=max(pref[i-1],tp[i].first+i);
    suff[t-1]=tp[t-1].first+t-2;
    for(int i=t-2;i>=0;i--)
        suff[i]=max(suff[i+1],tp[i].first+i-1);
    int smx=0;
    for(int i=2;i<t;i++)
        smx=max(smx,tp[i].first+i-1);
    if(t>1) smx+=tp[1].first-1;
    vector<int>preg(t),sufg(t);
    preg[0]=0;
    for(int i=1;i<t;i++)
        preg[i]=max(preg[i-1],tp[i].first+i);
    sufg[t-1]=tp[t-1].first+t-2;
    for(int i=t-2;i>=0;i--)
        sufg[i]=max(sufg[i+1],tp[i].first+i-1);
    for(int i=0;i<t;i++)
    {
        int v=tp[i].second;
        if(v==father) continue;
        int vf=1;
        if(i-1>=0) vf=max(vf,pref[i-1]);
        if(i+1<t) vf=max(vf,suff[i+1]);
        int vg=1;
        if(i==0) vg=smx;
        else
        {
            if(i-1>=0) vg=max(vg,preg[i-1]);
            if(i+1<t) vg=max(vg,sufg[i+1]);
            vg+=tp[0].first-1;
        }
        dfs2(v,u,vf,vg);
    }
    return;
}
void dfs3(int u,int father)
{
    vector<int>tf;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        tf.emplace_back(f[v]);
    }
    if(tf.empty())
    {
        f[u]=1;
        return;
    }
    sort(tf.begin(),tf.end(),greater<int>());
    f[u]=tf.front();
    for(int i=1;i<(int)tf.size();i++)
        f[u]=max(f[u],tf[i]+i);
    return;
}
int query(int r)
{
    printf("? %d\n",r);
    fflush(stdout);
    int v;
    scanf("%d",&v);
    return v;
}
int solve(int u,int father)
{
    vector<int>son;
    for(int v:G[u])
    {
        if(v==father) continue;
        son.emplace_back(v);
    }
    sort(son.begin(),son.end(),[=](const int &x,const int &y){return f[x]>f[y];});
    if(son.empty())
    {
        int p=query(u);
        if(p==u) return u;
        else return -p;
    }
    for(int v:son)
    {
        int p=solve(v,u);
        if(p>0) return p;
        else if(-p!=u) return p;
    }
    return u;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs1(1,0);
    dfs2(1,0,0,0);
    int res=*max_element(ans+1,ans+n+1);
    printf("%d\n",res);
    fflush(stdout);
    int rt;
    scanf("%d",&rt);
    dfs3(rt,0);
    vector<int>son=G[rt];
    sort(son.begin(),son.end(),[=](const int &x,const int &y){return f[x]>f[y];});
    int a=0,b=0;
    for(int v:son)
    {
        int p=solve(v,rt);
        if(p>0)
        {
            if(!a) a=p;
            else if(!b)
            {
                b=p;
                break;
            }
        }
    }
    if(!a) a=rt;
    if(!b) b=rt;
    printf("! %d %d",a,b);
    return 0;
}