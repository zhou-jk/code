#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=100005;
int n,q;
int a[N];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    set<int>pos;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) pos.insert(i);
        sum+=a[i];
    }
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int s;
            cin>>s;
            if(s>sum)
            {
                cout<<"NO\n";
                continue;
            }
            if(pos.empty())
            {
                if(sum%2!=s%2) cout<<"NO\n";
                else cout<<"YES\n";
                continue;
            }
            int l=*pos.begin(),r=*pos.rbegin();
            if(sum%2!=s%2)
            {
                if(s>sum-min((l-1)*2,(n-r)*2)-1) cout<<"NO\n";
                else cout<<"YES\n";
            }
            else cout<<"YES\n";
        }
        else
        {
            int i,v;
            cin>>i>>v;
            if(a[i]==1) pos.erase(pos.find(i));
            sum-=a[i];
            a[i]=v;
            if(a[i]==1) pos.insert(i);
            sum+=a[i];
        }
    }
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