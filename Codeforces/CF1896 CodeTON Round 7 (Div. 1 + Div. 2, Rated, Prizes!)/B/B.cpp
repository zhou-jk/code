#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
char s[N];
void solve()
{
    cin>>n;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    int pa=0,pb=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='A')
        {
            pa=i;
            break;
        }
    for(int i=n;i>=1;i--)
        if(s[i]=='B')
        {
            pb=i;
            break;
        }
    if(pa==0||pb==0||pa>pb)
    {
        cout<<0<<"\n";
        return;
    }
    cout<<pb-pa<<"\n";
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