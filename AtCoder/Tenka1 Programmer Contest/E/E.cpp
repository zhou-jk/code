#include<bits/stdc++.h>
using namespace std;
constexpr int N=305;
int h,w;
char s[N][N];
char t[N+N][N+N];
int n,m; 
int sr[N+N][N+N],sc[N+N][N+N];
int main()
{
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++)
        scanf("%s",s[i]+1);
    n=h+w,m=h+w;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            t[i][j]='.';
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            int x=i+j,y=i-j;
            y+=w;
            t[x][y]=s[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sr[i][j]=sr[i][j-1]+(t[i][j]=='#'),sc[i][j]=sc[i-1][j]+(t[i][j]=='#');
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        for(int l=1;l<=m;l++)
            if(t[x][l]=='#')
                for(int r=l+1;r<=m;r++)
                    if(t[x][r]=='#')
                    {
                        int len=r-l+1;
                        for(int y:{x+len-1,x-len+1})
                        {
                            if(y<1||y>n) continue;
                            ans+=sr[y][r]-sr[y][l-1];
                        }
                    }
    }
    for(int x=1;x<=m;x++)
    {
        for(int l=1;l<=m;l++)
            if(t[l][x]=='#')
                for(int r=l+1;r<=m;r++)
                    if(t[r][x]=='#')
                    {
                        int len=r-l+1;
                        for(int y:{x+len-1,x-len+1})
                        {
                            if(y<1||y>m) continue;
                            ans+=sc[r-1][y]-sc[l][y];
                        }
                    }
    }
    printf("%d",ans);
    return 0;
}
