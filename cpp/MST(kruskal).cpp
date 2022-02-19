/*
	* ũ�罺Į(Kruskal) �˰���: Minimum Spanning Tree�� ã�Ƴ��� �˰��� �� �ϳ��̴�.
	: ����ġ�� ���� �������� �׸����ϰ� MST�� ã�Ƴ��� �˰����̴�.

	* ��ǥ������ MST�� ã�Ƴ��� �˰������� Kruskal�� Prim�� �ִ�.
	 - Kruskal => ������ ������ ���� ��������� ���� �� ���� => O(E log E)
	 - Prim => ������ ���� ������ ��������� ���� �� ���� => O(E log V)

	���! - MST(Minimum Spanning Tree)�� ����?
		���� Spanning Tree�� ���� �˾ƺ���.
		Spanning Tree�� �׷����� ��� ������ �����ϴ� Ʈ�� ���¶�� ���� �ȴ�.
		�׷��ٸ� �ڿ������� �߿��� ��Ģ�� �����µ�, "�׻� ������ ����(E)�� ������ ����(V)���� 1�� �� ���� ����."
		�׷� �翬�� Minimum Spanning Tree�� �ּ� ������� ��� ������ ������ Ʈ���� �ǹ��Ѵ�.

		�ٽ� �������ڸ�, 4���� ������ �����ϴ� �׷��� �Ǵ� Ʈ�� ���·� �� �� �ִ�.
		1. �׷����� ��� ������ �����ؾ� �Ѵ�.
		2. ����� �������� ����ġ ���� �ּҰ� �Ǿ�� �Ѵ�.
		3. ��� ������ ���� ����Ǿ� �־�� �Ѵ�.(�и��� ���°� �ƴϿ��� �Ѵ�.)
		4. ����Ŭ�� �߻����� �ʾƾ� �Ѵ�.

	�׷��ٸ� ����Ŭ �˻�� ��� �ұ�?
		�� ��, Union-Find �˰����� ���ȴ�.
		������ �����ϱ� ����, �и��� �� �׷���(�Ǵ� ����)�� ���� ���� ���� �Ʒ� �ִٸ�,
		������ �ÿ� ����Ŭ�� �߻��ϰ� �Ǵ� ������ �̿��Ѵ�.

	>>> ũ�罺Į �˰����� ���� ����
	1. ��� �������� ������ ����ġ�� �������� �������� �����Ѵ�.
	2. ����ġ�� ���� ������ �����ؼ� ����Ŭ�� �߻��ϴ��� �˻� ��, �׷����� �߰��Ѵ�.
	3. 2���� ������ MST�� �ϼ��� ��(������ ������ V - 1���� �� ��)���� �ݺ��Ѵ�.

	�ð����⵵ => O(E log E)

	���� : https://www.weeklyps.com/entry/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Kruskals-algorithm
*/

// ��ǥ���� ����
// #1922 ��Ʈ��ũ ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1005; // ������ �ִ� ����
int V, E, parent[MAX], result; // Vertex, Edge, �θ� �迭, �����

struct Edge { // ���� �ϳ��� ������ ����
	// from: ���� ����, to: �� ����, cost: ����ġ
	int from, to, cost;
	// ����ġ�� �������� �����ϱ� ���ؼ� ������ �����ε�
	bool operator<(const Edge& e) const { return this->cost < e.cost; }
};
vector<Edge> graph; // ���� ������ �����ϴ� �׷��� ����

// ===== Union-Find =====
void initParent(int v) { // �θ� �迭 �ʱ�ȭ
	for (int i = 0; i <= v; ++i) parent[i] = i;
}

int getParent(int a) { // ���� a�� ������ ��ȯ
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]); // �θ� �迭 �ֽ�ȭ
}

void unionParent(int a, int b) { // �� ������ ����
	a = getParent(a);
	b = getParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}

bool hasSameParent(int a, int b) { // ���� ������ �������� �Ǻ�, ����Ŭ Ȯ��
	a = getParent(a);
	b = getParent(b);
	return a == b ? true : false;
}
// ======================

void kruskal() { // ũ�罺Į �˰���
	int cnt = 0; // ���� ����� ������ ����
	sort(graph.begin(), graph.end()); // ����ġ ���� �������� ����
	for (const auto& edge : graph) { 
		int f = edge.from, t = edge.to, c = edge.cost;
		if (!hasSameParent(f, t)) { // ����Ŭ �߻����� �ʴ´ٸ�
			unionParent(f, t); // �� �׷����� ����
			cnt++; // ������ �ϳ� �� ��������� �˸�
			result += c; // ����ġ ������
		}
		if (cnt == V - 1) break; // MST���� E == V - 1 �̻����� ã�� �ʿ� ����
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E; // ����, ���� ���� �Է¹���
	initParent(V); // �θ� �迭 �ʱ�ȭ

	// �׷��� ���� �Է¹޾Ƽ� �׷��� ���Ϳ� push back
	for (int a, b, c, i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		Edge e = { a, b, c };
		graph.push_back(e);
	}

	kruskal(); // ũ�罺Į �˰��� ����

	cout << result << "\n"; // ����� ���

	return 0;
}