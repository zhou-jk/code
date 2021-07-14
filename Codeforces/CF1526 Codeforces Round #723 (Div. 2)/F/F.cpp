#include<iostream>
#include<cstdio>
#include<tuple>
#include<numeric>
using namespace std;
const int N=100005;
int T;
int n;
int query(int a,int b,int c)
{
    printf("? %d %d %d\n",a,b,c);
    fflush(stdout);
    int v;
    scanf("%d",&v);
    return v;
}
pair<int,int> findabc()
{
    for(int i=1;i<=13;i++)
        for(int j=i+1;j<=13;j++)
            for(int k=j+1;k<=13;k++)
                if(query(i,j,k)<=(n-4)/6) return {i,j};
    return {-1,-1};
}
int p[N],q[N];
void solve()
{
    scanf("%d",&n);
    auto [a,b]=findabc();
    for(int i=1;i<=n;i++)
        if(i!=a&&i!=b) q[i]=query(a,b,i);
    static int id[N];
    int A=0;
    for(int i=1;i<=n;i++)
        if(i!=a&&i!=b&&q[i]>q[A]) A=i;
    int B1=0,B2=0;
    for(int i=1;i<=n;i++)
        if(i!=a&&i!=b&&q[i]!=q[A])
        {
            if(q[i]==q[B1]) B2=i;
            else if(q[i]>q[B1]) B1=i,B2=0;
        }
    int B;
    if(B2)
    {
        if(query(A,B1,a)<=query(A,B2,a)&&query(A,B1,b)<=query(A,B2,b)) B=B1;
        else B=B2;
    }
    else B=B1;
    p[A]=1,p[B]=2;
    for(int i=1;i<=n;i++)
        if(i!=A&&i!=B) p[i]=query(A,B,i)+2;
    if(p[1]>p[2])
    {
        for(int i=1;i<=n;i++)
            p[i]=n-p[i]+1;
    }
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%d ",p[i]);
    printf("\n");
    fflush(stdout);
    int res;
    scanf("%d",&res);
    if(res==-1) exit(1);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}