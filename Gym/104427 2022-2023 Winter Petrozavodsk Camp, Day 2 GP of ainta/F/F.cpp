#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=300005;
int n;
int p[N];
int a[N],c[N],tot;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    sort(p+1,p+n+1);
    tot=0;
    int lst=1;
    for(int i=2;i<=n;i++)
        if(p[i]!=p[i-1]) tot++,a[tot]=p[i-1],c[tot]=i-1-lst+1,lst=i;
    tot++,a[tot]=p[n],c[tot]=n-lst+1;
    priority_queue<int,vector<int>,greater<int>>q;
    int cntv=0,cntw=0; 
    for(int i=1;i<=tot;i++)
    {
        while(cntv+1<cntw+1)
        {
            int c=q.top();
            q.pop();
            if(c>1) q.emplace(c-1);
            else cntw--;
            cntv++;
        }
        q.emplace(c[i]),cntw++;
    }
    int ans=n-cntv;
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