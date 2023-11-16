#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
string s;
vector<int>manacher(const string &s)
{
    int n=s.size();
    vector<int>d(n);
    int l=0,r=-1;
    for(int i=0;i<n;i++)
    {
        int k=(i>r)?1:min(d[l+r-i],r-i+1);
        while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])
            k++;
        d[i]=k;
        k--;
        if(i+k>r) l=i-k,r=i+k;
    }
    return d;
}
void solve()
{
    cin>>s;
    n=s.size();
    string t="";
    for(int i=0;i<n;i++)
    {
        t+=s[i];
        if(i+1<n) t+='#';
    }
    vector<int>d=manacher(t);
    vector<int>cnt(26,0);
    for(int i=0;i<n-1;i++)
    {
        if(cnt[s[i]-'a']) break;
        cnt[s[i]-'a']++;
        int p=i+n,len=p-(i+1)*2+1;
        if(d[p]>=len)
        {
            cout<<"HE\n";
            return;
        }
    }
    cout<<"NaN\n";
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