#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
int h,w;
bool vis[N][N];
bool check(int i,int j)
{
    for(int ti:{i-1,i,i+1})
        for(int tj:{j-1,j,j+1})
            if(ti!=i||tj!=j)
            {
                if(vis[ti][tj]) return false;
            }
    return true;
}
void solve()
{
    scanf("%d%d",&h,&w);
    vis[1][1]=true;
    for(int j=1,i=1;j<=w;j++)
        vis[i][j]=check(i,j);
    for(int i=1,j=w;i<=h;i++)
        vis[i][j]=check(i,j);
    for(int j=w,i=h;j>=1;j--)
        vis[i][j]=check(i,j);
    for(int i=h,j=1;i>=1;i--)
        vis[i][j]=check(i,j);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
            if(vis[i][j]) printf("1");
            else printf("0");
        printf("\n");
    }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            vis[i][j]=false;
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}