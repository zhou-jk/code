#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n,c;
long long a[N];
int id[N];
long long b[N];
void solve()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        b[i]=(long long)i*c-a[i];
    iota(id+1,id+n+1,1);
    sort(id+2,id+n+1,[=](const int &x,const int &y){return b[x]<b[y];});
    long long s=a[1];
    for(int i=2;i<=n;i++)
        if(s>=b[id[i]]) s+=a[id[i]];
        else
        {
            cout<<"No\n";
            return;
        }
    cout<<"Yes\n";
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