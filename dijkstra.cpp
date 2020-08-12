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
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 2e4 + 10, INF = 0x7fffffff;
int V, E, S, dist[MAX];
bool visited[MAX];
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii> > pq; // �ּ���

void dijkstra(int start) {
	dist[start] = 0; // ���� ���������� �Ÿ��� 0�̴�
	pq.push(pii(0, start)); // ���� ������ �ְ� �����Ѵ�

	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		//} while (!pq.empty() && visited[curr]);
		} while (visited[curr]);
		
		if (visited[curr]) break;
		visited[curr] = true;

		for (const auto& nxt : graph[curr]) {
			if (dist[nxt.second] > dist[curr] + nxt.first) {
				dist[nxt.second] = dist[curr] + nxt.first;
				pq.push(pii(dist[nxt.second], nxt.second));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ���� dist �迭�� INF������ �ʱ�ȭ�����ش�.
	fill(dist, dist + MAX, INF);

	cin >> V >> E >> S;
	// ������ ����, ������ ����, ���� ����
	for (int u, v, w, i = 0; i < E; ++i) {
		cin >> u >> v >> w; // from, to, cost
		graph[u].push_back(pii(w, v)); // cost, to ����
	}
	dijkstra(S); // ���ͽ�Ʈ�� �˰��� ����

	for (int i = 1; i <= V; ++i) { // dist �迭 ���
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}