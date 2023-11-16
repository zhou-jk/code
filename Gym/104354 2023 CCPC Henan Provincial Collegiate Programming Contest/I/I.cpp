#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
int n;
struct BIT
{
private:
    int n;
    int C[N*2];
protected:
    int lowbit(int x)
    {
        return x&-x;
    }
public:
    BIT(int _n=0)
    {
        n=_n;
        memset(C,0,sizeof(C));
    }
    void resize(int _n)
    {
        n=_n;
        return;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}T;
vector<pair<int,int>>p[N*2],q[N*2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        p[x1].emplace_back(y1,1);
        p[x1].emplace_back(y2,1);
        p[x2+1].emplace_back(y1,-1);
        p[x2+1].emplace_back(y2,-1);
        q[x1].emplace_back(y1,y2);
        q[x2].emplace_back(y1,y2);
        ans+=(x2-x1+1)*2+(y2-y1+1)*2;
    }
    T.resize(2*n);
    for(int i=1;i<=2*n;i++)
    {
        for(auto [pos,v]:p[i])
            T.add(pos,v);
        for(auto [l,r]:q[i])
            ans-=T.query(l,r);
    }
    ans=4LL*n*n-ans;
    cout<<ans;
    return 0;
}