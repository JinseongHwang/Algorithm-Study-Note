/*
	* Union-Find �˰���(= Disjoint set, = ���μ� ���� ã��)
	- �̸� �״�� ũ�� �з����ڸ� Union �Լ��� Find �Լ��� �̷���� �˰����̴�.
	- ����(�Ǵ� �׷���)���� ������ ����(�Ǵ� ����)�� ���� ���� ����(�׷���)�ȿ� ���� �ִ��� �Ǻ��� �� ����Ѵ�.
	
	Union-Find �˰����� ����ϱ� ���� �Ʒ��� ������ �����ؾ� �Ѵ�.
	1. ��ü ������ ���� ���� �κ� �������� �����Ǹ�, �������� �������� �ʴ´�.
	2. ��� ������ �������� ��ü �����̴�.
	
	���� �˰��� �����ο��� 2���� ��Ģ�� �Ѱǵ�, �̴� �����ϴ� ������� �ٸ� �� �ִ�.
	1. n�� ����� �θ� n������ ��ϵǾ� �ִٸ�(���� ���ٸ�), n�� ������ �ְ� ���� ����̰ų�, �ܵ�����̴�.
	2. �θ��� ��ȣ�� ���տ� ���� ����� ��ȣ�� �� ���� ���� ��ȣ�� �����Ѵ�.
*/

// #1717 ������ ǥ��

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 10;
int N, M, parent[MAX];

void init() {
	for (int i = 0; i <= N; ++i) parent[i] = i;
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}

int main() {
	scanf("%d %d", &N, &M);

	init(); // ���� �ڽ��� �θ�� �ڽ��̴�.

	int query, a, b;
	while (M--) {
		scanf("%d %d %d", &query, &a, &b);
		if (query) { // ���� ���տ� �����ִ��� �Ǻ�
			getParent(a) == getParent(b) ? printf("YES\n") : printf("NO\n");
		}
		else { // �� ������ ���Ѵ�
			unionParent(a, b);
		}
	}

	return 0;
}