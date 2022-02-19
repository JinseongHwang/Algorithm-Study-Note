/*
	* 크루스칼(Kruskal) 알고리즘: Minimum Spanning Tree를 찾아내는 알고리즘 중 하나이다.
	: 가중치가 작은 간선부터 그리디하게 MST를 찾아내는 알고리즘이다.

	* 대표적으로 MST를 찾아내는 알고리즘으로 Kruskal과 Prim이 있다.
	 - Kruskal => 정점이 간선에 비해 상대적으로 많을 때 유리 => O(E log E)
	 - Prim => 간선에 비해 정점이 상대적으로 많을 때 유리 => O(E log V)

	잠깐! - MST(Minimum Spanning Tree)가 뭘까?
		먼저 Spanning Tree에 대해 알아보자.
		Spanning Tree는 그래프의 모든 정점을 연결하는 트리 형태라고 보면 된다.
		그렇다면 자연스럽게 중요한 규칙이 나오는데, "항상 간선의 개수(E)는 정점의 개수(V)에서 1을 뺀 값과 같다."
		그럼 당연히 Minimum Spanning Tree는 최소 비용으로 모든 정점을 연결한 트리를 의미한다.

		다시 정리하자면, 4가지 조건을 만족하는 그래프 또는 트리 형태로 볼 수 있다.
		1. 그래프의 모든 정점을 포함해야 한다.
		2. 연결된 간선들의 가중치 합이 최소가 되어야 한다.
		3. 모든 정점이 서로 연결되어 있어야 한다.(분리된 형태가 아니여야 한다.)
		4. 사이클이 발생하지 않아야 한다.

	그렇다면 사이클 검사는 어떻게 할까?
		이 때, Union-Find 알고리즘이 사용된다.
		간선을 연결하기 전에, 분리된 두 그래프(또는 정점)이 서로 같은 조상 아래 있다면,
		연결할 시에 사이클이 발생하게 되는 원리를 이용한다.

	>>> 크루스칼 알고리즘의 진행 순서
	1. 모든 간선들의 정보를 가중치를 기준으로 오름차순 정렬한다.
	2. 가중치가 작은 간선을 선택해서 사이클이 발생하는지 검사 후, 그래프에 추가한다.
	3. 2번의 과정을 MST가 완성될 때(간선의 개수가 V - 1개가 될 때)까지 반복한다.

	시간복잡도 => O(E log E)

	참고 : https://www.weeklyps.com/entry/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Kruskals-algorithm
*/

// 대표적인 유형
// #1922 네트워크 연결

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1005; // 정점의 최대 개수
int V, E, parent[MAX], result; // Vertex, Edge, 부모 배열, 결과값

struct Edge { // 간선 하나의 정보를 저장
	// from: 시작 정점, to: 끝 정점, cost: 가중치
	int from, to, cost;
	// 가중치를 기준으로 정렬하기 위해서 연산자 오버로딩
	bool operator<(const Edge& e) const { return this->cost < e.cost; }
};
vector<Edge> graph; // 간선 정보를 저장하는 그래프 벡터

// ===== Union-Find =====
void initParent(int v) { // 부모 배열 초기화
	for (int i = 0; i <= v; ++i) parent[i] = i;
}

int getParent(int a) { // 정점 a의 조상을 반환
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]); // 부모 배열 최신화
}

void unionParent(int a, int b) { // 두 정점을 연결
	a = getParent(a);
	b = getParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}

bool hasSameParent(int a, int b) { // 같은 조상을 가지는지 판별, 사이클 확인
	a = getParent(a);
	b = getParent(b);
	return a == b ? true : false;
}
// ======================

void kruskal() { // 크루스칼 알고리즘
	int cnt = 0; // 현재 연결된 간선의 개수
	sort(graph.begin(), graph.end()); // 가중치 기준 오름차순 정렬
	for (const auto& edge : graph) { 
		int f = edge.from, t = edge.to, c = edge.cost;
		if (!hasSameParent(f, t)) { // 사이클 발생하지 않는다면
			unionParent(f, t); // 두 그래프를 연결
			cnt++; // 간선이 하나 더 연결됐음을 알림
			result += c; // 가중치 더해줌
		}
		if (cnt == V - 1) break; // MST에서 E == V - 1 이상으로 찾을 필요 없음
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E; // 정점, 간선 개수 입력받음
	initParent(V); // 부모 배열 초기화

	// 그래프 정보 입력받아서 그래프 벡터에 push back
	for (int a, b, c, i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		Edge e = { a, b, c };
		graph.push_back(e);
	}

	kruskal(); // 크루스칼 알고리즘 실행

	cout << result << "\n"; // 결과값 출력

	return 0;
}