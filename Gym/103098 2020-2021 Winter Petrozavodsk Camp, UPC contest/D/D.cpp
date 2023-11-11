#include<iostream>
#include<cstdio>
using namespace std;
const int M=100005;
int n,m;
string query(int a,int b,int w)
{
    a--,b--;
    cout<<"? "<<a<<" "<<b<<" "<<w<<endl;
    string str;
    cin>>str;
    return str;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int tag;
    }tree[M*4];
    void insert(int i,int l,int r,int u)
    {
        if(!tree[i].tag)
        {
            tree[i].tag=u;
            return;
        }
        if(::query(tree[i].tag,u,l)=="SECOND") swap(u,tree[i].tag);
        if(l==r) return;
        int mid=(l+r)/2;
        if(::query(tree[i].tag,u,mid)=="SECOND") insert(ls,l,mid,tree[i].tag),tree[i].tag=u;
        else insert(rs,mid+1,r,u);
        return;
    }
    int query(int i,int l,int r,int u)
    {
        if(l==r) return tree[i].tag;
        int mid=(l+r)/2;
        int p=0;
        if(u<=mid) p=query(ls,l,mid,u);
        else p=query(rs,mid+1,r,u);
        if(!p) return tree[i].tag;
        if(!tree[i].tag) return p;
        if(::query(tree[i].tag,p,u)=="SECOND") return p;
        else return tree[i].tag;
    }
    #undef ls
    #undef rs
}T;
int solve(int w)
{
    return T.query(1,1,m,w);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    m=100000;
    for(int i=1;i<=n;i++)
        T.insert(1,1,m,i);
    cout<<"!"<<endl;
    while(true)
    {
        string str;
        cin>>str;
        if(str=="QUESTION")
        {
            int w;
            cin>>w;
            int res=solve(w);
            cout<<"! "<<res-1<<endl;
        }
        else break;
    }
    return 0;
}