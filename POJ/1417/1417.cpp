#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=305;
int n,p1,p2;
int fa[N<<1],dis[N<<1];
int find(int v)
{
    if(fa[v]==v) return v;
    int f=fa[v];
    fa[v]=find(fa[v]);
    dis[v]^=dis[f];
    return fa[v];
}
void merge(int u,int v,int w)
{
    int f1=find(u),f2=find(v);
    if(f1!=f2)
    {
        fa[f1]=f2;
        dis[f1]=(dis[v]-dis[u]+w+2)%2;
        return;
    }
    return;
}
int a[N<<1][2];
vector<int>b[N<<1][2];
bool book[N<<1];
int dp[N<<1][N],pre[N<<1][N];
int main()
{
    while(1)
    {
        scanf("%d%d%d",&n,&p1,&p2);
        if(n==0&&p1==0&&p2==0) return 0;
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=p1+p2;i++)
            fa[i]=i;
        for(int i=1;i<=n;i++)
        {
            int u,v,w;
            string s;
            scanf("%d%d",&u,&v);
            cin>>s;
            if(s=="yes") w=0;
            else if(s=="no") w=1;
            merge(u,v,w);
        }
        for(int i=1;i<=p1+p2;i++)
        {
            b[i][0].clear();
            b[i][1].clear();
            a[i][0]=a[i][1]=0;
        }
        memset(book,false,sizeof(book));
        int m=0;
        for(int i=1;i<=p1+p2;i++)
            if(!book[i])
            {
                m++;
                for(int j=i;j<=p1+p2;j++)
                    if(find(i)==find(j))
                    {
                        book[j]=true;
                        b[m][dis[j]].push_back(j);
                        a[m][dis[j]]++;
                    }
            }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
            for(int j=p1;j>=0;j--)
            {
                if(j>=a[i][0]&&dp[i-1][j-a[i][0]]) dp[i][j]+=dp[i-1][j-a[i][0]],pre[i][j]=0;
                if(j>=a[i][1]&&dp[i-1][j-a[i][1]]) dp[i][j]+=dp[i-1][j-a[i][1]],pre[i][j]=1;
            }
        if(dp[m][p1]!=1)
        {
            printf("no\n");
            continue;
        }
        vector<int>ans;
        int k=p1;
        for(int i=m;i>=1;i--)
        {
            for(int j=0;j<a[i][pre[i][k]];j++)
                ans.push_back(b[i][pre[i][k]][j]);
            k-=a[i][pre[i][k]];
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            printf("%d\n",ans[i]);
        printf("end\n");
    }
    return 0;
}