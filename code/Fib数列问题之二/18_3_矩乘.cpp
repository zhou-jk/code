// PrayerOJ 1380
#include <cstdio>
#include <cstring>

class Matrix
{
  public:
	Matrix(const long long n, const long long d,
		   const long long num = 0)
	{
		this->n = n;
		this->d = d;
		mat = new long long *[n];
		for (long long i = 0; i < n; i++)
		{
			mat[i] = new long long[n];
			memset(mat[i], 0, n * sizeof *mat[i]);
			mat[i][i] = num;
		}
	}
	Matrix(const long long n, const long long d,
		   const long long *mat)
	{
		this->n = n;
		this->d = d;
		this->mat = new long long *[n];
		for (long long i = 0; i < n; i++)
		{
			this->mat[i] = new long long[n];
			memcpy(this->mat[i], mat + i * n, n * sizeof *mat);
		}
	}
	Matrix &operator=(const Matrix &b)
	{
		n = b.n;
		d = b.d;
		mat = new long long *[n];
		for (long long i = 0; i < n; i++)
		{
			mat[i] = new long long[n];
			memcpy(mat[i], b.mat[i], n * sizeof *mat[i]);
		}
		return *this;
	}
	Matrix(const Matrix &b) { (*this) = b; }
	~Matrix()
	{
		for (int i = 0; i < n; i++) delete[] mat[i];
		delete[] mat;
	}
	Matrix *operator*(const Matrix &b)
	{
		Matrix *r = new Matrix(n, d);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					r->mat[i][j] =
						(r->mat[i][j] + mat[i][k] * b.mat[k][j])
						% d;
		return r;
	}
	void operator*=(const Matrix b)
	{
		Matrix *tmp = (*this) * b;
		(*this) = (*tmp);
		delete tmp;
	}
	Matrix *operator^(const long long _index)
	{
		Matrix *r = new Matrix(n, d, 1), tmp(*this);
		long long index = _index;
		while (index)
		{
			if (index & 1) (*r) *= tmp;
			tmp *= tmp;
			index >>= 1;
		}
		return r;
	}
	void operator^=(const long long index)
	{
		Matrix *tmp = (*this) ^ index;
		(*this) = (*tmp);
		delete tmp;
	}
	long long get(const int x, const int y)
	{
		return mat[x][y];
	}

  private:
	long long n, d, **mat;
};

int main()
{
	long long n, d;
	scanf("%lld%lld", &n, &d);
	long long tmp[2][2] = {{0, 1}, {1, 1}};
	Matrix mat(2, d, &tmp[0][0]);
	if (n <= 2)
		puts("1");
	else
	{
		mat ^= n - 2;
		printf("%lld", (mat.get(0, 1) + mat.get(1, 1)) % d);
	}
	return 0;
}