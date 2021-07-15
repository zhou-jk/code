#include"meetings.h"
#include<iostream>
#include<cstdio>
#include<ctime>
#include<random>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;
void Solve(int n)
{
    mt19937 rnd((unsigned)time(NULL));
    function<int(int,int)>rand=[&](int l,int r)
    {
        return rnd()%(r-l+1)+l;
    };
    function<void(int,const vector<int> &)>divide=[&](int x,const vector<int> &node)
    {
        if(node.size()==1)
        {
            if(x<node[0]) Bridge(x,node[0]);
            else Bridge(node[0],x);
            return;
        }
        vector<int>p=node;
        shuffle(p.begin(),p.end(),rnd);
        vector<int>id(n);
        for(int i=0;i<(int)p.size();i++)
            id[p[i]]=i;
        vector<vector<int>>son(p.size()+1);
        int y=p[0];
        vector<int>pos;
        for(int i=1;i<(int)p.size();i++)
        {
            int z=p[i];
            int l=Query(x,y,z);
            if(l!=z)
            {
                if(l==x) son.back().emplace_back(z);
                else son[id[l]].emplace_back(z);
            }
            else pos.emplace_back(z);
        }
        pos.emplace_back(y);
        for(int i=0;i<(int)p.size();i++)
            if(!son[i].empty()) divide(p[i],son[i]);
        if(!son.back().empty()) divide(x,son.back());
        sort(pos.begin(),pos.end(),[=](const int &a,const int &b){return Query(a,b,x)==a;});
        for(int i=0;i<(int)pos.size();i++)
            if(i==0)
            {
                if(pos[i]<x) Bridge(pos[i],x);
                else Bridge(x,pos[i]);
            }
            else
            {
                if(pos[i]<pos[i-1]) Bridge(pos[i],pos[i-1]);
                else Bridge(pos[i-1],pos[i]);
            }
        return;
    };
    int rt=rand(0,n-1);
    vector<int>pos;
    for(int i=0;i<n;i++)
        if(rt!=i) pos.emplace_back(i);
    divide(rt,pos);
    return;
}