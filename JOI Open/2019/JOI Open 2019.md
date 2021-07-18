#### 三段跳び / Triple Jump

如果在 $a,b$ 中存在 $i$ 满足 $A_i\ge A_a$ 或 $A_i\ge A_b$，那么选择 $i$ 肯定不会更劣。换句话说，合法的 $a,b$ 需要满足在 $\min(A_a,A_b)\gt \max\limits_{i=a+1}^{b-1}\{A_i\}$。所以 $b$ 要么是 $a$ 右边第一个大于等于它的，要么是第一个小于等于它的，我们可以用单调栈求出所有的 $(a,b)$。

将询问离线，从右往左扫，维护对于每个 $c$，$A_a+A_b+A_c$ 和 $A_a+A_b$ 的最大值，每次加入一个点对 $(a,b)$ 相当于将 $2b-a\sim n$ 这段区间对 $A_a+A_b$ 取 $\max$，每次询问相当于查询区间最大值，线段树维护即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int N=500005;
int n,Q;
int a[N];
int L[N],R[N];
int ans[N];
vector<pair<int,int>>ask[N],p[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int c,ab,abc;
        int lazy;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].c=max(tree[i*2].c,tree[i*2+1].c);
        tree[i].abc=max(tree[i*2].abc,tree[i*2+1].abc);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].c=tree[i].abc=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int v)
    {
        tree[i].lazy=max(tree[i].lazy,v);
        tree[i].ab=max(tree[i].ab,v);
        tree[i].abc=max(tree[i].abc,tree[i].c+tree[i].ab);
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].lazy) return;
        add(i*2,tree[i].lazy);
        add(i*2+1,tree[i].lazy);
        tree[i].lazy=0;
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].abc;
        push_down(i);
        int res=0;
        if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
        return res;
    }
}T;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        ask[l].emplace_back(r,i);
    }
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(!s.empty()) L[i]=s.top();
        s.emplace(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[i]>a[s.top()]) s.pop();
        if(!s.empty()) R[i]=s.top();
        s.emplace(i);
    }
    T.build(1,1,n);
    for(int i=1;i<=n;i++)
        if(L[i]) p[L[i]].emplace_back(L[i],i);
    for(int i=n;i>=1;i--)
    {
        for(auto [r,id]:p[i])
            T.modify(1,id*2-r,n,a[id]+a[r]);
        if(R[i]) T.modify(1,R[i]*2-i,n,a[i]+a[R[i]]);
        for(auto [r,id]:ask[i])
            ans[id]=T.query(1,i,r);
    }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
```

---

#### 送金 / Remittance

每次贪心能送就送，每次 $a_i-b_i$ 都会减半，所以只有 $\log$ 层。

---

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    while(true)
    {
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            int c=(a[i]-b[i])/2;
            if(a[i]-b[i]>1) a[j]+=c,a[i]-=c*2; 
        }
        bool flag=false;
        for(int i=0;i<n;i++)
            if(a[i]-b[i]>1)
            {
                flag=true;
                break;
            }
        if(!flag) break;
    }
    bool flag=true;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
        {
            flag=false;
            break;
        }
    if(flag)
    {
        printf("Yes");
        return 0;
    }
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]+1)
        {
            printf("No");
            return 0;
        }
    for(int i=0;i<n;i++)
        if(a[i]>=2)
        {
            flag=true;
            break;
        }
    if(flag) printf("Yes");
    else printf("No");
    return 0;
}
```

---

#### ウイルス実験 / Virus Experiment

分别预处理出上下左右四个格子的 $2^4$ 种感染情况，被有病毒的风最长吹了多久。

可以发现，如果一个点 $u$ 可以感染 $v$，那么感染 $u$ 肯定不如感染 $v$，我们可以将 $u$ 合并到 $v$ 上，表明我们接下来只需要考虑 $v$。这样每个联通块找到一个点合并，每次的联通块数会除以 $2$，复杂度类似 Boruvka 算法。

最后对独立的联通块算算就可以了。

---

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    while(true)
    {
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            int c=(a[i]-b[i])/2;
            if(a[i]-b[i]>1) a[j]+=c,a[i]-=c*2; 
        }
        bool flag=false;
        for(int i=0;i<n;i++)
            if(a[i]-b[i]>1)
            {
                flag=true;
                break;
            }
        if(!flag) break;
    }
    bool flag=true;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
        {
            flag=false;
            break;
        }
    if(flag)
    {
        printf("Yes");
        return 0;
    }
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]+1)
        {
            printf("No");
            return 0;
        }
    for(int i=0;i<n;i++)
        if(a[i]>=2)
        {
            flag=true;
            break;
        }
    if(flag) printf("Yes");
    else printf("No");
    return 0;
}
```