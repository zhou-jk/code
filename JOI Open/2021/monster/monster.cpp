#include<iostream>
#include<cstdio>
#include<vector>
#include<functional>
#include<map>
#include<algorithm>
#include"monster.h"
using namespace std;
map<pair<int,int>,bool>book;
bool query(int a,int b)
{
    if(book.count(make_pair(a,b))) return book[make_pair(a,b)];
    else return book[make_pair(a,b)]=Query(a,b);
}
vector<int> Solve(int N)
{
    int n=N;
    vector<int>id(n);
    for(int i=0;i<n;i++)
        id[i]=i;
    function<void(int,int)>merge_sort=[&](int l,int r)
    {
        if(l==r) return;
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        vector<int>tmp;
        int p1=l,p2=mid+1;
        while(p1<=mid&&p2<=r)
            if(!query(id[p1],id[p2])) tmp.emplace_back(id[p1]),p1++;
            else tmp.emplace_back(id[p2]),p2++;
        while(p1<=mid)
            tmp.emplace_back(id[p1]),p1++;
        while(p2<=r)
            tmp.emplace_back(id[p2]),p2++;
        for(int i=0;i<(int)tmp.size();i++)
            id[l+i]=tmp[i];
        return;
    };
    merge_sort(0,n-1);
    for(int i=0,j=0;i<n;i=j)
    {
        if(i==0)
        {
            if(query(id[i+2],id[i])) // 012 0321 1032
            {
                if(query(id[i+1],id[i])) //0321 1032
                {
                    for(j=i+3;j<n;j++)
                        if(!query(id[j],id[i])) break;
                    if(j+1<=n) j++;
                    if(query(id[j-1],id[i+1])) reverse(id.begin()+i,id.begin()+i+2),reverse(id.begin()+i+2,id.begin()+j);
                    else reverse(id.begin()+i+1,id.begin()+j);
                    continue;
                }
                else j=i+1;//012
            }
            else //021 102 210 3210
            {
                int cnt=0;
                int k=i+2;
                for(k=i+2;k<n;k++)
                    if(query(id[i],id[k]))
                    {
                        cnt++;
                        if(cnt>=2) break;
                    }
                    else break;
                if(cnt<2) //021 102 210
                {
                    if(i+5<n)
                    {
                        if(!query(id[i+3],id[i+5])&&(!query(id[i+3],id[i])||!query(id[i+3],id[i+1])||!query(id[i+3],id[i+2]))) //210354 021354 102354
                        {
                            if(!query(id[i+3],id[i])) reverse(id.begin()+i,id.begin()+i+3);
                            else if(!query(id[i+3],id[i+1])) reverse(id.begin()+i+1,id.begin()+i+3);
                            else reverse(id.begin()+i,id.begin()+i+2);
                            reverse(id.begin()+i+3,id.begin()+i+6);
                            j=i+6;
                            continue;
                        }
                        else if(!query(id[i+3],id[i+5])&&(!query(id[i+3],id[i])||!query(id[i+3],id[i+1])||!query(id[i+3],id[i+2]))) //210435 021435 102435
                        {
                            if(!query(id[i+3],id[i])) reverse(id.begin()+i,id.begin()+i+3);
                            else if(!query(id[i+3],id[i+1])) reverse(id.begin()+i+1,id.begin()+i+3);
                            else reverse(id.begin()+i,id.begin()+i+2);
                            reverse(id.begin()+i+3,id.begin()+i+6);
                            j=i+6;
                            continue;
                        }
                    }
                    for(j=i+3+2;j<n;j++)
                        if(!query(id[j-2],id[j])) break;
                    if(!query(id[j-1],id[i])) reverse(id.begin()+i,id.begin()+i+3); //210
                    else if(!query(id[j-1],id[i+1])) reverse(id.begin()+i+1,id.begin()+i+3); //021
                    else reverse(id.begin()+i,id.begin()+i+2); //102
                    reverse(id.begin()+i+3,id.begin()+j);
                    continue;
                }
                else //3210
                {
                    for(j=k+1;j<n;j++)
                        if(!query(id[j-2],id[j])) break;
                }
            }
        }
        else
        {
            for(j=i;j<n;j++)
                if(!query(id[j],id[i-1])) break;
            if(j+1<=n) j++;
        }
        reverse(id.begin()+i,id.begin()+j);
    }
    vector<int>s(n);
    for(int i=0;i<n;i++)
        s[id[i]]=i;
    return s;
}