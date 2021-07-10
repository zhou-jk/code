#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=200005;
int T;
int n;
int a[N];
set<int>S;
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    S.clear();
    S.insert(a[1]);
    for(int i=2;i<=n;i++)
    {
        S.insert(a[i]);
        if(a[i]>a[i-1])
        {
            if(*(++S.find(a[i-1]))!=a[i])
            {
                printf("NO\n");
                return;
            }
        }
        if(a[i]<a[i-1])
        {
            if(*(--S.find(a[i-1]))!=a[i])
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}