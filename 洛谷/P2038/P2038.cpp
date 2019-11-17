#include<iostream>
#include<cstdio>
using namespace std;
int d,n;
int res;
long long sum[129][129],ans;
void add(int x,int y,int z)
{
    for(int i=max(0,x-d);i<=min(128,x+d);i++)
        for(int j=max(0,y-d);j<=min(128,y+d);j++)
            sum[i][j]+=z;
    return;
}
int main()
{
    scanf("%d%d",&d,&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }    
    for(int i=0;i<=128;i++)
        for(int j=0;j<=128;j++)
            ans=max(ans,sum[i][j]);
    for(int i=0;i<=128;i++)
        for(int j=0;j<=128;j++)
            if(sum[i][j]==ans) res++;
    printf("%d %lld",res,ans);
    return 0;
}