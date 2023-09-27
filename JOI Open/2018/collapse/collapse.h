#include <cstdio>
#include <cstdlib>
#include <vector>

std::vector<int> simulateCollapse(
	int N,
	std::vector<int> T,
	std::vector<int> X,
	std::vector<int> Y,
	std::vector<int> W,
	std::vector<int> P
);

int main(int argc, char *argv[]) {
	int N, C, Q;
	scanf("%d%d%d", &N, &C, &Q);
	std::vector<int> T(C), X(C), Y(C);
	for(int i = 0; i < C; i++) {
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
	}
	std::vector<int> W(Q), P(Q);
	for(int i = 0; i < Q; i++) {
		scanf("%d%d", &W[i], &P[i]);
	}
	auto res = simulateCollapse(N, T, X, Y, W, P);
	for(auto i : res) {
		printf("%d\n", i);
	}
}
