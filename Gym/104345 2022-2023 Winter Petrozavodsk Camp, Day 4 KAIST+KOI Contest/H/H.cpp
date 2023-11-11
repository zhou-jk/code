#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int p[N];
int suf[N];
int pos[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    set<int>s;
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1];
        if(p[i]==-1) suf[i]++;
        else pos[p[i]]=i;
    }
    for(int i=1;i<=n;i++)
        if(!pos[i]) s.insert(i);
    for(int i=1;i<=n;i++)
        if(p[i]==-1)
        {
            if(suf[i]<=4)
            {
                vector<int>b;
                for(int j=i;j<=n;j++)
                    if(p[j]==-1) b.emplace_back(j);
                vector<int>val;
                for(int v:s)
                    val.emplace_back(v);
                vector<int>res(b.size());
                iota(res.begin(),res.end(),0);
                bool flag=false;
                do
                {
                    for(int i=0;i<(int)b.size();i++)
                        p[b[i]]=val[res[i]];
                    bool ok=true; 
                    for(int j:b)
                    {
                        if((j-1>=1&&abs(p[j-1]-p[j])==1)||(j+1<=n&&abs(p[j+1]-p[j])==1))
                        {
                            ok=false;
                            break;
                        }
                    }
                    if(ok)
                    {
                        flag=true;
                        break;
                    }
                }
                while(next_permutation(res.begin(),res.end()));
                if(flag) break;
                else
                {
                    cout<<"-1";
                    return 0;
                }
            }
            else
            {
                bool flag=false;
                for(int v:s)
                {
                    if(i-1>=1&&abs(p[i-1]-v)==1) continue;
                    if(i+1<=n&&abs(p[i+1]-v)==1) continue;
                    p[i]=v;
                    
                    flag=true;
                    s.erase(s.lower_bound(v));
                    break;
                }
                if(!flag)
                {
                    cout<<"-1";
                    return 0;
                }
            }
        }
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
    return 0;
}