#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int INF=1000000000;
const int MOD=1000000;
set<int> s;
int n;
int a,b,c;
int ans;
int main()
{
    scanf("%d",&n);
    s.insert(INF);
    s.insert(-INF);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(s.size()==2) s.insert(b),c=a;
        else if(a==c) s.insert(b);
        else
        {
            set<int>::iterator it=s.lower_bound(b);
            int r=*it-b,l=b-*(--it);
            if(l<=r) ans=(ans+l)%MOD,s.erase(it);
            else ans=(ans+r)%MOD,s.erase(++it);
        }
    }
    printf("%d",ans);
    return 0;
}