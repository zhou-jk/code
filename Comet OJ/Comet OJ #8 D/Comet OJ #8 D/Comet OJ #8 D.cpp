#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1001000;
int n,m,Q;
int L[N+1],R[N+1],a[N+1];
long long tree[N+1];
long long ans;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int y)
{
    if(x==0) return;
    for(int i=x;i<N;i+=lowbit(i))
        tree[i]+=y;
    return;
}
long long query(int x)
{
    long long ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=tree[i];
    return ans;
}
struct Ask
{
    int l,r,id;
}ask[N+1];
bool cmp(Ask x,Ask y)
{
    return x.r<y.r;
}
struct Node
{
    int id,val;
    bool operator>(const Node &b)const
    {
        return val>b.val;
    }
};
priority_queue<Node,vector<Node>,greater<Node> >q;
int main()
{
    memset(R,63,sizeof(R));
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y<x) L[x]=max(L[x],y);
        else R[x]=min(R[x],y);
    }
    for(int i=1;i<=Q;i++)
    {
        scanf("%d%d",&ask[i].l,&ask[i].r);
        ask[i].id=i;
    }
    sort(ask+1,ask+Q+1,cmp);
    int u=0;
    for(int i=1;i<=Q;i++)
    {
        for(int j=u+1;j<=ask[i].r;j++)
        {
            q.push((Node){j,R[j]});
            add(j,a[j]);
            add(L[j],-a[j]);
        }
        u=ask[i].r;
        while(!q.empty()&&q.top().val<=u)
        {
            int x=q.top().id;
            q.pop();
            add(x,-a[x]);
            add(L[x],+a[x]);
        }
        ans^=(ask[i].id*(query(ask[i].r)-query(ask[i].l-1)));
    }
    printf("%lld",ans);
    return 0;
}