#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N];
int b[N],tot;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    tot=0;
    for(int i=1;i<=n;i++)
        if(a[i]==0) m--;
        else b[++tot]=a[i];
    if(m<0)
    {
        cout<<"Impossible\n";
        return;
    }
    if(m==tot)
    {
        cout<<"Richman\n";
        return;
    }
    long long ans=0;
    for(int i=1;i<=m;i++)
        ans+=b[i];
    int v=*min_element(b+m+1,b+tot+1);
    ans+=v-1;
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