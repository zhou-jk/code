#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=105;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(*min_element(a+1,a+n+1)<0)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    vector<int>b;
    for(int i=0;i<=100;i++)
        b.emplace_back(i);
    int k=b.size();
    printf("%d\n",k);
    for(int x:b)
        printf("%d ",x);
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