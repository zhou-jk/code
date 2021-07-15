#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int N=2000005;
int n,m;
int a[N];
long long s[N];
int p[N];
int b[N];
long long t[N];
int q[N];
int x[N],y[N];
long long suma[N],sumb[N];
struct Seg
{
    int x,y,v;
}seg[N];
int cnt;
long long val[N];
set<pair<int,long long> >S;
long long f[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%lld%d",&a[i],&s[i],&p[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%lld%d",&b[i],&t[i],&q[i]);
    for(int i=1;i<=n;i++)
        suma[i]=suma[i-1]+a[i];
    for(int i=1;i<=m;i++)
        sumb[i]=sumb[i-1]+b[i];
    for(int i=1;i<=n;i++)
        y[i]=upper_bound(sumb,sumb+m+1,s[i]-suma[i])-sumb-1;
    for(int j=1;j<=m;j++)
        x[j]=upper_bound(suma,suma+n+1,t[j]-sumb[j])-suma-1;
    for(int i=1;i<=n;i++)
        if(i-1>=0&&y[i]+1<=m) seg[++cnt]=(Seg){i-1,y[i]+1,-p[i]};
    for(int j=1;j<=m;j++)
        if(x[j]>=0&&j<=m) seg[++cnt]=(Seg){x[j],j,q[j]};
    sort(seg+1,seg+cnt+1,[=](const Seg &a,const Seg &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    int j=1;
    for(int i=1;i<=n;i++)
    {
        vector<int>pos;
        long long add=0;
        while(j<=cnt&&seg[j].x==i-1)
        {
            if(seg[j].y==0) add+=seg[j].v;
            else
            {
                auto it=S.find({seg[j].y,val[seg[j].y]});
                if(it!=S.end()) S.erase(it);
                pos.push_back(seg[j].y),val[seg[j].y]+=seg[j].v;
                if(val[seg[j].y]!=0) S.insert({seg[j].y,val[seg[j].y]});
            }
            j++;
        }
        f[i]=f[i-1]+add;
        for(int y:pos)
            while(val[y]<0)
            {
                auto it=S.upper_bound({y,val[y]});
                if(it==S.end())
                {
                    S.erase(S.find({y,val[y]}));
                    val[y]=0;
                    continue;
                }
                int u=it->first;
                S.erase(it);
                if(val[u]<0)
                {
                    val[u]+=val[y];
                    if(val[u]!=0) S.insert({u,val[u]});
                    S.erase({y,val[y]});
                    val[y]=0;
                }
                else
                {
                    long long tmp=val[y];
                    long long d=min(-val[y],val[u]);
                    val[y]+=d,val[u]-=d;
                    if(val[u]!=0) S.insert({u,val[u]});
                    S.erase(S.find({y,tmp}));
                    if(val[y]!=0) S.insert({y,val[y]});
                }
            }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=p[i];
    ans+=f[n];
    while(j<=cnt&&seg[j].x==n)
        ans+=seg[j].v,j++;
    for(auto [y,v]:S)
        ans+=v;
    printf("%lld",ans);
    return 0;
}