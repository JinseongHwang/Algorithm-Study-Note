/*
	* 프림(Prim) 알고리즘: MST를 찾아내는 알고리즘 중 하나이다.
	 - 우선순위 큐(최소힙)을 사용해서 가장 작은 가중치의 정점을 선택한 후,
	 그 인접한 정점들의 가중치 값을 비교해서 갱신 여부를 결정한다.
	 - 처음에



	 시간복잡도 => O(ElogV)
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
bool visited[MAX]; // visited[i] : i 가 이전에 선택된 정점인가?
vector<pii> edge[MAX]; // edge[i] : i 노드에서 출발하는 간선, first = 비용, second = 목적지
priority_queue<pii, vector<pii>, greater<pii> > pq; // 선택될 가능성이 있는 간선을 저장

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
		cin >> u >> v >> c; // 시작점, 끝점, 비용
		edge[u].push_back(pii(c, v));
		edge[v].push_back(pii(c, u));
	}
	pq.push(pii(0, 1));
	// 1번 정점부터 시작한다고 가정, 1번 정점으로의 가중치는 0이다.
	cout << prim() << '\n'; // 프림 알고리즘 실행

	return 0;
}