#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
vector<int>G[N];
int in[N];
void solve()
{
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    fill(in+1,in+n+1,0);
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=n;i++)
    {
        G[i].emplace_back(b[i]);
        in[b[i]]++;
    }
    vector<int>in0;
    for(int i=1;i<=n;i++)
        if(in[i]==0) in0.emplace_back(i);
    vector<int>moved;
    for(int u=1;u<=n;u++)
        if(in[b[u]]>=2)
        {
            int v=in0.back();
            int t=0;
            if(u==v) continue;
            in[b[u]]--;
            b[u]=v;
            in[b[u]]++;
            in0.pop_back();
            moved.emplace_back(u);
        }
    vector<int>me;
    for(int i=1;i<=n;i++)
        if(b[i]==i) me.emplace_back(i);
    if((int)me.size()>1)
    {
        for(int i=0;i+1<(int)me.size();i++)
            b[me[i]]=me[i+1];
        b[me.back()]=me.front();
    }
    else if((int)me.size()==1)
    {
        if(!moved.empty()) b[me[0]]=b[moved[0]],b[moved[0]]=me[0];
        else
        {
            if(me[0]!=1) b[me[0]]=b[1],b[1]=me[0];
            else b[me[0]]=b[2],b[2]=me[0];
        }
    }
    int k=0;
    for(int i=1;i<=n;i++)
        if(a[i]==b[i]) k++;
    printf("%d\n",k);
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}