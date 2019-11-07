#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,t,k;
int cnt;
vector<int> v[200005];
int a[200005],fa[200005];
int main()
{
    scanf("%d%d%d",&n,&t,&k);
    a[0]=1;
    for(int i=1;i<=t;i++)
        scanf("%d",&a[i]);
    if(a[t]>k||n-t<k)
    {
        printf("-1");
        return 0;
    }
    for(int i=0;i<=t;i++)
        for(int j=1;j<=a[i];j++)
            v[i].push_back(++cnt);
    for(int i=0;i<a[1];i++)
        fa[v[1][i]]=1;
    for(int i=2;i<=t;i++)
        fa[v[i][0]]=v[i-1][0];
    int tot=n-t-k;
    for(int i=2;i<=t;i++)
        for(int j=1;j<a[i];j++)
            if(tot>0&&j<a[i-1]) fa[v[i][j]]=v[i-1][j],tot--;
            else fa[v[i][j]]=v[i-1][0];
    if(tot>0)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n",n);
    for(int i=2;i<=n;i++)
        printf("%d %d\n",fa[i],i);
    return 0;
}