#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	/*
		* 최소값과 최대값을 찾아주는 함수: min_element(), max_element()
		주의! 찾은 값을 반환하는 것이 아니라, 값의 주소를 반환하기 때문에 값에 접근하기 위해서는 '*'을 붙여야 한다.

		- 배열, 벡터, 문자열 등에서 사용 가능
		- 만약 문자열에 영소문자, 대문자, 특수문자가 섞여있다면 ASCII의 순서에 따라 출력
	*/
	vector<int> v = { 6,8,2,3,7,9,1,0,9 };
	cout << *max_element(v.begin(), v.end()) << "\n"; // expected output: 9
	cout << *min_element(v.begin(), v.end()) << "\n"; // expected output: 0

	string str = "algorithm";
	cout << *max_element(str.begin(), str.end()) << "\n"; // expected output: t
	cout << *min_element(str.begin(), str.end()) << "\n"; // expected output: a

	v.clear();

	/*
		* 순열을 STL로 구해주는 함수: next_permutation(), prev_permutation()
		: 다음(또는 이전) 순열로 벡터를 변경하고 true를 반환한다.
	*/
	
	v = { 1,2,3 };
	for (const auto& elem : v) cout << elem << " "; cout << "\n";
	while (next_permutation(v.begin(), v.end())) {
		// 다음 순열 값이 초기 값(3, 2, 1)과 같다면, 마지막 조건 확인 때 (3, 2, 1)으로 바꾸고 false를 반환한다.
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