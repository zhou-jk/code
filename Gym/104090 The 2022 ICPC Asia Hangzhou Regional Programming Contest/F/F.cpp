#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n;
map<string,bool>vis;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        int cnt=0;
        for(int j=1;j<=m;j++)
        {
            string str;
            cin>>str;
            if(str.find("bie")!=str.npos&&!vis.count(str))
            {
                cout<<str<<"\n";
                vis[str]=true;
                cnt++;
            }
        }
        if(cnt==0) cout<<"Time to play Genshin Impact, Teacher Rice!\n";
    }
    return 0;
}