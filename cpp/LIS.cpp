/*
	* 가장 긴 증가하는 부분 수열(LIS: Longest Increasing Subsequence)
*/

// O(N^2)

#include <cstdio>

using namespace std;

const int MAX = 1005;
int N, arr[MAX], dp[MAX];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", arr + i);

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int result = 0;
    for (int v : dp) {
        if (result < v) result = v;
    }
    printf("%d\n", result);

	return 0;
}