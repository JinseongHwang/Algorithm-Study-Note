/*
	* ������ ���� �˰���.
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

	// GCD: �ִ�����, LCM: �ּҰ����
	llt gcd = GCD(x, y);
	llt lcm = LCM(x, y, gcd);

	cout << x << "�� " << y << "��\n";
	cout << "�ִ�����: " << gcd << "\n";
	cout << "�ּҰ����: " << lcm << "\n";

	hr();

	// [0, limit] ������ �ִ� �Ҽ���� �� ������ ����Ѵ�.
	int limit = 111;
	sieve_of_eratosthenes(limit);

	hr();

	// target�� ���� ������� ������ ����Ѵ�.
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
	// 0���� limit������ �Ҽ��� ���
	// limit�� �ִ밪�� 100,000�̶�� ����.
	const int MAX = 1e5 + 1;
	bool is_prime[MAX];
	memset(is_prime, true, sizeof(is_prime)); // ��� true�� �ʱ�ȭ

	// 0�� 1�� �Ҽ��� �ƴϴ�.
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
	cout << "\n�Ҽ��� �� ����: " << cnt << "\n";
}

void number_of_divisor(int target) {
	int i, cnt = 0;
	vector<int> divisor; // ��¿�
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
	cout << target << "�� ����� ����: " << cnt << "\n";

	// �Ʒ��� ���
	cout << "���� ��: ";
	for (int elem : divisor) {
		cout << elem << " ";
	}
	sort(divisor.begin(), divisor.end());
	cout << "\n���� ��: ";
	for (int elem : divisor) {
		cout << elem << " ";
	}
}