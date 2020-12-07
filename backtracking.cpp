/*
	* ��Ʈ��ŷ(��Ž��)
	: ��Ʈ��ŷ���� ����, �ߺ�����, ����, �ߺ����ո� ������ �� ������ ���� �� �� �ִٰ� �����Ѵ�.

	N�� M�ø���, N-Queen�� Ǯ���.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 6;
int selected[MAX * 3]; // �ߺ�** ���� ���� ���� ������ ���� ������ �÷��ش�.
bool visited[MAX];

void combination(int input[], int r, int index, int depth); // ����
void r_combination(int input[], int r, int index, int depth); // �ߺ�����
void permutation(int input[], int r, int depth); // ����
void r_permutation(int input[], int r, int depth); // �ߺ� ����

int main() {

	// ������ ���� 6���� �����Ѵ�.
	int input[MAX] = { 12,33,21,6,54,90 };

	// ������ ������ٸ� ������ �ϰԵǸ� ���� �������ϴ�.
	sort(input, input + MAX);

	// ���� ������ ǥ���� ��, "C(n, r)" �Ǵ� "nCr"�� ���� ǥ���� ���� ����Ѵ�.
	// ������ ���ڸ� 6�� �־������Ƿ� n = 6 �̴�.
	// r���� �����غ���.
	int r = 4;

	// ���� ���� ���̴� ����
	combination(input, r, 0, 0);

	// �ߺ� ����
	r_combination(input, r, 0, 0);

	// ����
	permutation(input, r, 0);

	// �ߺ�����
	r_permutation(input, r, 0);

	return 0;
}

void combination(int input[], int r, int index, int depth) {
	if (depth == r) { // ���õ� ������ ������ r�� ������ ��, ����Ѵ�.
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
	// ���տ��� �湮 üũ �����ְ�, ���� index ������ ���� i������ �����Ѵ�.
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
	// ���տ��� index �Ű������� �����ָ� �Ȱ���.
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
	// ���տ��� �湮 üũ�� index �Ű������� �����ָ� �� �Ȱ���.
	// �Ȱ��� ���ҿ� �������� �����ϱ� ������ �湮 üũ�� ���� ���ƾ� �Ѵ�.
	// �߰� ���Ҹ� �����߾, �� ���� ���Ҵ� ù ��° ���Ұ� �� �� �ֱ� ������ index�� �����ؾ� �Ѵ�.
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