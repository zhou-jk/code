#include<iostream>
#include<cstdio>
#include"interaction.h"
using namespace std;
vector<int> res;
int main()
{
    int n=get_num();
    for(int i=0;i<n;i++)
    {
        int l=0,r=1000000;
        while(l<=r)
        {
            int mid=(l+r)/2,val;
            val=guess(i,mid);
            if(val==-1) l=mid+1;
            if(val==1) r=mid-1;
            if(val==0)
            {
                res.push_back(mid);
                break;
            }
        }
    }
    submit(res);
    return 0;
}