#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n,q;
long long cnt[26][26];
long long sum;
struct Trie
{
    int ch[N][26],tot;
    int s[N];
    Trie():tot(1){}
    void insert(const string &str)
    {
        int u=1;
        for(int i=0;i<(int)str.size();i++)
        {
            int c=str[i]-'a';
            if(!ch[u][c]) ch[u][c]=++tot;
            for(int d=0;d<26;d++)
                cnt[c][d]+=s[ch[u][d]];
            s[u]++;
            u=ch[u][c];
        }
        for(int d=0;d<26;d++)
            sum+=s[ch[u][d]];
        s[u]++;
        return;
    }
}T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        T.insert(s);
    }
    while(q--)
    {
        string t;
        cin>>t;
        long long ans=sum;
        for(int i=0;i<26;i++)
            for(int j=i+1;j<26;j++)
                ans+=cnt[t[i]-'a'][t[j]-'a'];
        cout<<ans<<"\n";
    }
    return 0;
}