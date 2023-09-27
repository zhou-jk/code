#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int m,n,k;
int a[N],d[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        a[i]-=i;
    for(int i=1;i<=n;i++)
        d[i]=a[i]-a[i-1];
    int ans=0;
    for(int i=n;i>=max(1,n-k+1);i--)
    {
        int sum=0;
        for(int j=i;j>=1;j-=k*2)
            sum^=d[j];
        ans^=sum;
    }
    if(ans) cout<<"Twinkle";
    else cout<<"Nova";
    return 0;
}