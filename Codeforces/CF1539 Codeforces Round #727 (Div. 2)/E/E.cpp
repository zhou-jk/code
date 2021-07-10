#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=100005;
int n,m;
int k[N];
set<pair<int,int>>f[2];
int pos[N][2];
void print(int i,int j)
{
    if(i==0) return;
    print(pos[i][j],j^1);
    for(int k=pos[i][j]+1;k<=i;k++)
        printf("%d ",j);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    f[0].insert({0,0});
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        int al,bl;
        scanf("%d%d",&al,&bl);
        int ar,br;
        scanf("%d%d",&ar,&br);
        bool flag0=false,flag1=false;
        if(al<=k[i]&&k[i]<=bl)
        {
            if(ar<=k[i-1]&&k[i-1]<=br)
            {
                if(!f[1].empty()) flag0=true;
            }
        }
        if(ar<=k[i]&&k[i]<=br)
        {
            if(al<=k[i-1]&&k[i-1]<=bl)
            {
                if(!f[0].empty()) flag1=true;
            }
        }
        if(al<=k[i]&&k[i]<=bl)
        {
            while(!f[0].empty())
                if(f[0].begin()->first<ar) f[0].erase(f[0].begin());
                else break;
            while(!f[0].empty())
                if(f[0].rbegin()->first>br) f[0].erase(--f[0].end());
                else break;
        }
        else f[0].clear();
        if(ar<=k[i]&&k[i]<=br)
        {
            while(!f[1].empty())
                if(f[1].begin()->first<al) f[1].erase(f[1].begin());
                else break;
            while(!f[1].empty())
                if(f[1].rbegin()->first>bl) f[1].erase(--f[1].end());
                else break;
        }
        else f[1].clear();
        if(flag1) f[1].insert({k[i-1],i-1});
        if(flag0) f[0].insert({k[i-1],i-1});
        if(!f[0].empty()) pos[i][0]=f[0].begin()->second;
        if(!f[1].empty()) pos[i][1]=f[1].begin()->second;
    }
    if(!f[0].empty())
    {
        printf("Yes\n");
        print(n,0);
        return 0;
    }
    if(!f[1].empty())
    {
        printf("Yes\n");
        print(n,1);
        return 0;
    }
    printf("No");
    return 0;
}