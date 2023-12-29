#include<iostream>
#include<cstdio>
using namespace std;
const int dir[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
void solve()
{
    int a,b;
    cin>>a>>b;
    int xk,yk,xq,yq;
    cin>>xk>>yk;
    cin>>xq>>yq;
    int cnt=0;
    for(auto [dx,dy]:dir)
    {
        int x=xk+dx*a,y=yk+dy*b;
        if(abs(xq-x)==a&&abs(yq-y)==b) cnt++;
        else if(abs(xq-x)==b&&abs(yq-y)==a) cnt++;
    }
    if(a!=b)
    {
        for(auto [dx,dy]:dir)
        {
            int x=xk+dx*b,y=yk+dy*a;
            if(abs(xq-x)==a&&abs(yq-y)==b) cnt++;
            else if(abs(xq-x)==b&&abs(yq-y)==a) cnt++;
        }
    }
    cout<<cnt<<"\n";
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