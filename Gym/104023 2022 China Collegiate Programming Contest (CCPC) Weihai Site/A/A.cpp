#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,m;
map<string,bool>vis;
int champion[6],normal[6];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
        {
            string name;
            cin>>name;
            vis[name]=true;
        }
    cin>>m; 
    for(int i=1;i<=m;i++)
    {
        string name;
        int p;
        cin>>name>>p;
        if(vis.count(name)) champion[p]++;
        else normal[p]++;
    }
    int ans=0;
    for(int i=1;i<=5;i++)
        ans+=champion[i];
    for(int i=1;i<=5;i++)
        ans=min(ans,champion[i]+normal[i]);
    cout<<ans;
    return 0;
}
