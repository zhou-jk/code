#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1000005;
int n,m;
int c[N];
vector<int>pos[N];
int cnt[N],num[N];
int mx;
void add(int x)
{
    num[cnt[x]]--;
    cnt[x]++;
    num[cnt[x]]++;
    mx=max(mx,cnt[x]);
    return;
}
void del(int x)
{
    num[cnt[x]]--;
    cnt[x]--;
    num[cnt[x]]++;
    if(num[mx]==0) mx--;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        pos[c[i]].emplace_back(i),add(c[i]);
    for(int i=1;i<=m;i++)
    {
        c[0]=c[n+1]=i;
        int num=pos[i].size();
        for(int x:pos[i])
            del(c[x]);
        for(int x:pos[i])
            if(c[x^1]!=i) del(c[x^1]);
        int ans1=n-num-mx;
        for(int x:pos[i])
            if(c[x^1]!=i) add(c[x^1]);
        for(int x:pos[i])
            if(c[((x-1)^1)+1]!=i) del(c[((x-1)^1)+1]);
        int ans2=n-num-mx;
        printf("%d\n",min(ans1,ans2));
        for(int x:pos[i])
            if(c[((x-1)^1)+1]!=i) add(c[((x-1)^1)+1]);
        for(int x:pos[i])
            add(c[x]);
    }
    return 0;
}