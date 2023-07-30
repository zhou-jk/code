#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,k,x;
void solve()
{
    scanf("%d%d%d",&n,&k,&x);
    vector<int>res;
    if(x==1)
    {
        if(n==1||k==1)
        {
            printf("NO\n");
            return;
        }
        if(n%2!=0)
        {
            if(k<=2)
            {
                printf("NO\n");
                return;
            }
            else
            {
                n-=3;
                res.emplace_back(3);
            }
        }
        for(int i=1;i<=n/2;i++)
            res.emplace_back(2);
    }
    else
    {
        for(int i=1;i<=n;i++)
            res.emplace_back(1);
    }
    printf("YES\n");
    int m=res.size();
    printf("%d\n",m);
    for(int v:res)
        printf("%d ",v);
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}