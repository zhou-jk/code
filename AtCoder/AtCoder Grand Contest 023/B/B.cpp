#include<iostream>
#include<cstdio>
using namespace std;
const int N=305;
int n;
char s[N+N][N+N];
int solve(int sx,int sy)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[sx+i-1][sy+j-1]!=s[sx+j-1][sy+i-1]) return 0;
    if(sx==1) return n-sy+1;
    else return n-sx+1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            s[i+n][j]=s[i][j+n]=s[i+n][j+n]=s[i][j];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=1;
        ans+=solve(i,j);
    }
    for(int j=2;j<=n;j++)
    {
        int i=1;
        ans+=solve(i,j);
    }
    printf("%d",ans);
    return 0;
}