#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int n,m,q;
int a[201],f[201][201];
void floyd(int k)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(f[i][j]>f[i][k]+f[k][j])
                f[i][j]=f[i][k]+f[k][j];
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            f[i][j]=i==j?0:INF;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        f[x][y]=f[y][x]=z;
    }
    scanf("%d",&q);
    int k=0;
    for(int i=1;i<=q;i++)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        while(a[k]<=t&&k<n)
        {
            floyd(k);
            k++;
        }
        if(a[x]>t||a[y]>t) printf("-1\n");
        else if(f[x][y]>=INF) printf("-1\n");
        else printf("%d\n",f[x][y]);
    }
    return 0;
}