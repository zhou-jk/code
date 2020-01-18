#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int l[7],r[7];
int sum,ans;
int main()
{
    memset(l,-1,sizeof(l));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum=(sum+x)%7;
        if(l[sum]==-1) l[sum]=i;
        r[sum]=i;
    }
    for(int i=0;i<7;i++)
        if(l[i]!=-1) ans=max(ans,r[i]-l[i]);
    printf("%d",ans);
    return 0;
}