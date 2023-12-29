#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k;
int a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool allone=true;
    for(int i=1;i<=n;i++)
        if(a[i]!=1)
        {
            allone=false;
            break;
        }
    if(allone)
    {
        cout<<max(n-k,0)<<"\n";
        return;
    }
    vector<int>len;
    int c1=0,c2=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&(a[i]==1)==(a[j]==1)) j++;
        if(a[i]==1)
        {
            if(j==n+1) c1+=j-i;
            else if(i==1) c1+=j-i;
            else len.emplace_back(j-i);
        }
        else
        {
            int lst=i;
            for(int k=i;k<j;k++)
            {
                if(k==j-1||gcd(a[k],a[k+1])!=1)
                {
                    int cnt=(k-lst+1-1)/2;
                    c2+=cnt;
                    if((k-lst+1)%2==0) c1++; 
                    lst=k+1;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<n;i++)
        if(gcd(a[i],a[i+1])==1) ans++;
    ans-=min(c2,k)*2,k-=min(c2,k);
    sort(len.begin(),len.end());
    for(int l:len)
        if(k>=l) ans-=l+1,k-=l;
        else if(k) ans-=k,k=0;
    ans-=min(c1,k),k-=min(c1,k);
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