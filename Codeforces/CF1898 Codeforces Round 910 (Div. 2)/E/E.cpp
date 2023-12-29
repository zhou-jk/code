#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200005;
int n,m;
char s[N],t[N];
void solve()
{
    cin>>n>>m;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    cin>>str;
    for(int i=1;i<=m;i++)
        t[i]=str[i-1];
    queue<int>q[26];
    for(int i=1;i<=n;i++)
        q[s[i]-'a'].emplace(i);
    for(int i=1;i<=m;i++)
    {
        if(q[t[i]-'a'].empty())
        {
            cout<<"NO\n";
            return;
        }
        int p=q[t[i]-'a'].front();
        for(int j=0;j<=t[i]-'a';j++)
            while(!q[j].empty()&&q[j].front()<=p) q[j].pop();
    }
    cout<<"YES\n";
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
