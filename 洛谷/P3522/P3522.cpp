#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1000001;
int n;
int l[N],r[N];
deque<int>q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&l[q.front()]>r[i]) q.pop_front();
        if(!q.empty()) ans=max(ans,i-q.front()+1);
        int k=i;
        while(!q.empty()&&l[i]>l[q.back()]) k=q.back(),q.pop_back();
        l[k]=l[i];
        q.push_back(k);
    }
    printf("%d",ans);
    return 0;
}