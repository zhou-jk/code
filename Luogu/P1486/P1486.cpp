#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,sum,m,ans;
vector<int>a;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char ch;
        int x;
        for(ch=getchar();ch!='I'&&ch!='A'&&ch!='S'&&ch!='F';ch=getchar());
        scanf("%d",&x);
        if(ch=='I')
        {
            if(x>=m) a.insert(lower_bound(a.begin(),a.end(),x-sum),x-sum);
        }
        else if(ch=='A') sum+=x;
        else if(ch=='S')
        {
            sum-=x;
            while(!a.empty()&&a[0]+sum<m)
            {
                a.erase(a.begin());
                ans++;
            }
        }
        else if(ch=='F')
            if(a.size()>=x) printf("%d\n",a[a.size()-x]+sum);
            else printf("-1\n");
    }
    printf("%d",ans);
    return 0;
}