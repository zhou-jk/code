#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=2005;
int n;
vector<pair<int,int>>G;
vector<int>query(int i)
{
    printf("? %d\n",i+1);
    fflush(stdout);
    vector<int>dis(n);
    for(int j=0;j<n;j++)
        scanf("%d",&dis[j]);
    return dis;
}
int main()
{
    scanf("%d",&n);
    vector<int>dis=query(0);
    vector<int>odd,even;
    for(int i=1;i<n;i++)
        if(dis[i]&1) odd.emplace_back(i);
        else even.emplace_back(i);
    if(odd.size()>even.size())
    {
        for(int i=0;i<n;i++)
            if(dis[i]==1) G.emplace_back(0,i);
        for(int u:even)
        {
            vector<int>d=query(u);
            for(int i=0;i<n;i++)
                if(d[i]==1) G.emplace_back(u,i);
        }
    }
    else
    {
        for(int u:odd)
        {
            vector<int>d=query(u);
            for(int i=0;i<n;i++)
                if(d[i]==1) G.emplace_back(u,i);
        }
    }
    printf("!\n");
    for(auto [u,v]:G)
        printf("%d %d\n",u+1,v+1);
    return 0;
}