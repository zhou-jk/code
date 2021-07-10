#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=1005;
int T;
int n;
string s;
map<string,bool>book;
void solve()
{
    cin>>n;
    cin>>s;
    book.clear();
    for(int i=0;i<n;i++)
        book[s.substr(i,1)]=true;
    for(int i=0;i+1<n;i++)
        book[s.substr(i,2)]=true;
    for(int i=0;i+2<n;i++)
        book[s.substr(i,3)]=true;
    for(int i=0;i<26;i++)
    {
        string s;
        s+=(char)(i+'a');
        if(!book[s])
        {
            cout<<s<<"\n";
            return;
        }
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            string s;
            s+=(char)(i+'a');
            s+=(char)(j+'a');
            if(!book[s])
            {
                cout<<s<<"\n";
                return;
            }
        }
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
            {
                string s;
                s+=(char)(i+'a');
                s+=(char)(j+'a');
                s+=(char)(k+'a');
                if(!book[s])
                {
                    cout<<s<<"\n";
                    return;
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