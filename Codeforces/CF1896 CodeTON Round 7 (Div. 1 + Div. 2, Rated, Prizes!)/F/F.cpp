#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
int a[N*2];
void solve()
{
    cin>>n;
    n*=2;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        a[i]=str[i-1]-'0';
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=a[i];
    if(a[1]!=a[n]||(cnt&1))
    {
        cout<<-1<<"\n";
        return;
    }
    vector<string>res;
    if(a[1])
    {
        string s="";
        for(int i=1;i<=n;i++)
        {
            if(i&1) s+='(';
            else s+=')';
            a[i]^=1;
        }
        res.emplace_back(s);
    }
    int sum=0;
    a[1]^=1,a[n]^=1;
    string s="(";
    for(int i=2;i<n;i+=2) 
    {
        if(a[i]==a[i+1]) s+="()";
        else if(!sum) s+="((",a[i+1]^=1,sum^=1;
        else s+="))",a[i]^=1,sum^=1;
    }
    s+=')';
    res.emplace_back(s);
    s="(";
    for(int i=2;i<n;i+=2)
        if(a[i]) s+=")(";
        else s+="()";
    s+=')';
    res.emplace_back(s);
    int k=res.size();
    cout<<k<<"\n";
    for(string s:res)
        cout<<s<<"\n";
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