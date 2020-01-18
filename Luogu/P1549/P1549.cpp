#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500;
int n;
int f[15][15],ans;
int prime[N+1],tot;
bool isprime[N+1];
bool book[N+1];
void dfs(int x,int y)
{
    if(x==n&&y==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%d ",f[i][j]);
            printf("\n");
        }
        exit(0);
    }
    if(f[x][y]!=0) return;
    if(y==n+1)
    {
        dfs(x+1,1);
        return ;
    }
    if(x==1||y==1)
    {
        for(int i=2;i<=n*n;i++)
        {
            if(book[i]) continue;
            if(x==1&&isprime[f[x][y-1]+i]==0) continue;
            if(y==1&&isprime[f[x-1][y]+i]==0) continue;
            f[x][y]=i;
            book[i]=true;
            dfs(x,y+1);
            f[x][y]=0;
            book[i]=false;
        }
    }
    else
    {
        for(int i=n*n;i>=2;i--)
        {
            if(book[i]) continue;
            if(isprime[f[x][y-1]+i]==0) continue;
            if(isprime[f[x-1][y]+i]==0) continue;
            f[x][y]=i;
            book[i]=true;
            dfs(x,y+1);
            f[x][y]=0;
            book[i]=false;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        printf("NO");
        return 0;
    }
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<=N;i++)
    {
        if(isprime[i]) prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=N;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
    f[1][1]=1;
    book[1]=true;
    dfs(1,2);
    printf("NO");
    return 0;
}