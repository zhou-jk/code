#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct Kuhn_Munkres
{
    static const int N=405;
    static const int INF=1061109567;
    int n;
    int a[N][N];
    int hl[N],hr[N],slk[N];
    int fl[N],fr[N];
    bool vl[N],vr[N];
    int pre[N];
    queue<int>q;
    bool check(int i)
    {
        vl[i]=1;
        if(fl[i]!=0)
        {
            q.push(fl[i]);
            vr[fl[i]]=true;
            return true;
        }
        while(i!=0)
            fl[i]=pre[i],swap(i,fr[fl[i]]);
        return false;
    }
    void bfs(int s)
    {
        for(int i=1;i<=n;i++)
            slk[i]=INF;
        fill(vl+1,vl+n+1,false);
        fill(vr+1,vr+n+1,false);
        while(!q.empty())
            q.pop();
        q.push(s);
        vr[s]=true;
        while(true)
        {
            while(!q.empty())
            {
                int j=q.front();
                q.pop();
                for(int i=1;i<=n;i++)
                {
                    int d=hl[i]+hr[j]-a[i][j]; 
                    if(!vl[i]&&slk[i]>=d)
                    {
                        pre[i]=j;
                        if(d) slk[i]=d;
                        else if(!check(i)) return;
                    }
                }
            }
            int d=INF;
            for(int i=1;i<=n;i++)
                if(!vl[i]&&d>slk[i]) d=slk[i];
            for(int i=1;i<=n;i++)
            {
                if(vl[i]) hl[i]+=d;
                else slk[i]-=d;
                if(vr[i]) hr[i]-=d;
            }
            for(int i=1;i<=n;i++)
                if(!vl[i]&&!slk[i]&&!check(i)) return;
        }
    }
    void solve()
    {
        fill(fl+1,fl+n+1,0);
        fill(fr+1,fr+n+1,0);
        fill(hr+1,hr+n+1,0);
        for(int i=1;i<=n;i++)
            hl[i]=*max_element(a[i]+1,a[i]+n+1);
        for(int j=1;j<=n;j++)
            bfs(j);
        return;
    }
}km;