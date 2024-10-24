#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=105;
int n;
int a[N];
string s;
void solve()
{
    cin>>n;
    cin>>s;
    int c[2]={};
    deque<int>q;
    for(int i=1;i<=n;i++)
        a[i]=s[i-1]-'0',c[a[i]]++,q.emplace_back(a[i]);
    vector<int>res;
    int cur=0;
    while(!q.empty())
    {
        if(c[0]==0||c[1]==0)
        {
            cout<<-1<<"\n";
            return;
        }
        if(q.front()==q.back())
        {
            if(q.front()==0) res.emplace_back(q.size()+cur),q.emplace_back(0),q.emplace_back(1);
            else res.emplace_back(cur),q.emplace_front(1),q.emplace_front(0);
            c[0]++,c[1]++;
        }
        else
        {
            q.pop_front(),q.pop_back();
            cur++;
            c[0]--,c[1]--;
        }
    }
    int p=res.size();
    cout<<p<<"\n";
    for(int x:res)
        cout<<x<<" ";
    cout<<"\n";
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