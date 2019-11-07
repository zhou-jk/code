#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,tot;
int H[2001],L[2001];
char s[2001];
long long solve(int *a,int n,int m)
{
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        long long sum=0,cnt=m-a[i];
        for(int j=1;j<=n;j++)
            if(a[j]) sum+=(m-1)*abs(i-j);
            else sum+=m*abs(i-j);
        if(a[i]) res+=(m-1)*sum;
        else res+=m*sum;
        if(a[i])
        {
            int l=i-1,r=i+1;
            while(a[l+1]<a[l])
                cnt+=m-a[l--];
            while(a[r-1]<a[r])
                cnt+=m-a[r++];
            res+=4*cnt*(a[i]-1);
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
            if(s[j]=='X') H[i]=j,L[j]=i,tot++;
    }
    printf("%.6lf",(solve(H,n,m)+solve(L,m,n))*1.0/(n*m-tot)/(n*m-tot));
    return 0;
}