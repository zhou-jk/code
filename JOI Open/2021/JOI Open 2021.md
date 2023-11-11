#### 交配 / Crossing

令 `J` 为 $0$，`O` 为 $1$，`I` 为 $2$，杂交相当于是 $c\equiv -(a+b)\pmod 3$

可以发现最后的状态数不会超过 $27$ 种，直接暴力线段树维护即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=200005;
const int BASE=233;
const int MOD1=1000000007,MOD2=1000000009;
int n,q;
bool f[3][3][3];
pair<int,int> pw[N],fac[4][N];
char sa[N],sb[N],sc[N];
char t[N];
int get_val(char ch)
{
    if(ch=='J') return 0;
    else if(ch=='O') return 1;
    else if(ch=='I') return 2;
    else return -1;
}
map<pair<int,int>,bool>book;
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int tag;
        pair<int,int> val;
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        c.tag=0;
        c.val=make_pair(((long long)a.val.first*pw[b.r-b.l+1].first+b.val.first)%MOD1,((long long)a.val.second*pw[b.r-b.l+1].second+b.val.second)%MOD2);
        return c;
    }
    void push_up(int i)
    {
        tree[i]=merge(tree[ls],tree[rs]);
        return;
    }
    void add(int i,int v)
    {
        tree[i].tag=v;
        tree[i].val=fac[v][tree[i].r-tree[i].l+1];
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(ls,tree[i].tag);
        add(rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r) return add(i,get_val(t[l])+1);
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[ls].r) modify(ls,l,r,v);
        if(r>=tree[rs].l) modify(rs,l,r,v);
        push_up(i);
        return;
    }
    Node query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
        push_down(i);
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
int main()
{
    scanf("%d",&n);
    scanf("%s",sa+1);
    scanf("%s",sb+1);
    scanf("%s",sc+1);
    f[1][0][0]=f[0][1][0]=f[0][0][1]=true;
    while(true)
    {
        bool flag=true;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    if(f[i][j][k])
                        for(int o=0;o<3;o++)
                            for(int p=0;p<3;p++)
                                for(int q=0;q<3;q++)
                                    if(f[o][p][q])
                                    {
                                        int a=(6-i-o)%3,b=(6-j-p)%3,c=(6-k-q)%3;
                                        if(!f[a][b][c])
                                        {
                                            f[a][b][c]=true;
                                            flag=false;
                                        }
                                    }
        if(flag) break;
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                if(f[i][j][k])
                {
                    int sum1=0,sum2=0;
                    for(int l=1;l<=n;l++)
                    {
                        int v=(get_val(sa[l])*i+get_val(sb[l])*j+get_val(sc[l])*k)%3;
                        v=(v+3)%3;
                        sum1=((long long)sum1*BASE+v+1)%MOD1;
                        sum2=((long long)sum2*BASE+v+1)%MOD2;
                    }
                    book[make_pair(sum1,sum2)]=true;
                }
    pw[0]=make_pair(1,1);
    for(int i=1;i<=n;i++)
        pw[i]=make_pair((long long)pw[i-1].first*BASE%MOD1,(long long)pw[i-1].second*BASE%MOD2);
    for(int v=1;v<=3;v++)
        for(int i=1;i<=n;i++)
            fac[v][i]=make_pair(((long long)fac[v][i-1].first*BASE+v)%MOD1,((long long)fac[v][i-1].second*BASE+v)%MOD2);
    scanf("%d",&q);
    scanf("%s",t+1);
    T.build(1,1,n);
    if(book[T.query(1,1,n).val]) printf("Yes\n");
    else printf("No\n");
    while(q--)
    {
        int l,r;
        char c;
        scanf("%d%d",&l,&r);
        for(c=getchar();c!='J'&&c!='O'&&c!='I';c=getchar());
        T.modify(1,l,r,get_val(c)+1);
        if(book[T.query(1,1,n).val]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
```

---

#### 決算報告 / Financial Report

令 $f_i$ 表示以 $i$ 结尾的答案最大时多少，考虑转移，当 $a_j< a_i$ 且 $[j+1,i-1]$ 中 $\ge a_i$ 的数组成的所有连续段长度 $<D$ 时有 $f_i=f_j+1$。

考虑优化，将所有数按照 $a_i$ 排序，当前算出了 $1\sim a_i-1$ 的 $f$，可以用并查集找到从 $[i-d,i-1]$ 中最左边能跳到的位置 $p$，那么 $f_i=\max\limits_{j=p}^{i-1}f_j+1$。

---


```cpp
#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=300005;
int n,d;
int a[N];
int f[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int mx;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].mx=max(tree[ls].mx,tree[rs].mx);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].mx=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mx=v;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l>r) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
        int res=0;
        if(l<=tree[ls].r) res=max(res,query(ls,l,r));
        if(r>=tree[rs].l) res=max(res,query(rs,l,r));
        return res;
    }
    int find_right(int i,int l,int r)
    {
        if(!tree[i].mx) return 0;
        if(tree[i].l==tree[i].r) return tree[i].l;
        int res=0;
        if(r>=tree[rs].l) res=find_right(rs,l,r);
        if(res) return res;
        if(l<=tree[ls].r) return find_right(ls,l,r);
        else return 0;
    }
    int find_left(int i,int l,int r)
    {
        if(!tree[i].mx) return 0;
        if(tree[i].l==tree[i].r) return tree[i].l;
        int res=0;
        if(l<=tree[ls].r) res=find_right(ls,l,r);
        if(res) return res;
        if(r>=tree[rs].l) return find_right(rs,l,r);
        else return 0;
    }
    #undef ls
    #undef rs
}T;
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return fa[v];
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    T.build(1,1,n);
    iota(fa+1,fa+n+1,1);
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&a[id[i]]==a[id[j]]) j++;
        for(int k=i;k<j;k++)
        {
            int pre=T.find_right(1,id[k]-d,id[k]-1);
            f[id[k]]=max(T.query(1,pre?getf(pre):max(id[k]-d,1),id[k]-1)+1,1);
        }
        for(int k=i;k<j;k++)
        {
            T.modify(1,id[k],f[id[k]]);
            int pre=T.find_right(1,id[k]-d,id[k]-1),suf=T.find_left(1,id[k]+1,id[k]+d);
            if(pre) merge(pre,id[k]);
            if(suf) merge(id[k],suf);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}
```

---

#### モンスターゲーム / Monster Game

如果我们把这个比较丢到 sort 里面，最后会得到若干段相邻递减 $1$ 的总体上升的序列

询问 $(i,i-2)$ 可以判断这段递减的结束了没有。

但是长度 $< 3$ 的需要特殊处理

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<functional>
#include<map>
#include<algorithm>
#include"monster.h"
using namespace std;
map<pair<int,int>,bool>book;
bool query(int a,int b)
{
    if(book.count(make_pair(a,b))) return book[make_pair(a,b)];
    else return book[make_pair(a,b)]=Query(a,b);
}
vector<int> Solve(int N)
{
    int n=N;
    vector<int>id(n);
    for(int i=0;i<n;i++)
        id[i]=i;
    function<void(int,int)>merge_sort=[&](int l,int r)
    {
        if(l==r) return;
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        vector<int>tmp;
        int p1=l,p2=mid+1;
        while(p1<=mid&&p2<=r)
            if(!query(id[p1],id[p2])) tmp.emplace_back(id[p1]),p1++;
            else tmp.emplace_back(id[p2]),p2++;
        while(p1<=mid)
            tmp.emplace_back(id[p1]),p1++;
        while(p2<=r)
            tmp.emplace_back(id[p2]),p2++;
        for(int i=0;i<(int)tmp.size();i++)
            id[l+i]=tmp[i];
        return;
    };
    merge_sort(0,n-1);
    for(int i=0,j=0;i<n;i=j)
    {
        if(i==0)
        {
            if(query(id[i+2],id[i])) // 012 0321 1032
            {
                if(query(id[i+1],id[i])) //0321 1032
                {
                    for(j=i+3;j<n;j++)
                        if(!query(id[j],id[i])) break;
                    if(j+1<=n) j++;
                    if(query(id[j-1],id[i+1])) reverse(id.begin()+i,id.begin()+i+2),reverse(id.begin()+i+2,id.begin()+j);
                    else reverse(id.begin()+i+1,id.begin()+j);
                    continue;
                }
                else j=i+1;//012
            }
            else //021 102 210 3210
            {
                int cnt=0;
                int k=i+2;
                for(k=i+2;k<n;k++)
                    if(query(id[i],id[k]))
                    {
                        cnt++;
                        if(cnt>=2) break;
                    }
                    else break;
                if(cnt<2) //021 102 210
                {
                    if(i+5<n)
                    {
                        if(!query(id[i+3],id[i+5])&&(!query(id[i+3],id[i])||!query(id[i+3],id[i+1])||!query(id[i+3],id[i+2]))) //210354 021354 102354
                        {
                            if(!query(id[i+3],id[i])) reverse(id.begin()+i,id.begin()+i+3);
                            else if(!query(id[i+3],id[i+1])) reverse(id.begin()+i+1,id.begin()+i+3);
                            else reverse(id.begin()+i,id.begin()+i+2);
                            reverse(id.begin()+i+3,id.begin()+i+6);
                            j=i+6;
                            continue;
                        }
                        else if(!query(id[i+3],id[i+5])&&(!query(id[i+3],id[i])||!query(id[i+3],id[i+1])||!query(id[i+3],id[i+2]))) //210435 021435 102435
                        {
                            if(!query(id[i+3],id[i])) reverse(id.begin()+i,id.begin()+i+3);
                            else if(!query(id[i+3],id[i+1])) reverse(id.begin()+i+1,id.begin()+i+3);
                            else reverse(id.begin()+i,id.begin()+i+2);
                            reverse(id.begin()+i+3,id.begin()+i+6);
                            j=i+6;
                            continue;
                        }
                    }
                    for(j=i+3+2;j<n;j++)
                        if(!query(id[j-2],id[j])) break;
                    if(!query(id[j-1],id[i])) reverse(id.begin()+i,id.begin()+i+3); //210
                    else if(!query(id[j-1],id[i+1])) reverse(id.begin()+i+1,id.begin()+i+3); //021
                    else reverse(id.begin()+i,id.begin()+i+2); //102
                    reverse(id.begin()+i+3,id.begin()+j);
                    continue;
                }
                else //3210
                {
                    for(j=k+1;j<n;j++)
                        if(!query(id[j-2],id[j])) break;
                }
            }
        }
        else
        {
            for(j=i;j<n;j++)
                if(!query(id[j],id[i-1])) break;
            if(j+1<=n) j++;
        }
        reverse(id.begin()+i,id.begin()+j);
    }
    vector<int>s(n);
    for(int i=0;i<n;i++)
        s[id[i]]=i;
    return s;
}
```