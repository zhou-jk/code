#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=505;
const int INF=1061109567;
int n;
int a[N][N];
int d[N][N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=1;j<=n;j++)
            a[i][j]=str[j-1]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i][j]==1) d[i][j]=1;
            else d[i][j]=INF;
        d[i][i]=0;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(k!=i)
                for(int j=1;j<=n;j++)
                    if(k!=j)
                        if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(d[i][j]>=INF)
            {
                cout<<"NO\n";
                return;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]==0)
            {
                if(d[i][j]%2!=0)
                {
                    cout<<"NO\n";
                    return;
                }
            }
    cout<<"YES\n";
    vector<pair<int,int>>edge;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i][j]) edge.emplace_back(i,j);
    int m=edge.size();
    cout<<m<<"\n";
    for(auto [u,v]:edge)
        cout<<u<<" "<<v<<"\n";
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