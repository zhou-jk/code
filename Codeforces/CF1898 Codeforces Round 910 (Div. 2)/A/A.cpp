#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=105;
int n,k;
char s[N];
void solve()
{
    cin>>n>>k;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    int cb=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='B') cb++;
    if(cb<k)
    {
        cout<<1<<"\n";
        int ca=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='A') ca++;
            if(ca==k-cb)
            {
                cout<<i<<" "<<'B'<<"\n";
                return;
            }
        }
    }
    else if(cb>k)
    {
        cout<<1<<"\n";
        int ca=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='B') ca++;
            if(ca==cb-k)
            {
                cout<<i<<" "<<'A'<<"\n";
                return;
            }
        }
    }
    else
    {
        cout<<0<<"\n";
        return;
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
