#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=400005;
vector<int>manacher(const string &s)
{
    int n=s.size();
    vector<int>p(n);
    int l=0,r=-1;
    for(int i=0;i<n;i++)
    {
        int k=(i>r)?1:min(p[l+r-i],r-i+1);
        while(0<=i-k&&i+k<n&&s[i-k]==s[i+k]) k++;
        p[i]=k;
        k--;
        if(i+k>r) l=i-k,r=i+k;
    }
    return p;
}
int n;
int a[N];
void solve()
{
    string str;
    cin>>str;
    string s="#";
    for(int i=0;i<(int)str.size();i++)
        s+=str[i],s+="#";
    vector<int>d=manacher(s);
    n=d.size();
    for(int i=1;i<=n;i++)
        a[i]=d[i-1];
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]>a[y];});
    set<int>pos;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int u=id[i];
        if(s[u-1]!='#') continue;
        int l=max(u-a[u],1),r=min(u+a[u],n);
        if(l<u)
        {
            auto it=pos.lower_bound(l);
            if(it!=pos.end()&&*it<u) ans=max(ans,(u-*it+1)/2*3);
        }
        if(r>u&&!pos.empty()&&r>=*pos.begin())
        {
            auto it=prev(pos.upper_bound(r));
            if(*it>u) ans=max(ans,(*it-u+1)/2*3);
        }
        pos.insert(u);
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