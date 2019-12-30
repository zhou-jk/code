#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=10005;
int n;
struct Node
{
    int p,d;
    bool operator<(const Node &b)const
    {
        return p<b.p;
    }
}a[N];
bool cmp(Node a,Node b)
{
    return a.d>b.d;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int Max=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].p,&a[i].d);
            if(a[i].d>Max) Max=a[i].d;
        }
        sort(a+1,a+n+1,cmp);
        priority_queue<Node>q;
        int j=1,sum=0;
        for(int i=Max;i>0;i--)
        {
            while(j<=n&&a[j].d>=i) q.push(a[j++]);
            if(!q.empty())
                sum+=q.top().p,q.pop();
        }
        printf("%d\n",sum);
    }
    return 0;
}