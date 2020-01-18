#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100001;
int n,m;
int s[N];
struct Segment_Tree
{
    struct Node
    {
   	    long long a[4][2][2],b[4][2];
        Node()
        {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            return;
        }
        Node operator=(const int &val)
        {
            memset(a[3],0,sizeof(a[3]));
            memset(b[3],0,sizeof(b[3]));
            a[3][val][val^1]=1;
            b[3][val]=1;
            return *this;
        }
        Node operator+(const Node &r)const
        {
            Node res;
   	        for(int i=0;i<2;i++)
            {
   	    	    for(int j=0;j<2;j++)
                {
   	    		    res.a[0][i][j]=a[0][i][j]+r.a[0][i][j]+a[2][i][j]+r.a[1][i][j];
   	    	        res.a[1][i][j]=a[1][i][j]+a[3][i][j];
   	    	        res.a[2][i][j]=r.a[2][i][j]+r.a[3][i][j];
   	    	        res.a[3][i][j]=0;
                }
   	    	    res.b[0][i]=b[0][i]+r.b[0][i]+b[2][i]+r.b[1][i];
   	    	    res.b[1][i]=b[1][i]+b[3][i];
   	    	    res.b[2][i]=r.b[2][i]+r.b[3][i];
   	    	    res.b[3][i]=0;
   	        }
            for(int i=0;i<2;i++)
   	            for(int j=0;i+j<2;j++)
                {
   	     	        int y=i+j;
   	     	        for(int k=0;k<2;k++)
   	     	            for(int l=0;l<2;l++)
                        {
   	     	 	            int x=(k+l)&1;
   	     	 	            res.a[0][x][y]+=a[2][k][i]*r.a[1][l][j];
   	     	                res.a[1][x][y]+=a[3][k][i]*r.a[1][l][j];
   	     	                res.a[2][x][y]+=a[2][k][i]*r.a[3][l][j];
   	     	                res.a[3][x][y]+=a[3][k][i]*r.a[3][l][j];
                        }
   	     	        res.b[0][y]+=b[2][i]*r.b[1][j];
   	     	        res.b[1][y]+=b[3][i]*r.b[1][j];
   	                res.b[2][y]+=b[2][i]*r.b[3][j];
   	     	        res.b[3][y]+=b[3][i]*r.b[3][j];
   	            }
   	        return res;
        }
    };
    struct
    {
        int l,r;
        Node sum;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
   	    if(l==r)
        {
            tree[i].sum=s[l];
            return;
        }
   	    int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void update(int i,int u,int val)
    {
   	    if(tree[i].l==tree[i].r)
        {
   	   	    tree[i].sum=val;
            return;
        }
        if(u<=tree[i*2].r) update(i*2,u,val);
        else update(i*2+1,u,val);
        push_up(i);
        return;
    }
    Node query(int i,int L,int R)
    {
   	    if(L<=tree[i].l&&tree[i].r<=R) return tree[i].sum;
   	    else if(R<=tree[i*2].r) return query(i*2,L,R);
   	    else if(L>=tree[i*2+1].l) return query(i*2+1,L,R);
   	    else return query(i*2,L,R)+query(i*2+1,L,R);
    } 
    long long getans(int x,int y)
    {
        Node res=query(1,x,y);
        long long ans=0;
        for(int i=0;i<4;i++)
        {
      	    for(int j=0;j<2;j++)
                ans+=res.a[i][1][j];
            ans+=res.b[i][1];
        }
        return ans;
    } 
}T;
struct Binary_Indexed_Tree
{
    long long C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,long long y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    long long query(int x)
    {
        long long res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
}tree[2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        if(s[i]) tree[0].add(i,1);
        if(i>1&&(s[i-1]^s[i])) tree[1].add(i,1);
    }
    T.build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        int op,x,y;
        scanf("%d%d",&op,&x);
        if(op==1)
        {
            s[x]^=1;
            T.update(1,x,s[x]);
            tree[0].add(x,s[x]?1:(-1));
            if(x>1) tree[1].add(x,(s[x]==s[x-1])?(-1):1);
            if(x<n) tree[1].add(x+1,(s[x]==s[x+1])?(-1):1);
        }
        else
        {
            scanf("%d",&y);
            long long z=y-x+1;
            printf("%lld\n",z*(z+1)/2-T.getans(x,y)+tree[1].query(y)-tree[1].query(x)+tree[0].query(y)-tree[0].query(x-1));
        }
    }
    return 0;
}