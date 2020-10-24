/*
	* ��������(Topological Sort): �۾��� �켱������ ������ ��, ������ �°� �����ϴ� �˰���

	������ ��쿡 ����Ѵ�.
	: �ݵ�� ����Ǵ� �۾��� ������ ���� �۾��� ������ �� �ִ� ��쿡 ����Ѵ�.

	���� ���ǵ��� ������ �� ��밡���ϴ�.
	1. ����׷����̴�.
	2. �����ϴ� ������ �����ϸ� �ȵȴ�.
	3. ����Ŭ�� �����ϸ� �ȵȴ�.

	���� ����
	1. ���� A���� ���� B�� ���� ������ ���� ��, B�� ���� ������ +1 �Ѵ�. ��� ������ ���� ���� ���� ��ó���� �����Ѵ�.
	2. ���������� 0�� ������ queue�� �����Ѵ�.
	3. queue���� �ϳ��� pop�� ��尡 �� �� �ִ� ������ indegree�� -1 ���ش�.
	4. �� �� indegree�� 0�� �Ǵ� ������ �ִٸ� �� ���� queue�� �����Ѵ�.
	5-1. queue�� �� �� ���� �ݺ��ϰ�, result�� ũ��� ���� ���� �Ǵ�
	5-2. ������ ������ŭ �ݺ��ϰ�, �߰��� queue�� ��� ���� �߻��ߴٰ� �Ǵ�
	-> 5���� ���� �� �ص� �������.
	
	: queue���� pop�ϴ� ������ ���� ������ ����̴�.
*/

// #2623 �������α׷�

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1005;
int N, M, indegree[MAX]; // N: ������ ��, M: ���� ��, indegree[i]: i�� ����� ��������
vector<int> v[MAX], result; // v[i]: i�� ��忡�� �� �� �ִ� ������ ����

void topologicalSort() {
	queue<int> q;
	// ó���� ���������� 0�� ������ queue�� �����Ѵ�.
	for (int i = 1; i <= N; ++i) if (!indegree[i]) q.push(i);

	/* 
		5-1 
	*/
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		result.push_back(curr); // �ϳ��� ����� �־��ָ� �ȴ�.

		// curr ��忡�� �� �� �ִ� ����� ���������� �ϳ��� ���ְ�,
		// ���������� 0�� �Ǿ��ٸ� �ٷ� queue�� ����������.
		for (const int& nxt : v[curr]) {
			indegree[nxt]--;
			if (!indegree[nxt]) q.push(nxt);
		}
	}
	// ������� ���� �ѿ���ŭ �ȳ��Դٸ� ���������� �� �� ���� ��Ȳ
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
		if (q.empty()) { // queue�� ��� ����Ŭ �߻��ߴٴ� �ǹ�
			printf("0\n");
			return;
		}
		int curr = q.front();
		q.pop();
		result.push_back(curr); // �ϳ��� ����� �־��ָ� �ȴ�.

		// curr ��忡�� �� �� �ִ� ����� ���������� �ϳ��� ���ְ�,
		// ���������� 0�� �Ǿ��ٸ� �ٷ� queue�� ����������.
		for (const int& nxt : v[curr]) {
			indegree[nxt]--;
			if (!indegree[nxt]) q.push(nxt);
		}
	}
	// ����� ���
	for (const int& elem : result) printf("%d\n", elem);
}

int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		int k; scanf("%d", &k);
		vector<int> input(k);
		for (int i = 0; i < k; ++i) scanf("%d", &input[i]);
		for (int i = 1; i < k; ++i) { // �������� �������ֱ�
			int& preVal = input[i - 1], & currVal = input[i];
			v[preVal].push_back(currVal);
			indegree[currVal]++;
		}
	}
	topologicalSort();

	return 0;
}