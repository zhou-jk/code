#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
int sg[22];
int getsg(int x)
{
    if(x==n) return 0;
    if(sg[x]!=-1) return sg[x];
    bool mark[10001];
    memset(mark,false,sizeof(mark));
    for(int i=x+1;i<=n;i++)
        for(int j=i;j<=n;j++)
            mark[getsg(i)^getsg(j)]=true;
    for(int i=0;;i++)
        if(!mark[i])
        {
            sg[x]=i;
            return i;
        }
} 
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(sg,-1,sizeof(sg));
        int tot=0,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x&1) ans^=getsg(i);
        }
        for(int i=1;i<=n;i++)
           for(int j=i+1;j<=n;j++)
                for(int k=j;k<=n;k++)
                {
                    if((ans^getsg(i)^getsg(j)^getsg(k))!=0) continue;
                    tot++;
                    if(tot==1)printf("%d %d %d\n",i-1,j-1,k-1);
            }
        if(tot==0) printf("-1 -1 -1\n");
        printf("%d\n",tot);
    }
    return 0;
}