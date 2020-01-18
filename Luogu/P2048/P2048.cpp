#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=500001;
int n,K,L,R;
long long sum[N],ans;
int f[N][20];
struct Node 
{
    int l,r,x,y;
    bool operator <(const Node &b)const
    {
        return sum[r]-sum[l]<sum[b.r]-sum[b.l];
    }
};
priority_queue<Node,vector<Node> >q;
int Min(int a,int b)
{
    return sum[a]<sum[b]?a:b;
}
int query(int l, int r)
{
    int k=log2(r-l+1);
    return Min(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%d%d%d",&n,&K,&L,&R);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    for(int i=1;i<=n;i++)
        f[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<=n;i++)
            f[i][j]=Min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=L;i<=n;i++)
    {
        int x=max(i-R,0),y=i-L;
        q.push((Node){query(x,y),i,x,y});
    }
    while(K--)
    {
        Node u=q.top();
        q.pop();
        ans+=sum[u.r]-sum[u.l];
        if(u.x<u.l) q.push((Node){query(u.x,u.l-1),u.r,u.x,u.l-1});
        if(u.l<u.y) q.push((Node){query(u.l+1,u.y),u.r,u.l+1,u.y});
    }
    printf("%lld",ans);
    return 0;
} 