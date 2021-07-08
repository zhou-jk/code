#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int T;
int n;
map<string,pair<pair<string,string>,long long>>book;
int calc(string t)
{
    int cnt=0;
    for(int i=0;i+3<(int)t.size();i++)
        if(t[i]=='h'&&t[i+1]=='a'&&t[i+2]=='h'&&t[i+3]=='a') cnt++;
    return cnt;
}
void solve()
{
    cin>>n;
    book.clear();
    string t;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        string op;
        cin>>op;
        if(op==":=")
        {
            string s;
            cin>>s;
            if(s.size()<3) book[x]={{s,s},calc(s)};
            else book[x]={{s.substr(0,3),s.substr(s.size()-3,3)},calc(s)};
        }
        else if(op=="=")
        {
            string a,b;
            cin>>a>>op>>b;
            auto [sa,va]=book[a];
            auto [sb,vb]=book[b];
            long long v=va+vb+calc(sa.second+sb.first);
            string s,t;
            if(sa.first.size()<3) s=sa.first+sb.first.substr(0,min(3-sa.first.size(),sb.first.size()));
            else s=sa.first;
            if(sb.second.size()<3) t=sa.second.substr(max((int)sa.second.size()-(3-(int)sb.second.size()),0),min(3-sb.second.size(),sa.second.size()))+sb.second;
            else t=sb.second;
            book[x]={{s,t},v};
        }
        if(i==n)
        {
            printf("%lld\n",book[x].second);
            break;
        }
    }
    return;
}
int main()
{
    cin>>T;
    while(T--)
        solve();
    return 0;
}