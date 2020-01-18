#include<iostream>
#include<cstdio>
using namespace std;
const int N=200001;
const int MOD=10007;
int n;
int w[N];
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    } 
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int sum=0,res=0;
    for(int u=1;u<=n;u++)
    {
        int val=0,Max=0;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            sum=(sum+val*w[v])%MOD;
            val=(val+w[v])%MOD;
            res=max(res,Max*w[v]);
            Max=max(Max,w[v]);
        }
    }
    printf("%d %d",res,(2*sum)%MOD);
    return 0; 
}