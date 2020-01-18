#include<iostream>
#include<cstdio>
using namespace std;
int T,n,a[1001];
int L[1001][1001],R[1001][1001];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            L[i][i]=R[i][i]=a[i];
        }
        for(int k=2;k<=n;k++)
            for(int i=1;i<=n-k+1;i++)
            {
                int j=i+k-1;
                int x=a[j],l=L[i][j-1],r=R[i][j-1];
                if(x==r)L[i][j]=0;
                else if((x>l&&x>r)||(x<l&&x<r))L[i][j]=x;
                else if(r<x&&x<l)L[i][j]=x-1;
                else L[i][j]=x+1;
                x=a[i],l=L[i+1][j],r=R[i+1][j];
                if(x==l)R[i][j]=0;
                else if((x>l&&x>r)||(x<l&&x<r))R[i][j]=x;
                else if(r<x&&x<l)R[i][j]=x+1;
                else R[i][j]=x-1;
            }
        if(a[1]==L[2][n]) printf("0\n");
        else printf("1\n");
    }
    return 0;
}