/*
	* ����(Prim) �˰���: MST�� ã�Ƴ��� �˰��� �� �ϳ��̴�.
	 - �켱���� ť(�ּ���)�� ����ؼ� ���� ���� ����ġ�� ������ ������ ��,
	 �� ������ �������� ����ġ ���� ���ؼ� ���� ���θ� �����Ѵ�.
	 - ó����



	 �ð����⵵ => O(ElogV)
*/

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
		if (visited[curr]) continue;
		visited[curr] = 1;

		result += cost;
		if (++cnt == V) break;

		for (const auto& nxt : edge[curr]) {
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