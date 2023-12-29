#include<iostream>
#include<cstdio>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    if(s[0]=='0')
    {
        cout<<-1<<"\n";
        return;
    }
    int a=-1,b=-1;
    for(int i=1;i<(int)s.size();i++)
        if(s[i]!='0')
        {
            a=stoi(s.substr(0,i)),b=stoi(s.substr(i));
            break;
        }
    if(b>a) cout<<a<<" "<<b<<"\n";
    else cout<<-1<<"\n";
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