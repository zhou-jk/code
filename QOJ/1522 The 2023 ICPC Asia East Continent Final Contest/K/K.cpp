#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int m;
int a[N],b[N];
void solve()
{
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    long long ca=0,cb=0;
    for(int i=0;i<m;i++)
        ca+=a[i],cb+=b[i];
    if(ca<cb)
    {
        swap(ca,cb);
        for(int i=0;i<m;i++)
            swap(a[i],b[i]);
    }
    bool has_greater_m=false;
    long long sum=0;
    for(int i=1;i<m;i++)
    {
        sum+=b[m-i];
        if(a[i]>0&&sum>0)
        {
            has_greater_m=true;
            break;
        }
    }
    if(!has_greater_m)
    {
        cout<<0<<"\n";
        return;
    }
    bool exist_begin=false;
    long long ans=0;
    long long ret=0;
    b[0]+=1e9;
    for(int i=0,j=m-i;i<m;i++)
    {
        int cnt=min(a[i],b[m-1-i]);
        a[i]-=cnt,b[m-1-i]-=cnt;
        if(a[i]>0&&ans>0) exist_begin=true;
        ans+=cnt;
        if(cnt>0&&ret>0) exist_begin=true;
        if(a[i]>0&&ret>0)
        {
            exist_begin=true;
            long long del=min((long long)a[i],ret);
            ans+=del;
            a[i]-=del,ret-=del;
        }
        if(b[m-1-i]>0) ret+=b[m-1-i];
    }
    if(!exist_begin)
    {
        ans--;
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