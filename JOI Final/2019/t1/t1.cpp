#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
int n,m;
char s[N][N];
int ci[N][N],co[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int j=1;j<=m;j++)
        for(int i=n;i>=1;i--)
            ci[i][j]=ci[i+1][j]+(s[i][j]=='I');
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            co[i][j]=co[i][j+1]+(s[i][j]=='O');
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='J') ans+=ci[i+1][j]*co[i][j+1];
    printf("%lld",ans);
    return 0;
}