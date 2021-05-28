#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=20;
int n,k;
string s[N+1];
int nxt[N+1][1<<N][2];
vector<vector<int>>f[2][1<<N];
int main()
{
    cin>>n>>k;
    for(int i=0;i<=n;i++)
        cin>>s[i];
    int cur=0;
    f[cur][0].resize(n+1);
    for(int i=0;i<=n;i++)
        f[cur][0][i].resize(1<<i);
    for(int i=0;i<=n;i++)
        for(int j=0;j<(1<<i);j++)
            if(s[i][j]=='1') f[cur][0][i][j]++;
    for(int i=0;i<=n;i++)
        for(int S=0;S<(1<<i);S++)
        {
            nxt[i][S][0]=-1;
            for(int j=i-1;j>=0;j--)
                if(!(S&(1<<j)))
                {
                    nxt[i][S][0]=j;
                    break;
                }
            nxt[i][S][1]=-1;
            for(int j=i-1;j>=0;j--)
                if(S&(1<<j))
                {
                    nxt[i][S][1]=j;
                    break;
                }
        }
    int la=0,ans=0;
    for(int ls=0;ls<=n;ls++)
    {
        for(int S=0;S<(1<<ls);S++)
            f[cur^1][S].clear();
        if(ls+1<=n)
        {
            for(int S=0;S<(1<<(ls+1));S++)
            {
                f[cur^1][S].resize(n-(ls+1)+1);
                for(int lt=0;lt<=n-(ls+1);lt++)
                    f[cur^1][S][lt].resize(1<<lt);
            }
        }
        for(int S=0;S<(1<<ls);S++)
            for(int lt=n-ls;lt>=0;lt--)
                for(int T=(1<<lt)-1;T>=0;T--)
                    if(f[cur][S][lt][T])
                    {
                        int v=f[cur][S][lt][T];
                        if(lt==0)
                        {
                            if(v>=k)
                            {
                                if(ls>la) la=ls,ans=S;
                                else if(ls==la) ans=min(ans,S);
                            }
                            continue;
                        }
                        int f0=nxt[lt][T][0];
                        if(f0!=-1) 
                        {
                            int s0=S<<1,t0=T&((1<<f0)-1);
                            f[cur^1][s0][f0][t0]+=v;
                        }
                        int f1=nxt[lt][T][1];
                        if(f1!=-1)
                        {
                            int s1=(S<<1)|1,t1=T&((1<<f1)-1);
                            f[cur^1][s1][f1][t1]+=v;
                        }
                        f[cur][S][0][0]+=v;
                    }
        cur^=1;
    }
    for(int i=la-1;i>=0;i--)
        if(ans&(1<<i)) cout<<"1";
        else cout<<"0";
    return 0;
}