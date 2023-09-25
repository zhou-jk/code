#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
string s[N];
bool book[26];
bool check(const string &t)
{
    for(int i=0;i<(int)t.size();i++)    
        if(!book[t[i]-'A']) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        book[s[i][0]-'A']=true;
    for(int i=1;i<=n;i++)
        if(check(s[i]))
        {
            cout<<"Y";
            return 0;
        }
    cout<<"N";
    return 0;
}
