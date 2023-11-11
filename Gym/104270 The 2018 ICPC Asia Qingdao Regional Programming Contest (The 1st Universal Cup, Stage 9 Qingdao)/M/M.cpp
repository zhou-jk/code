#include<iostream>
#include<cstdio>
using namespace std;
int x,k;
int calc(int x)
{
    if(x==0) return 1;
    if(x==1||x==2||x==3) return 0;
    if(x==4) return 1;
    if(x==5) return 0;
    if(x==6) return 1;
    if(x==7) return 0;
    if(x==8) return 2;
    if(x==9) return 1;
    return -1;
}
int f(int x)
{
    if(x==0) return 1;
    int sum=0;
    while(x>0)
        sum+=calc(x%10),x/=10;
    return sum;
}
void solve()
{
    cin>>x>>k;
    for(int i=1;i<=k;i++)
    {
        x=f(x);
        if(x==0||x==1)
        {
            x^=(k-i)&1;
            break;
        }
    }
    cout<<x<<"\n";
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