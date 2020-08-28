/*
	* 이진 탐색(Binary Search): 정렬된 배열에서 값의 존재 유무를 판단

	오름차순으로 정렬되었다고 가정하면,
	- 가장 왼쪽 요소가 최소값이고, 가장 오른쪽 요소가 최대값이다.
	- 찾는 값(target)과 중간값(중간 요소)의 대소 비교를 통해 O(log N)만에 탐색한다.
	
	직접 구현해서 사용하는 것도 크게 어렵지 않다.
	하지만 사용 목적이 단순하고, 목적이 분명하다면 STL을 사용하는 것이
	개발 시간도 단축시켜 줄 수 있다.

	"algorithm" 라이브러리 안에 속해있는 binary_search() 함수는 3개의 매개변수를 받는다.
	-> 탐색 시작 주소, 끝 주소 + 1, 찾으려는 값

	매우 간단하니 원하는 방식으로 사용하도록 하자.
*/

// #1920 수 찾기

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
int N, M, arr[MAX];

// 이진 탐색 직접 구현하기
bool My_Binary_Search(int target) {
	int L = 0, R = N; // 0 부터 N까지 이다!
	while (L <= R) { // 조건 조심 !
		int mid = (L + R) / 2;
		if (arr[mid] == target) { // 원하는 값을 찾은 경우
			return true;
		}
		else if (arr[mid] < target) { // 원하는 값보다 현재 값이 작을 경우
			L = mid + 1;
		}
		else { // arr[mid] > target // 원하는 값보다 현재 값이 클 경우
			R = mid - 1;
		}
	}
	return false; // 못 찾은 경우
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N; // 입력받는 수의 개수
	for (int i = 0; i < N; ++i) cin >> arr[i];

	sort(arr, arr + N); // 정렬은 STL을 사용

	cin >> M; // 질의 개수
	for (int inp, i = 0; i < M; ++i) {
		cin >> inp;
		// 직접 함수를 구현해서 사용하는 방법
		My_Binary_Search(inp) ? cout << "1\n" : cout << "0\n";

		// 이미 구현된 STL을 사용하는 방법
		binary_search(arr, arr + N, inp) ? cout << "1\n" : cout << "0\n";
	}
	return 0;
}



/*
	* 이진 탐색을 활용한 bound 함수들: lower_bound(), upper_bound()
	 - 두 함수 역시 "algorithm" 헤더 파일 안에 속해있다.
	 - 두 함수 모두 3개의 매개변수를 받는데, binary_search()와 동일하다.
	 
	lower_bound(): target 값보다 크거나 같으면서 가장 작은 값의 주소값을 반환한다.
	upper_bound(): target 값보다 큰 값들 중 가장 작은 값의 주소값을 반환한다.
	만약, target값이 존재하지 않는다면 끝주소 + 1 값을 반환한다.

	실질적인 값을 참조하고 싶다면 *lower_bound()와 같이 사용해야 한다.

	직접 구현하거나 STL을 사용해도 된다.

	내가 구현한 bound 함수들은,
	target을 찾았을 경우, 찾은 값의 배열 index를 반환한다.
	못 찾았을 경우, 배열의 마지막 index + 1을 반환한다.
*/

// #10807 개수 세기

// 이 문제는 STL을 사용하는 것 보다 구현해서 사용하는 것이 맞다고 생각한다.
// 사실 N이 최대 100이기 때문에 브루트포스로 풀어도 되지만,
// bound를 사용해서 풀 수도 있기 때문에 공부할 겸 풀어보았다.

int n, k, arr[105] = { 0, };

int My_Lower_Bound() {
	int L = 0, R = n; // 시작 범위가 0부터 n까지다!
	while (L < R) {
		int mid = (L + R) / 2;
		// 조건문에 '=' 가 없으면 lower bound
		if (arr[mid] < k) L = mid + 1;
		else R = mid;
	}
	return R;
}

int My_Upper_Bound() {
	int L = 0, R = n; // 시작 범위가 0부터 n까지다!
	while (L < R) {
		int mid = (L + R) / 2;
		// 조건문에 '=' 가 있으면 upper bound
		if (arr[mid] <= k) L = mid + 1;
		else R = mid;
	}
	return R;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	cin >> k;
	int lb = My_Lower_Bound();
	int ub = My_Upper_Bound();

	// STL 사용 예제
	int stl_lb = *lower_bound(arr, arr + n, k);
	int stl_ub = *upper_bound(arr, arr + n, k);

	if (lb == n) cout << "0\n";
	else cout << ub - lb << "\n";

	return 0;
}