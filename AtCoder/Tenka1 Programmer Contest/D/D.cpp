#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
const int N=100005;
int n;
vector<int>ans[N];
int main()
{
    scanf("%d",&n); 
    int k=1;
    while(k*(k-1)<n*2) k++;
    if(k*(k-1)!=n*2)
    {
        printf("No");
        return 0;
    }
    int cur=1;
    for(int i=1;i<=k;i++)
        for(int j=i+1;j<=k;j++)
            ans[i].emplace_back(cur),ans[j].emplace_back(cur),cur++;
    printf("Yes\n");
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
    {
        int m=ans[i].size();
        printf("%d ",m);
        for(int v:ans[i])
            printf("%d ",v);
        printf("\n");
    }
    return 0;
}