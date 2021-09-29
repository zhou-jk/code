#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=105;
int n;
int a[N],b[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int suma=0,sumb=0;
    for(int i=1;i<=n;i++)
        suma+=a[i],sumb+=b[i];
    if(suma!=sumb)
    {
        printf("-1\n");
        return;
    }
    vector<int>add,del;
    for(int i=1;i<=n;i++)
        if(a[i]<b[i])
        {
            for(int j=1;j<=b[i]-a[i];j++)
                add.emplace_back(i);
        }
        else if(a[i]>b[i])
        {
            for(int j=1;j<=a[i]-b[i];j++)
                del.emplace_back(i);
        }
    if(add.size()!=del.size())
    {
        printf("-1\n");
        return;
    }
    int m=add.size();
    printf("%d\n",m);
    for(int i=0;i<m;i++)
        printf("%d %d\n",del[i],add[i]);
    
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