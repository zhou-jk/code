#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=25;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int cntp=0,cntn=0;
    for(int i=1;i<=n;i++)
        if(a[i]>0) cntp++;
        else if(a[i]<0) cntn++;
    int mxp=max_element(a+1,a+n+1)-a,mxn=min_element(a+1,a+n+1)-a;
    vector<pair<int,int>>res;
    if(a[mxp]>0&&a[mxn]<0)
    {
        int sp=cntn,sn=cntp;
        if(a[mxp]+a[mxn]>=0) sn+=5;
        else sp+=5;
        if(sp<=sn)
        {
            while(a[mxp]+a[mxn]<0) res.emplace_back(mxp,mxp),a[mxp]=a[mxp]+a[mxp];
            for(int i=1;i<=n;i++)
                if(a[i]<0) res.emplace_back(i,mxp),a[i]+=a[mxp];
        }
        else
        {
            while(a[mxp]+a[mxn]>0) res.emplace_back(mxn,mxn),a[mxn]=a[mxn]+a[mxn];
            for(int i=1;i<=n;i++)
                if(a[i]>0) res.emplace_back(i,mxn),a[i]+=a[mxn];
        }
    }
    if(*max_element(a+1,a+n+1)>0)
    {
        for(int i=2;i<=n;i++)
            if(a[i]<a[i-1]) res.emplace_back(i,i-1),a[i]+=a[i-1];
    }
    else
    {
        for(int i=n-1;i>=1;i--)
            if(a[i]>a[i+1]) res.emplace_back(i,i+1),a[i]+=a[i+1];
    }
    int k=res.size();
    printf("%d\n",k);
    for(auto [i,j]:res)
        printf("%d %d\n",i,j);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}