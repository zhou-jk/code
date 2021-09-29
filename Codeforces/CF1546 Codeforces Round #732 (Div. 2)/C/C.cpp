#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int even[2][N],odd[2][N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(i%2==0) even[0][a[i]]++;
        else odd[0][a[i]]++;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(i%2==0) even[1][a[i]]++;
        else odd[1][a[i]]++;
    int m=*max_element(a+1,a+n+1);
    for(int v=1;v<=m;v++)
        if(even[0][v]!=even[1][v]||odd[0][v]!=odd[1][v])
        {
            printf("NO\n");
            for(int i=1;i<=n;i++)
                even[0][a[i]]=odd[0][a[i]]=even[1][a[i]]=odd[1][a[i]]=0;
            return;
        }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        even[0][a[i]]=odd[0][a[i]]=even[1][a[i]]=odd[1][a[i]]=0;
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