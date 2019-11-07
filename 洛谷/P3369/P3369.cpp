#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
multiset<int>tree;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1) tree.insert(x);
        else if(op==2) tree.erase(tree.lower_bound(x));
        else if(op==3) printf("%d\n",distance(tree.begin(),tree.lower_bound(x))+1);
        else if(op==4)
        {
            multiset<int>::iterator it;
            it=tree.begin();
            advance(it,x-1);
            printf("%d\n",*it);
        }
        else if(op==5) printf("%d\n",*--tree.lower_bound(x));
        else if(op==6) printf("%d\n",*tree.upper_bound(x));
    }
    return 0;
}