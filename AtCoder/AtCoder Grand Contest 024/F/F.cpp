#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=20;
int n,k;
string s[N+1];
int nxt[1<<N][N][2];
map<pair<pair<int,string>,pair<int,string>>,int>f;
int main()
{
    cin>>n>>k;
    for(int i=0;i<=n;i++)
        cin>>s[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<(int)s[i].size();j++)
            if(s[i][j]=='1')
            {
                string t;
                for(int k=i-1;k>=0;k--)
                    if(j&(1<<k)) t+='1';
                    else t+='0';
                f[{{i,t},{0,""}}]++;
            }
    for(auto [str,v]:f)
    {
        auto [ls,S]=str.first;
        auto [lt,T]=str.second;
        
    }
}