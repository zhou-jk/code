#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int n;
int a[N];
int s[N];
int suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(a[i]==-1) s[i]=s[i-1]-1;
        else s[i]=s[i-1]+1;
    suf[n+1]=suf[n]=s[n];
    for(int i=n-1;i>=1;i--)
        suf[i]=min(suf[i+1],s[i]);
    int tot=1,sum=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) tot++,sum++;
        else if(a[i]==-1)
        {
            if(tot>=2) tot--;
            else
            {
                cout<<"-1\n";
                return;
            }
        }
        else
        {
            if(tot-1<=-(suf[i+1]-s[i])) sum++,tot++;
            else
            {
                if(tot>=2) tot--;
                else sum++,tot++;
            }
        }
    }
    int g=gcd(tot,sum);
    tot/=g,sum/=g;
    cout<<sum<<" "<<tot<<"\n";
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