/*
	* 정수론 관련 알고리즘.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <memory.h>

using namespace std;

typedef long long int llt;

__inline void hr() { cout << "--------------------------------------\n"; }
llt GCD(llt a, llt b);
llt LCM(llt a, llt b, llt g);
void sieve_of_eratosthenes(int limit);
void number_of_divisor(int target);

int main() {

	llt x = 20;
	llt y = 68;

	// GCD: 최대공약수, LCM: 최소공배수
	llt gcd = GCD(x, y);
	llt lcm = LCM(x, y, gcd);

	cout << x << "와 " << y << "의\n";
	cout << "최대공약수: " << gcd << "\n";
	cout << "최소공배수: " << lcm << "\n";

	hr();

	// [0, limit] 범위에 있는 소수들과 총 개수를 출력한다.
	int limit = 111;
	sieve_of_eratosthenes(limit);

	hr();

	// target의 양의 약수들의 개수를 출력한다.
	int target = 64;
	number_of_divisor(target);

	return 0;
}

llt GCD(llt a, llt b) {
	return b == 0 ? a : GCD(b, a % b);
}

llt LCM(llt a, llt b, llt g) {
	return (a * b) / g;
}

void sieve_of_eratosthenes(int limit) {
	// 0부터 limit까지의 소수를 출력
	// limit의 최대값이 100,000이라고 가정.
	const int MAX = 1e5 + 1;
	bool is_prime[MAX];
	memset(is_prime, true, sizeof(is_prime)); // 모두 true로 초기화

	// 0과 1은 소수가 아니다.
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= limit; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= limit; j += i) {
			is_prime[j] = false;
		}
	}
	
	int cnt = 0;
	for (int i = 2; i <= limit; i++) {
		if (is_prime[i]) {
			cout << i << " ";
			cnt++;
		}
	}
	cout << "\n소수의 총 개수: " << cnt << "\n";
}

void number_of_divisor(int target) {
	int i, cnt = 0;
	vector<int> divisor; // 출력용
	for (i = 1; i * i < target; i++) {
		if (target % i == 0) {
			cnt += 2;
			divisor.push_back(i);
			divisor.push_back(target / i);
		}
	}
	if (i * i == target) {
		cnt++;
		divisor.push_back(i);
	}
	cout << target << "의 약수의 개수: " << cnt << "\n";

	// 아래는 출력
	cout << "정렬 전: ";
	for (int elem : divisor) {
		cout << elem << " ";
	}
	sort(divisor.begin(), divisor.end());
	cout << "\n정렬 후: ";
	for (int elem : divisor) {
		cout << elem << " ";
	}
}