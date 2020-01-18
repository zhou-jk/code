#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans=1e9;
struct Map
{
    int x,y;
}a[51];
struct Node
{
    int l,r,u,d;
    bool flag;
}p[5];
bool judge(Node a, int x, int y)
{
    if(x>=a.l&&x<=a.r&&y>=a.d&&y<=a.u) return true;
    return false;
}
bool check(Node a, Node b)
{
    if(judge(a,b.l,b.u)) return true;
    if(judge(a,b.l,b.d)) return true;
    if(judge(a,b.r,b.u)) return true;
    if(judge(a,b.r,b.d)) return true;
    return false;
}
void dfs(int step)
{
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        if(p[i].flag)
            for(int j=i+1;j<=m;j++)
                if(check(p[i],p[j])) return;
        sum+=(p[i].r-p[i].l)*(p[i].u-p[i].d);
    }
    if(sum>=ans) return;
    if(step>n)
    {
        ans=sum;
        return;
    }
    for(int i=1;i<=m;i++)
    {
        Node tmp=p[i];
        if(!p[i].flag)
        {
            p[i].flag=true;
            p[i].l=p[i].r=a[step].x;
            p[i].u=p[i].d=a[step].y;
            dfs(step+1);
            p[i]=tmp;
            break;
        }
        else 
        {
            p[i].r=max(p[i].r,a[step].x); 
            p[i].l=min(p[i].l,a[step].x);
            p[i].u=max(p[i].u,a[step].y); 
            p[i].d=min(p[i].d,a[step].y);
            dfs(step+1);
            p[i]=tmp;
        }    
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    dfs(1);
    printf("%d",ans);
    return 0;
}