#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-7;
int T;
double dfs(double c,double m,double p,double v,int t)
{
    double res=p*t;
    if(c>=eps)
    {
        if(c>=v)
        {
            if(m>=eps&&p>=eps) res+=c*dfs(c-v,m+v/2,p+v/2,v,t+1);
            else if(m>=eps) res+=c*dfs(c-v,m+v,p,v,t+1);
            else if(p>=eps) res+=c*dfs(c-v,m,p+v,v,t+1);
        }
        else
        {
            if(m>=eps&&p>=eps) res+=c*dfs(0,m+c/2,p+c/2,v,t+1);
            else if(m>=eps) res+=c*dfs(0,m+c,p,v,t+1);
            else if(p>=eps) res+=c*dfs(0,m,p+c,v,t+1);
        }
    }
    if(m>=eps)
    {
        if(m>=v)
        {
            if(c>=eps&&p>=eps) res+=m*dfs(c+v/2,m-v,p+v/2,v,t+1);
            else if(c>=eps) res+=m*dfs(c+v,m-v,p,v,t+1);
            else if(p>=eps) res+=m*dfs(c,m-v,p+v,v,t+1);
        }
        else
        {
            if(c>=eps&&p>=eps) res+=m*dfs(c+m/2,0,p+m/2,v,t+1);
            else if(c>=eps) res+=m*dfs(c+m,0,p,v,t+1);
            else if(p>=eps) res+=m*dfs(c,0,p+m,v,t+1);
        }
    }
    return res;
}
double c,m,p,v;
void solve()
{
    scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
    double ans=dfs(c,m,p,v,1);
    printf("%.7lf\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}