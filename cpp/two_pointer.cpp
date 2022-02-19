/*
	* �� ������(two pointer): ȭ��ǥ 2���� ��� ���� Ž���ϸ� ������ ���Ѵ�.
	
	���ǹ� ���� ��, [L, R) ������ Ž���Ѵٰ� ���������� '=' ��ȣ�� �ΰ��ϰ� �����ؾ� �Ѵ�.
*/

// ��ǥ���� ����
// #2003 ������ ��2

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