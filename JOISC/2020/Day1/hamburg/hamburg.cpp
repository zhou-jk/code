#include<iostream>
#include<cstdio>
#include<cassert>
#include<set>
#include<stack>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,k;
int l[N],d[N],r[N],u[N];
bool vis[N];
pair<int,int>p[5];
void dfs(int step)
{
    if(step>k)
    {
        for(int i=1;i<=n;i++)
            if(!vis[i]) return;
        for(int i=1;i<=k;i++)
            printf("%d %d\n",p[i].first,p[i].second);
        exit(0);
    }
    int maxl=0,minr=INF,maxd=0,minu=INF;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            maxl=max(maxl,l[i]);
            minr=min(minr,r[i]);
            maxd=max(maxd,d[i]);
            minu=min(minu,u[i]);
        }
    vector<int>pos;
    int x,y;
    x=maxl,y=maxd;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    x=maxl,y=minu;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    x=minr,y=maxd;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    x=minr,y=minu;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    return;
}
int c[N];
int id[N][2],cnt;
int pos[N][2];
vector<tuple<int,int,int,int>>L,R,D,U;
vector<int>G[N*10];
int dfn[N*10],low[N*10],Index;
int bel[N*10],tot;
void tarjan(int u)
{
    static bool vis[N*10];
    static stack<int>s;
    dfn[u]=low[u]=++Index;
    s.emplace(u);
    vis[u]=true;
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            bel[s.top()]=tot;
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=tot;
        vis[u]=false;
        s.pop();
    }
    return;
}
int val[N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&l[i],&d[i],&r[i],&u[i]);
    dfs(1);
    if(k==4)
    {
        int maxl=*max_element(l+1,l+n+1),minr=*min_element(r+1,r+n+1),maxd=*max_element(d+1,d+n+1),minu=*min_element(u+1,u+n+1);
        assert(minr<=maxl&&minu<=maxd);
        for(int i=1;i<=n;i++)
        {
            if(l[i]<=minr&&minr<=r[i]) c[i]++;
            if(l[i]<=maxl&&maxl<=r[i]) c[i]++;
            if(d[i]<=minu&&minu<=u[i]) c[i]++;
            if(d[i]<=maxd&&maxd<=u[i]) c[i]++;
            if(c[i]>=3) continue;
            assert(c[i]>0);
            id[i][0]=++cnt,id[i][1]=++cnt;
            if(c[i]==1)
            {
                G[id[i][1]].emplace_back(id[i][0]);
                if(l[i]<=minr&&minr<=r[i]) L.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=1;
                else if(l[i]<=maxl&&maxl<=r[i]) R.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=2;
                else if(d[i]<=minu&&minu<=u[i]) D.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=3;
                else if(d[i]<=maxd&&maxd<=u[i]) U.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=4;
                else assert(false);
            }
            if(c[i]==2)
            {
                for(int j=1;j<=4;j++)
                    for(int k=j+1;k<=4;k++)
                    {
                        bool fj=false;
                        if(j==1) fj=l[i]<=minr&&minr<=r[i];
                        else if(j==2) fj=l[i]<=maxl&&maxl<=r[i];
                        else if(j==3) fj=d[i]<=minu&&minu<=u[i];
                        else if(j==4) fj=d[i]<=maxd&&maxd<=u[i];
                        bool fk=false;
                        if(k==1) fk=l[i]<=minr&&minr<=r[i];
                        else if(k==2) fk=l[i]<=maxl&&maxl<=r[i];
                        else if(k==3) fk=d[i]<=minu&&minu<=u[i];
                        else if(k==4) fk=d[i]<=maxd&&maxd<=u[i];
                        if(fj&&fk)
                        {
                            if(j==1) L.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=1;
                            else if(j==2) R.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=2;
                            else if(j==3) D.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=3;
                            else if(j==4) U.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=4;
                            else assert(false);
                            if(k==1) L.emplace_back(d[i],u[i],id[i][1],id[i][0]),pos[i][1]=1;
                            else if(k==2) R.emplace_back(d[i],u[i],id[i][1],id[i][0]),pos[i][1]=2;
                            else if(k==3) D.emplace_back(l[i],r[i],id[i][1],id[i][0]),pos[i][1]=3;
                            else if(k==4) U.emplace_back(l[i],r[i],id[i][1],id[i][0]),pos[i][1]=4;
                            else assert(false);
                        }
                    }
            }
        }
        for(auto a:{L,R,D,U})
        {
            vector<int>to(a.size()),from(a.size());
            for(int i=0;i<(int)a.size();i++)
                to[i]=++cnt,from[i]=++cnt;
            sort(a.begin(),a.end(),[=](const tuple<int,int,int,int> &x,const tuple<int,int,int,int> &y){return get<1>(x)<get<1>(y);});
            for(int i=0;i<(int)a.size();i++)
            {
                G[to[i]].emplace_back(get<3>(a[i]));
                G[get<2>(a[i])].emplace_back(from[i]);
                if(i>0)
                {
                    G[to[i]].emplace_back(to[i-1]);
                    G[from[i-1]].emplace_back(from[i]);
                }
            }
            vector<int>posr(a.size());
            for(int i=0;i<(int)posr.size();i++)
                posr[i]=get<1>(a[i]);
            for(int i=0;i<(int)a.size();i++)
            {
                auto [li,ri,i1,i0]=a[i];
                if(i>0)
                {
                    int j=lower_bound(posr.begin(),posr.begin()+i,li)-posr.begin()-1;
                    if(j>=0)
                    {
                        G[i1].emplace_back(to[j]);
                        G[from[j]].emplace_back(i0);
                    }
                }
            }
        }
        for(int i=1;i<=cnt;i++)
            if(!dfn[i]) tarjan(i);
        for(int i=1;i<=n;i++)
            if(c[i]==1||c[i]==2) assert(bel[id[i][0]]!=bel[id[i][1]]);
        for(int i=1;i<=n;i++)
            if(c[i]==1||c[i]==2) val[i]=bel[id[i][1]]<bel[id[i][0]];
        int ld=0,lu=INF,rd=0,ru=INF;
        int dl=0,dr=INF,ul=0,ur=INF;
        for(int i=1;i<=n;i++)
            if(c[i]==1)
            {
                if(pos[i][0]==1) ld=max(ld,d[i]),lu=min(lu,u[i]);
                else if(pos[i][0]==2) rd=max(rd,d[i]),ru=min(ru,u[i]);
                else if(pos[i][0]==3) dl=max(dl,l[i]),dr=min(dr,r[i]);
                else if(pos[i][0]==4) ul=max(ul,l[i]),ur=min(ur,r[i]);
            }
            else if(c[i]==2)
            {
                if(pos[i][val[i]]==1) ld=max(ld,d[i]),lu=min(lu,u[i]);
                else if(pos[i][val[i]]==2) rd=max(rd,d[i]),ru=min(ru,u[i]);
                else if(pos[i][val[i]]==3) dl=max(dl,l[i]),dr=min(dr,r[i]);
                else if(pos[i][val[i]]==4) ul=max(ul,l[i]),ur=min(ur,r[i]);
            }
        assert(ld<=lu&&rd<=ru&&dl<=dr&&ul<=ur);
        printf("%d %d\n",minr,ld);
        printf("%d %d\n",maxl,rd);
        printf("%d %d\n",dl,minu);
        printf("%d %d",ul,maxd);
    }
    return 0;
}