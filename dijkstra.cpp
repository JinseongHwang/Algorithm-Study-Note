/*
	* 다익스트라(Dijkstra) 알고리즘: 하나의 정점으로부터 다른 정점까지의 최단 경로를 구하는 알고리즘

	주의! 가중치가 음수일 경우에는 사용 불가능하다.

	1. 거리를 저장하는 배열을 선언해서 시작 정점으로의 거리는 0, 나머지는 INF로 초기화한다.
	2. 아직 방문하지 않은 정점들 중 거리가 가장 짧은 정점 하나를 선택해 방문한다
	3. 해당 정점과 연결된 정점들 중 아직 방문하지 않은 정점들까지의 거리를 갱신한다.
	4. 2~3 과정을 모든 정점을 방문할 때 까지 반복한다.

	시간복잡도 : (우선순위 큐를 사용할 경우) O(E log V)

	참고: https://blog.naver.com/kks227/220796029558

*/

// #1753 최단경로

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
priority_queue<pii, vector<pii>, greater<pii> > pq; // 최소힙

void dijkstra(int start) {
	dist[start] = 0; // 시작 정점으로의 거리는 0이다
	pq.push(pii(0, start)); // 시작 정점만 넣고 시작한다

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

	// 최초 dist 배열을 INF값으로 초기화시켜준다.
	fill(dist, dist + MAX, INF);

	cin >> V >> E >> S;
	// 정점의 개수, 간선의 개수, 시작 정점
	for (int u, v, w, i = 0; i < E; ++i) {
		cin >> u >> v >> w; // from, to, cost
		graph[u].push_back(pii(w, v)); // cost, to 삽입
	}
	dijkstra(S); // 다익스트라 알고리즘 실행

	for (int i = 1; i <= V; ++i) { // dist 배열 출력
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}