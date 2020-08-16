/*
	* �÷��̵�-����(Floyd-Warshall) �˰���: ��� ���� �� ������ �ִ� �Ÿ��� ���ϴ� �˰���.
	
	* ���� ����ġ�� �����ص� ��� �����ϴ�!

	1. �ִ� �Ÿ����� �����ϴ� dist �迭�� 2���� �迭�� �����Ѵ�.
	2. �迭�� ��� ������ INF������ �ʱ�ȭ���ֵ�, �ڱ� �ڽ������� �Ÿ��� 0���� �����Ѵ�.
	3. �������� �ٲ㰡�鼭 ��� �ִ� �Ÿ����� ���Ѵ�.
	
	�ð����⵵: O(V^3)
*/

// #11404 �÷��̵�

#include <iostream>
#include <algorithm>
using namespace std;

// INF ���� INT_MAX ���� ������ ������ ��,
// ���������� �� ����ġ�� ���ؼ� ���� �� int Ÿ�� �����÷ο찡 �߻��� �� ������
// ���ǹ��� �߰��ϰų�, 8byte Ÿ������ �����ϰų�, INF�� ���� (INT_MAX / 2) ������ ������ ��������
const int MAX = 110, INF = 987654321;
int V, E, dist[MAX][MAX]; // dist[i][j]: ���� i���� ���� j�� ���� �ִ� ���

void floyd_warshall() { // �÷��̵� ���� �˰���
	for (int via = 1; via <= V; ++via) // ������
		for (int from = 1; from <= V; ++from) // source
			for (int to = 1; to <= V; ++to) // destination
				dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
}

void printDistance() { // ���
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

	for (int i = 0; i <= V; ++i) { // dist �迭 ��ó��
		fill(dist[i], dist[i] + V + 1, INF); // INF������ �ʱ�ȭ
		dist[i][i] = 0; // �ڱ� �ڽ������� ����ġ�� 0�̴�.
	}

	for (int from, to, cost, i = 0; i < E; ++i) { // �Է�
		cin >> from >> to >> cost;
		// ������ ������ ���� ������ �ߺ� �Էµ� ��� �� ���� ����ġ�� �����Ѵ�.
		dist[from][to] = min(dist[from][to], cost);
	}
	
	floyd_warshall(); // �÷��̵� ���� �˰��� ����
	printDistance(); // ���

	return 0;
}