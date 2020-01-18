#include<iostream>
#include<cstdio>
using namespace std;
int n;
int ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x!=0) ans++;
    }
    if(ans%2==1) printf("YES");
    else printf("NO");
    return 0;
}