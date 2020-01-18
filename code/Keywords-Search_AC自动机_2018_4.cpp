//HDU 2222
#include <cstdio>

const char FIRST_CH='a',LAST_CH='z';
const int N_PAT=10000,LEN_STR=1000000,LEN_PAT=50,N_KIND_CHAR=LAST_CH-FIRST_CH+1;

class Node
{
public:
	Node()
	{
		next=NULL;
		for (int i=0; i<N_KIND_CHAR; i++) p[i]=NULL;
		n_end=0;
	}
	~Node()
	{
		for (int i=0; i<N_KIND_CHAR; i++)
			if (p[i]!=NULL) delete p[i];
	}
	friend void insert(const char *const str);
	friend void make_next();
	friend int solve(const char *const str);
private:
	Node *next,*p[N_KIND_CHAR];
	int n_end;
} *q[N_PAT*LEN_PAT],*trie;
char str[LEN_STR+1],pat[LEN_PAT+1];

void insert(const char *const str)
{
	Node *p=trie;
	int k;
	for (int i=0; str[i]; i++)
	{
		k=str[i]-FIRST_CH;
		if (p->p[k]==NULL) p->p[k]=new Node;
		p=p->p[k];
	}
	p->n_end++;
}

void make_next()
{
	Node *p1,*p2;
	int l=0,r=0;
	q[r++]=trie;
	while (l<r)
	{
		p1=q[l++]; p2=NULL;
		for (int i=0; i<N_KIND_CHAR; i++)
			if (p1->p[i]!=NULL)
			{
				if (p1==trie) p1->p[i]->next=trie;
				else
				{
					p2=p1->next;
					while (p2!=NULL)
					{
						if (p2->p[i]!=NULL)
						{
							p1->p[i]->next=p2->p[i];
							break;
						}
						p2=p2->next;
					}
					if (p2==NULL) p1->p[i]->next=trie;
				}
				q[r++]=p1->p[i];
			}
	}
}

int solve(const char *const str)
{
	Node *p1=trie,*p2;
	int ret=0,k;
	for (int i=0; str[i]; i++)
	{
		k=str[i]-FIRST_CH;
		while (p1->p[k]==NULL&&p1!=trie) p1=p1->next;
		p1=p1->p[k]==NULL?trie:p1->p[k];
		p2=p1;
		while (p2!=trie&&p2->n_end>-1)
		{
			ret+=p2->n_end;
			p2->n_end=-1;
			p2=p2->next;
		}
	}
	return ret;
}

int main()
{
	int t,n;
	for (scanf("%d",&t); t; t--)
	{
		trie=new Node;
		scanf("%d",&n);
		for (int i=0; i<n; i++)
		{
			scanf("%s",pat);
			insert(pat);
		}
		make_next();
		scanf("%s",str);
		printf("%d\n",solve(str));
		delete trie;
	}
	return 0;
}