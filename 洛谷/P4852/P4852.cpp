#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=41,M=200001;
int n,m,c,d,s;
int sum[M],p[M],f[M][N];
struct Node
{
    int id,val;
};
int pre[M][N];
deque<Node>q[N];
vector<int>res;
int main()
{
    scanf("%d%d%d%d",&n,&m,&c,&d);
    s=c*n+m;
    for(int i=1;i<=s;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    for(int i=1;i<=s-c+1;i++)
        p[i]=sum[i+c-1]-sum[i];
    int k=0,ans=0;
    for(int i=1;i<=s-c+1;i++)
    {
    	if(i<=c)
        {
            f[i][1]=p[i];
            continue;
        }
        for(int j=(i+c-2)/(c+d)+1;j<=n&&j<=(i+c-1)/c;j++)
        {
            if(!q[j-1].empty()&&q[j-1].front().id<i-c-d) q[j-1].pop_front();
            if(j-1>=(i-2)/(c+d)+1&&j-1<=(i-1)/c)
            {
                while(!q[j-1].empty()&&q[j-1].back().val>=f[i-c][j-1]) q[j-1].pop_back();
                q[j-1].push_back((Node){i-c,f[i-c][j-1]});
            }
            f[i][j]=q[j-1].front().val+p[i];
            pre[i][j]=q[j-1].front().id;
            if(i>=s-c-d+1&&j==n&&ans<sum[s]-f[i][j]) ans=sum[s]-f[i][j],k=i;
        }
    }
    printf("%d\n",ans);
    for(int i=n;i>0;i--)
    {
        res.push_back(k);
        k=pre[k][i];
    }
    for(int i=res.size()-1;i>=0;i--)
        printf("%d ",res[i]);
    return 0;
}