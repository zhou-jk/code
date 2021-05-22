#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
const int M=100000;
int n;
int l[N],r[N];
long long solve(int s,bool flag)
{
    vector<int>posl[N+N],posr[N+N];
    for(int i=1;i<=n;i++)
        posl[l[i]].emplace_back(i),posr[r[i]].emplace_back(i);
    static bool vis[N];
    fill(vis+1,vis+n+1,false);
    int i=0,j=M+M;
    int now=s;
    long long ans=0;
    for(int k=1;k<=n;k++)
    {
        if(flag)
        {
            while(j>now)
            {
                while(!posl[j].empty()&&vis[posl[j].back()]) posl[j].pop_back();
                if(posl[j].empty()) j--;
                else break;
            }
            if(j<=now) break;
            ans+=j-now,now=j;
            vis[posl[j].back()]=true;
        }
        else
        {
            while(i<now)
            {
                while(!posr[i].empty()&&vis[posr[i].back()]) posr[i].pop_back();
                if(posr[i].empty()) i++;
                else break;
            }
            if(i>=now) break;
            ans+=now-i,now=i;
            vis[posr[i].back()]=true;
        }
        flag=!flag;
    }
    ans+=abs(now-s);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        l[i]+=M,r[i]+=M;
    }
    printf("%lld",max(solve(M,false),solve(M,true)));
    return 0;
}