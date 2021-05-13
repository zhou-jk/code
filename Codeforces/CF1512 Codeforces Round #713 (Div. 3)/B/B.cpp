#include<iostream>
#include<cstdio>
using namespace std;
const int N=405;
int T;
int n;
char s[N][N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    int sx=0,sy=0,tx,ty;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]=='*')
            {
                if(sx&&sy) tx=i,ty=j;
                else sx=i,sy=j;
            }
    if(sx!=tx&&sy!=ty) s[sx][ty]=s[tx][sy]='*';
    else if(sx==tx)
    {
        if(sx==1) s[sx+1][sy]=s[tx+1][ty]='*';
        else s[sx-1][sy]=s[tx-1][ty]='*';
    }
    else if(sy==ty)
    {
        if(sy==1) s[sx][sy+1]=s[tx][ty+1]='*';
        else s[sx][sy-1]=s[tx][ty-1]='*';
    }
    for(int i=1;i<=n;i++)
        printf("%s\n",s[i]+1);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}