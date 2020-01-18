//VOJ HDU 2087
#include <cstdio>
#include <cstring>

template <typename T>
void make_next(const T arr[],const int len,int next[]) {
	next[0]=0;
	for (int i=1,k=0;i<len;i++) {
		while (arr[i]!=arr[k]&&k) k=next[k-1];
		if (arr[i]==arr[k]) k++;
		next[i]=k;
	}
}

template <typename T>
int num_match(const T a[],const int len_a,const T b[],const int len_b) {
	int *next=new int[len_b],r=0;
	make_next<T>(b,len_b,next);
	for (int i=0,k=0;i<len_a;i++) {
		while (a[i]!=b[k]&&k) k=next[k-1];
		if (a[i]==b[k]) k++;
		if (k==len_b) r++,k=0;
	}
	delete[] next;
	return r;
}

int main() {
	char a[1001],b[1001];
	while (scanf("%s%s",a,b)==2) printf("%d\n",num_match<char>(a,strlen(a),b,strlen(b)));
	return 0;
}