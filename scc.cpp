/*
	* ���� ���� ���(Strongly Connected Component)
	 : ���� �׷������� �� ���� ���̿� ���� ������ �� �ִ� ��ΰ� �����Ѵٸ�,
	  �� ������ ���� SCC�� ���ԵǾ� �ִٰ� ǥ���ȴ�. ���� �ϳ��� SCC �ȿ� �ִ��� ����
	  ������ ���Խ��Ѿ� �Ѵٴ� ������ ������ �ִ�. ����Ŭ(Cycle)�� �����ϴ� ���� �����̴�.

	 : ���� SCC�� �ϳ��� �������� �ٶ󺸸�, SCC ������ �������� ������ DAG^�� ���� �� �ִ�.
	  �̷��� ������ �׷����� ����(condensation)�̶�� �Ѵ�.
	  ^ DAG(Directed Acyclic Graph): ���� ���ȯ �׷���

	  ���� ������� DAG���� ���������� �ϰų� ~ ���� ������ �����Ѵ�.
	  + Biconnected Component, SAT, 2-SAT ... ����

	* �ڻ����(Kosaraju) �˰���� Ÿ��(Tarjan) �˰����� �ִµ�, Ÿ�� �˰����� ä����.
	* Ÿ��(Tarjan) �˰���: �� ���� DFS�� �׷������� SCC�� �����ϴ� �˰���
	 => �ð����⵵: O(V + E)

	0. ����׷������ ���� (�ƴϴ��� ������ ������ ������ŭ �ݺ��ϱ� ������ �������)
	1. �׷����� DFS�� 1ȸ �����ϸ鼭 �湮 ������ ���� ��ȣ�� �ο��Ѵ�.(DFS Spanning Tree ����)
	2. Ž�� ������ ���� ������ ���ÿ� ���ʷ� �����Ѵ�.
	3. DFS�� Ž���ϸ鼭 �ڽ��� �θ� ����� ���� �� ���� ���� ������ �����س�����.
	4. ���� �ְ� ������ �ڱ� �ڽ��� ��ã�Ҵٸ� SCC ������ �����Ѵ�.
	
	5. stack�� �׾Ƶ� �������� �ڽ�(����)�� ���� ������ pop�ϸ� SCC�� �����ش�.
	6. ����� SCC�� 2���� ���Ϳ� �ϳ��� �����Ѵ�.

	7. 3~6 ������ ������ ������ŭ �ݺ����ش�.
	   ���� �̹� �湮�� ����(dfsn[i] == 0)�� Ž������ �ʴ´�.
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
	// dfsn ���� ��� �湮 ������ ����ȴ�.
	// ��, 1���� ����Ǳ� ������ 0�� ��� �湮���� ���� �����̶� ������ �� �ִ�.
	dfsn[x] = ++id;
	s.push(x); // stack�� �ڽ��� push�Ѵ�

	// ���� ������ �� ��ȣ�� ���� ���� ������ �����̶�� �������.
	// �ڽ� �Ǵ� �ڽĵ��� dfsn�� ���� ���� ���� ancestor�� ����
	int ancestor = dfsn[x];
	for (const auto& node : graph[x]) {
		// ���� �湮���� �ʾ��� ���
		if (!dfsn[node]) ancestor = min(ancestor, dfs(node));
		// �湮�� ������ ���� ������ ���� ���� �̿� ����
		else if (!finished[node]) ancestor = min(ancestor, dfsn[node]);
	}

	// �ڽ��� ������ ��� SCC�� �����Ѵ�.
	if (ancestor == dfsn[x]) {
		vector<int> scc;
		while (1) {
			// stack���� �ڽ��� ���� ������ pop�ϰ�
			int curr = s.top();
			s.pop();
			scc.push_back(curr); // �ϳ��� scc�� �����ش�
			finished[curr] = true; // �̹� ����Ϸ�� ����
			if (curr == x) break; // �ڽ� �߰�
		}
		sort(scc.begin(), scc.end()); // ���� ���ǿ� ���� ����
		SCC.push_back(scc); // ��ü SCC ���Ϳ� �ϳ��� SCC�� ����
	}

	return ancestor; // ���� ������ ��ȣ�� ��ȯ
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// �Է�
	cin >> V >> E;
	for (int from, to, i = 0; i < E; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	// DFS�� �����ϸ� SCC�� ����
	for (int i = 1; i <= V; ++i) {
		if (!dfsn[i]) dfs(i);
	}

	// ���� �䱸���ǿ� �°� ����ϱ� ���� ���� �� ���
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