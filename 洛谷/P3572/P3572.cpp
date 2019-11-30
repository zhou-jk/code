#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1000001;
int n,Q;
int a[N],dp[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&Q);
    while(Q--)
    {
        int x;
        scanf("%d",&x);
        deque<int>q;
        dp[1]=0;
        q.push_back(1);
        for(int i=2;i<=n;i++)
        {
            while(!q.empty()&&q.front()+x<i) q.pop_front();
            if(a[i]>=a[q.front()]) dp[i]=dp[q.front()]+1;
            else dp[i]=dp[q.front()];
            while(!q.empty()&&(dp[q.back()]>dp[i]||(dp[q.back()]==dp[i]&&a[q.back()]<=a[i]))) q.pop_back();
            q.push_back(i);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}