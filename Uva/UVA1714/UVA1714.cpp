#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=51,M=10001;
pair<int,int> dir[N][N][4];
int n,m;
int visk[N][N],visp[N][N];
char c[N][N],s[M];
struct Node
{
    int x,y,k,pa;
};
queue<Node> q;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(visk,-1,sizeof(visk));
        for(int i=1;i<=n;i++)
            scanf("%s",c[i]+1);
        scanf("%s",s+1);
        int l=strlen(s+1)+1;
        s[l]='*';
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                for(int k=i+1;k<=n;k++)
                    if(c[k][j]!=c[i][j])
                    {
                        dir[i][j][0]=make_pair(k,j);
                        break;
                    }
                for(int k=i-1;k>0;k--)
                    if(c[k][j]!=c[i][j])
                    {
                        dir[i][j][1]=make_pair(k,j);
                        break;
                    }
                for(int k=j+1;k<=m;k++)
                    if(c[i][k]!=c[i][j])
                    {
                        dir[i][j][2]=make_pair(i,k);
                        break;
                    }
                for(int k=j-1;k>0;k--)
                    if(c[i][k]!=c[i][j])
                    {
                        dir[i][j][3]=make_pair(i,k);
                        break;
                    }
            }
        while(!q.empty()) q.pop();
        q.push((Node){1,1,0,0});
        while(!q.empty())
        {
            Node u=q.front();
            q.pop();
            bool flag=true;
            if(c[u.x][u.y]==s[u.k+1])
            {
                q.push((Node){u.x,u.y,u.k+1,u.pa+1});
                if(u.k+1==l)
                {
                    printf("%d\n",u.pa+1);
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
            else for(int i=0;i<4;i++)
            {
                pair<int,int> t=dir[u.x][u.y][i];
                if(t.first==0) continue;
                if(visk[t.first][t.second]>=u.k) continue;
                visk[t.first][t.second]=u.k;
                q.push((Node){t.first,t.second,u.k,u.pa+1});
            }
        }
    }
    return 0;
}