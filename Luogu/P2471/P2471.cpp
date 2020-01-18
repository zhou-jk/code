#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m;
int a[N];
int r[N],s[N],t[N];
int Max[N][21];
int query(int l,int r)
{
    if(r<l) return -1e9;
    int k=log2(r-l+1);
    return max(Max[l][k],Max[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&Max[i][0]);
    scanf("%d",&m);
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&s[i],&t[i]);
        int x=lower_bound(a+1,a+1+n,s[i])-a,y=lower_bound(a+1,a+1+n,t[i])-a;
        bool nl=(x<=n&&a[x]==s[i]),nr=(y<=n&&t[i]==a[y]);
        if((x<=n&&a[x]==s[i])&&(y<=n&&t[i]==a[y]))
        {
            if(Max[y][0]>Max[x][0]) printf("false\n");
            else if(query(x+1,y-1)<Max[y][0])
            {
                if(y-x==t[i]-s[i]) printf("true\n");
                else printf("maybe\n");
            }
            else printf("false\n");
        }
        else if((x<=n&&a[x]==s[i])&&!(y<=n&&t[i]==a[y]))
        {
            if(Max[x][0]>query(x+1,y-1)) printf("maybe\n");
            else printf("false\n");
        }
        else if(!(x<=n&&a[x]==s[i])&&(y<=n&&t[i]==a[y]))
        {
            if(query(x,y-1)<Max[y][0]) printf("maybe\n");
            else printf("false\n");
        }
        else if(!(x<=n&&a[x]==s[i])&&!(y<=n&&t[i]==a[y]))
        {
            printf("maybe\n");
        }
    }
    return 0;
}