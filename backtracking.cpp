/*
	* 백트래킹(퇴각탐색)
	: 백트래킹으로 순열, 중복순열, 조합, 중복조합만 구현할 수 있으면 모든걸 할 수 있다고 생각한다.

	N과 M시리즈, N-Queen은 풀어보자.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 6;
int selected[MAX * 3]; // 중복** 들을 위해 선택 가능한 값의 개수를 늘려준다.
bool visited[MAX];

void combination(int input[], int r, int index, int depth); // 조합
void r_combination(int input[], int r, int index, int depth); // 중복조합
void permutation(int input[], int r, int depth); // 순열
void r_permutation(int input[], int r, int depth); // 중복 순열

int main() {

	// 임의의 숫자 6개를 선언한다.
	int input[MAX] = { 12,33,21,6,54,90 };

	// 순서가 상관없다면 정렬을 하게되면 보기 편해집니다.
	sort(input, input + MAX);

	// 보통 조합을 표현할 때, "C(n, r)" 또는 "nCr"과 같은 표현을 많이 사용한다.
	// 위에서 숫자를 6개 주어졌으므로 n = 6 이다.
	// r값을 설정해보자.
	int r = 4;

	// 가장 많이 쓰이는 조합
	combination(input, r, 0, 0);

	// 중복 조합
	r_combination(input, r, 0, 0);

	// 순열
	permutation(input, r, 0);

	// 중복순열
	r_permutation(input, r, 0);

	return 0;
}

void combination(int input[], int r, int index, int depth) {
	if (depth == r) { // 선택된 원소의 개수와 r이 동일할 때, 출력한다.
		for (int i = 0; i < r; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < MAX; i++) {
		if (!visited[i]) {
			selected[depth] = input[i];
			visited[i] = true;
			combination(input, r, i + 1, depth + 1);
			visited[i] = false;
		}
	}
}

void r_combination(int input[], int r, int index, int depth) {
	// 조합에서 방문 체크 없애주고, 다음 index 시작을 현재 i값으로 설정한다.
	if (depth == r) {
		for (int i = 0; i < r; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < MAX; i++) {	
		selected[depth] = input[i];
		r_combination(input, r, i, depth + 1);
	}
}

void permutation(int input[], int r, int depth) {
	// 조합에서 index 매개변수만 없애주면 똑같다.
	if (depth == r) {
		for (int i = 0; i < r; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < MAX; i++) {
		if (!visited[i]) {
			selected[depth] = input[i];
			visited[i] = true;
			permutation(input, r, depth + 1);
			visited[i] = false;
		}
	}
}

void r_permutation(int input[], int r, int depth) {
	// 조합에서 방문 체크랑 index 매개변수만 없애주면 다 똑같다.
	// 똑같은 원소에 재참조가 가능하기 때문에 방문 체크는 하지 말아야 한다.
	// 중간 원소를 선택했어도, 그 다음 원소는 첫 번째 원소가 될 수 있기 때문에 index도 제거해야 한다.
	if (depth == r) {
		for (int i = 0; i < r; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < MAX; i++) {
		selected[depth] = input[i];
		r_permutation(input, r, depth + 1);
	}
}