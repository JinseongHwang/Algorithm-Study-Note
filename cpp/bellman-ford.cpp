/*
	* ����-����(Bellman-Ford) �˰���
	 => ���� �������κ��� �ٸ� ����������� �ִ� �Ÿ��� ���Ұǵ�, ���� ����ġ�� �����ص� ��� ������ �˰����̴�.
	 => ���� ���� ����Ŭ�� �߻� ���ε� �Ǵ��� �� �ִ�.
	
	- ���꿡 ���Ǵ� ������ ���ͽ�Ʈ�� �˰���� ��������� ���� ���������� ���̰� �ִ�.
	- ������ 2�� for���� ����� ������ ������ŭ ��� ������ Ȯ��-���� ������ ��ġ�� ������
	 ������ �����ϴ� �� ���� �ð��� �ɸ���.

	1. �ִܰ�δ� ���� ������ �� �� ���� �� ����! -> �ִ� ��� ���� ���� ����: V-1 ��
	2. V-1�� ������ �����ϸ鼭 �ִ� �Ÿ����� �ٻ簪�� ã�� �� Ȯ������ ã�Ƴ����� ����̴�.
	 Ȯ���� ���� ��� ã�� ���� �ִ� �Ÿ����� �ٽ� ���ŵȴٸ� ���� ����Ŭ�� �����Ѵٰ� �Ǵ�.

	1. �ִ� ��δ� ����Ŭ�� ������ �� ���� ������ �ִ� V-1 ���� ������ ��� �����ϴ�.
	2. ���� V-1�� �ݺ����ָ� �Ǵ°ɱ�? ��� ���� �� ������ ���� Ȯ��-���� ������ ��ġ��
	 �ѹ� �� �������ش�. �� V�� �ݺ��Ѵ�. ���� ������ �ݺ� �� ���ŵǴ�(�� ���� �Ÿ� �߰�) ��찡
	 �����Ѵٸ�, ���� ����Ŭ�� �����Ѵٰ� �Ǵ��� �� �ִ�.

	�ð����⵵ : O(VE)

	����: https://www.crocus.co.kr/534
*/

// 11657 Ÿ�Ӹӽ�

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
	while (iter <= V) { // (V - 1) + 1 �� �ݺ��Ѵ�
		for (int i = 1; i <= V; ++i) {
			if (dist[i] == INF) continue;
			for (const auto& elem : graph[i]) {
				int nxt = elem.first, d = elem.second;
				if (dist[nxt] > dist[i] + d) { // �������� �� �� ���� ����ġ���
					// ������ �ݺ� �� ���ŵȴٸ� ���� ����Ŭ�� �����Ѵٴ� �ǹ�
					if (iter == V) {
						minusCycle = true;
						break;
					}
					dist[nxt] = dist[i] + d; // ����
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
	fill(dist, dist + V + 1, INF); // dist �迭�� INF�� �ʱ�ȭ
	for (int from, to, cost, i = 0; i < E; ++i) { // �Է�
		cin >> from >> to >> cost;
		graph[from].push_back(pii(to, cost));
	}
	bellman_ford();
	if (minusCycle) cout << "-1\n"; // ���� ����Ŭ�� �߻��� ���
	else {
		for (int i = 2; i <= V; ++i)
			(dist[i] != INF) ? (cout << dist[i] << '\n') : (cout << "-1\n");
	}

	return 0;
}