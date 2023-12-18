#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<numeric>
using namespace std;
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    vector<vector<int>>a(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            a[i][j]--;
        }
    set<vector<int>>p;
    if(m<=18)
    {
        for(int s=1;s<(1<<m);s++)
        {
            vector<int>c(n);
            iota(c.begin(),c.end(),0);
            for(int i=0;i<m;i++)
                if((s>>i)&1)
                {
                    vector<int>to(n);
                    for(int j=0;j<n;j++)
                        to[j]=c[a[i][j]];
                    c=to;
                }
            p.insert(c);
        }
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            set<vector<int>>np=p;
            for(const vector<int> &c:p)
            {
                vector<int>to(n);
                for(int j=0;j<n;j++)
                    to[j]=c[a[i][j]];
                np.insert(to);
            }
            np.insert(a[i]);
            p=np;
        }
    }
    int ans=p.size();
    cout<<ans<<"\n";
    return 0;
}