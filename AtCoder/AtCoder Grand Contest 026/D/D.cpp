#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
const int MOD=1000000007;
int n;
int h[N];
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
pair<int,int>solve(int l,int r,int now)
{
    int mi=1e9;
    for(int i=l;i<=r;i++)
        mi=min(mi,h[i]);
    int cnt=0;
    for(int i=l;i<=r;i++)
        if(h[i]==mi) cnt++;
    if(cnt==r-l+1)
    {
        return {(ksm(2,r-l+1)-2+MOD)%MOD,ksm(2,mi-now+1)};
    }
    int s0=1,s1=2;
    for(int i=l,j=l;i<=r;i=j)
    {
        if(h[i]==mi)
        {
            while(j<=r&&h[j]==mi) j++;
            s0=1LL*s0*ksm(2,j-i)%MOD;
        }
        else
        {
            while(j<=r&&h[j]>mi) j++;
            pair<int,int>s=solve(i,j-1,mi+1);
            s0=1LL*s0*(s.first+2LL*s.second)%MOD;
            s1=1LL*s1*s.second%MOD;
        }
    }
    s0=((long long)s0-s1+MOD)%MOD;
    s1=1LL*s1*ksm(2,mi-now)%MOD;
    return {s0,s1};
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    int res=1;
    for(int i=1;i<=n;i++)
        if(h[i]>h[i-1]&&h[i]>h[i+1])
        {
            res=1LL*res*ksm(2,h[i]-max(h[i-1],h[i+1]))%MOD;
            h[i]=max(h[i-1],h[i+1]);
        }
    pair<int,int> ans=solve(1,n,1);
    res=1LL*res*(ans.first+ans.second)%MOD;
    printf("%d",res);
    return 0;
}