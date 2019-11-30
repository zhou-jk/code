#include<iostream>
#include<cstdio>
using namespace std;
const int N=10001,M=5001,K=505;
int n,k,Max;
int a[N],f[N][K];
struct Binary_Indexed_Tree
{
    int C[K][M+K];
    int lowbit(int x)
    {
        return x&-x;
    }
    void update(int x,int y,int z)
    {
        for(int i=x;i<=k;i+=lowbit(i))
            for(int j=y;j<=Max;j+=lowbit(j))
                C[i][j]=max(C[i][j],z);
    }
    int query(int x,int y)
    {
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i))
            for(int j=y;j>0;j-=lowbit(j))
                ans=max(ans,C[i][j]);
        return ans;
    }
}tree;
int main()
{
    scanf("%d%d",&n,&k);
    k++;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
    }
    Max+=k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
            f[i][j]=tree.query(j,a[i]+j)+1;
        for(int j=1;j<=k;j++)
            tree.update(j,a[i]+j,f[i][j]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            ans=max(ans,f[i][j]);
    printf("%d",ans);
    return 0;
}