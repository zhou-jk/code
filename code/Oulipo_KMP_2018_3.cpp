//VOJ HDU 1686
#include <cstdio>
#include <cstring>

template <typename T>
void make_next(const T arr[],const int len,int next[]) {
	next[0]=0;
	for (int i=1,k=0;i<len;i++) {
		while (k&&arr[i]!=arr[k]) k=next[k-1];
		if (arr[i]==arr[k]) k++;
		next[i]=k;
	}
}

template <typename T>
int num_match(const T a[],const int len_a,const T b[],const int len_b) {
	int *next=new int[len_b],r=0;
	make_next<T>(b,len_b,next);
	for (int i=0,k=0;i<len_a;i++) {
		while (k&&a[i]!=b[k]) k=next[k-1];
		if (a[i]==b[k]) k++;
		if (k==len_b) r++;
	}
	delete[] next;
	return r;
}

int main() {
	int t;
	char a[1000001],b[10001];
	scanf("%d\n",&t);
	for (int i=0;i<t;i++) {
		gets(b); gets(a);
		printf("%d\n",num_match<char>(a,strlen(a),b,strlen(b)));
	}
	return 0;
}