#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
const int dir[9][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
int n,m;
char s[N][N],t[2][2];
bool check(int i,int j)
{
    return s[i][j]==t[0][0]&&s[i][j+1]==t[0][1]&&s[i+1][j]==t[1][0]&&s[i+1][j+1]==t[1][1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    scanf("%s",t[0]);
    scanf("%s",t[1]);
    int sum=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(check(i,j)) sum++;
    int ans=sum;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
        {
            int now=sum;
            char ch=s[x][y];
            for(int i=0;i<9;i++)
            {
                int tx=x+dir[i][0],ty=y+dir[i][1];
                if(tx<1||tx>=n||ty<1||ty>=m) continue;
                if(check(tx,ty)) now--;
            }
            int res=now;
            for(char c:{'J','O','I'})
            {
                s[x][y]=c;
                res=now;
                for(int i=0;i<9;i++)
                {
                    int tx=x+dir[i][0],ty=y+dir[i][1];
                    if(tx<1||tx>=n||ty<1||ty>=m) continue;
                    if(check(tx,ty)) res++;
                }
                ans=max(ans,res);
            }
            s[x][y]=ch;
        }
    printf("%d",ans);
    return 0;
}