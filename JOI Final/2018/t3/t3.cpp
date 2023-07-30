#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3005;
int n,m;
char e[N][N];
bool book[N][N];
int solve(int x,int y)
{
    int a,b,c;
    int A=0,B=0,C=0;
    while(!book[x][y]&&e[x][y]=='G')
    {
        a=A,b=B,c=C; 
        A=max({A,B,C});
        B=C=0;
        book[x][y]=true;
        if(e[x][y-1]=='R'&&e[x][y+1]=='W') B=max({B,a+1,b+1});
        if(e[x-1][y]=='R'&&e[x+1][y]=='W') C=max({C,a+1,c+1});
        x--,y++;
    }
    return max({A,B,C});
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",e[i]+1);
    int ans=0;
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            if(!book[i][j]&&e[i][j]=='G') ans+=solve(i,j);
    printf("%d",ans);
    return 0;
}