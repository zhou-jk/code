#include<iostream>
#include<cstdio>
#include<cassert>
#include<tuple>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1005;
int n;
int x[N],y[N];
int maxx[N],maxy[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
    vector<tuple<int,int,int>>res;
    for(int i=1;i<n;i++)
        maxx[y[i]]=max(maxx[y[i]],x[i]),maxy[x[i]]=max(maxy[x[i]],y[i]);
    for(int i=n;i>1;i--)
        if(maxy[i]==0)
        {
            res.emplace_back(1,1,i);
            for(int j=1;j<n;j++)
                if(x[j]==1) x[j]=i;
            break;
        }
    for(int i=1;i<n;i++)
        if(maxx[i]==0)
        {
            res.emplace_back(2,i,n);
            for(int j=1;j<n;j++)
                if(y[j]==n) y[j]=i;
            break;
        }
    fill(maxx+1,maxx+n+1,0);
    fill(maxy+1,maxy+n+1,0);
    for(int i=1;i<n;i++)
        maxx[y[i]]=max(maxx[y[i]],x[i]),maxy[x[i]]=max(maxy[x[i]],y[i]);
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &a,const int &b){return maxy[a]<maxy[b];});
    static int pos[N],now[N];
    iota(pos+1,pos+n+1,1);
    iota(now+1,now+n+1,1);
    for(int i=1;i<=n;i++)
        if(now[i]!=id[i])
        {
            int l=pos[now[i]],r=pos[id[i]];
            res.emplace_back(1,l,r);
            swap(pos[now[i]],pos[id[i]]);
            swap(now[l],now[r]);
        }
    for(int i=1;i<n;i++)
        assert(maxy[now[i]]<=maxy[now[i+1]]);
    int m=res.size();
    printf("%d\n",m);
    for(auto [t,i,j]:res)
        printf("%d %d %d\n",t,i,j);
    return 0;
}