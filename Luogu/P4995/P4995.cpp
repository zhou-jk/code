#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=301;
int n;
int h[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    sort(h+1,h+n+1);
    long long ans=h[n]*h[n];
    int l=1,r=n;
    while(l<r)
    {
        ans+=(h[r]-h[l])*(h[r]-h[l]);
        r--;
        ans+=(h[r]-h[l])*(h[r]-h[l]);
        l++;
    }
    printf("%lld",ans);
    return 0;
}