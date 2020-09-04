#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	/*
		* �ּҰ��� �ִ밪�� ã���ִ� �Լ�: min_element(), max_element()
		����! ã�� ���� ��ȯ�ϴ� ���� �ƴ϶�, ���� �ּҸ� ��ȯ�ϱ� ������ ���� �����ϱ� ���ؼ��� '*'�� �ٿ��� �Ѵ�.

		- �迭, ����, ���ڿ� ��� ��� ����
		- ���� ���ڿ��� ���ҹ���, �빮��, Ư�����ڰ� �����ִٸ� ASCII�� ������ ���� ���
	*/
	vector<int> v = { 6,8,2,3,7,9,1,0,9 };
	cout << *max_element(v.begin(), v.end()) << "\n"; // expected output: 9
	cout << *min_element(v.begin(), v.end()) << "\n"; // expected output: 0

	string str = "algorithm";
	cout << *max_element(str.begin(), str.end()) << "\n"; // expected output: t
	cout << *min_element(str.begin(), str.end()) << "\n"; // expected output: a

	v.clear();

	/*
		* ������ STL�� �����ִ� �Լ�: next_permutation(), prev_permutation()
		: ����(�Ǵ� ����) ������ ���͸� �����ϰ� true�� ��ȯ�Ѵ�.
	*/
	
	v = { 1,2,3 };
	for (const auto& elem : v) cout << elem << " "; cout << "\n";
	while (next_permutation(v.begin(), v.end())) {
		// ���� ���� ���� �ʱ� ��(3, 2, 1)�� ���ٸ�, ������ ���� Ȯ�� �� (3, 2, 1)���� �ٲٰ� false�� ��ȯ�Ѵ�.
		for (const auto& elem : v) cout << elem << " "; cout << "\n";
	}
	/* expected output:
	1 2 3
	1 3 2
	2 1 3
	2 3 1
	3 1 2
	3 2 1 */

	v = { 3,2,1 };
	for (const auto& elem : v) cout << elem << " "; cout << "\n";
	while (prev_permutation(v.begin(), v.end())) {
		for (const auto& elem : v) cout << elem << " "; cout << "\n";
	}
	/* expected output:
	3 2 1
	3 1 2
	2 3 1
	2 1 3
	1 3 2
	1 2 3
	*/

	return 0;
}