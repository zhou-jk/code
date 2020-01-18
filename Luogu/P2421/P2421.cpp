#include<iostream>
#include<cstdio>
using namespace std;
int person[16][4],n,m;
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int c=exgcd(b,a%b,x,y),k=x;
    x=y,y=k-a/b*y;
    return c;
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int check(int a)
{
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int c=person[i][1]-person[j][1],p=person[j][2]-person[i][2];
            int x=0,b=a,y=0,t=gcd(p,b);
            if(c%t==0)
            {
                p/=t,c/=t,b/=t;
                exgcd(p,b,x,y);
                if(b<0) b=-b;
                x=((x*c)%b+b)%b;
                if(!x) x+=b;
                if(x<=min(person[i][3],person[j][3])) return false;
            }
        }   
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&person[i][1],&person[i][2],&person[i][3]),m=max(m,person[i][1]);
    for(int i=m;;i++)
        if(check(i))
        {
            printf("%d\n",i);
            return 0;
        }
    return 0;
}