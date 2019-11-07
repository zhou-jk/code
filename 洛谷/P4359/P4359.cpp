#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int prime[32]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127};
int m;
long long n;
struct Node
{
    int tot,last,pre;
    long long val;
    bool operator < (const Node &a) const
    {
        return val<a.val;
    }
};
priority_queue<Node,vector<Node> >q;
int main()
{
    scanf("%lld%d",&n,&m);
    for(int i=1;i<=31;i++)
    {
        long long fac=1;
        int j;
        for(j=0;fac<=n/prime[i];j++)
            fac*=prime[i];
        q.push((Node){i,j-1,0,fac});
    }
    for(int i=1;i<m;i++)
    {
        Node u=q.top();
        q.pop();
        if(u.tot) q.push((Node){u.tot-1,1,u.last-1,u.val/prime[u.tot]*prime[u.tot-1]});
        if(u.pre) q.push((Node){u.tot,u.last+1,u.pre-1,u.val/prime[u.tot+1]*prime[u.tot]});
    }
    printf("%lld",q.top().val);
    return 0;
}