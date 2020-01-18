//VOJ 2018年寒假网赛第六场 C
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

class Num{
public:
	Num(){}
	Num(double new_num) {
		memset(num,0,sizeof num); len=p=0;
		//puts("%");
		while (abs(round(new_num)-new_num)>=0.00001) p++,new_num*=10;
		//puts("&");
		int new_num_=round(new_num);
		while (new_num_) num[len++]=new_num_%10,new_num_/=10;
		//output();
	}
	void operator*=(Num &a) {
		//output();
		int tmp[144];
		memset(tmp,0,sizeof tmp);
		for (int i=0;i<len;i++)
			for (int j=0;j<a.len;j++) tmp[i+j]+=num[i]*a.num[j];
		memcpy(num,tmp,sizeof tmp);
		//output();
		len+=a.len-1; p+=a.p;
		for (int i=0;i<len;i++) num[i+1]+=num[i]/10,num[i]%=10;
		if (num[len]) len++;
		while (num[len-1]>9)
			num[len++]=num[len-2]/10,num[len-2]%=10; 
		//output();
	}
	void output() {
		//printf("%d %d\n",len,p);
		//for (int i=143;i>=0;i--) printf("%d ",num[i]);
		//printf("\n");
		for (int i=len-1;i>=p;i--) printf("%d",num[i]);
		if (p) putchar('.');
		int tmp;
		for (tmp=0;!num[tmp];tmp++);
		for (int i=p-1;i>=tmp;i--) printf("%d",num[i]);
		printf("\n");
	}
private: 
	int len,num[144],p;
};

int main() {
	double r;
	int n;
	while (~scanf("%lf%d",&r,&n)) {
		Num r_(r),ans;
		//puts("#");
		ans=r_;
		for (int i=1;i<n;i++) ans*=r_;
		ans.output();
	}
	return 0;
}
