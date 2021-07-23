#include"chameleon.h"
#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;
void Solve(int n)
{
    function<vector<int>(const vector<int> &,int)>addback=[=](const vector<int> &p,int u)
    {
        vector<int>S=p;
        S.emplace_back(u);
        return S;
    };
    vector<int>deg(n*2+1);
    vector<vector<int>>G(n*2+1);
    function<void(const vector<int> &,int)>findedge=[&](const vector<int> &S,int u)
    {
        if(S.empty()) return;
        if(S.size()==1)
        {
            G[S[0]].emplace_back(u);
            G[u].emplace_back(S[0]);
            deg[u]++,deg[S[0]]++;
            return;
        }
        int mid=max((int)(S.size()/2.8),1);
        vector<int>l,r;
        for(int i=0;i<mid;i++)
            l.emplace_back(S[i]);
        for(int i=mid;i<(int)S.size();i++)
            r.emplace_back(S[i]);
        if(Query(addback(l,u))==(int)l.size()+1) return findedge(r,u);
        else if(Query(addback(r,u))==(int)r.size()+1) return findedge(l,u);
        else findedge(l,u),findedge(r,u);
        return;
    };
    function<void(const vector<int> &)> divide=[&](const vector<int> &p)
    {
        if(p.empty()) return;
        int lst=0;
        vector<int>S,ret;
        for(int u:p)
        {
            if(lst==0)
            {
                S.emplace_back(u),lst++;
                continue;
            }
            if(deg[u]==3) continue;
            bool flag=true;
            for(int v:S)
            {
                for(int t:G[u])
                    if(v==t)
                    {
                        flag=false;
                        break;
                    }
                if(!flag) break;
            }
            if(!flag) ret.emplace_back(u);
            else
            {
                int now=Query(addback(S,u));
                if(now>lst) S.emplace_back(u),lst=now;
                else ret.emplace_back(u);
            }
        }
        for(int u:ret)
        {
            findedge(S,u);
            vector<int>nxt;
            for(int v:S)
                if(deg[v]<3) nxt.emplace_back(v);
            S=nxt; 
        }
        divide(ret);
        return;
    };
    vector<int>S(n*2);
    iota(S.begin(),S.end(),1);
    divide(S);
    vector<int>to(n*2+1);
    for(int u=1;u<=n*2;u++)
        if(deg[u]==3)
        {
            if(Query({u,G[u][0],G[u][1]})==1) to[u]=G[u][2];
            else if(Query({u,G[u][0],G[u][2]})==1) to[u]=G[u][1];
            else to[u]=G[u][0];
        }
    vector<int>from(n*2+1);
    for(int u=1;u<=n*2;u++)
        if(deg[u]==3) from[to[u]]=u;
    vector<int>match(n*2+1);
    for(int u=1;u<=n*2;u++)
        if(!match[u])
        {
            if(deg[u]==1)
            {
                int v=G[u][0];
                match[u]=v;
                match[v]=u;
                Answer(u,v);
            }
            else if(deg[u]==3)
            {
                int v;
                if(G[u][0]!=from[u]&&G[u][0]!=to[u]) v=G[u][0];
                else if(G[u][1]!=from[u]&&G[u][1]!=to[u]) v=G[u][1];
                else v=G[u][2];
                match[u]=v;
                match[v]=u;
                Answer(u,v);
            }
        }
    return;
}