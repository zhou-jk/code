#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string s;
    cin>>s;
    int m=1000;
    string t=s.substr(0,m);
    for(int i=m;i<=10000;i++)
        if(s.substr(i,m)==t)
        {
            cout<<"No";
            return 0;
        }
    cout<<"Yes";
    return 0;
}
