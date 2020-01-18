#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int N=105,M=2000001;
const int INF=1044266559;
int n,m,mc;
int C[N],a[N],w[N];
int D,f[N][N],Max;
vector<pair<int,int> >q;
struct Node
{
    int f,d,l;
};
queue<Node>Q;
map<pair<int,int>,bool>H;
void bfs()
{
    Q.push((Node){1,1,0});
    H[make_pair(1,0)]=true;
    while(!Q.empty())
    {
        Node u=Q.front();
        Q.pop();
        if(u.d>=D) continue;
        Q.push((Node){u.f,u.d+1,u.l+1});
        if(u.l<=1||u.f>Max/u.l) continue;
        Node t=(Node){u.l*u.f,u.d+1,u.l};
        if(H[make_pair(t.f,t.l)]) continue; 
        H[make_pair(t.f,t.l)]=true;
        q.push_back(make_pair(t.f,t.d));
        Q.push(t);
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&mc);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&C[i]);
        Max=max(Max,C[i]);
    }
    memset(f,-63,sizeof(f));
    f[0][mc]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j+a[i]<=mc;j++)
            f[i][j]=max(f[i][j],f[i-1][j+a[i]]+1),
        f[i][min(mc,j+w[i])]=max(f[i][min(mc,j+w[i])],f[i-1][j+a[i]]);
        for(int j=0;j<=mc;j++) D=max(f[i][j],D);
    }
    bfs();
    sort(q.begin(),q.end());
    for(int i=1;i<=m;i++)
    {
        if(C[i]<=D)
        {
            printf("1\n");
            continue;
        }
        int mx=-INF,ans=0;
        for(int j=q.size()-1,k=0;j>=0;j--)
        {
            while(k<q.size()&&q[k].first+q[j].first<=C[i]) mx=max(mx,q[k].first-q[k].second),k++;
            if(q[j].first<=C[i]&&q[j].first+D-q[j].second>=C[i])
            {
                ans=1;
                break;
            }
            if(q[j].first-q[j].second+mx+D>=C[i])
            {
                ans=1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}