#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int l[N],r[N];
int v[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>l[i]>>r[i];
    fill(v+1,v+n+1,0);
    int ans=0;
    for(int p=29;p>=0;p--)
    {
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            int nl=v[i]|(1<<p),nr=v[i]|((1<<(p+1))-1);
            if(nr<l[i]||nl>r[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            ans+=1<<p;
            for(int i=1;i<=n;i++)
                v[i]|=1<<p;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                int nl=v[i]|(1<<p),nr=v[i]|((1<<(p+1))-1);
                if(nr<l[i]||nl>r[i]) continue;
                int x=v[i]|((1<<p)-1);
                if(l[i]<=x&&x<=r[i]) continue;
                else v[i]|=1<<p;
            }
        }
    }
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