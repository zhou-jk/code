#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4005;
int n,m,l,p;
bool c[N][N];
int prex[N];
int ld[N][N],rd[N][N];
struct BIT
{
    int C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=(n+m+1)/2;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}Tl[N+N],Tr[N+N];
pair<short,short> pl[N*N],pr[N*N];
int main()
{
    scanf("%d%d%d%d",&n,&m,&l,&p);
    for(int i=1;i<=p;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        c[a][b]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(c[i][j]) prex[j]=0;
            else prex[j]++;
        int prey=0;
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]) prey=0;
            else prey++;
            ld[i][j]=min(prex[j],prey);
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
            if(c[i][j]) prex[j]=0;
            else prex[j]++;
        int prey=0;
        for(int j=m;j>=1;j--)
        {
            if(c[i][j]) prey=0;
            else prey++;
            rd[i][j]=min(prex[j],prey);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            pl[(i-1)*m+j]=pr[(i-1)*m+j]={i,j};
    sort(pl+1,pl+n*m+1,[=](const pair<short,short> &a,const pair<short,short> &b){return ld[a.first][a.second]>ld[b.first][b.second];});
    sort(pr+1,pr+n*m+1,[=](const pair<short,short> &a,const pair<short,short> &b){return rd[a.first][a.second]>rd[b.first][b.second];});
    long long ans=0;
    for(int len=min(n,m),i=0,j=0;len>=l;len--)
    {
        while(j+1<=n*m&&ld[pl[j+1].first][pl[j+1].second]>=len)
        {
            auto [x,y]=pl[j+1];
            int p=(x+y+1)/2;
            if(max(p-len+1,1)<=max(p-l+1,0)) ans+=Tr[x-y+m].query(max(p-len+1,1),max(p-l+1,0));
            Tl[x-y+m].add(p,1);
            j++;
        }
        while(i+1<=n*m&&rd[pr[i+1].first][pr[i+1].second]>=len)
        {
            auto [x,y]=pr[i+1];
            int p=(x+y+1)/2;
            if(min(p+l-1,(n+m+1)/2+1)<=min(p+len-1,(n+m+1)/2)) ans+=Tl[x-y+m].query(min(p+l-1,(n+m+1)/2+1),min(p+len-1,(n+m+1)/2));
            Tr[x-y+m].add(p,1);
            i++;
        }
    }
    printf("%lld",ans);
    return 0;
}