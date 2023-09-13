#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const long long INF=4557430888798830399;
int n;
int a[N],b[N];
long long f[N][2][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=0;i<=n;i++)
        f[i][0][0]=f[i][1][0]=f[i][0][1]=-INF;
    f[0][0][0]=0;
    for(int i=1;i<=n;i++)
        if(b[i]==1)
        {
            f[i][0][0]=max(f[i-1][0][0]+a[i],f[i-1][0][1]);
            f[i][0][1]=f[i-1][0][1]+a[i];
            f[i][1][0]=max(f[i-1][0][0],f[i-1][1][0]+a[i]);
        }
        else
        {
            f[i][0][0]=max(f[i-1][0][0],f[i-1][1][0]+a[i]);
            f[i][0][1]=f[i-1][0][0]+a[i];
        }
    cout<<f[n][0][0];
    return 0;
}