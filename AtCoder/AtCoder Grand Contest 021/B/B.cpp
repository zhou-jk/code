#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
typedef pair<double,double> Point;
#define x first
#define y second
const int N=105;
const double PI=acos(-1);
int n;
Point p[N];
double slope(Point a,Point b)
{
    return (b.y-a.y)/(b.x-a.x);
}
double dis(Point a,Point b)
{
    return sqrt((b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x));
}
double ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        p[i]={x,y};
    }
    vector<int>t;
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &a,const int &b){return p[a].x<p[b].x;});
    static int s[N];
    int top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>1&&((p[s[top]].x==p[id[i]].x&&p[s[top]].y<p[id[i]].y)||slope(p[s[top-1]],p[s[top]])<slope(p[s[top]],p[id[i]]))) top--;
        s[++top]=id[i];
    }
    for(int i=1;i<=top;i++)
        t.emplace_back(s[i]);
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &a,const int &b){return p[a].x<p[b].x;});
    top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>1&&((p[s[top]].x==p[id[i]].x&&p[s[top]].y>p[id[i]].y)||slope(p[s[top-1]],p[s[top]])>slope(p[s[top]],p[id[i]]))) top--;
        s[++top]=id[i];
    }
    if(s[top]!=t.back()) t.emplace_back(s[top]);
    for(int i=top-1;i>=2;i--)
        t.emplace_back(s[i]);
    if(s[1]!=t.front()) t.emplace_back(s[1]);
    int m=t.size();
    for(int i=0;i<m;i++)
    {
        int l=i-1>=0?i-1:m-1,r=i+1<m?i+1:0;
        double a=dis(p[t[l]],p[t[i]]),b=dis(p[t[i]],p[t[r]]),c=dis(p[t[l]],p[t[r]]);
        ans[t[i]]=(PI-acos((a*a+b*b-c*c)/(2*a*b)))/(2*PI);
    }
    for(int i=1;i<=n;i++)
        printf("%.6lf\n",ans[i]);
    return 0;
}