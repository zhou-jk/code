#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
int cnt[21];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof(cnt));
            int k;
            scanf("%d",&k);
            for(int i=1;i<=k;i++)
            {
                int x;
                scanf("%d",&x);
                cnt[x]++;
            }
            int tot=0,p;
            bool flag=0;
            for(p=20;cnt[p]>0;p--);
            while(p!=0)
            {
                if(cnt[p]==0)
                {
                    if(flag) ans^=tot;
                    flag=!flag,tot=0;
                }
                else tot++;
                p--;
            }
            if(flag) ans^=tot;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}