#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct Basis
{
    static const int N=63;
    long long a[N];
    vector<int>b;
    Basis()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void clear()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void insert(long long t)
    {
        for(int i=N-1;i>=0;i--)
            if((t>>i)&1)
            {
                if(a[i]) t^=a[i];
                else
                {
                    for(int j=0;j<i;j++)
                        if((t>>j)&1) t^=a[j];
                    for(int j=i+1;j<N;j++)
                        if((a[j]>>i)&1) a[j]^=t;
                    a[i]=t;
                    break;
                }
            }
        b.clear();
        for(int i=0;i<N;i++)
            if(a[i]) b.push_back(i);
        return;
    }
    int size()
    {
        return b.size();
    }
};
const int N=55;
const int MOD=2008;
int n,m;
char s[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%s",s[i]+1);
    Basis lb;
    for(int i=1;i<=m;i++)
    {
        long long v=0;
        for(int j=1;j<=n;j++)
            if(s[i][j]=='O') v|=1LL<<j;
        lb.insert(v);
    }
    int ans=(1LL<<lb.size())%MOD;
    printf("%d",ans);
    return 0;
}