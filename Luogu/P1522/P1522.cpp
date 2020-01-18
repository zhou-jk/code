#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double INF=1061109567;
double x[151],y[151];
double f[151][151],Max[151];
double ans1,ans2=INF;
int n;
double count(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=i==j?0:INF;
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char ch;
            for(ch=getchar();ch!='0'&&ch!='1';ch=getchar());
            if(ch=='1') f[i][j]=count(i,j);
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(f[i][j]==INF)continue;
            Max[i]=max(Max[i],f[i][j]);
            ans1=max(Max[i],ans1);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]==INF) ans2=min(ans2,Max[i]+count(i,j)+Max[j]);
    printf("%.6lf",max(ans1,ans2));
    return 0;
}