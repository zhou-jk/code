#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int T;
int n;
char s[N];
struct BIT
{
    int C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}tree;
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    vector<int>pos[5];
    for(int i=1;i<=n;i++)
        if(s[i]=='A') pos[1].emplace_back(i);
        else if(s[i]=='N') pos[2].emplace_back(i);
        else if(s[i]=='T') pos[3].emplace_back(i);
        else if(s[i]=='O') pos[4].emplace_back(i);
    static int id[5];
    iota(id+1,id+4+1,1);
    long long ans=-1;
    static int res[5];
    do
    {
        vector<int>b;
        for(int i=1;i<=4;i++)
            for(int p:pos[id[i]])
                b.emplace_back(p);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=tree.query(b[i]+1,n);
            tree.add(b[i],1);
        }
        for(int i=0;i<n;i++)
            tree.add(b[i],-1);
        if(sum>ans)
        {
            ans=sum;
            for(int i=1;i<=4;i++)
                res[i]=id[i];
        }
    }
    while(next_permutation(id+1,id+4+1));
    for(int i=1;i<=4;i++)
        for(int j=0;j<(int)pos[res[i]].size();j++)
            if(res[i]==1) printf("A");
            else if(res[i]==2) printf("N");
            else if(res[i]==3) printf("T");
            else if(res[i]==4) printf("O");
    printf("\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}