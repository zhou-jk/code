#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001];
int book[1000001],Max,ans[1000001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
        book[a[i]]++;
    }
    for(int i=1;i<=Max;i++)
        if(book[i])
            for(int j=i;j<=Max;j+=i)
                ans[j]+=book[i];
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[a[i]]-1);
    return 0;
}