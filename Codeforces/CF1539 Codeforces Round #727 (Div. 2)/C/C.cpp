#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
long long k,x;
long long a[N];
int main()
{
    scanf("%d%lld%lld",&n,&k,&x);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    vector<long long>b;
    for(int i=1;i<=n;i++)
        if(a[i+1]-a[i]>x) b.emplace_back((a[i+1]-a[i]-1)/x);
    sort(b.begin(),b.end());
    int res=b.size()+1;
    for(long long v:b)
        if(k>=v) k-=v,res--;
    printf("%d",res);
    return 0;
}