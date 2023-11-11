#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dir[][2]={{0,2},{0,-2},{1,1},{1,-1},{-1,1},{-1,-1}};
const int pos[19][2]={{1,3},{1,5},{1,7},{2,2},{2,4},{2,6},{2,8},{3,1},{3,3},{3,5},{3,7},{3,9},{4,2},{4,4},{4,6},{4,8},{5,3},{5,5},{5,7}};
const int n=19;
int q;
int a[n];
int f[1<<n];
int id[6][10];
int dfs(int s)
{
    if(f[s]!=-1) return f[s];
    if(s==0) return f[s]=0; 
    int &ans=f[s];
    for(int i=0;i<n;i++)
        if((s>>i)&1)
        {
            ans=max(ans,dfs(s^(1<<i)));
            auto [x,y]=pos[i];
            for(auto [dx,dy]:dir)
            {
                int jx=x+dx,jy=y+dy,kx=x-dx,ky=y-dy;
                if(jx<1||jx>5||jy<1||jy>9) continue;
                if(kx<1||kx>5||ky<1||ky>9) continue;
                if(id[jx][jy]==-1||id[kx][ky]==-1) continue;
                int j=id[jx][jy],k=id[kx][ky];
                if(((s>>j)&1)&&(!((s>>k)&1)))
                {
                    ans=max(ans,dfs(s^(1<<i)^(1<<j)^(1<<k))+a[i]);
                }
            }
        }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    memset(f,-1,sizeof(f));
    memset(id,-1,sizeof(id));
    for(int i=0;i<n;i++)
    {
        auto [x,y]=pos[i];
        id[x][y]=i;
    }
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>q;
    while(q--)
    {
        char c;
        int s=0;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            if(c=='#') s|=1<<i;
        }
        cout<<dfs(s)<<"\n";
    }
    return 0;
}