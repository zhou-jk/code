#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=81;
int n;
double l[N],r[N];
double ans[N][N],g[N],f[N],dp[N][N];
vector<double>X;
vector<pair<double,double> >p;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&l[i],&r[i]);
        X.push_back(l[i]),X.push_back(r[i]);
    }
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    for(int i=0;i<X.size()-1;i++)
        p.push_back(make_pair(X[i],X[i+1]));
    for(auto [L,R]:p)
    {
        for(int i=1;i<=n;i++)
        {
            if(L<r[i]&&l[i]<R)
            {
                for(int j=0;j<=n;j++)
                    for(int k=0;k<=n;k++)
                        dp[j][k]=0.0;
                dp[0][0]=1.0;
                int cnt=0;
                vector<int>used;
                for(int k=1;k<=n;k++)
                    if(l[k]>=R||r[k]<=L)
                    {
                        f[k]=0.0;
                        if(r[k]<=L) cnt++;
                    }
                    else f[k]=(R-L)/(r[k]-l[k]),used.push_back(k);
                for(int j=0;j<used.size();j++)
                {
                    int x=used[j];
                    if(x==i) continue;
                    for(int k=j+1;k>=0;k--)
                        for(int o=j+1-k;o>=0;o--)
                        {
                            dp[k+1][o]+=dp[k][o]*g[x];
                            dp[k][o+1]+=dp[k][o]*f[x];
                            dp[k][o]*=1.0-f[x]-g[x];
                        }
                }
                for(int j=0;j<used.size();j++)
                    for(int k=0;j+k<used.size();k++)
                    {
                        ans[i][cnt+j]+=dp[j][k]*f[i]/(1+k);
                        ans[i][cnt+j+k+1]-=dp[j][k]*f[i]/(1+k);
                    }
            }
        }
        for(int i=1;i<=n;i++)
            g[i]+=f[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<n;j++)
            ans[i][j]+=ans[i][j-1];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%.6lf ",ans[i][j]);
        printf("\n");
    }
    return 0;
}