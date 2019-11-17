#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
const int N=10001;
char k[N],m[N];
int main()
{
    scanf("%s%s",k,m);
	for(int i=0;i<strlen(k);i++)
	    if(isupper(k[i])) k[i]=tolower(k[i]);
    int j=0;
	for(int i=0;i<strlen(m);i++)
    {
		if(islower(m[i]))
        {
			m[i]-=k[j++]-'a';
			if(m[i]<'a') m[i]+=26;
		}
		else
        {
			m[i]-=k[j++]-'a';
			if(m[i]<'A') m[i]+=26;
		}
		if(j>=strlen(k)) j=0;
	}
	printf("%s",m);
    return 0;
}