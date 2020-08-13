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
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 2e4 + 10, INF = 0x7fffffff;
int V, E, K; // V: 정점의 개수, E: 간선의 개수, K: 시작 정점 번호
int dist[MAX]; // dist[i]: 시작 정점으로부터 i번째 정점까지의 최단 거리
vector<pii> edge[MAX]; // first: 정점 번호, second: 비용
priority_queue<pii, vector<pii>, greater<pii> > pq; // 최소힙 - first: 비용, second: 정점 번호

void dijkstra() {
	dist[K] = 0; // 시작 정점으로의 거리는 0이다
	pq.push(pii(0, K)); // 시작 정점의 정보를 pq에 삽입

	while (!pq.empty()) { // pq가 비었을 경우 종료한다
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] < cost) continue; // 갱신될 가능성이 없는 경우
		for (const auto& elem : edge[curr]) { // curr에서 갈 수 있는 간선들을 살펴봄
			int nxt = elem.first;
			int ncost = elem.second;
			// 만약 현재 저장된 거리값이 curr을 경유해서 가는 것보다 클 경우 갱신한다
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
	// 최초 dist 배열을 INF값으로 초기화한다.
	fill(dist, dist + V + 1, INF);
	// 간선의 개수만큼 반복 후 edge 벡터에 저장
	for (int from, to, cost, i = 0; i < E; ++i) {
		cin >> from >> to >> cost;
		edge[from].push_back(pii(to, cost));
	}
	dijkstra(); // 다익스트라 알고리즘 실행
	for (int i = 1; i <= V; ++i) { // 출력
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}