#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
const int N=200005;
int n,q;
char s[N];
int prex[N],prey[N];
map<pair<int,int>,set<int>>pre,suf;
int sufx[N],sufy[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1];
    pre[{0,0}].insert(0);
    for(int i=1;i<=n;i++)
    {
        int dx=0,dy=0;
        if(s[i]=='U') dx=0,dy=1;
        else if(s[i]=='D') dx=0,dy=-1;
        else if(s[i]=='L') dx=-1,dy=0;
        else if(s[i]=='R') dx=1,dy=0;
        prex[i]=prex[i-1]+dx,prey[i]=prey[i-1]+dy;
        pre[{prex[i],prey[i]}].insert(i);
    }
    for(int i=n;i>=1;i--)
    {
        int dx=0,dy=0;
        if(s[i]=='U') dx=0,dy=1;
        else if(s[i]=='D') dx=0,dy=-1;
        else if(s[i]=='L') dx=-1,dy=0;
        else if(s[i]=='R') dx=1,dy=0;
        sufx[i]=sufx[i+1]+dx,sufy[i]=sufy[i+1]+dy;
        suf[{sufx[i],sufy[i]}].insert(i);
    }
    while(q--)
    {
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        if(pre.count({x,y})&&(*pre[{x,y}].begin()<l||*pre[{x,y}].rbegin()>r)) cout<<"YES\n";
        else if(suf.count({x-prex[l-1]+sufx[r+1],y-prey[l-1]+sufy[r+1]}))
        {
            auto &p=suf[{x-prex[l-1]+sufx[r+1],y-prey[l-1]+sufy[r+1]}];
            auto it=p.lower_bound(l);
            if(it!=p.end()&&*it<=r) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}