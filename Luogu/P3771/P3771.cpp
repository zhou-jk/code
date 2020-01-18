#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long INF=4557430888798830399;
int N;
long long C;
struct Edge
{
    int to,next,val;
}edge[200001];
int head[100001],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int n;
long long b[100001];
int pla[100001];
long long len[100001];
bool vis[100001];
int p[100001],cntn;
int f[100001];
long long d[100001],temp[100001];
void dfs(int u,int father)
{
    f[u]=father;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        d[v]=d[u]+edge[i].val;
        dfs(v,u);
    }
    return;
}
void find(int u)
{
    vis[u]=true;
    if(f[u]) find(f[u]);
    p[++cntn]=u;
    return;
}
long long Dfs(int u,int father)
{
    long long res=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        if(vis[v]) continue;
        res=max(res,edge[i].val+Dfs(v,u));
    }
    return res;
}
struct Binary_Indexed_Tree
{
    long long C[100001];
    Binary_Indexed_Tree()
    {
        for(int i=1;i<=n;i++)
            C[i]=-INF;
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,long long y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]=max(C[i],y);
        return;
    }
    long long query(int x)
    {
        long long res=-INF;
        for(int i=x;i>0;i-=lowbit(i))
            res=max(res,C[i]);
        return res;
    }
};
bool check(long long x)
{
    long long lim1=-INF,lim2=-INF,lim3=-INF,lim4=-INF;
    Binary_Indexed_Tree T[2];
    for(int i=1;i<=cntn;i++)
    {
        int p=lower_bound(b+1,b+1+n,d[i]+len[i]-x)-b-1;
        long long sum=T[0].query(p),num=T[1].query(p);
        lim1=max(lim1,d[i]+len[i]+sum+C-x);
        lim2=max(lim2,-d[i]+len[i]+sum+C-x);
        lim3=max(lim3,d[i]+len[i]+num+C-x);
        lim4=max(lim4,-d[i]+len[i]+num+C-x);
        T[0].add(pla[i],d[i]+len[i]);
        T[1].add(pla[i],-d[i]+len[i]);
    }
    int p1=1,p2=1;
    for(int i=1;i<=cntn;i++)
    {
        long long tl=max(lim1-d[i],lim2+d[i]),tr=min(-lim3+d[i],-lim4-d[i]);
        if(tl>tr) continue;
        while(d[p1]<tl&&p1<=cntn) p1++;
        while(d[p1-1]>=tl&&p1>1) p1--;
        while(d[p2+1]<=tr&&p2<cntn) p2++;
        while(d[p2]>tr&&p2>=1) p2--;
        if(p1<=p2) return true;
    }
    return false;
}
int main()
{
    while(1)
    {
        scanf("%d%lld",&N,&C);
        if(N==0&&C==0) return 0;
        cntn=cnt=n=0;
        memset(head,0,sizeof(head));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<N;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);
            add_edge(y,x,z);
        }
        d[1]=0;
        dfs(1,0);
        int lp=max_element(d+1,d+N+1)-d;
        d[lp]=0;
        dfs(lp,0);
        int rp=max_element(d+1,d+N+1)-d;
        memcpy(temp,d,sizeof(d));
        find(rp);
        for(int i=1;i<=cntn;i++)
            len[i]=Dfs(p[i],0);
        long long l=0,r=INF,mid,ans=INF;
        l=max(l,*max_element(len+1,len+cntn+1));
        for(int i=1;i<=cntn;i++)
            d[i]=temp[p[i]];
        for(int i=1;i<=cntn;i++)
            b[i]=d[i]-len[i];
        sort(b+1,b+cntn+1);
        n=unique(b+1,b+cntn+1)-b-1;
        for(int i=1;i<=cntn;i++)
            pla[i]=lower_bound(b+1,b+n+1,d[i]-len[i])-b;
        r=l*2+d[cntn];
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}