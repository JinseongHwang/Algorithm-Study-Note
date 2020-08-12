/*
	* 프림(Prim) 알고리즘: Minimum Spanning Tree를 찾아내는 알고리즘 중 하나이다.

	* 대표적으로 MST를 찾아내는 알고리즘으로 Kruskal과 Prim이 있다.
	 - Kruskal => 정점이 간선에 비해 상대적으로 많을 때 유리 => O(E log E)
	 - Prim => 간선에 비해 정점이 상대적으로 많을 때 유리 => O(E log V)

	: 우선순위 큐(최소힙)을 사용해서 가장 작은 가중치의 정점을 선택한 후,
	그 인접한 정점들을 포함시켜 나가는 방법이다.

	1. 시작 정점을 선택하고, 그 정점으로의 가중치는 0이다.
	2. 시작 정점을 우선순위 큐에 삽입한다.
	3. 우선순위 큐의 top에(최소 가중치) 접근해서, 방문 여부 확인 후 포함시킨다.
	4. 포함 후 pop하고, 포함된 정점과 연결된 다른 정점들을 우선순위 큐에 삽입한다.
	5. 3~4 과정을 모든 정점을 방문할 때 까지 반복한다.

	시간복잡도 => O(E log V)

	참고 : https://www.weeklyps.com/entry/%ED%94%84%EB%A6%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Prims-algorithm
*/

// 대표적인 유형
// #1922 네트워크 연결

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
		if (visited[curr]) continue; // 이미 방문했다면 무시, 사이클 방지
		visited[curr] = true; // 방문 처리

		result += cost;
		if (++cnt == V) break; // 모든 정점을 방문했을 경우

		for (const auto& nxt : edge[curr]) { // 현재 정점과 연결된 정점
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