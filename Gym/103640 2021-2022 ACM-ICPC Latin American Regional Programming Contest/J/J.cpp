#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=100005;
int w,h;
int n;
struct Point
{
    int x,y;
}p[N][2],pp[N][2];
vector<tuple<int,int,int>>d;
void solve()
{
    d.clear();
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
        {
            if(p[i][j].x==w&&(p[i][j^1].x!=w||p[i][j^1].y<p[i][j].y)) d.emplace_back(p[i][j].y,i,j);
        }
    sort(d.begin(),d.end());
    int mnl=w+1,mxu=-1,mxr=-1;
    int pre=-1;
    vector<pair<int,int>>seg;
    for(auto [v,i,j]:d)
    {
        if(p[i][j^1].x==w) 
        {
            if(p[i][j^1].y<pre)
            {
                cout<<"N";
                exit(0); 
            }
            seg.emplace_back(p[i][j^1].y,v);
        }
        if(p[i][j^1].y==0)
        {
            if(mxu!=-1||mxr!=-1)
            {
                cout<<"N";
                exit(0);
            }
            if(p[i][j^1].x>mnl)
            {
                cout<<"N";
                exit(0);
            }
            else mnl=p[i][j^1].x;
            pre=v;
        }
        if(p[i][j^1].x==0)
        {
            if(mxr!=-1)
            {
                cout<<"N";
                exit(0);
            }
            if(p[i][j^1].y<mxu)
            {
                cout<<"N";
                exit(0);
            }
            else mxu=p[i][j^1].y;
            pre=v;
        }
        if(p[i][j^1].y==h)
        {
            if(p[i][j^1].x<mxr)
            {
                cout<<"N";
                exit(0);
            }
            else mxr=p[i][j^1].x;
            pre=v;
        }
    }
    sort(seg.begin(),seg.end());
    for(int i=1;i<(int)seg.size();i++)
        if(seg[i].first<seg[i-1].second&&seg[i].second>seg[i-1].second)
        {
            cout<<"N";
            exit(0);
        }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>w>>h;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>pp[i][0].x>>pp[i][0].y>>pp[i][1].x>>pp[i][1].y;
    vector<int> ud,lr;
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
        {
            if(pp[i][j].x==0&&pp[i][j^1].x==w) ud.emplace_back(i);
            if(pp[i][j].y==0&&pp[i][j^1].y==h) lr.emplace_back(i);
        }
    if(!ud.empty()&&!lr.empty())
    {
        if((int)ud.size()>1||(int)lr.size()>1||ud[0]!=lr[0])
        {
            cout<<"N";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            p[i][j]=pp[i][j];
    solve();
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            p[i][j].x=w-pp[i][j].x,p[i][j].y=h-pp[i][j].y;
    solve();
    swap(w,h);
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            swap(pp[i][j].x,pp[i][j].y);
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            p[i][j]=pp[i][j];
    solve();
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            p[i][j].x=w-pp[i][j].x,p[i][j].y=h-pp[i][j].y;
    solve();
    cout<<"Y";
    return 0;
}