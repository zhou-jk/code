#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> count(int n)
{
    vector<int>prime;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        {
            prime.emplace_back(i);
            while(n%i==0) n/=i;
        }
    if(n!=1) prime.emplace_back(n);
    return prime;
}
int k;
void solve()
{
    cin>>k;
    vector<int>res1=count(k),res2=count(k+1);
    int p1=0,p2=0;
    int ans=0;
    while(p1<(int)res1.size()&&p2<(int)res2.size())
    {
        if(res1[p1]<res2[p2]) ans++,p1++;
        else if(res1[p1]>res2[p2]) ans++,p2++;
        else ans++,p1++,p2++;
    }
    ans+=(int)res1.size()-p1+(int)res2.size()-p2;
    cout<<ans<<"\n";
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
