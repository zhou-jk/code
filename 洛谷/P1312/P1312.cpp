#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[8][6];
int n;
int res[10][3];
bool vis[8][6];
int check()
{
    int f1=0,f2=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=7;i++)
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]) f1=1;
            if(j<=3&&a[i][j]&&a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])vis[i][j]=vis[i][j+1]=vis[i][j+2]=1,f2=1;
            if(i<=5&&a[i][j]&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j])vis[i][j]=vis[i+1][j]=vis[i+2][j]=1,f2=1;
        }
    if(f1==0) return -1;
    return f2;
}
void insert(int x,int y,int g,int step)
{
    res[step][1]=y-1,res[step][2]=x-1,res[step][0]=g;
    return;
}
void down()
{
    for(int i=1;i<=7;i++)
        for(int j=1;j<=5;j++)
            if(vis[i][j]) a[i][j]=0;
    for(int i=1;i<=7;i++)
        for(int j=1;j<=5;j++)
            if(!a[i][j])
                for(int k=i+1;k<=7;k++)
                    if(a[k][j])
                    {
                        a[i][j]=a[k][j],a[k][j]=0;
                        break;
                    }
    return;
}
void move(int x,int y,int g)
{
    swap(a[x][y],a[x][y+g]);
    memset(vis,false,sizeof(vis));
    for(down();check()==1;down());
    return;
}
int cnt[10];
void dfs(int step)
{
    if(check()==-1)
    {
        for(int i=1;i<=step;i++)
            printf("%d %d %d\n",res[i][1],res[i][2],res[i][0]);
        exit(0);
    }
    if(step>=n) return;
    int b[8][6];
    memcpy(b,a,sizeof(b));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=7;i++)
        for(int j=1;j<=5;j++)
            cnt[a[i][j]]++;
    for(int i=1;i<=10;i++)
        if(cnt[i]==1||cnt[i]==2)return;
    for(int j=1;j<=5;j++)
        for(int i=1;i<=7;i++) 
        {
            if(!a[i][j]) continue;
            if(j!=5&&a[i][j]!=a[i][j+1])
            {
                insert(i,j,1,step+1);
                move(i,j,1);
                dfs(step+1);
                memcpy(a,b,sizeof(a));
            }
            if(j!=1&&!a[i][j-1])
            {
                insert(i,j,-1,step+1);
                move(i,j,-1);
                dfs(step+1);
                memcpy(a,b,sizeof(b));
            }
        }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=5;i++)
    {
        int x,cnt=0;
        while(1)
        {
            scanf("%d",&a[++cnt][i]);
            if(a[cnt][i]==0) break;
        }
    }
    dfs(0);
    printf("-1");
    return 0;
}