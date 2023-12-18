#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n;
bool isprime[N];
void init(int n=100000)
{
    fill(isprime+1,isprime+n+1,true);
    isprime[1]=false;
    for(int i=2;i<=n;i++)
        if(isprime[i])
            for(int j=i+i;j<=n;j+=i)
                isprime[j]=false;
    return;
}
bool vis[N];
void solve()
{
    cin>>n;
    fill(vis+1,vis+n+1,false);
    vector<pair<int,int>>ans;
    for(int i=n/2;i>=2;i--)
        if(isprime[i])
        {
            vector<int>val;
            for(int j=i;j<=n;j+=i)
                if(j!=i*2&&!vis[j]) val.emplace_back(j);
            if(!vis[i*2]) val.emplace_back(i*2);
            for(int i=0;i+1<(int)val.size();i+=2)
                ans.emplace_back(val[i],val[i+1]),vis[val[i]]=vis[val[i+1]]=true;
        }
    int k=ans.size();
    cout<<k;
    for(auto [a,b]:ans)
        cout<<" "<<a<<" "<<b;
    cout<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}