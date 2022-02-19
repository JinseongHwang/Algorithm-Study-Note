/*
	* Union-Find 알고리즘(= Disjoint set, = 서로소 집합 찾기)
	- 이름 그대로 크게 분류하자면 Union 함수와 Find 함수로 이루어진 알고리즘이다.
	- 집합(또는 그래프)에서 임의의 원소(또는 정점)가 서로 같은 집합(그래프)안에 속해 있는지 판별할 때 사용한다.
	
	Union-Find 알고리즘을 사용하기 위해 아래의 조건을 만족해야 한다.
	1. 전체 집합은 여러 개의 부분 집합으로 구성되며, 교집합은 존재하지 않는다.
	2. 모든 집합의 합집합은 전체 집합이다.
	
	또한 알고리즘 구현부에서 2가지 규칙을 둘건데, 이는 구현하는 사람마다 다를 수 있다.
	1. n번 노드의 부모가 n번으로 기록되어 있다면(서로 같다면), n번 정점은 최고 조상 노드이거나, 단독노드이다.
	2. 부모의 번호는 집합에 속한 노드의 번호들 중 가장 작은 번호로 통일한다.
*/

// #1717 집합의 표현

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 10;
int N, M, parent[MAX];

void init() {
	for (int i = 0; i <= N; ++i) parent[i] = i;
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}

int main() {
	scanf("%d %d", &N, &M);

	init(); // 최초 자신의 부모는 자신이다.

	int query, a, b;
	while (M--) {
		scanf("%d %d %d", &query, &a, &b);
		if (query) { // 같은 집합에 속해있는지 판별
			getParent(a) == getParent(b) ? printf("YES\n") : printf("NO\n");
		}
		else { // 두 집합을 합한다
			unionParent(a, b);
		}
	}

	return 0;
}