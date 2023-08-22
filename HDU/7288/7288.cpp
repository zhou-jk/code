#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long K;
string s;
void solve()
{
    cin>>n>>K;
    cin>>s;
    bool flag=false;
    for(int i=0,j=0;i<n;i=j)
    {
        while(j<n&&s[i]==s[j]) j++;
        if(s[i]=='0')
        {
            if(K==0) break;
            flag=true;
            for(int k=i;k<j;k++)
                s[k]='1';
            K--;
        }
    }
    if(n==1)
    {
        if(K%2==1)
        {
            if(s[0]=='0') s[0]='1';
            else s[0]='0';
        }
    }
    else
    {
        if(!flag&&K==1) s[n-1]='0';
    }
    for(int i=0;i<n;i++)
        cout<<s[i];
    cout<<"\n";
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