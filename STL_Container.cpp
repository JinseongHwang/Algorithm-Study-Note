/*
	* C++ STL Container: C++�� ǥ�� ���ø� ���̺귯���� ������ �ڷᱸ��
	 - STL Container�� Ŭ���� ���ø� ���·� �����Ǿ� �ֱ� ������ "�� ������ ��ü�� ������ �� �ִ�."
	
	* Pair Ŭ����
	 : �� ��ü�� �ϳ��� ���� ������ �����Ѵ�.

	* ���� �����̳�(Sequence Container)
	 : �������� �����͸� �����Ѵ�. ���� �Ϲ����� �����̳��̴�.
	 : vector, deque, list
	
	* ���� �����̳�(Associate Contatiner)
	: �����͸� key�� �߽����� ����ȭ�ؼ� �����ϴ� �����̳��̴�.
	: set, map, bitset,(unordered_set, unordered_map)

	* �����̳� �����(Container Adaptor)
	 : ����, ���� �����̳ʸ� ������ �°� ������ �����̳��̴�.
	 : stack, queue, priority_queue

	 ����: https://blockdmask.tistory.com/category/%3C%EA%B0%9C%EC%9D%B8%EA%B3%B5%EB%B6%80%3E/%5BC%2B%2B%5D
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

#include <utility>
void how_to_use_pair() {
	// ���� �ִ� 3���� ���
	pair<int, int> P_arr[3] = { make_pair(1, 2), pair<int, int>(3, 4), {5, 6} };

	 // ���� ������ ���� first�� second�� ����
	int a = P_arr[0].first;
	int b = P_arr[0].second;

	// ������ �����ϸ� first�� ���� ���ϰ�, ���� ��� second�� ���Ѵ�.
	sort(P_arr, P_arr + 3);
}

#include <vector>
void how_to_use_vector() {
	// N�� �۴ٸ� �迭���� ������ �� �ִ�. N�� �ʹ� ũ�ٸ� �迭�� �������.
	// ������ ���ҿ� �����ϰų� �� �ڿ� ���� �߰� �� ����: ���һ�ȯ�м�(amortized) O(1)
	// ������ ��ġ�� ���� �߰� �� ����: O(n)
	
	vector<int> vec; // int���� �����ϴ� ����
	vector<double> vec2(5, 3.14); // 5ĭ �Ҵ�޾Ƽ� 3.14�� �ʱ�ȭ �� ����
	vector<vector<int> > vec3(N, vector<int>(M, 0)); // N�� M�� 2���� ���͸� 0���� �ʱ�ȭ

	int x = 987654321;
	vec[0]; vec.at(0); // ������ 0��° ��ҿ� ����. ���� ������
	vec.push_back(x); // ������ �� �ڿ� x�� ����
	vec.pop_back(); // ������ �� �� ���� ����

	vec.front(); // ������ ù ������ ���� ��ȯ
	vec.back(); // ������ ������ ������ ���� ��ȯ

	vec.begin(); // ������ ù ������ �ݺ��ڸ� ��ȯ
	vec.end(); // ������ ������ ������ �ݺ��ڸ� ��ȯ

	// ���͸� 10ĭ¥���� ���Ҵ��Ѵ�.
	// ���� �� �۾����ٸ�, �� �κ��� ������.
	// ���� �� Ŀ���ٸ�, 0���� �ʱ�ȭ �ϰų�, �� ��° ���� ������ �ʱ�ȭ �Ѵ�.
	vec.resize(10);
	vec.resize(10, 5);

	vec.size(); // ���Ϳ� ����� ������ ������ ��ȯ
	vec.capacity(); // ���� �Ҵ�� �޸𸮿� ���� �� �ִ� ������ ������ ��ȯ(size�� �ٸ�)

	vec.clear(); // ������ ��� ���Ҹ� �����Ѵ�. size()�� 0�� ������, capacity()�� ������ �ʴ´�.

	// ���Ϳ��� �ߺ��Ǵ� ���� �����ϴ� ���
	// unique�� �ߺ��� ������ �迭�� �ڷ� ���Ƴ��� ��, �ߺ��� ���� �����ϴ� ��ġ�� ��ȯ�Ѵ�.(���� �ʼ�)
	// �ߺ� ������ �����ϴ� ����� �ְ�, �ߺ����� ���� ����θ� ���� ���Ҵ��� �ϴ� ����� �ִ�.
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}

// ���� ��κ��� ��� �Լ��� vector�� ��� ����� ����ϴ�.

#include <deque>
void how_to_use_deque() {
	// ��������� ���԰� ������ ������ ť �����̴�. -> �ð����⵵ O(1)
	// �߰��� ���Ҹ� ���� �Ǵ� ���� -> �ð����⵵ O(n)
	// ���͸� �����ϱ� ���� ��������� -> ��κ� ���Ϳ� ������
	// ���Ϳ� ������ �� �ð����⵵ ���鿡�� ������ ������, �������⵵ ���鿡�� ����� �Ҹ��ϴ�.
	// �޸𸮰� ������ ���, �޸� ���� �߰� �Ҵ�ް� �ϳ��� ������ ����Ѵ�.

	deque<int> dq;
	dq.push_front(5); dq.push_back(10);
	dq.pop_front(); dq.pop_back();

	dq[0]; dq.at(0); // ������ ���� ���� ����
}

#include <list>
void how_to_use_list() {
	// ����� ���Ḯ��Ʈ �����̴�.
	// ���� ������ �Ұ����ϸ� ++ �Ǵ� -- ���� �� ĭ���� �Űܰ��� Ž�� �����ϴ�.
	// ���Ϳʹ� �޸� �߰��� ������ ��� ��ġ���� ������ ���� �Ǵ� ������ �ð����⵵�� O(1)�̴�.

	list<int> l;
	l.push_front(10); l.push_back(5);
	l.pop_front(); l.pop_back();

	// ����� �ݺ��ڸ� ���� �� �� �ִ�.
	for (auto iter = l.begin(); iter != l.end(); iter++) cout << *iter << " ";
	for (auto iter : l) cout << iter << " ";
}

// set�� map ��� N�� �۴ٸ� �Ҹ��� �� �ִ�.(�������)
#include <set>
void how_to_use_set() {
	// key���� �ߺ��� �� ����.
	// ���� �ߺ����� insert�ϸ� ���õȴ�.
	// insert�� ���� �� �ڵ� ������ ����ȴ�.
	// ������ ����, ����, Ž�� O(log n)�� ����ȴ�.

	set<int, less<int> > s; // default: ��������
	set<int, greater<int> > sg; // ��������
	
	// ���� ���� �� ���
	for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << " ";
	for (auto iter : s) cout << iter << " ";

	// ���� x��� ���� �ִٸ� �����ϰ�, ���ٸ� �߰��ϰ� �ʹ�!
	// find()�� ã���� ã�� ���� �ݺ��ڸ� ��ȯ�ϰ�, ���ٸ� end() �ݺ��ڸ� ��ȯ�Ѵ�.
	if (s.find(x) == s.end()) s.insert(x);
	else s.erase(x);
}

#include <map> // �Ǵ� Dictionary
void how_to_use_map() {
	// key-value�� �����Ǿ� �ְ�, key���� �ߺ��� �� ����.
	// ���� �ߺ��� key�� �����Ѵٸ� value�� ���ŵȴ�.
	// �ڵ� ������ ����ǰ�, key���� �������� ���ĵȴ�.
	// ������ ����, ����, Ž�� O(log n)�� ����ȴ�.

	map<string, int> mp;
	// operator[]�� ���� ���Ե� �����ϰ�, pairŸ���� �����ϵ� �־ �������.
	mp["jonas"] = 10;
	mp["cplusplus"] = 123;
	mp.insert(pair<string, int>("samsung", 987));
	mp.insert(make_pair("kakao_Blind_Recruitment_", 765));
	mp.insert({ "coding", 7878 });

	// ���� ���� �� ���
	for (auto iter = mp.begin(); iter != mp.end(); iter++) cout << iter->first << " " << iter->second << " ";
	for (auto iter = mp.begin(); iter != mp.end(); iter++) cout << (*iter).first << " " << (*iter).second << " ";
	for (auto iter : mp) cout << iter.first << " " << iter.second << " ";

	// key�����ε� value�� ���� ����������
	// ���� key�� �������� ���� ������ �߻����� �ʰ� ���ο� ��ü�� ���� 0�� ��ȯ���ش�. ��������.
	cout << mp["jonas"]; // output: 10
	cout << mp["abcabcabcabcabc"]; // output: 0
}

// insert, erase, find ��� ��� O(1)�� �����ش�.(�ؽ�)
// set�� map�� O(log n)���� �� ����ȭ�� �ʿ��� �� �������.
#include <unordered_set> // set�� ���� / ���� �ȵ� / �� ����
#include <unordered_map> // map�� ���� / ���� �ȵ� / �� ����
void how_to_use_unordered() {
	unordered_set<int> us;
	unordered_map<int, double> mid;
}

#include <bitset>
void how_to_use_bitset() {
	// ����: https://www.crocus.co.kr/549
	bitset<10> bit; // 10��Ʈ�� �����ϴ� �ڷᱸ��
	bit.set(); // ��ü ��Ʈ�� 1�� ����.
	bit.reset(); // ��ü ��Ʈ�� 0���� ����.
	bit.size(); // expected return: 10
	bit.any(); // OR����. �ϳ��� 1�̸� 1 ��ȯ, ��� 0�̸� 0 ��ȯ
	bit.none(); // any�� �ݴ�. �ϳ��� 1�̸� 0 ��ȯ, ��� 0�̸� 1 ��ȯ
	bit.flip(); // ��ü ��Ʈ ����
	bit.flip(4); // 5��° ��Ʈ ����
	bit.test(4); bit[4]; // 5��° ��Ʈ �˻�(0 �Ǵ� 1)
	string s = bit.to_string(); // ��ü ��Ʈ�� string Ÿ������ ��ȯ
	unsigned long ul = bit.to_ulong(); // unsigned long Ÿ������ ��ȯ
	unsigned long long ull = bit.to_ullong(); // unsigned long long Ÿ������ ��ȯ

	// #12813 ���������� solution
	bitset<(int)1e5> a, b;
	cin >> a >> b;
	cout << (a & b) << '\n'; // AND
	cout << (a | b) << '\n'; // OR
	cout << (a ^ b) << '\n'; // XOR
	cout << (~a) << '\n'; // NOT A
	cout << (~b) << '\n'; // NOT B
}

// stack�� queue���� ��쿡�� ���������� ���� �����̳ʵ�� �����Ǿ� ����.
// ������ stack�� queue��� ������ �°� �����Ǿ ���� ����� �� �ְ� �� ���̴�.
#include <stack>
void how_to_use_stack() {
	// LIFO(Last in First out): ���Լ��� -> ���� ���� ����
	
	stack<int> s;
	s.push(5); // ����
	s.pop(); // ����
	s.empty(); // ��������� 1, ���� ������ 0 ��ȯ
	s.top(); // �ֻ��� ������ ���� ����
	s.size(); // ����� ������ ������ ��ȯ
}

#include <queue>
void how_to_use_queue() {
	// FIFO(First in First out): ���Լ��� -> ��Ʈ ��� ��� �� ����

	queue<int> q;
	q.push(5); // ����
	q.pop(); // ����
	q.empty(); // ��������� 1, ���� ������ 0 ��ȯ
	q.front(); // pop�ϸ� ���� ��
	q.back(); // ��� push�� ��
	q.size(); // ����� ������ ������ ��ȯ

	// �켱���� ť, ���� ���ؼ��� "heap.cpp"��� ���Ͽ� �����ص���.
	priority_queue<int, vector<int> > pq;
}