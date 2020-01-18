#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int INF=1061109567;
const int N=100001;
int n,k,ans;
int pre[N],nxt[N];
int a[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void del(int i)
{
    pre[nxt[i]]=pre[i];
    nxt[pre[i]]=nxt[i];
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    int lst=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=x-lst,lst=x;
    }
    for(int i=1;i<=n;i++)
        pre[i]=i-1,nxt[i]=i+1;
    pre[2]=0,nxt[n]=0;
    for(int i=2;i<=n;i++)
        q.push(make_pair(a[i],i));
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        while(q.top().first!=a[q.top().second]) q.pop();
        pair<int,int> u=q.top();
        q.pop();
        ans+=u.first;
        a[u.second]=(pre[u.second]&&nxt[u.second])?min(a[pre[u.second]]+a[nxt[u.second]]-a[u.second],INF):INF;
        a[pre[u.second]]=a[nxt[u.second]]=INF;
        del(pre[u.second]);
        del(nxt[u.second]);
        q.push(make_pair(a[u.second],u.second));
    }
    printf("%d",ans);
    return 0;
}