#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
const int BASE=233;
const int MOD1=1000000007,MOD2=1000000009;
int n,m,q;
string s[N];
pair<int,int> pw[N];
pair<int,int> operator+(const pair<int,int> &a,const int &b)
{
    pair<int,int> c=make_pair(a.first+b,a.second+b);
    if(c.first>=MOD1) c.first-=MOD1;
    if(c.second>=MOD2) c.second-=MOD2;
    return c;
}
pair<int,int> operator*(const pair<int,int> &a,const int &b)
{
    pair<int,int> c=make_pair((long long)a.first*b%MOD1,(long long)a.second*b%MOD2);
    return c;
}
pair<int,int> operator-(const pair<int,int> &a,const pair<int,int> &b)
{
    pair<int,int> c=make_pair(a.first-b.first,a.second-b.second);
    if(c.first<0) c.first+=MOD1;
    if(c.second<0) c.second+=MOD2;
    return c;
}
pair<int,int> operator*(const pair<int,int> &a,const pair<int,int> &b)
{
    pair<int,int> c=make_pair((long long)a.first*b.first%MOD1,(long long)a.second*b.second%MOD2);
    return c;
}
vector<vector<pair<int,int>>>hsh;
pair<int,int> get_val(int id,int l,int r)
{
    pair<int,int> res=hsh[id][r];
    if(l-1>=0) res=res-hsh[id][l-1]*pw[r-l+1];
    return res;
}
vector<vector<pair<int,int>>>val;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        s[i]=s[i]+s[i];
    pw[0]=make_pair(1,1);
    for(int i=1;i<=m+m;i++)
        pw[i]=pw[i-1]*BASE;
    hsh.clear();
    hsh.resize(n+1);
    for(int i=1;i<=n;i++)
        hsh[i].resize(m+m);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m+m;j++)
            if(j==0) hsh[i][j]=make_pair((int)(s[i][j]-'a'+1),(int)(s[i][j]-'a'+1));
            else hsh[i][j]=hsh[i][j-1]*BASE+(int)(s[i][j]-'a'+1);
    }
    val.clear();
    val.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        val[i].resize(m);
        for(int j=0;j<m;j++)
            val[i][j]=get_val(i,j,j+m-1);
        sort(val[i].begin(),val[i].end());
    }
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(val[x][0]==val[y][0]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}