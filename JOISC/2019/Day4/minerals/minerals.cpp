#include"minerals.h"
#include<iostream>
#include<cstdio>
#include<vector>
#include<functional>
using namespace std;
void Solve(int n)
{
    function<bool(int)>Ask=[&](int x)
    {
        static int lst=0;
        int now=Query(x);
        bool f=lst!=now;
        lst=now;
        return f;
    };
    vector<int>a,b;
    for(int i=1;i<=2*n;i++)
        if(Ask(i)) a.emplace_back(i);
        else b.emplace_back(i);
    function<void(const vector<int> &,const vector<int> &,bool)>solve=[&](const vector<int> &l,const vector<int> &r,bool op)
    {
        if(l.size()==1&&r.size()==1)
        {
            Answer(l[0],r[0]);
            return;
        }
        else
        {
            int mid;
            if(!op) mid=(int)(r.size()/3);
            else mid=(int)(r.size()/3*2);
            mid=max(mid,1);
            vector<int>rl,rr;
            for(int i=0;i<mid;i++)
                rl.emplace_back(r[i]);
            for(int i=mid;i<(int)r.size();i++)
                rr.emplace_back(r[i]);
            vector<int>ll,lr;
            if(!op)
                for(int i=0;i<mid;i++)
                    Ask(r[i]);
            else
                for(int i=mid;i<(int)r.size();i++)
                    Ask(r[i]);
            for(int u:l)
            {
                if(ll.size()==rl.size())
                {
                    lr.emplace_back(u);
                    continue; 
                }
                if(lr.size()==rr.size())
                {
                    ll.emplace_back(u);
                    continue;
                }
                if(Ask(u)) lr.emplace_back(u);
                else ll.emplace_back(u);
            }
            solve(ll,rl,true);
            solve(lr,rr,false);
        }
        return;
    };
    solve(a,b,1);
    return;
}