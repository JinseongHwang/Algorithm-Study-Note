/*
	* 강한 결합 요소(Strongly Connected Component)
	 : 유향 그래프에서 두 정점 사이에 서로 도달할 수 있는 경로가 존재한다면,
	  두 정점은 같은 SCC에 포함되어 있다고 표현된다. 또한 하나의 SCC 안에 최대한 많은
	  정점을 포함시켜야 한다는 성질을 가지고 있다. 사이클(Cycle)을 포괄하는 상위 개념이다.

	 : 또한 SCC를 하나의 정점으로 바라보면, SCC 사이의 간선들을 연결한 DAG^를 만들 수 있다.
	  이러한 과정을 그래프의 압축(condensation)이라고 한다.
	  ^ DAG(Directed Acyclic Graph): 유향 비순환 그래프

	  이후 만들어진 DAG에서 위상정렬을 하거나 ~ 응용 문제로 발전한다.
	  + Biconnected Component, SAT, 2-SAT ... 응용

	* 코사라주(Kosaraju) 알고리즘과 타잔(Tarjan) 알고리즘이 있는데, 타잔 알고리즘을 채택함.
	* 타잔(Tarjan) 알고리즘: 한 번의 DFS로 그래프에서 SCC를 추출하는 알고리즘
	 => 시간복잡도: O(V + E)

	0. 연결그래프라고 가정 (아니더라도 어차피 정점의 개수만큼 반복하기 때문에 상관없음)
	1. 그래프에 DFS를 1회 수행하면서 방문 순서에 따라 번호를 부여한다.(DFS Spanning Tree 생성)
	2. 탐색 순서에 따른 정점을 스택에 차례로 삽입한다.
	3. DFS를 탐색하면서 자신의 부모를 연결된 정점 중 가장 작은 값으로 갱신해나간다.
	4. 만약 최고 조상인 자기 자신을 되찾았다면 SCC 추출을 시작한다.
	
	5. stack에 쌓아둔 정점들을 자신(조상)이 나올 때까지 pop하며 SCC로 묶어준다.
	6. 추출된 SCC를 2차원 벡터에 하나씩 저장한다.

	7. 3~6 과정을 정점의 개수만큼 반복해준다.
	   물론 이미 방문된 정점(dfsn[i] == 0)은 탐색하지 않는다.
*/

// #2150 Strongly Connected Component

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 10;
int V, E, id, dfsn[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x) {
	// dfsn 에는 노드 방문 순서가 저장된다.
	// 즉, 1부터 저장되기 때문에 0일 경우 방문하지 않은 정점이라 생각할 수 있다.
	dfsn[x] = ++id;
	s.push(x); // stack에 자신을 push한다

	// 여러 정점들 중 번호가 가장 작은 정점이 조상이라고 약속하자.
	// 자신 또는 자식들의 dfsn중 가장 작은 값을 ancestor에 갱신
	int ancestor = dfsn[x];
	for (const auto& node : graph[x]) {
		// 아직 방문하지 않았을 경우
		if (!dfsn[node]) ancestor = min(ancestor, dfs(node));
		// 방문은 했지만 아직 결정된 것이 없는 이웃 정점
		else if (!finished[node]) ancestor = min(ancestor, dfsn[node]);
	}

	// 자신이 조상일 경우 SCC를 추출한다.
	if (ancestor == dfsn[x]) {
		vector<int> scc;
		while (1) {
			// stack에서 자신이 나올 때까지 pop하고
			int curr = s.top();
			s.pop();
			scc.push_back(curr); // 하나의 scc로 묶어준다
			finished[curr] = true; // 이미 추출완료된 정점
			if (curr == x) break; // 자신 발견
		}
		sort(scc.begin(), scc.end()); // 문제 조건에 따른 정렬
		SCC.push_back(scc); // 전체 SCC 벡터에 하나의 SCC를 삽입
	}

	return ancestor; // 조상 정점의 번호를 반환
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 입력
	cin >> V >> E;
	for (int from, to, i = 0; i < E; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	// DFS를 수행하며 SCC를 추출
	for (int i = 1; i <= V; ++i) {
		if (!dfsn[i]) dfs(i);
	}

	// 문제 요구조건에 맞게 출력하기 위해 정렬 후 출력
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (const auto& comp : SCC) {
		for (const auto& v : comp) {
			cout << v << ' ';
		}
		cout << "-1\n";
	}

	return 0;
}