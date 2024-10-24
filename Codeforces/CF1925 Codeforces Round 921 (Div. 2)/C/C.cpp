#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,k,m;
string s;
void solve()
{
    cin>>n>>k>>m;
    cin>>s;
    int c[26]={};
    int cnt=0;
    string ans="";
    for(int i=0;i<m;i++)
    {
        if(c[s[i]-'a']==0) cnt++;
        c[s[i]-'a']=1;
        if(cnt==k)
        {
            ans+=s[i];
            cnt=0;
            for(int j=0;j<k;j++)
                c[j]=0;
        }
    }
    if((int)ans.size()>=n) cout<<"YES\n";
    else
    {
        cout<<"NO\n";
        for(int i=0;i<k;i++)
            if(c[i]==0)
            {
                while((int)ans.size()<n)
                    ans+=char('a'+i);
                break;
            }
        cout<<ans<<"\n";
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