/*
	* 위상정렬(Topological Sort): 작업의 우선순위가 존재할 때, 순서에 맞게 정렬하는 알고리즘

	다음의 경우에 사용한다.
	: 반드시 선행되는 작업을 끝내고서 다음 작업을 시작할 수 있는 경우에 사용한다.

	다음 조건들을 만족할 때 사용가능하다.
	1. 유향그래프이다.
	2. 역행하는 간선이 존재하면 안된다.
	3. 사이클이 존재하면 안된다.

	진행 과정
	1. 정점 A에서 정점 B로 가는 간선이 있을 때, B의 진입 차수를 +1 한다. 모든 간선에 대해 진입 차수 전처리를 수행한다.
	2. 진입차수가 0인 정점을 queue에 삽입한다.
	3. queue에서 하나를 pop한 노드가 갈 수 있는 노드들의 indegree를 -1 해준다.
	4. 이 때 indegree가 0이 되는 정점이 있다면 이 역시 queue에 삽입한다.
	5-1. queue가 빌 때 가지 반복하고, result의 크기로 문제 여부 판단
	5-2. 정점의 개수만큼 반복하고, 중간에 queue가 비면 문제 발생했다고 판단
	-> 5번의 경우는 뭘 해도 상관없음.
	
	: queue에서 pop하는 순서가 위상 정렬의 결과이다.
*/

// #2623 음악프로그램

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1005;
int N, M, indegree[MAX]; // N: 가수의 수, M: 질의 수, indegree[i]: i번 노드의 진입차수
vector<int> v[MAX], result; // v[i]: i번 노드에서 갈 수 있는 노드들을 저장

void topologicalSort() {
	queue<int> q;
	// 처음에 진입차수가 0인 노드들을 queue에 삽입한다.
	for (int i = 1; i <= N; ++i) if (!indegree[i]) q.push(i);

	/* 
		5-1 
	*/
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		result.push_back(curr); // 하나씩 결과에 넣어주면 된다.

		// curr 노드에서 갈 수 있는 노드의 진입차수를 하나씩 빼주고,
		// 진입차수가 0이 되었다면 바로 queue에 삽입해주자.
		for (const int& nxt : v[curr]) {
			indegree[nxt]--;
			if (!indegree[nxt]) q.push(nxt);
		}
	}
	// 결과값이 가수 총원만큼 안나왔다면 위상정렬을 할 수 없는 상황
	if (result.size() == N) {
		for (const int& elem : result)printf("%d\n", elem);
	}
	else {
		printf("0\n");
	}

	/*
		5-2
	*/
	for (int i = 0; i < N; ++i) {
		if (q.empty()) { // queue가 비면 사이클 발생했다는 의미
			printf("0\n");
			return;
		}
		int curr = q.front();
		q.pop();
		result.push_back(curr); // 하나씩 결과에 넣어주면 된다.

		// curr 노드에서 갈 수 있는 노드의 진입차수를 하나씩 빼주고,
		// 진입차수가 0이 되었다면 바로 queue에 삽입해주자.
		for (const int& nxt : v[curr]) {
			indegree[nxt]--;
			if (!indegree[nxt]) q.push(nxt);
		}
	}
	// 결과값 출력
	for (const int& elem : result) printf("%d\n", elem);
}

int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		int k; scanf("%d", &k);
		vector<int> input(k);
		for (int i = 0; i < k; ++i) scanf("%d", &input[i]);
		for (int i = 1; i < k; ++i) { // 진입차수 설정해주기
			int& preVal = input[i - 1], & currVal = input[i];
			v[preVal].push_back(currVal);
			indegree[currVal]++;
		}
	}
	topologicalSort();

	return 0;
}