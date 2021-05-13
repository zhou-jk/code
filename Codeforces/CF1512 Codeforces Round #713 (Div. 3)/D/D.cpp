#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n;
int b[N];
map<int,bool>vis;
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n+2;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+n+2+1);
    long long sum=0;
    for(int i=1;i<=n+1;i++)
        sum+=b[i];
    for(int i=1;i<=n+1;i++)
        if(sum-b[i]==b[n+2])
        {
            for(int j=1;j<=n+1;j++)
                if(i!=j) printf("%d ",b[j]);
            printf("\n");
            return;
        }
    if(sum-b[n+1]==b[n+1])
    {
        for(int i=1;i<=n;i++)
            printf("%d ",b[i]);
        printf("\n");
        return;
    }
    printf("-1\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}