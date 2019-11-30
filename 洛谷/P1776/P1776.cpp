#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100001;
int n,m;
int v[N],w[N],num[N];
int dp[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&v[i],&w[i],&num[i]);
    for(int i=1;i<=n;i++)
    {
        num[i]=min(num[i],m/w[i]);
        for(int j=0;j<w[i];j++)
        {
            deque<pair<int,int> >q;
            for(int k=0;k<=(m-j)/w[i];k++)
            {
                int x=k,y=dp[k*w[i]+j]-k*v[i];
                while()
            }
        }
    }
}