#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int M=3005;
int n,m,k;
int a,b,c;
long long T;
int d[M];
long long t[M];
int now[M];
priority_queue<int,vector<int>>q;
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d%d",&a,&b,&c);
    scanf("%lld",&T);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&d[i]);
        if(i!=1)T-=(long long)(d[i]-d[i-1])*b;
        t[i]=T;
        now[i]=d[i];
    }
    int ans=0;
    for(int i=1;i<m;i++)
        if(t[i]>=0)
        {
            int x=min((long long)d[i+1],now[i]+t[i]/a+1);
            ans+=x-now[i];
            t[i]-=(long long)(x-now[i])*c;
            now[i]=x;
        }
    for(int i=1;i<=k;i++)
        for(int j=1;j<m;j++)
            if(t[j]>=0)
            {
                int x=min((long long)d[j+1],now[j]+t[j]/a+1);
                q.push(x-now[j]);
                t[j]-=(long long)(x-now[j])*c;
                now[j]=x;
            }
    for(int i=1;i<=k-m;i++)
        if(!q.empty()) ans+=q.top(),q.pop();
    if(T<0) ans--;
    printf("%d",ans);
    return 0;
}