#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const long long INF=1e18;
char number7[10][8][8]={
{
    "0000000",
    "0.....0",
    "0.....0",
    "0.....0",
    "0.....0",
    "0.....0",
    "0000000",
},
{
    "......1",
    "......1",
    "......1",
    "......1",
    "......1",
    "......1",
    "......1",
},
{
    "2222222",
    "......2",
    "......2",
    "2222222",
    "2......",
    "2......",
    "2222222",
},
{
    "3333333",
    "......3",
    "......3",
    "3333333",
    "......3",
    "......3",
    "3333333",
},
{
    "4.....4",
    "4.....4",
    "4.....4",
    "4444444",
    "......4",
    "......4",
    "......4",
},
{
    "5555555",
    "5......",
    "5......",
    "5555555",
    "......5",
    "......5",
    "5555555",
},
{
    "6666666",
    "6......",
    "6......",
    "6666666",
    "6.....6",
    "6.....6",
    "6666666",
},
{
    "7777777",
    "......7",
    "......7",
    "......7",
    "......7",
    "......7",
    "......7",
},
{
    "8888888",
    "8.....8",
    "8.....8",
    "8888888",
    "8.....8",
    "8.....8",
    "8888888",
},
{
    "9999999",
    "9.....9",
    "9.....9",
    "9999999",
    "......9",
    "......9",
    "9999999",
}
};
char number5[10][8][8]={
{
    "00000",
    "0...0",
    "0...0",
    "0...0",
    "00000",
},
{
    "....1",
    "....1",
    "....1",
    "....1",
    "....1",
},
{
    "22222",
    "....2",
    "22222",
    "2....",
    "22222",
},
{
    "33333",
    "....3",
    "33333",
    "....3",
    "33333",
},
{
    "4...4",
    "4...4",
    "44444",
    "....4",
    "....4",
},
{
    "55555",
    "5....",
    "55555",
    "....5",
    "55555",
},
{
    "66666",
    "6....",
    "66666",
    "6...6",
    "66666",
},
{
    "77777",
    "....7",
    "....7",
    "....7",
    "....7",
},
{
    "88888",
    "8...8",
    "88888",
    "8...8",
    "88888",
},
{
    "99999",
    "9...9",
    "99999",
    "....9",
    "99999",
}
};

char equals[8][8]=
{
    ".......",
    ".......",
    "=======",
    ".......",
    "=======",
    ".......",
    ".......",
};
char inf[3][8][8]=
{
{
    "IIIIIII",
    "...I...",
    "...I...",
    "...I...",
    "...I...",
    "...I...",
    "IIIIIII",
},
{
    "N.....N",
    "NN....N",
    "N.N...N",
    "N..N..N",
    "N...N.N",
    "N....NN",
    "N.....N",
},
{
    "FFFFFFF",
    "F......",
    "F......",
    "FFFFFFF",
    "F......",
    "F......",
    "F......",
}
};
long long qpow(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1)
        {
            if((__int128)res*a>INF) return -1;
            res*=a;
        }
        b>>=1;
        if(b==0) break;
        if((__int128)a*a>INF) return -1;
        a*=a;
    }
    return res;
}
vector<int>divide(long long v)
{
    if(v==0) return {0};
    vector<int>res;
    while(v)
        res.emplace_back(v%10),v/=10;
    reverse(res.begin(),res.end());
    return res;
}

void solve()
{
    long long x,y;
    cin>>x;
    char ch;
    cin>>ch;
    cin>>ch;
    cin>>y;
    cin>>ch;
    long long z=qpow(x,y);
    vector<vector<char>>res(10,vector<char>(1,'.'));
    auto print=[&](const char ch[8][8],int s,int t)
    {
        for(int i=0;i<s;i++)
            for(int j=0;j<t-s+1;j++)
                res[i].emplace_back('.');
        for(int i=t+1;i<(int)res.size();i++)
            for(int j=0;j<t-s+1;j++)
                res[i].emplace_back('.');
        for(int i=0;i<t-s+1;i++)
            for(int j=0;j<t-s+1;j++)
                res[s+i].emplace_back(ch[i][j]);
        for(int i=0;i<(int)res.size();i++)
            res[i].emplace_back('.');
        return;
    };
    vector<int>px=divide(x),py=divide(y);
    for(int u:px)
        print(number7[u],2,8);
    for(int u:py)
        print(number5[u],1,5);
    print(equals,2,8);
    if(z==-1)
    {
        for(auto ch:inf)
            print(ch,2,8);
    }
    else
    {
        vector<int>pz=divide(z);
        for(int u:pz)
            print(number7[u],2,8);
    }
    for(int i=0;i<(int)res.size();i++)
    {
        for(int j=0;j<(int)res[i].size();j++)
            cout<<res[i][j];
        cout<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0; 
}