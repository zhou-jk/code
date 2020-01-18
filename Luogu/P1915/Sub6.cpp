#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define w w0
#define v V
#define tot_t T
// #define x x0
// #define y y0
#define max Max
const int max=10000000;
const double zero=1e-6;
struct ty1
{
    double w,x,y,p,q;
};
struct ty2
{
    double t,x,y;
    int s;
};
double w,x,y,v,tot_t,now_t,ans,d;
int n,i,j,t,tot;
ty1 f[10001];
bool get[10001];
ty2 step[10001];
double dis(int i,double x,double y)
{
    return (sqrt(sqrt(x-f[i].x)+sqrt(y-f[i].y)));
}
int main()
{
    freopen("nemo9.in","r",stdin);
    freopen("temp.txt","w",stdout);
    scanf("%lf%lf%lf%lf%lf",&w,&v,&tot_t,&x,&y);
    scanf("%d",&n);
    ans=0,tot=0,now_t=0;
    memset(get,false,sizeof(get));
    for(int i=1;i<=n;i++)
        scanf("%lf%lf%lf%lf%lf",&f[i].w,&f[i].x,&f[i].y,&f[i].p,&f[i].q);
    for(int i=1;i<=n;i++)
    {
        d=max;t=0;
        for(int j=1;j<=n;j++)
            if(!get[j]&&f[j].w-w<zero&&dis(j,x,y)<d)
            {
                t=j,d=dis(j,x,y);
            }
        if(t==0) break;
        now_t=now_t+dis(t,x,y)/v;
        if(now_t-tot_t>zero) break;
        get[t]=true;
        w=w+f[t].w;
        ans=ans+f[t].w;
        tot++;
        step[tot].t=now_t;
        step[tot].s=t;
        step[tot].x=f[t].x;
        step[tot].y=f[t].y;
        x=f[t].x,y=f[t].y;
    }
    printf("%d\n",tot);
    printf("%.6lf\n",ans);
    for(int i=1;i<=tot;i++)
        printf("%.6lf %.6lf %.6lf %d\n",step[i].t,step[i].x,step[i].y,step[i].s);
    return 0;
}