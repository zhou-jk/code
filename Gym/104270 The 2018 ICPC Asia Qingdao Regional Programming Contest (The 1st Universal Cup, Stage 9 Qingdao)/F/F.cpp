#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,k;
int a[N][N];
int lowbit(int x)
{
    return x&-x; 
}
void solve()
{
    cin>>n>>k;
    if(k>lowbit(n)-1)
    {
        cout<<"Impossible\n";
        return;
    }
    for(int i=1;i<=n;i++)
        a[0][i]=i;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
            a[i][j]=a[i-1][j]; 
        int len=lowbit(i);
        for(int j=1;j<=n;j+=len*2)
            for(int k=0;k<len;k++)
                swap(a[i][j+k],a[i][j+len*2-1-k]);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}