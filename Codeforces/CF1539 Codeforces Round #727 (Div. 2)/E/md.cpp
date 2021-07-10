#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=1005;
int n,m;
int k[N];
bool f[N][2][N];
pair<int,int> pre[N][2][N];
set<pair<int,int>>f[2];
void print(int i,int j,int k)
{
    if(i==0) return;
    print(i-1,pre[i][j][k].first,pre[i][j][k].second);
    printf("%d ",j);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    f[0][0][0]=true;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        int al,bl;
        scanf("%d%d",&al,&bl);
        int ar,br;
        scanf("%d%d",&ar,&br);
        if(al<=k[i]&&k[i]<=bl)
        {
            for(int j=ar;j<=br;j++)
                if(f[i-1][0][j])
                {
                    pre[i][0][j]={0,j};
                    f[i][0][j]=true;
                }
            if(ar<=k[i-1]&&k[i-1]<=br)
                for(int j=0;j<=m;j++)
                    if(f[i-1][1][j])
                    {
                        pre[i][0][k[i-1]]={1,j};
                        f[i][0][k[i-1]]=true;
                    }
        }
        if(ar<=k[i]&&k[i]<=br)
        {
            for(int j=al;j<=bl;j++)
                if(f[i-1][1][j])
                {
                    pre[i][1][j]={1,j};
                    f[i][1][j]=true;
                }
            if(al<=k[i-1]&&k[i-1]<=bl)
                for(int j=0;j<=m;j++)
                    if(f[i-1][0][j])
                    {
                        pre[i][1][k[i-1]]={0,j};
                        f[i][1][k[i-1]]=true;
                    }
        }
    }
    for(int j=0;j<=m;j++)
        if(f[n][0][j])
        {
            printf("Yes\n");
            print(n,0,j);
            return 0;
        }
    for(int j=0;j<=m;j++)
        if(f[n][1][j])
        {
            printf("Yes\n");
            print(n,1,j);
            return 0;
        }
    printf("No");
    return 0;
}