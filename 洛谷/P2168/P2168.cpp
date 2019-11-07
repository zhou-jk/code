#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,k,res;
long long ans;
struct Node
{
    int id;
    long long val;
    bool operator < (const Node &a)const
    {
        if(a.val==val) return a.id<id;
        return a.val<val;
    }
};
priority_queue<Node>q;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        long long x;
        scanf("%lld",&x);
        q.push((Node){1,x});
    }
    int m=(n-1)%(k-1);
    if(m!=0) m=k-1-m,n+=m;
    for(int i=1;i<=m;i++) q.push((Node){1,0});
    while(n>1)
    {
        int d=0;
        long long tot=0;
        for(int i=1;i<=k;i++)
        {
            Node u=q.top();
            q.pop();
            tot+=u.val;
            d=max(d,u.id);
        }      
        q.push((Node){d+1,tot});
        ans+=tot;
        res=max(res,d);
        n-=k-1;
    }
    printf("%lld\n%d",ans,res);
    return 0;
}