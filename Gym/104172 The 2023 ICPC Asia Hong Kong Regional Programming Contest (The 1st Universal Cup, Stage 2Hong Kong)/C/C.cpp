#include<iostream>
#include<cstdio>
#include<map>
#include<numeric>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
const int N=1005;
int n,m;
string a[N];
void solve()
{
    cin>>n>>m;
    if(n*m%2==1)
    {
        cout<<"NO\n";
        return;
    }
    if(n<=30&&(1<<n)<m)
    {
        cout<<"NO\n";
        return;
    }
    if(m<=30&&(1<<m)<n)
    {
        cout<<"NO\n";
        return;
    }
    bool rev=false;
    if(m%2!=0) rev=true,swap(n,m);
    for(int i=1;i<=n;i++)
        a[i].resize(m+1);
    int k=ceil(log2(m)),v=0;
    static bool vis[N*2];
    for(int i=0;i<=(1<<k);i++)
        vis[i]=false;
    auto getstatusrev=[=](int x)
    {
        return (~x)&((1<<k)-1);
    };
    int cur=0;
    for(int j=1;j<=m;j+=2)
    {
        int val;
        while(cur<k&&(vis[1<<cur]||vis[getstatusrev(1<<cur)])) cur++;
        if(cur<k) val=1<<cur,cur++;
        else
        {
            while(vis[v]||vis[getstatusrev(v)]) v++;
            val=v;
        }
        vis[val]=vis[getstatusrev(val)]=true;
        for(int i=1;i<=k;i++)
            a[i][j]=((val>>(i-1))&1)+'0',a[i][j+1]=(((val>>(i-1))&1)^1)+'0';
    }
    if(k<n)
    {
        sort(a+1,a+k+1);
        map<string,bool>book;
        for(int i=1;i<=k;i++)
            book[a[i]]=true;
        auto getrev=[=](string s)
        {
            string t;
            t.resize(m+1);
            for(int i=1;i<=m;i++)
                if(s[i]=='1') t[i]='0';
                else t[i]='1';
            return t;
        };
        for(int i=k+2;i<=n;i+=2)
        {
            if(i-2>k)
            {
                for(int j=1;j<=m;j++)
                    a[i][j]=a[i-2][j];
                bool flag=false;
                do
                {
                    a[i][m]++;
                    for(int j=m;j>=1;j--)
                        if(a[i][j]=='2')
                        {
                            if(j-1>=1) a[i][j-1]++;
                            else
                            {
                                flag=true;
                                break;
                            }
                            a[i][j]='0';
                        }
                        else break;
                    if(flag) break;
                }
                while(book.count(a[i])||book.count(getrev(a[i])));
                if(!flag) a[i-1]=getrev(a[i]);
                else
                {
                    for(int j=1;j<=m;j++)
                        a[i][j]='0';
                    while(book.count(a[i]))
                    {
                        a[i][m]++;
                        for(int j=m;j>=1;j--)
                            if(a[i][j]=='2')
                            {
                                if(j-1>=1) a[i][j-1]++;
                                a[i][j]='0';
                            }
                            else break;
                    }
                    for(int j=1;j<=m;j++)
                        a[i-1][j]=a[i][j];
                    do
                    {
                        a[i-1][m]++;
                        for(int j=m;j>=1;j--)
                            if(a[i-1][j]=='2')
                            {
                                if(j-1>=1) a[i-1][j-1]++;
                                a[i-1][j]='0';
                            }
                            else break;
                    }
                    while(book.count(a[i-1]));
                }
            }
            else
            {
                for(int j=1;j<=m;j++)
                    a[i][j]='0';
                while(book.count(a[i])||book.count(getrev(a[i])))
                {
                    a[i][m]++;
                    for(int j=m;j>=1;j--)
                        if(a[i][j]=='2')
                        {
                            if(j-1>=1) a[i][j-1]++;
                            a[i][j]='0';
                        }
                        else break;
                }
                a[i-1]=getrev(a[i]);
            }
            book[a[i]]=book[a[i-1]]=true;
        }
        if((n-k)%2==1)
        {
            static int p[N];
            static mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
            iota(p+1,p+m+1,1);
            do
            {
                shuffle(p+1,p+m+1,rnd);
                for(int i=1;i<=m/2;i++)
                    a[n][p[i]]='1';
                for(int i=m/2+1;i<=m;i++)
                    a[n][p[i]]='0';
            }
            while(book.count(a[n]));
        }
    }
    cout<<"YES\n";
    if(rev)
    {
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
                cout<<a[i][j];
            cout<<"\n";
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<a[i][j];
            cout<<"\n";
        }
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