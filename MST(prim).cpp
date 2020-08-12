/*
	* ����(Prim) �˰���: Minimum Spanning Tree�� ã�Ƴ��� �˰��� �� �ϳ��̴�.

	* ��ǥ������ MST�� ã�Ƴ��� �˰������� Kruskal�� Prim�� �ִ�.
	 - Kruskal => ������ ������ ���� ��������� ���� �� ���� => O(E log E)
	 - Prim => ������ ���� ������ ��������� ���� �� ���� => O(E log V)

	: �켱���� ť(�ּ���)�� ����ؼ� ���� ���� ����ġ�� ������ ������ ��,
	�� ������ �������� ���Խ��� ������ ����̴�.

	1. ���� ������ �����ϰ�, �� ���������� ����ġ�� 0�̴�.
	2. ���� ������ �켱���� ť�� �����Ѵ�.
	3. �켱���� ť�� top��(�ּ� ����ġ) �����ؼ�, �湮 ���� Ȯ�� �� ���Խ�Ų��.
	4. ���� �� pop�ϰ�, ���Ե� ������ ����� �ٸ� �������� �켱���� ť�� �����Ѵ�.
	5. 3~4 ������ ��� ������ �湮�� �� ���� �ݺ��Ѵ�.

	�ð����⵵ => O(E log V)

	���� : https://www.weeklyps.com/entry/%ED%94%84%EB%A6%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Prims-algorithm
*/

// ��ǥ���� ����
// #1922 ��Ʈ��ũ ����

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1010, INF = 0x7fffffff;
int V, E, cnt;
bool visited[MAX]; // visited[i] : i �� ������ ���õ� �����ΰ�?
vector<pii> edge[MAX]; // edge[i] : i ��忡�� ����ϴ� ����, first = ���, second = ������
priority_queue<pii, vector<pii>, greater<pii> > pq; // ���õ� ���ɼ��� �ִ� ������ ����

int prim() {
	int result = 0;
	while (!pq.empty()) {
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visited[curr]) continue; // �̹� �湮�ߴٸ� ����, ����Ŭ ����
		visited[curr] = true; // �湮 ó��

		result += cost;
		if (++cnt == V) break; // ��� ������ �湮���� ���

		for (const auto& nxt : edge[curr]) { // ���� ������ ����� ����
			if (visited[nxt.second]) continue;
			pq.push(nxt);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int u, v, c, i = 0; i < E; ++i) {
		cin >> u >> v >> c; // ������, ����, ���
		edge[u].push_back(pii(c, v));
		edge[v].push_back(pii(c, u));
	}
	pq.push(pii(0, 1));
	// 1�� �������� �����Ѵٰ� ����, 1�� ���������� ����ġ�� 0�̴�.
	cout << prim() << '\n'; // ���� �˰��� ����

	return 0;
}