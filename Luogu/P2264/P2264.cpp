#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,ans;
map<string,bool> book,vis;
string s,t;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<s.size();j++)
            if(s[j]<'a') s[j]+='a'-'A';
        book[s]=1;
    }
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',') s[i]=' ';
        if(s[i]!='.'&&s[i]!=' '&&s[i]<'a') s[i]+='a'-'A';
    }
    int pos=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' '||s[i]=='.')
        {
            t=s.substr(pos,i-pos);
            pos=i+1;
            if(!vis[t]) vis[t]=1,ans+=book[t];
        }
        if(s[i]=='.') vis.clear();
    }
    printf("%d",ans);
    return 0;
}