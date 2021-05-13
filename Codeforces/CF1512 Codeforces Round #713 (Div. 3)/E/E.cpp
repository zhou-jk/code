#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n,l,r,s;
void solve()
{
    scanf("%d%d%d%d",&n,&l,&r,&s);
    int k=r-l+1;
    int ret=s;
    vector<int>a,b;
    for(int i=n;i>=1;i--)
        if(ret-i>=1LL*(k-1)*k/2)
        {
            a.emplace_back(i);
            ret-=i,k--;
        }
        else b.emplace_back(i);
    if(ret!=0||a.size()!=r-l+1)
    {
        printf("-1\n");
        return;
    }
    for(int i=1;i<=n;i++)
        if(l<=i&&i<=r) printf("%d ",a.back()),a.pop_back();
        else printf("%d ",b.back()),b.pop_back();
    printf("\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}