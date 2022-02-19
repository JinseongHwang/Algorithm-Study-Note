/*
	* ��Ʈ��ũ ����(Network Flow)
	 : ������ �׷������� �ϳ��� ������ "����� �� ������ ��ȣ", "����ġ(cost)" ������ ������ ��� �־���.
	  ��Ʈ��ũ ���� �׷��������� "����ġ(cost)" ��ſ� "�뷮(capacity)" �̶�� �������� ��ü�ȴ�.
	  ���� ����(flow)��� ������ �߰��� ����׷����̴�.

	- �׷������� ���� �ٸ� �� ������ Source(S)�� Sink(T) ���� �־�����.
	  S���� �߻��� ������ T�� ��� ������ ���� ��ǥ�̴�.

	  => 1/3 �� �ǹ̴� "�뷮�� 3�� ������ ������ 1�̴�." ��� �ǹ��̴�.
	  => ���� u���� v�� ���� ������ �뷮�� c(u, v), ���� �帣�� ������ f(u, v) ��� ǥ���Ѵ�.
	
	�������� �� ���� �Ǵ� ���
	1. �� ������ �帣�� ������ �� ������ �뷮�� �Ѿ �� ����.
	2. ���� S�� T�� ������ ��� �������� ������ ���� ���հ� ������ ���� ������ ���ƾ� �Ѵ�.
	3. ���� u���� v�� ������ �帣�� �ִٸ�, v���� u�� �帣�� ���� ������ �ִٰ� �����Ѵ�.

	* ����-ǮĿ��(Ford-Fulkerson)�� ����� �� ������-ī��(Edmonds-Karp) �˰����� ä����.
	* ������-ī��(Edmonds-Karp) �˰���
	 1. ���� S���� T���� �ܿ� �뷮�� ���� �����鸸�� ����ؼ� BFS�� �����Ѵ�.
	 2. �� �̻� ������ ���� �� ���� ���� ��ΰ� ������ ������ �ݺ��Ѵ�.
	 3. S���� T�� Ž���س����ٰ� T�� ������ ���� ��ε��� �ǵ��ư��� �ּ� ������ ã�Ƽ� totalFlow�� �����ش�.

	�ð����⵵: O(V * E^2)
	
	����: �˰��� �����ذ�����(������ ��)
	����: https://kks227.blog.me/220804885235
*/

#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

const int MAX = 1000, INF = 987654321;
int V;
int capacity[MAX][MAX]; // capacity[u][v]: u���� v�� ������� �� �ִ� �뷮
int flow[MAX][MAX]; // flow[u][v]: u���� v�� �귯���� ����(�ݴ� ������ ��쿡�� ����)

int networkFlow(int S, int T) {
	memset(flow, 0, sizeof(flow));

	int totalFlow = 0;
	while (1) {
		// BFS�� Ž��
		int prev[MAX];
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		prev[S] = S;
		q.push(S);
		while (!q.empty() && prev[T] == -1) {
			int curr = q.front();
			q.pop();
			for (int nxt = 0; nxt < V; ++nxt) {
				// �ܿ� �뷮�� �����ִ� ������ ���� Ž�� && �湮���� ���� ����
				if (capacity[curr][nxt] - flow[curr][nxt] > 0 && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = curr; // ���Ŀ� ������ ���
				}
			}
		}
		// ���� ��ΰ� ���ٸ� �����Ѵ�.
		if (prev[T] == -1) break;
		// ���� ��θ� ���� �󸶳� ��������� �����Ѵ�.
		int amount = INF;
		for (int p = T; p != S; p = prev[p]) {
			amount = min(capacity[prev[p]][p] - flow[prev[p]][p], amount);
		}
		// ���� ��θ� ���� ������ ���������.
		for (int p = T; p != S; p = prev[p]) {
			flow[prev[p]][p] += amount;
			flow[p][prev[p]] -= amount;
		}
		totalFlow += amount;
	}

	return totalFlow;
}