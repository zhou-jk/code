#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	int x;
        scanf("%d",&x);
        int j=1;
        while(x>=j) x-=j,j++;
        j--;
        ans^=j;
    }
    if(ans==0) printf("YES");
    else printf("NO");
    return 0;
}
