#include<iostream>
#include<cstdio>
#include<functional>
using namespace std;
const int N=20;
int n,q;
int a[1<<N];
int f[1<<N],g[1<<N];
vector<int>getsubmack(int s,vector<int> &pos)
{
    int m=pos.size();
    vector<int>res;
    function<void(int,int)> dfs=[&](int step,int now)
    {
        if(step>=m)
        {
            res.emplace_back(now);
            return;
        }
        dfs(step+1,now);
        dfs(step+1,now|(1<<pos[step]));
        return;
    };
    dfs(0,s);
    return res;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<(1<<n);i++)
        scanf("%1d",&a[i]);
    for(int i=0;i<(1<<n);i++)
        f[i]=a[i];
    for(int j=0;j<n;j++)
        for(int i=0;i<(1<<n);i++)
            if(i&(1<<j)) f[i]+=f[i^(1<<j)];
    for(int i=0;i<(1<<n);i++)
        g[i]=a[((1<<n)-1)^i];
    for(int j=0;j<n;j++)
        for(int i=0;i<(1<<n);i++)
            if(i&(1<<j)) g[i]+=g[i^(1<<j)];
    while(q--)
    {
        char t[N];
        scanf("%s",t);
        int c0=0,c1=0,c2=0;
        vector<int>pos0,pos1,pos2;
        for(int i=0;i<n;i++)
            if(t[i]=='0') c0++,pos0.emplace_back(n-i-1);
            else if(t[i]=='1') c1++,pos1.emplace_back(n-i-1);
            else if(t[i]=='?') c2++,pos2.emplace_back(n-i-1);
        if(c2<=min(c0,c1))
        {
            int s=0;
            for(int i=0;i<n;i++)
                if(t[i]=='1') s|=1<<(n-i-1);
            vector<int>mask=getsubmack(s,pos2);
            int ans=0;
            for(int v:mask)
                ans+=a[v];
            printf("%d\n",ans);
        }
        else if(c1<=min(c0,c2))
        {
            int s=0;
            for(int i=0;i<n;i++)
                if(t[i]=='?') s|=1<<(n-i-1);
            vector<int>mask=getsubmack(s,pos1);
            int ans=0;
            for(int v:mask)
            {
                if((c1+c2-__builtin_popcount(v))%2==0) ans+=f[v];
                else ans-=f[v];
            }
            printf("%d\n",ans);
        }
        else if(c0<=min(c1,c2))
        {
            int s=0;
            for(int i=0;i<n;i++)
                if(t[i]=='?') s|=1<<(n-i-1);
            vector<int>mask=getsubmack(s,pos0);
            int ans=0;
            for(int v:mask)
            {
                if((c0+c2-__builtin_popcount(v))%2==0) ans+=g[v];
                else ans-=g[v];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}