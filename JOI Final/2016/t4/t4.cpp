#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k;
char s[N];
map<pair<int,int>,int>book;
int cnt;
vector<pair<int,int>>seg[N],seg1[N];
long long solve(const vector<pair<int,int>>&a,const vector<pair<int,int>>&b,const vector<pair<int,int>>&c,const vector<pair<int,int>>&d)
{
    function<vector<pair<int,int>>(const vector<pair<int,int>> &)>convert=[=](const vector<pair<int,int>> &p)
    {
       vector<pair<int,int>>notp;
        if(-n-k<=p.front().first-1) notp.emplace_back(-n-k,p.front().first-1);
        for(int i=1;i<(int)p.size();i++)
            if(p[i-1].second+1<=p[i].first-1) notp.emplace_back(p[i-1].second+1,p[i].first-1);
        if(p.back().second+1<=n+k) notp.emplace_back(p.back().second+1,n+k);
        return notp;
    };
    function<vector<pair<int,int>>(const vector<pair<int,int>> &,const vector<pair<int,int>> &)>merge_seg=[](const vector<pair<int,int>> &a,const vector<pair<int,int>> &b)
    {
        vector<pair<int,int>>v;
        for(int i=0,j=-1;i<(int)a.size();i++)
        {
            while(j+1<(int)b.size()&&b[j+1]<a[i]) v.emplace_back(b[j+1]),j++;
            v.emplace_back(a[i]);
        }
        vector<pair<int,int>>nowab;
        auto [l,r]=v[0];
        for(int i=1;i<(int)v.size();i++)
        {
            auto [ll,rr]=v[i];
            if(ll<=r+1) r=max(r,rr);
            else
            {
                nowab.emplace_back(l,r);
                l=ll,r=rr;
            }
        }
        nowab.emplace_back(l,r);
        return nowab;
    };
    vector<pair<int,int>>seg=convert(merge_seg(merge_seg(convert(a),convert(b)),merge_seg(convert(c),convert(d))));
    long long res=0;
    for(auto [x,y]:seg)
        res+=y-x+1;
    return res;
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    int tx=0,ty=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='E') tx++;
        else if(s[i]=='N') ty++;
        else if(s[i]=='W') tx--;
        else if(s[i]=='S') ty--;
    if(tx==0&&ty==0)
    {
        static set<pair<int,int>>pos;
        for(int i=1;i<=n;i++)
        {
            static int x=0,y=0;
            if(s[i]=='E') x++;
            else if(s[i]=='N') y++;
            else if(s[i]=='W') x--;
            else if(s[i]=='S') y--;
            pos.insert({x,y});
        }
        int ans=0;
        for(auto [x,y]:pos)
        {
            if(pos.find({x+1,y})!=pos.end()&&pos.find({x,y+1})!=pos.end()&&pos.find({x+1,y+1})!=pos.end()) ans++;
        }
        printf("%d",ans);
        return 0;
    }
    if(tx==0)
    {
        for(int i=1;i<=n;i++)
            if(s[i]=='E') s[i]='N';
            else if(s[i]=='N') s[i]='E';
            else if(s[i]=='W') s[i]='S';
            else if(s[i]=='S') s[i]='W';
        swap(tx,ty);
    }
    if(tx<0)
    {
        for(int i=1;i<=n;i++)
            if(s[i]=='E') s[i]='W';
            else if(s[i]=='W') s[i]='E';
        tx=-tx;
    }
    if(ty<0)
    {
        for(int i=1;i<=n;i++)
            if(s[i]=='N') s[i]='S';
            else if(s[i]=='S') s[i]='N';
        ty=-ty;
    }
    book[{0,0}]=++cnt;
    seg[book[{0,0}]].emplace_back(1,k);
    for(int i=1;i<=n;i++)
    {
        static int x=0,y=0;
        if(s[i]=='E') x++;
        else if(s[i]=='N') y++;
        else if(s[i]=='W') x--;
        else if(s[i]=='S') y--;
        int d=x/tx;
        int ax=x-d*tx,ay=y-d*ty;
        if(ax<0) d--,ax+=tx,ay+=ty;
        if(book.find({ax,ay})==book.end()) book[{ax,ay}]=++cnt;
        seg[book[{ax,ay}]].emplace_back(d+1,d+k);
    }
    for(auto it:book)
    {
        vector<pair<int,int>> v=seg[it.second];
        sort(v.begin(),v.end());
        vector<pair<int,int>>now,now1;
        auto [l,r]=v[0];
        for(int i=1;i<(int)v.size();i++)
        {
            auto [ll,rr]=v[i];
            if(ll<=r+1) r=max(r,rr);
            else
            {
                now.emplace_back(l,r);
                now1.emplace_back(l-1,r-1);
                l=ll,r=rr;
            }
        }
        now.emplace_back(l,r);
        now1.emplace_back(l-1,r-1);
        seg[it.second]=now;
        seg1[it.second]=now1;
    }
    long long ans=0;
    for(auto it:book)
    {
        auto [x1,y1]=it.first;
        int x2=(x1+1)%tx,y2=y1-(x1+1==tx)*ty;
        int x3=x1,y3=y1+1;
        int x4=(x1+1)%tx,y4=y1+1-(x1+1==tx)*ty;
        if(book.find({x2,y2})!=book.end()&&book.find({x3,y3})!=book.end()&&book.find({x4,y4})!=book.end()) ans+=solve(seg[it.second],x1+1==tx?seg1[book[{x2,y2}]]:seg[book[{x2,y2}]],seg[book[{x3,y3}]],x1+1==tx?seg1[book[{x4,y4}]]:seg[book[{x4,y4}]]);
    }
    printf("%lld",ans);
    return 0;
}