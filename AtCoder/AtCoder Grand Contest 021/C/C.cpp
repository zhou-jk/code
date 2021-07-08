#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,m,a,b;
char s[N][N];
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]='.';
    if(n&1)
    {
        for(int j=1;j<=m;j++)
            if(s[n][j]=='.'&&s[n][j+1]=='.'&&a>0) s[n][j]='<',s[n][j+1]='>',a--;
    }
    if(m&1)
    {
        for(int i=1;i<=n;i++)
            if(s[i][m]=='.'&&s[i+1][m]=='.'&&b>0) s[i][m]='^',s[i+1][m]='v',b--;
    }
    for(int i=1;i<=n;i+=2)
        for(int j=1;j<=m;j+=2)
            if(s[i][j]=='.'&&s[i+1][j]=='.'&&s[i][j+1]=='.'&&s[i+1][j+1]=='.')
            {
                if(a==0&&b==0) continue;
                if(a==1&&b==1) s[i][j]='<',s[i][j+1]='>',a--;
                else if(a==1&&b==0) s[i][j]='<',s[i][j+1]='>',a--;
                else if(a==0&&b==1) s[i][j]='^',s[i+1][j]='v',b--;
                else
                {
                    if(a>=b) s[i][j]='<',s[i][j+1]='>',s[i+1][j]='<',s[i+1][j+1]='>',a-=2;
                    else s[i][j]='^',s[i+1][j]='v',s[i][j+1]='^',s[i+1][j+1]='v',b-=2;
                }
            }
    if(n%2==1&&m%2==1)
    {
        if(a==1&&b==0&&s[n-2][m-2]=='^'&&(s[n-2][m]=='.'||s[n-2][m-1]=='.'||s[n-2][m-2]=='.')) s[n-2][m-2]='^',s[n-1][m-2]='v',s[n][m-2]='<',s[n][m-1]='>',s[n][m]='v',s[n-1][m]='^',s[n-2][m]='>',s[n-2][m-1]='<',s[n-1][m-1]='.',a--;
        if(a==0&&b==1&&s[n-2][m-2]=='<'&&(s[n][m-2]=='.'||s[n-1][m-2]=='.'||s[n-2][m-2]=='.')) s[n-2][m-2]='^',s[n-1][m-2]='v',s[n][m-2]='<',s[n][m-1]='>',s[n][m]='v',s[n-1][m]='^',s[n-2][m]='>',s[n-2][m-1]='<',s[n-1][m-1]='.',b--;
    }
    if(a==0&&b==0)
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%c",s[i][j]);
            printf("\n");
        }
    }
    else printf("NO\n");
    return 0;
}