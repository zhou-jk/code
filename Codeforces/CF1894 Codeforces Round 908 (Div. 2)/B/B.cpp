#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=105;
int n;
int a[N],b[N];
int v[N],tot;
vector<int>pos[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    tot=0;
    for(int i=1;i<=n;i++)
        v[++tot]=a[i];
    sort(v+1,v+tot+1);
    tot=unique(v+1,v+tot+1)-v-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(v+1,v+tot+1,a[i])-v;
    for(int i=1;i<=tot;i++)
        pos[i].clear();
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    for(int i=1;i<=n;i++)
        b[i]=0;
    int flag=0;
    for(int i=1;i<=tot;i++)
        if((int)pos[i].size()>=2)
        {
            if(flag<2) flag++;
            b[pos[i][0]]=flag,b[pos[i][1]]=flag+1;
            for(int j=2;j<(int)pos[i].size();j++)
                b[pos[i][j]]=flag;
        }
        else if(!pos[i].empty()) b[pos[i][0]]=2;
    if(flag<2)
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
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
