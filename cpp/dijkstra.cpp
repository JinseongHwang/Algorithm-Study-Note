/*
	* ���ͽ�Ʈ��(Dijkstra) �˰���: �ϳ��� �������κ��� �ٸ� ���������� �ִ� ��θ� ���ϴ� �˰���

	����! ����ġ�� ������ ��쿡�� ��� �Ұ����ϴ�.

	1. �Ÿ��� �����ϴ� �迭�� �����ؼ� ���� ���������� �Ÿ��� 0, �������� INF�� �ʱ�ȭ�Ѵ�.
	2. ���� �湮���� ���� ������ �� �Ÿ��� ���� ª�� ���� �ϳ��� ������ �湮�Ѵ�
	3. �ش� ������ ����� ������ �� ���� �湮���� ���� ����������� �Ÿ��� �����Ѵ�.
	4. 2~3 ������ ��� ������ �湮�� �� ���� �ݺ��Ѵ�.

	�ð����⵵ : (�켱���� ť�� ����� ���) O(E log V)

	����: https://blog.naver.com/kks227/220796029558
*/

// #1753 �ִܰ��

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 2e4 + 10, INF = 0x7fffffff;
int V, E, K; // V: ������ ����, E: ������ ����, K: ���� ���� ��ȣ
int dist[MAX]; // dist[i]: ���� �������κ��� i��° ���������� �ִ� �Ÿ�
vector<pii> edge[MAX]; // first: ���� ��ȣ, second: ���
priority_queue<pii, vector<pii>, greater<pii> > pq; // �ּ��� - first: ���, second: ���� ��ȣ

void dijkstra() {
	dist[K] = 0; // ���� ���������� �Ÿ��� 0�̴�
	pq.push(pii(0, K)); // ���� ������ ������ pq�� ����

	while (!pq.empty()) { // pq�� ����� ��� �����Ѵ�
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] < cost) continue; // ���ŵ� ���ɼ��� ���� ���
		for (const auto& elem : edge[curr]) { // curr���� �� �� �ִ� �������� ���캽
			int nxt = elem.first;
			int ncost = elem.second;
			// ���� ���� ����� �Ÿ����� curr�� �����ؼ� ���� �ͺ��� Ŭ ��� �����Ѵ�
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				pq.push(pii(dist[nxt], nxt));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E >> K;
	// ���� dist �迭�� INF������ �ʱ�ȭ�Ѵ�.
	fill(dist, dist + V + 1, INF);
	// ������ ������ŭ �ݺ� �� edge ���Ϳ� ����
	for (int from, to, cost, i = 0; i < E; ++i) {
		cin >> from >> to >> cost;
		edge[from].push_back(pii(to, cost));
	}
	dijkstra(); // ���ͽ�Ʈ�� �˰��� ����
	for (int i = 1; i <= V; ++i) { // ���
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}