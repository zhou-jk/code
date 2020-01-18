//VOJ HDU 1575
#include <cstdio>
#include <cstring>

const int d=9973;
class Matrix{
public:
	Matrix(const int n) {
		this->n=n;
		mat=new int*[n];
		for (int i=0;i<n;i++) {
			mat[i]=new int[n];
			memset(mat[i],0,n*sizeof *mat[i]);
		}
	}
	Matrix(const int n,const int num) {
		this->n=n;
		mat=new int*[n];
		for (int i=0;i<n;i++) {
			mat[i]=new int[n];
			memset(mat[i],0,n*sizeof *mat[i]);
			mat[i][i]=num;
		}
	}
	Matrix(const int n,const int **mat) {
		this->n=n;
		this->mat=new int*[n];
		for (int i=0;i<n;i++) {
			this->mat[i]=new int[n];
			memcpy(this->mat[i],mat[i],n*sizeof *mat[i]);
		}
	}
	Matrix& operator=(const Matrix &b) {
		//puts("c");
		n=b.n;
		mat=new int*[n];
		for (int i=0;i<n;i++) {
			mat[i]=new int[n];
			memcpy(mat[i],b.mat[i],n*sizeof *mat[i]);
			/*for (int j=0;j<n;j++) printf("%d ",mat[i][j]);
			printf("\n");*/
		}
		//printf("\n\n");
		return *this;
	}
	Matrix(const Matrix &b) {
		(*this)=b;
	}
	~Matrix() {
		//puts("~");
		for (int i=0;i<n;i++) delete[] mat[i];
		delete[] mat;
	}
	void input() {
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) scanf("%d",&mat[i][j]);
	}
	Matrix* operator*(const Matrix &b) {
		Matrix *r=new Matrix(n);
		/*puts("*");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",r->mat[i][j]);
			printf("\n");
		}
		printf("\n");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",b.mat[i][j]);
			printf("\n");
		}
		printf("\n");*/
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				for (int k=0;k<n;k++) r->mat[i][j]=(r->mat[i][j]+mat[i][k]*b.mat[k][j])%d;
		/*for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",r->mat[i][j]);
			printf("\n");
		}
		printf("\n\n");*/
		return r;
	}
	void operator*=(const Matrix b) {
		/*puts("*=");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",mat[i][j]);
			printf("\n");
		}
		printf("\n");*/
		Matrix *tmp=(*this)*b;
		/*puts("*=_");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",tmp->mat[i][j]);
			printf("\n");
		}
		printf("\n");*/
		(*this)=(*tmp);
		/*for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",mat[i][j]);
			printf("\n");
		}
		printf("\n");*/
		delete tmp;
		/*for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",mat[i][j]);
			printf("\n");
		}
		printf("\n\n");*/
	}
	Matrix* operator^(const int _index) {
		Matrix *r=new Matrix(n,1),tmp(*this);
		/*puts("^");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",r->mat[i][j]);
			printf("\n");
		}
		printf("\n");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",tmp.mat[i][j]);
			printf("\n");
		}
		printf("\n");*/
		int index=_index;
		while (index) {
			//puts("&&");
			if (index&1) (*r)*=tmp;
			tmp*=tmp;
			index>>=1;
		}
		/*puts("^_");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",r->mat[i][j]);
			printf("\n");
		}
		printf("\n\n");*/
		return r;
	}
	void operator^=(const int index) {
		/*puts("^=");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",mat[i][j]);
			printf("\n");
		}
		printf("\n");*/
		Matrix *tmp=(*this)^index;
		(*this)=(*tmp);
		delete tmp;
		/*puts("^=_");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) printf("%d ",mat[i][j]);
			printf("\n\n");
		}*/
	}
	int tr() {
		int r=0;
		for (int i=0;i<n;i++) r=(r+mat[i][i])%d;
		return r;
	}
private:
	int n,**mat;
};

int main() {
	int t,n,k;
	scanf("%d",&t);
	for (int i=0;i<t;i++) {
		//puts("!!");
		scanf("%d%d",&n,&k);
		Matrix mat(n);
		mat.input();
		//puts("**");
		mat^=k;
		printf("%d\n",mat.tr());
	}
	return 0;
}