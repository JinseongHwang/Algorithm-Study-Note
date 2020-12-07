/*
	* 기본적인 그래프 개념들
		- DFS(깊이 우선 탐색)
		- BFS(너비 우선 탐색)
		- 생각나면 추가할게요
*/

// 대표적인 유형
// #1260 DFS와 BFS

#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

const int VERTEX_MAX = 1005;
bool graph[VERTEX_MAX][VERTEX_MAX]; // 인접 행렬로 표현
bool visited[VERTEX_MAX]; // 방문 확인 배열
int V, E, S; // 정점의 개수, 간선의 개수, 시작 정점

void DFS(int curr);
void BFS();

int main() {
	scanf("%d %d %d", &V, &E, &S);
	for (int i = 0; i < E; i++) {
		int a, b; scanf("%d %d", &a, &b);
		// 양방향 그래프를 표현
		graph[a][b] = graph[b][a] = true;
	}

	DFS(S);
	BFS();

	return 0;
}

void DFS(int curr) {
	visited[curr] = true;
	printf("%d ", curr);
	for (int i = 1; i <= V; i++) {
		if (!visited[i] && graph[curr][i]) {
			DFS(i);
		}
	}
}

void BFS() {
	// 줄바꿈 및 초기화
	printf("\n");
	memset(visited, false, sizeof(visited));

	queue<int> Q;
	visited[S] = true;
	printf("%d ", S);
	Q.push(S);

	while (!Q.empty()) {
		int f = Q.front();
		Q.pop();
		for (int i = 1; i <= V; i++) {
			if (!visited[i] && graph[f][i]) {
				Q.push(i);
				visited[i] = true;
				printf("%d ", i);
			}
		}
	}
}