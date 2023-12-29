#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
string s[N];
int l[N],v[N];
int calc(const string &str)
{
    int res=0;
    for(int i=0;i<(int)str.size();i++)
        res+=str[i]-'0';
    return res;
}
int cnt[6][46];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        l[i]=s[i].size();
        v[i]=calc(s[i]);
        cnt[l[i]][v[i]]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=cnt[l[i]][v[i]];
        for(int j=l[i]-2;j>=1;j-=2)
        {
            int nl=(l[i]+j)/2;
            int val=calc(s[i].substr(0,nl))-calc(s[i].substr(nl));
            if(val>=0) ans+=cnt[j][val];
        }
        for(int j=l[i]-2;j>=1;j-=2)
        {
            int nl=(l[i]+j)/2;
            int val=calc(s[i].substr(l[i]-nl))-calc(s[i].substr(0,l[i]-nl));
            if(val>=0) ans+=cnt[j][val];
        }
    }
    cout<<ans<<"\n";
    return 0;
}