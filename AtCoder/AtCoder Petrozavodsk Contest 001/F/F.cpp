#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005,M=16;
const int INF=1061109567;
int n,m;
int a[N];
int f[1<<M];
int dfs(int s)
{
    if(f[s]!=-1) return f[s];
    if(s==0) return f[s]=0;
    int res=INF;
    for(int i=1;i<=m;i++)
        if(s&(1<<i))
            for(int j=i+1;j<=m;j++)
                if(s&(1<<j)) res=min(res,dfs(s^(1<<i)^(1<<j)^(1<<(i^j)))+1+((s>>(i^j))&1));
    return f[s]=res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        a[x]^=z,a[y]^=z;
    }
    static int c[M];
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    m=*max_element(a+1,a+n+1);
    int ans=0;
    int s=0;
    for(int i=1;i<=m;i++)
    {
        ans+=c[i]/2;
        if(c[i]&1) s|=1<<i;
    }
    memset(f,-1,sizeof(f));
    ans+=dfs(s);
    printf("%d",ans);
    return 0;
}