#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int m;
int cnt[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>m;
    while(m--)
    {
        int t,v;
        cin>>t>>v;
        if(t==1)
        {
            cnt[v]++;
        }
        else if(t==2)
        {
            int x=v;
            for(int i=29;i>=0;i--)
                if(x>=(1<<i)) x-=(1<<i)*min(cnt[i],x/(1<<i));
            if(x==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}