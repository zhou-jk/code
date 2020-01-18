//Virtual Judge UVA 11732
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

#define N 4000001

struct Node{
	int head,next,count;
	char c;
} node[N];

int time,count;

void add_node(int k,char c) {
	node[++count].c=c;
	node[count].next=node[k].head;
	node[k].head=count;
	node[count].head=0;
	node[count].count=0;
}

long long build(char *s) {
	int k=0,l=strlen(s);
	long long t=0;
	for (int i=0;i<=l;i++) {
		int j=node[k].head;
	    while (j&&node[j].c!=s[i]) j=node[j].next;
	    if (!j) {
	    	add_node(k,s[i]);
	    	j=count;
		}
		t+=node[k].count+node[j].count;
		//printf("%d %d\n",node[k].count,node[j].count);
		node[k].count++;
		k=j;
	}
	node[k].count++; 
	return t;
}

int main() {
	char s[1002];
	long long t;
	int n;
	while (scanf("%d",&n)&&n>0) {
		count=0;
		node[0].head=0;
		node[0].count=0;
		t=0;
		for (int i=0;i<n;i++) {
			scanf("%s",s);
			t+=build(s);
		}
		printf("Case %d: %lld\n",++time,t);
	}
	return 0;
}
