/*
	* 벨만-포드(Bellman-Ford) 알고리즘
	 => 시작 정점으로부터 다른 정점들까지의 최단 거리를 구할건데, 음수 가중치가 존재해도 사용 가능한 알고리즘이다.
	 => 또한 음수 사이클의 발생 여부도 판단할 수 있다.
	
	- 연산에 사용되는 개념은 다익스트라 알고리즘과 비슷하지만 수행 과정에서는 차이가 있다.
	- 하지만 2중 for문을 사용해 정점의 개수만큼 모든 간선을 확인-갱신 과정을 거치기 때문에
	 연산을 수행하는 데 오랜 시간이 걸린다.

	1. 최단경로는 같은 정점을 두 번 지날 수 없다! -> 최대 사용 가능 간선 개수: V-1 개
	2. V-1번 연산을 수행하면서 최단 거리값의 근사값을 찾은 후 확정값을 찾아나가는 방식이다.
	 확정된 값을 모두 찾은 이후 최단 거리값이 다시 갱신된다면 음의 사이클이 존재한다고 판단.

	1. 최단 경로는 사이클을 포함할 수 없기 때문에 최대 V-1 개의 간선만 사용 가능하다.
	2. 따라서 V-1번 반복해주면 되는걸까? 모든 정점 및 간선에 대해 확인-갱신 과정을 거치고
	 한번 더 진행해준다. 즉 V번 반복한다. 만약 마지막 반복 때 갱신되는(더 작은 거리 발견) 경우가
	 존재한다면, 음의 사이클이 존재한다고 판단할 수 있다.

	시간복잡도 : O(VE)

	참고: https://www.crocus.co.kr/534
*/

// 11657 타임머신

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
typedef long long int llt;
const int MAX = 510;
const llt INF = 9e18;
int V, E;
bool minusCycle;
llt dist[MAX];
vector<pii> graph[MAX];

void bellman_ford() {
	dist[1] = 0;
	int iter = 1;
	while (iter <= V) { // (V - 1) + 1 번 반복한다
		for (int i = 1; i <= V; ++i) {
			if (dist[i] == INF) continue;
			for (const auto& elem : graph[i]) {
				int nxt = elem.first, d = elem.second;
				if (dist[nxt] > dist[i] + d) { // 경유했을 때 더 적은 가중치라면
					// 마지막 반복 때 갱신된다면 음수 사이클이 존재한다는 의미
					if (iter == V) {
						minusCycle = true;
						break;
					}
					dist[nxt] = dist[i] + d; // 갱신
				}
			}
		}
		iter++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> V >> E;
	fill(dist, dist + V + 1, INF); // dist 배열은 INF로 초기화
	for (int from, to, cost, i = 0; i < E; ++i) { // 입력
		cin >> from >> to >> cost;
		graph[from].push_back(pii(to, cost));
	}
	bellman_ford();
	if (minusCycle) cout << "-1\n"; // 음수 사이클이 발생한 경우
	else {
		for (int i = 2; i <= V; ++i)
			(dist[i] != INF) ? (cout << dist[i] << '\n') : (cout << "-1\n");
	}

	return 0;
}