#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
int n;
struct Operator
{
    int op;
    int x1,y1,x2,y2,r;
    char col;
}p[N];
int tot;
char query(int u,int v)
{
    for(int i=tot;i>=1;i--)
        if(p[i].op==1)
        {
            int x=p[i].x1,y=p[i].y1,r=p[i].r;
            if((long long)(u-x)*(u-x)+(long long)(v-y)*(v-y)<=(long long)r*r) return p[i].col;
        }
        else if(p[i].op==2)
        {
            int x1=p[i].x1,y1=p[i].y1,x2=p[i].x2,y2=p[i].y2;
            if(x1<=u&&u<=x2&&y1<=v&&v<=y2) return p[i].col;
        }
    return '.';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s=="Circle")
        {
            p[++tot].op=1;
            int x,y,r;
            char col;
            cin>>x>>y>>r>>col;
            p[tot].x1=x,p[tot].y1=y,p[tot].r=r,p[tot].col=col;
        }
        else if(s=="Rectangle")
        {
            p[++tot].op=2;
            int x1,y1,x2,y2;
            char col;
            cin>>x1>>y1>>x2>>y2>>col;
            p[tot].x1=x1,p[tot].y1=y1,p[tot].x2=x2,p[tot].y2=y2,p[tot].col=col;
        }
        else if(s=="Render")
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            for(int j=y2;j>=y1;j--)
            {
                for(int i=x1;i<=x2;i++)
                    cout<<query(i,j);
                cout<<"\n";
            }

        }
    }
    return 0;
}