/*
	* 투 포인터(two pointer): 화살표 2개를 들고 순차 탐색하며 조건을 비교한다.
	
	조건문 만들 때, [L, R) 범위로 탐색한다고 가정했으며 '=' 기호에 민감하게 반응해야 한다.
*/

// 대표적인 유형
// #2003 수들의 합2

#include <cstdio>

using namespace std;

const int MAX = 1e4 + 10;
int N, M, arr[MAX];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", arr + i);

	int L, R, sum, result;
	L = R = sum = result = 0;

	while (L <= R) {
		if (sum <= M && R <= N) {
			if (sum == M) result++;
			sum += arr[R];
			R++;
		}
		else { // sum > M
			sum -= arr[L];
			L++;
		}
	}
	printf("%d\n", result);

	return 0;
}