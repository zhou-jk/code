#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=10;
int n,m;
int a[N],b[N];
double resa,resb,resc;
int hpa[N],hpb[N];
int cnta[N],cntb[N];
void dfs(int cur,double sum)
{
    int posa=0;
    for(int i=1;i<=n;i++)
        if(hpa[i]>0)
        {
            if(posa==0||cnta[i]<cnta[posa]) posa=i;
        }
    int posb=0;
    for(int i=1;i<=m;i++)
        if(hpb[i]>0)
        {
            if(posb==0||cntb[i]<cntb[posb]) posb=i;
        }
    if(posa==0&&posb==0)
    {
        resc+=sum;
        return;
    }
    if(posa==0)
    {
        resb+=sum;
        return;
    }
    if(posb==0)
    {
        resa+=sum;
        return;
    }
    if(cur==0)
    {
        int cnt=0;
        for(int i=1;i<=m;i++)
            if(hpb[i]>0) cnt++;
        for(int i=1;i<=m;i++)
            if(hpb[i]>0)
            {
                hpb[i]-=a[posa];
                hpa[posa]-=b[i];
                cnta[posa]++;
                dfs(cur^1,sum/cnt);
                hpb[i]+=a[posa];
                hpa[posa]+=b[i];
                cnta[posa]--;
            }
    }
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(hpa[i]>0) cnt++;
        for(int i=1;i<=n;i++)
            if(hpa[i]>0)
            {
                hpa[i]-=b[posb];
                hpb[posb]-=a[i];
                cntb[posb]++;
                dfs(cur^1,sum/cnt);
                hpa[i]+=b[posb];
                hpb[posb]+=a[i];
                cntb[posb]--;
            }
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        hpa[i]=a[i];
    for(int i=1;i<=m;i++)
        hpb[i]=b[i];
    if(n>m) dfs(0,1);
    else if(n<m) dfs(1,1);
    else dfs(0,0.5),dfs(1,0.5);
    printf("%.10lf\n%.10lf\n%.10lf",resa,resb,resc);
    return 0;
}
