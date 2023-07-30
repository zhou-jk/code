#include<iostream>
#include<cstdio>
#include<functional>
using namespace std;
const int N=2005;
int n,m;
int a[N][N];
int mina,maxa;
int posx,posy;
bool check(int x)
{
    static bool vis[N][N];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            vis[i][j]=a[i][j]-mina<=x;
    static int prei[N],nxti[N];
    for(int i=1;i<=n;i++)
    {
        nxti[i]=m;
        for(int j=1;j<=m;j++)
            if(!vis[i][j])
            {
                nxti[i]=j-1;
                break;
            }
    }
    for(int i=1;i<=n;i++)
    {
        prei[i]=1;
        for(int j=m;j>=1;j--)
            if(!vis[i][j])
            {
                prei[i]=j+1;
                break;
            }
    }
    static int col[N][N];
    function<int()> calc=[=]()
    {
        int mi=maxa,mx=mina;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(col[i][j]==0) mi=min(mi,a[i][j]),mx=max(mx,a[i][j]);
        return mx-mi;
    };
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                col[i][j]=0;
        int nowy=m;
        for(int i=1;i<=n;i++)
        {
            nowy=min(nowy,nxti[i]);
            if(nowy<1) break;
            for(int j=1;j<=nowy;j++)
                col[i][j]=1;
        }
        if(calc()<=x) return true;
    }
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                col[i][j]=0;
        int nowy=m;
        for(int i=n;i>=1;i--)
        {
            nowy=min(nowy,nxti[i]);
            if(nowy<1) break;
            for(int j=1;j<=nowy;j++)
                col[i][j]=1;
        }
        if(calc()<=x) return true;
    }
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                col[i][j]=0;
        int nowy=1;
        for(int i=1;i<=n;i++)
        {
            nowy=max(nowy,prei[i]);
            if(nowy>m) break;
            for(int j=nowy;j<=m;j++)
                col[i][j]=1;
        }
        if(calc()<=x) return true;
    }
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                col[i][j]=0;
        int nowy=1;
        for(int i=n;i>=1;i--)
        {
            nowy=max(nowy,prei[i]);
            if(nowy>m) break;
            for(int j=nowy;j<=m;j++)
                col[i][j]=1;
        }
        if(calc()<=x) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    maxa=a[1][1],mina=a[1][1];
    posx=posy=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            maxa=max(maxa,a[i][j]);
            if(a[i][j]<mina) posx=i,posy=j,mina=a[i][j];
        }
    int l=0,r=maxa-mina,ans=maxa-mina;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}