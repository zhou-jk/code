#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=105;
const int MOD=998244353;
map<string,int>f,g;
string s;
int dfsg(const string &s);
int dfsf(const string &s)
{
    if(f[s]) return f[s];
    if(s=="") return f[s]=1;
    int len=s.size();
    int res=0;
    for(int i=1;i<=len;i++)
        res=(res+1LL*dfsg(s.substr(0,i))*dfsf(s.substr(i,len-i)))%MOD;
    return f[s]=res;
}
int dfsg(const string &s)
{
    if(g[s]) return g[s];
    if(s=="") return g[s]=1;
    if(s=="0") return g[s]=1;
    if(s=="1") return g[s]=2;
    int len=s.size();
    int res=0;
    for(int d=1;d<len;d++)
        if(len%d==0)
        {
            string t;
            for(int i=0;i<d;i++)
            {
                char x='1';
                for(int j=i;j<len;j+=d)
                    if(s[j]=='0')
                    {
                        x='0';
                        break;
                    }
                t+=x;
            }
            res=(res+dfsf(t))%MOD;
        }
    return g[s]=res;
}
int main()
{
    cin>>s;
    cout<<dfsf(s);
    return 0;
}