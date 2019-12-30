#include<iostream>
#include<cstdio>
#include<queue>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
int n;
struct Node
{
    int num,t;
    bool operator<(const Node &b)const
    {
        return t<b.t;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int Case=0;
    while(1)
    {
        cin>>n;
        if(n==0) return 0;
        printf("Case #%d:\n",++Case);
        __gnu_pbds::priority_queue<Node>A,B,C;
        for(int i=1;i<=n;i++)
        {
            string op,s;
            int x;
            cin>>op;
            if(op=="push")
            {
                cin>>s>>x;
                if(s=="A") A.push((Node){x,i});
                else if(s=="B") B.push((Node){x,i});
            }
            else if(op=="pop")
            {
                cin>>s;
                if(s=="A"&&!A.empty())
                {
                    printf("%d\n",A.top().num);
                    A.pop();
                }
                else if(s=="B"&&!B.empty())
                {
                    printf("%d\n",B.top().num);
                    B.pop();
                }
                else
                {
                    printf("%d\n",C.top().num);
                    C.pop();
                }
            }
            else if(op=="merge")
            {
                cin>>s>>s;
                C.join(A);
                C.join(B);
            }
        }
    }
    return 0;
}