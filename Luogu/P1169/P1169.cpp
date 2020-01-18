#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std ;
#define rep( i , x ) for ( int i = 0 ; i ++ < x ; )
#define maxn 2010
#define clear( x ) memset( x , 0 , sizeof( x ) )
#define inf 0x7fffffff 
#define down( i , x ) for ( int i = x ; i ; -- i )
int ans2 = 0 , ans1 = 0 , n , m , a[ maxn ][ maxn ] ;
 
int h[ maxn ][ maxn ] , l[ maxn ][ maxn ] , r[ maxn ][ maxn ] ;
 
void solve()
{
    memset(h,0,sizeof(h));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j]) h[i-1][j]+1;
    for(int i=1;i<=m;i++)
        l[1][i]=-inf,r[1][i]=inf;
    for(int i=1;i<=n;i++)
    {
        int temp=1;
        for(int j=1;j<=m;j++)
            if(!a[i][j])
            {
                l[i][j]=temp;
                if(!a[i-1][j]&&i>1) l[i][j]=max(l[i][j],l[i-1][j]);
            }
            else temp=j+1;
    }
    for(int i=1;i<=n;i++)
    {
        int temp=m;
        for(int j=1;j<=m;j++)
            if(!a[i][j])
            {
                r[i][j]=temp;
                if(!a[i-1][j]&&i>1) r[i][j]=min(r[i][j],r[i-1][j]);
            }
            else temp=j-1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j])
            {
                ans2=max(ans2,h[i][j]*(r[i][j]-l[i][j]+1));
                int res=min(h[i][j],r[i][j]-l[i][j]+1);
                ans1=max(ans1,res*res);
            }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((i+j)%2==1) a[i][j]^=1;
    solve();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]^=1;
    solve();
    printf("%d\n%d",ans1,ans2);
    return 0 ; 
}