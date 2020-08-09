#include <iostream>
#include <queue>
using namespace std;

struct a {
	int start, end, value;
};

//bool operator<(a u, a v) {
//	return u.value < v.value; // ��������
//	return u.value > v.value; // ��������
//}

struct compare {
	bool operator()(a u, a v) {
		return u.value < v.value; // ��������
		return u.value > v.value; // ��������
	}
};

// <�ڷ���, ����ü, �񱳿�����>
// priority_queue<a, vector<a> > pq;
priority_queue<a, vector<a>, compare > pq;

// priority_queue<int, vector<int> > pq; // �⺻�� -> ��������(�ִ���)
// priority_queue<int, vector<int>, greater<int> > pq; // ��������(�ּ���)


int main() {
	a x = { 23,65,55 };
	a y = { 3,2,1 };
	a z = { 11,44,23 };

	// int x = 12, y = 34, z = 56;

	pq.push(x);
	pq.push(y);
	pq.push(z);

	while (!pq.empty()) {
		cout << pq.top().start << ' ' << pq.top().end << ' ' << pq.top().value << "\n";
		pq.pop();
	}

	return 0;
}