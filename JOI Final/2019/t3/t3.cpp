#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=405;
const int INF=1061109567;
int n;
char s[N];
int a[N];
int cnt[N][3];
int f[N][N][N][3];
vector<int>pos[3];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        if(s[i]=='R') a[i]=0;
        else if(s[i]=='G') a[i]=1;
        else if(s[i]=='Y') a[i]=2;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            cnt[i][j]=cnt[i-1][j];
        cnt[i][a[i]]++;
    }
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    memset(f,63,sizeof(f));
    if(!pos[0].empty()) f[1][1][0][0]=pos[0][0]-1;
    if(!pos[1].empty()) f[1][0][1][1]=pos[1][0]-1;
    if(!pos[2].empty()) f[1][0][0][2]=pos[2][0]-1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;j+k<=i;k++)
            {
                int l=i-j-k;
                for(int x=0;x<3;x++)
                {
                    int v;
                    if(x==0) v=j;
                    else if(x==1) v=k;
                    else v=l;
                    if(v<=0) continue;
                    if((int)pos[x].size()<v) continue;
                    int p=pos[x][v-1];
                    int sum=0;
                    if(x!=0) sum+=max(cnt[p][0]-j,0);
                    if(x!=1) sum+=max(cnt[p][1]-k,0);
                    if(x!=2) sum+=max(cnt[p][2]-l,0);
                    for(int y=0;y<3;y++)
                        if(x!=y) f[i][j][k][x]=min(f[i][j][k][x],f[i-1][j-(x==0)][k-(x==1)][y]+sum);
                }
            }
    int ans=INF;
    for(int j=0;j<=n;j++)
        for(int k=0;j+k<=n;k++)
            for(int x=0;x<3;x++)
                ans=min(ans,f[n][j][k][x]);
    if(ans>=INF) printf("-1");
    else printf("%d",ans);
    return 0;
}