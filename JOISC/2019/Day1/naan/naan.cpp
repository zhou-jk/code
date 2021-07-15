#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
const int INF=1061109567;
int n,m;
int v[N][N]; 
struct Factor
{
    long long p,q;
    bool operator < (const Factor &b)const
    {
        return (long double)p/q<(long double)b.p/b.q;
    }
}pos[N][N];
bool vis[N];
Factor x[N];
int p[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    for(int i=1;i<=n;i++)
    {
        long long sum=0;
        for(int j=1;j<=m;j++)
            sum+=v[i][j];
        long long now=0;
        long double avg=(long double)sum/n;
        for(int j=1,k=1;j<=n;j++)
        {
            while(k<m&&(long double)(now+v[i][k])/j<avg) now+=v[i][k],k++;
            pos[i][j]=(Factor){1LL*n*v[i][k]*(k-1)+sum*j-now*n,1LL*n*v[i][k]};
        }
    }
    for(int j=1;j<=n;j++)
    {
        int a=0;
        pos[a][j]=(Factor){INF,1};
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                if(pos[i][j]<pos[a][j]) a=i;
            }
        vis[a]=true;
        x[j]=pos[a][j];
        p[j]=a;
    }
    for(int i=1;i<=n-1;i++)
        printf("%lld %lld\n",x[i].p,x[i].q);
    for(int i=1;i<=n;i++)
        printf("%d ",p[i]);
    return 0; 
}