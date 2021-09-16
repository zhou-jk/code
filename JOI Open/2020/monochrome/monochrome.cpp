#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
char s[N*2];
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int m=n*2;
    vector<int>a,b;
    for(int i=0;i<m;i++)
        if(s[i]=='B') a.emplace_back(i);
        else if(s[i]=='W') b.emplace_back(i);
    int ans=0;
    for(int k=0;k<n;k++)
    {
        int res=0;
        for(int i=0;i<n;i++)
            res+=min((a[i]-b[(i+k)%n]+m)%m-1,(b[(i+k)%n]-a[i]+m)%m-1);
        ans=max(ans,res);
    }
    printf("%d",ans/2);
    return 0;
}