/*
	* 플로이드-워셜(Floyd-Warshall) 알고리즘: 모든 정점 쌍 사이의 최단 거리를 구하는 알고리즘.
	
	* 음수 가중치가 존재해도 사용 가능하다!

	1. 최단 거리값을 저장하는 dist 배열을 2차원 배열로 생성한다.
	2. 배열의 모든 값들을 INF값으로 초기화해주되, 자기 자신으로의 거리는 0으로 설정한다.
	3. 경유점을 바꿔가면서 모든 최단 거리값을 구한다.
	
	시간복잡도: O(V^3)
*/

// #11404 플로이드

#include <iostream>
#include <algorithm>
using namespace std;

// INF 값을 INT_MAX 등의 값으로 설정할 시,
// 경유점에서 두 가중치를 합해서 비교할 시 int 타입 오버플로우가 발생할 수 있으니
// 조건문을 추가하거나, 8byte 타입으로 변경하거나, INF의 값을 (INT_MAX / 2) 이하의 값으로 변경하자
const int MAX = 110, INF = 987654321;
int V, E, dist[MAX][MAX]; // dist[i][j]: 정점 i에서 정점 j로 가는 최단 경로

void floyd_warshall() { // 플로이드 워셜 알고리즘
	for (int via = 1; via <= V; ++via) // 경유점
		for (int from = 1; from <= V; ++from) // source
			for (int to = 1; to <= V; ++to) // destination
				dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
}

void printDistance() { // 출력
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			(dist[i][j] != INF) ? (cout << dist[i][j] << ' ') : (cout << "0 ");
		} cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;

	for (int i = 0; i <= V; ++i) { // dist 배열 전처리
		fill(dist[i], dist[i] + V + 1, INF); // INF값으로 초기화
		dist[i][i] = 0; // 자기 자신으로의 가중치는 0이다.
	}

	for (int from, to, cost, i = 0; i < E; ++i) { // 입력
		cin >> from >> to >> cost;
		// 동일한 간선에 대한 정보가 중복 입력될 경우 더 작은 가중치를 저장한다.
		dist[from][to] = min(dist[from][to], cost);
	}
	
	floyd_warshall(); // 플로이드 워셜 알고리즘 수행
	printDistance(); // 출력

	return 0;
}