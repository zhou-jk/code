#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
char s[N];
void solve()
{
    string str;
    cin>>str;
    n=str.size();
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        if(s[i]==')') cnt++;
        if(s[i]=='(') cnt--;
        if(cnt<0)
        {
            cout<<"impossible\n";
            return;
        }
    }
    cout<<str<<"\n";
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