/*
	* �⺻���� �׷��� �����
		- DFS(���� �켱 Ž��)
		- BFS(�ʺ� �켱 Ž��)
		- �������� �߰��ҰԿ�
*/

// ��ǥ���� ����
// #1260 DFS�� BFS

#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

const int VERTEX_MAX = 1005;
bool graph[VERTEX_MAX][VERTEX_MAX]; // ���� ��ķ� ǥ��
bool visited[VERTEX_MAX]; // �湮 Ȯ�� �迭
int V, E, S; // ������ ����, ������ ����, ���� ����

void DFS(int curr);
void BFS();

int main() {
	scanf("%d %d %d", &V, &E, &S);
	for (int i = 0; i < E; i++) {
		int a, b; scanf("%d %d", &a, &b);
		// ����� �׷����� ǥ��
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
	// �ٹٲ� �� �ʱ�ȭ
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