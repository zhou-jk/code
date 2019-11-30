#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const long long INF=4557430888798830399;
const int N=505,M=10001;
int K,E,n;
struct Node
{
    int x,f,c;
}a[N];
bool cmp(Node a,Node b)
{
    return a.x<b.x;
}
long long dp[M];
int main()
{
    scanf("%d%d%d",&K,&E,&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].f,&a[i].c);
    sort(a+1,a+n+1,cmp);
    a[++n].x=E;
    memset(dp,63,sizeof(dp));
    dp[0]=0;
    for(int i=2;i<=n;i++)
    {
        deque<pair<int,long long> >q;
        for (int j=0;j<=K;j++)
        {
            long long val=dp[j]-(long long)a[i-1].c*j;
            while(!q.empty()&&q.front().first+a[i-1].f<j) q.pop_front();
            while(!q.empty()&&q.back().second>=val) q.pop_back();
            q.push_back(make_pair(j,val));
            dp[j]=q.front().second+(long long)a[i-1].c*j+(long long)j*j*(a[i].x-a[i-1].x);
        }
    }
    printf("%lld",dp[K]);
    return 0;
}