#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int a[N];
int res[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        long long sum=0;
        for(int j=max(i-31,1);j<=i;j++)
            sum+=(1LL<<(j-i+31))*a[j];
        if(sum>0) res[i]=1;
        else if(sum<0) res[i]=-1;
        else res[i]=res[max(i-32,0)]; 
    }
    for(int i=1;i<=n;i++)
        if(res[i]>0) cout<<"+";
        else if(res[i]<0) cout<<"-";
        else cout<<"0";
    return 0;
}