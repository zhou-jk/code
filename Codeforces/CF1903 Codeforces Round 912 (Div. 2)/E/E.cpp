#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=100005;
int n;
int x[N],y[N];
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>x[i]>>y[i];
    set<int>p[2];
    int c[2]={};
    for(int i=1;i<=n;i++)
    {
        c[(x[i]+y[i])%2]++;
        p[(x[i]+y[i])%2].insert(i);
    }
    int t=(x[0]+y[0])%2;
    if(c[t]>=c[t^1])
    {
        cout<<"First"<<endl;
        while(true)
        {
            if(!p[t^1].empty())
            {
                cout<<*p[t^1].begin()<<endl;
                p[t^1].erase(p[t^1].begin());
            }
            else if(!p[t].empty())
            {
                cout<<*p[t].begin()<<endl;
                p[t].erase(p[t].begin());
            }
            if(p[0].empty()&&p[1].empty()) break;
            int j;
            cin>>j;
            p[(x[j]+y[j])%2].erase(p[(x[j]+y[j])%2].find(j));
            if(p[0].empty()&&p[1].empty()) break;
        }
    }
    else
    {
        cout<<"Second"<<endl;
        while(true)
        {
            int j;
            cin>>j;
            p[(x[j]+y[j])%2].erase(p[(x[j]+y[j])%2].find(j));
            if(p[0].empty()&&p[1].empty()) break;
            if(!p[t].empty())
            {
                cout<<*p[t].begin()<<endl;
                p[t].erase(p[t].begin());
            }
            else if(!p[t^1].empty())
            {
                cout<<*p[t^1].begin()<<endl;
                p[t^1].erase(p[t^1].begin());
            }
            if(p[0].empty()&&p[1].empty()) break;
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