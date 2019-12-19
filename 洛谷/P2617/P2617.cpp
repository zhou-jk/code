#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
int a[N];
struct Segment_Tree
{
    struct Node
    {
        int lc,rc;
        long long sum;
    }tree[N<<5];
    int rt[N],tot;
    void push_up(int i)
    {
        tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
        return;
    }
    void update(int &i,int l,int r,int u)
    {
        if(!i) i=++tot;
        if(l==r)
        {
            tree[i].sum++;
            return;
        }
        int mid=(l+r)/2;
        if(u<=mid) update(tree[i].lc,l,mid,u);
        else update(tree[i].rc,mid+1,r,u);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r,int L,int R)
    {
        if()

    }
}
int main()
{

}