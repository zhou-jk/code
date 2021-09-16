#include<iostream>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
int pre[N],suf[N];
int ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    static int ida[N],idb[N];
    iota(ida+1,ida+n+1+1,1);
    iota(idb+1,idb+n+1,1);
    sort(ida+1,ida+n+1+1,[=](const int &x,const int &y){return a[x]<a[y];});
    sort(idb+1,idb+n+1,[=](const int &x,const int &y){return b[x]<b[y];});
    for(int i=1;i<=n;i++)
        pre[i]=max(pre[i-1],max(a[ida[i]]-b[idb[i]],0));
    for(int i=n;i>=1;i--)
        suf[i]=max(suf[i+1],max(a[ida[i+1]]-b[idb[i]],0));
    for(int i=1;i<=n+1;i++)
        ans[ida[i]]=max(pre[i-1],suf[i]);
    for(int i=1;i<=n+1;i++)
        printf("%d ",ans[i]);
    return 0;
}