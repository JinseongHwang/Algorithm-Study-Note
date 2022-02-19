/*
	* 네트워크 유량(Network Flow)
	 : 기존의 그래프에서 하나의 간선은 "연결된 두 정점의 번호", "가중치(cost)" 정도의 정보를 담고 있었다.
	  네트워크 유량 그래프에서는 "가중치(cost)" 대신에 "용량(capacity)" 이라는 개념으로 대체된다.
	  또한 유량(flow)라는 개념이 추가된 방향그래프이다.

	- 그래프에서 서로 다른 두 정점인 Source(S)와 Sink(T) 점이 주어진다.
	  S에서 발생한 유량을 T로 흘려 보내는 것이 목표이다.

	  => 1/3 의 의미는 "용량이 3인 간선에 유량이 1이다." 라는 의미이다.
	  => 정점 u에서 v로 가는 간선의 용량을 c(u, v), 실제 흐르는 유량을 f(u, v) 라고 표기한다.
	
	지켜져야 할 조건 또는 약속
	1. 각 간선에 흐르는 유량은 그 간선의 용량을 넘어설 수 없다.
	2. 정점 S와 T를 제외한 모든 정점에서 들어오는 유량 총합과 나가는 유량 총합이 같아야 한다.
	3. 정점 u에서 v로 유량이 흐르고 있다면, v에서 u로 흐르는 음수 유량이 있다고 생각한다.

	* 포드-풀커슨(Ford-Fulkerson)의 방법론 중 에드몬드-카프(Edmonds-Karp) 알고리즘을 채택함.
	* 에드몬드-카프(Edmonds-Karp) 알고리즘
	 1. 정점 S에서 T까지 잔여 용량이 남은 간선들만을 사용해서 BFS를 수행한다.
	 2. 더 이상 유량을 보낼 수 없게 증가 경로가 없어질 때까지 반복한다.
	 3. S에서 T로 탐색해나가다가 T에 도달한 순간 경로따라 되돌아가며 최소 유량을 찾아서 totalFlow에 더해준다.

	시간복잡도: O(V * E^2)
	
	참고: 알고리즘 문제해결전략(구종만 저)
	참고: https://kks227.blog.me/220804885235
*/

#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

const int MAX = 1000, INF = 987654321;
int V;
int capacity[MAX][MAX]; // capacity[u][v]: u에서 v로 흘려보낼 수 있는 용량
int flow[MAX][MAX]; // flow[u][v]: u에서 v로 흘러가는 유량(반대 방향의 경우에는 음수)

int networkFlow(int S, int T) {
	memset(flow, 0, sizeof(flow));

	int totalFlow = 0;
	while (1) {
		// BFS로 탐색
		int prev[MAX];
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		prev[S] = S;
		q.push(S);
		while (!q.empty() && prev[T] == -1) {
			int curr = q.front();
			q.pop();
			for (int nxt = 0; nxt < V; ++nxt) {
				// 잔여 용량이 남아있는 간선을 따라 탐색 && 방문하지 않은 정점
				if (capacity[curr][nxt] - flow[curr][nxt] > 0 && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = curr; // 거쳐온 정점을 기록
				}
			}
		}
		// 증가 경로가 없다면 종료한다.
		if (prev[T] == -1) break;
		// 증가 경로를 통해 얼마나 흘려보낼지 결정한다.
		int amount = INF;
		for (int p = T; p != S; p = prev[p]) {
			amount = min(capacity[prev[p]][p] - flow[prev[p]][p], amount);
		}
		// 증가 경로를 통해 유량을 흘려보낸다.
		for (int p = T; p != S; p = prev[p]) {
			flow[prev[p]][p] += amount;
			flow[p][prev[p]] -= amount;
		}
		totalFlow += amount;
	}

	return totalFlow;
}