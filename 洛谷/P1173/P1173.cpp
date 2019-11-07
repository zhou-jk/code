#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int T,N,M,K;
int tot;
bool flag,key;
struct Node
{
    int id,x,y;
    bool operator <(const Node &b)const
    {
        if(key)    
            if(x==b.x) return y<b.y;
            else return x<b.x;
        else
            if(y==b.y) return x<b.x;
            else return y<b.y;
    }
    bool operator ==(const Node &b)const
    {
        return x==b.x&&y==b.y;
    }
}a[100001],b[2500001];
int X[300001],Y[300001];
struct Edge
{
    int to,next;
}edge[9000001];
int head[2500001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int low[2500001],dfn[2500001],Index;
void dfs(int u,int father)
{
    dfn[u]=low[u]=++Index;
    int child=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        if(!dfn[v])
        {
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(father&&dfn[u]<=low[v]) flag=true;
            else if(!father&&child>=2) flag=true;
        }
        else low[u]=min(low[u],dfn[v]);
    }
    return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
        scanf("%d%d%d",&N,&M,&K);
        memset(dfn,0,sizeof(dfn)); 
        memset(low,0,sizeof(low));
        memset(head,0,sizeof(head));
        int cntx=0,cnty=0,num=0;
        tot=cnt=edge[1].to=0;
        flag=false;
        for(int i=1;i<=K;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=(Node){0,x,y};
            X[++cntx]=x;
            Y[++cnty]=y;
            if(x>1) X[++cntx]=x-1;
            if(x<N) X[++cntx]=x+1;
            if(y>1) Y[++cnty]=y-1;
            if(y<M) Y[++cnty]=y+1;
            for(int j=0;j<8;j++)
            {
                int tx=x+dir[j][0],ty=y+dir[j][1];
                if(tx<1||tx>N||ty<1||ty>M) continue;
                b[++num]=(Node){0,tx,ty};
            }
        }
        if((long long)N*M-K<=1)
	    {
		    printf("-1\n");
		    continue;
	    }
        int U=100001,D=0,L=100001,R=0;
        for(int i=1;i<=cntx;i++)
            L=min(X[i],L),R=max(X[i],R);
        for(int i=1;i<=cnty;i++)
            U=min(Y[i],U),D=max(Y[i],D);
        if(L>1) L--;
        if(R<N) R++;
        if(U>1) U--;
        if(D<M) D++;
        X[++cntx]=L,X[++cntx]=R;
        Y[++cnty]=U,Y[++cnty]=D;
        sort(X+1,X+cntx+1);
        cntx=unique(X+1,X+cntx+1)-X-1;
        sort(Y+1,Y+cnty+1);
        cnty=unique(Y+1,Y+cnty+1)-Y-1;
        for(int i=1;i<=cntx;i++)
            b[++num]=(Node){0,X[i],Y[1]},b[++num]=(Node){0,X[i],Y[cnty]};
        for(int i=1;i<=cnty;i++)
            b[++num]=(Node){0,X[1],Y[i]},b[++num]=(Node){0,X[cntx],Y[i]};
        key=false;
        sort(a+1,a+K+1);
        sort(b+1,b+num+1);
        num=unique(b+1,b+num+1)-b-1;
        for(int i=1;i<=K;i++)
            a[i].x=lower_bound(X+1,X+cntx+1,a[i].x)-X,a[i].y=lower_bound(Y+1,Y+cnty+1,a[i].y)-Y;
        for(int i=1;i<=num;i++)
            b[i].x=lower_bound(X+1,X+cntx+1,b[i].x)-X,b[i].y=lower_bound(Y+1,Y+cnty+1,b[i].y)-Y,b[i].id=i;
        for(int t=1,v=1,u=1;u<=num;u++)
        {
            Node tmp=b[u];
            while(t<=K&&a[t]<tmp) t++;
            if(t>=1&&t<=K&&a[t]==tmp) continue;
            tot++;
            tmp.x++;
            while(t<=K&&a[t]<tmp) t++;
            while(v<=num&&b[v]<tmp) v++;
            if(v<1||v>num) continue;
            if(t>=1&&t<=K&&!(b[v]<a[t])) continue;
            if(b[v].y==b[u].y&&b[v].x>b[u].x) add_edge(b[u].id,b[v].id),add_edge(b[v].id,b[u].id);
        }
        key=true;
        sort(a+1,a+K+1);
        sort(b+1,b+num+1);
        for(int t=1,v=1,u=1;u<=num;u++)
        {
            Node tmp=b[u];
            while(t<=K&&a[t]<tmp) t++;
            if(t>=1&&t<=K&&a[t]==tmp) continue;
            tmp.y++;
            while(t<=K&&a[t]<tmp) t++;
            while(v<=num&&b[v]<tmp) v++;
            if(v<1||v>num) continue;
            if(t>=1&&t<=K&&!(b[v]<a[t])) continue;
            if(b[v].x==b[u].x&&b[v].y>b[u].y) add_edge(b[u].id,b[v].id),add_edge(b[v].id,b[u].id);
        }
        Index=0;
        int v=edge[1].to;
        if(v) dfs(v,0);
        if((long long)N*M-K==2&&(Index==2||K==0)) printf("-1\n");
        else if((long long)N*M-K>=2&&Index<tot) printf("0\n");
        else if(Index==tot&&flag) printf("1\n");
        else if(N==1||M==1) printf("1\n");
        else printf("2\n");
    }
    return 0;
}