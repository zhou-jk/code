#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const int INF=1061109567;
int n;
int a[N];
int pre[N],suf[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=max(pre[i-1],a[i]);
    suf[n+1]=INF;
    for(int i=n;i>=1;i--)
        suf[i]=min(suf[i+1],a[i]);
    int ans=0;
    for(int k=1;k<=n;k++)
    {
        bool flag=true;
        for(int i=1;i<=n/k;i++)
            if(pre[i*k]>suf[i*k+1])
            {
                flag=false;
                break;
            }
        if(flag) ans++;
    }
    cout<<ans;
    return 0;
}