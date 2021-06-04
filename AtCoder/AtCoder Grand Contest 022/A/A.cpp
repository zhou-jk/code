#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=26;
int n;
string s;
int cnt[N];
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    if(n<26)
    {
        cout<<s;
        for(int i=0;i<26;i++)
            if(cnt[i]==0)
            {
                cout<<(char)(i+'a');
                break;
            }
    }
    else
    {
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<s[i+1])
            {
                cout<<s.substr(0,i);
                char now=s[i+1];
                for(int j=i+1;j<=n-1;j++)
                    if(s[j]>s[i]) now=min(now,s[j]);
                cout<<now;
                return 0;
            }
        }
        cout<<"-1";
    }
    return 0;
}