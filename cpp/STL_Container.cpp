/*
	* C++ STL Container: C++의 표준 템플릿 라이브러리에 구현된 자료구조
	 - STL Container는 클래스 템플릿 형태로 구현되어 있기 때문에 "한 종류의 객체만 보관할 수 있다."
	
	* Pair 클래스
	 : 두 객체를 하나로 묶는 역할을 수행한다.

	* 순차 컨테이너(Sequence Container)
	 : 선형으로 데이터를 저장한다. 가장 일반적인 컨테이너이다.
	 : vector, deque, list
	
	* 연관 컨테이너(Associate Contatiner)
	: 데이터를 key값 중심으로 조직화해서 저장하는 컨테이너이다.
	: set, map, bitset,(unordered_set, unordered_map)

	* 컨테이너 어댑터(Container Adaptor)
	 : 순차, 연관 컨테이너를 목적에 맞게 변형한 컨테이너이다.
	 : stack, queue, priority_queue

	 참고: https://blockdmask.tistory.com/category/%3C%EA%B0%9C%EC%9D%B8%EA%B3%B5%EB%B6%80%3E/%5BC%2B%2B%5D
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

#include <utility>
void how_to_use_pair() {
	// 값을 넣는 3가지 방법
	pair<int, int> P_arr[3] = { make_pair(1, 2), pair<int, int>(3, 4), {5, 6} };

	 // 값에 접근할 때는 first와 second로 접근
	int a = P_arr[0].first;
	int b = P_arr[0].second;

	// 정렬을 수행하면 first값 먼저 비교하고, 같을 경우 second를 비교한다.
	sort(P_arr, P_arr + 3);
}

#include <vector>
void how_to_use_vector() {
	// N이 작다면 배열보다 유리할 수 있다. N이 너무 크다면 배열을 사용하자.
	// 임의의 원소에 접근하거나 맨 뒤에 원소 추가 및 제거: 분할상환분석(amortized) O(1)
	// 임의의 위치에 원소 추가 및 제거: O(n)
	
	vector<int> vec; // int형을 저장하는 벡터
	vector<double> vec2(5, 3.14); // 5칸 할당받아서 3.14로 초기화 한 벡터
	vector<vector<int> > vec3(N, vector<int>(M, 0)); // N행 M열 2차원 벡터를 0으로 초기화

	int x = 987654321;
	vec[0]; vec.at(0); // 벡터의 0번째 요소에 접근. 거의 동일함
	vec.push_back(x); // 벡터의 맨 뒤에 x를 삽입
	vec.pop_back(); // 벡터의 맨 뒤 값을 삭제

	vec.front(); // 벡터의 첫 원소의 값을 반환
	vec.back(); // 벡터의 마지막 원소의 값을 반환

	vec.begin(); // 벡터의 첫 원소의 반복자를 반환
	vec.end(); // 벡터의 마지막 원소의 반복자를 반환

	// 벡터를 10칸짜리로 재할당한다.
	// 만약 더 작아졌다면, 뒷 부분은 버린다.
	// 만약 더 커졌다면, 0으로 초기화 하거나, 두 번째 인자 값으로 초기화 한다.
	vec.resize(10);
	vec.resize(10, 5);

	vec.size(); // 벡터에 저장된 원소의 개수를 반환
	vec.capacity(); // 현재 할당된 메모리에 넣을 수 있는 원소의 개수를 반환(size와 다름)

	vec.clear(); // 벡터의 모든 원소를 삭제한다. size()는 0이 되지만, capacity()는 변하지 않는다.

	// 벡터에서 중복되는 값을 제거하는 방법
	// unique는 중복된 값들을 배열의 뒤로 몰아넣은 뒤, 중복된 값이 시작하는 위치를 반환한다.(정렬 필수)
	// 중복 값들을 삭제하는 방법이 있고, 중복되지 않은 값들로만 공간 재할당을 하는 방법이 있다.
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}

// 이후 대부분의 멤버 함수는 vector와 사용 방법이 비슷하다.

#include <deque>
void how_to_use_deque() {
	// 양방향으로 삽입과 삭제가 가능한 큐 형태이다. -> 시간복잡도 O(1)
	// 중간에 원소를 삽입 또는 삭제 -> 시간복잡도 O(n)
	// 벡터를 보완하기 위해 만들어졌음 -> 대부분 벡터와 유사함
	// 벡터와 비교했을 때 시간복잡도 측면에서 우위에 있지만, 공간복잡도 측면에서 상당히 불리하다.
	// 메모리가 부족할 경우, 메모리 블럭을 추가 할당받고 하나의 블럭으로 취급한다.

	deque<int> dq;
	dq.push_front(5); dq.push_back(10);
	dq.pop_front(); dq.pop_back();

	dq[0]; dq.at(0); // 임의의 원소 참조 가능
}

#include <list>
void how_to_use_list() {
	// 양방향 연결리스트 구조이다.
	// 임의 접근이 불가능하며 ++ 또는 -- 으로 한 칸씩만 옮겨가며 탐색 가능하다.
	// 벡터와는 달리 중간을 포함한 모든 위치에서 원소의 삽입 또는 삭제의 시간복잡도는 O(1)이다.

	list<int> l;
	l.push_front(10); l.push_back(5);
	l.pop_front(); l.pop_back();

	// 출력은 반복자를 통해 할 수 있다.
	for (auto iter = l.begin(); iter != l.end(); iter++) cout << *iter << " ";
	for (auto iter : l) cout << iter << " ";
}

// set과 map 모두 N이 작다면 불리할 수 있다.(오버헤드)
#include <set>
void how_to_use_set() {
	// key값은 중복될 수 없다.
	// 따라서 중복값을 insert하면 무시된다.
	// insert로 삽입 시 자동 정렬이 보장된다.
	// 원소의 삽입, 삭제, 탐색 O(log n)이 보장된다.

	set<int, less<int> > s; // default: 오름차순
	set<int, greater<int> > sg; // 내림차순
	
	// 원소 참조 및 출력
	for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << " ";
	for (auto iter : s) cout << iter << " ";

	// 만약 x라는 값이 있다면 삭제하고, 없다면 추가하고 싶다!
	// find()가 찾으면 찾은 값의 반복자를 반환하고, 없다면 end() 반복자를 반환한다.
	if (s.find(x) == s.end()) s.insert(x);
	else s.erase(x);
}

#include <map> // 또는 Dictionary
void how_to_use_map() {
	// key-value로 구성되어 있고, key값은 중복될 수 없다.
	// 만약 중복된 key가 존재한다면 value가 갱신된다.
	// 자동 정렬이 보장되고, key값을 기준으로 정렬된다.
	// 원소의 삽입, 삭제, 탐색 O(log n)이 보장된다.

	map<string, int> mp;
	// operator[]을 통해 삽입도 가능하고, pair타입을 삽입하듯 넣어도 상관없다.
	mp["jonas"] = 10;
	mp["cplusplus"] = 123;
	mp.insert(pair<string, int>("samsung", 987));
	mp.insert(make_pair("kakao_Blind_Recruitment_", 765));
	mp.insert({ "coding", 7878 });

	// 원소 참조 및 출력
	for (auto iter = mp.begin(); iter != mp.end(); iter++) cout << iter->first << " " << iter->second << " ";
	for (auto iter = mp.begin(); iter != mp.end(); iter++) cout << (*iter).first << " " << (*iter).second << " ";
	for (auto iter : mp) cout << iter.first << " " << iter.second << " ";

	// key값으로도 value에 접근 가능하지만
	// 없는 key로 접근했을 때는 에러가 발생하지 않고 새로운 객체를 만들어서 0을 반환해준다. 주의하자.
	cout << mp["jonas"]; // output: 10
	cout << mp["abcabcabcabcabc"]; // output: 0
}

// insert, erase, find 모두 평균 O(1)을 보여준다.(해싱)
// set과 map의 O(log n)보다 더 최적화가 필요할 때 사용하자.
#include <unordered_set> // set과 동일 / 정렬 안됨 / 더 빠름
#include <unordered_map> // map과 동일 / 정렬 안됨 / 더 빠름
void how_to_use_unordered() {
	unordered_set<int> us;
	unordered_map<int, double> mid;
}

#include <bitset>
void how_to_use_bitset() {
	// 참고: https://www.crocus.co.kr/549
	bitset<10> bit; // 10비트를 저장하는 자료구조
	bit.set(); // 전체 비트를 1로 만듦.
	bit.reset(); // 전체 비트를 0으로 만듦.
	bit.size(); // expected return: 10
	bit.any(); // OR느낌. 하나라도 1이면 1 반환, 모두 0이면 0 반환
	bit.none(); // any의 반대. 하나라도 1이면 0 반환, 모두 0이면 1 반환
	bit.flip(); // 전체 비트 반전
	bit.flip(4); // 5번째 비트 반전
	bit.test(4); bit[4]; // 5번째 비트 검사(0 또는 1)
	string s = bit.to_string(); // 전체 비트를 string 타입으로 변환
	unsigned long ul = bit.to_ulong(); // unsigned long 타입으로 변환
	unsigned long long ull = bit.to_ullong(); // unsigned long long 타입으로 변환

	// #12813 이진수연산 solution
	bitset<(int)1e5> a, b;
	cin >> a >> b;
	cout << (a & b) << '\n'; // AND
	cout << (a | b) << '\n'; // OR
	cout << (a ^ b) << '\n'; // XOR
	cout << (~a) << '\n'; // NOT A
	cout << (~b) << '\n'; // NOT B
}

// stack과 queue같은 경우에는 내부적으로 순차 컨테이너들로 구현되어 있음.
// 하지만 stack과 queue라는 목적에 맞게 변형되어서 쉽게 사용할 수 있게 된 것이다.
#include <stack>
void how_to_use_stack() {
	// LIFO(Last in First out): 후입선출 -> 접시 쌓은 구조
	
	stack<int> s;
	s.push(5); // 삽입
	s.pop(); // 삭제
	s.empty(); // 비어있으면 1, 뭔가 있으면 0 반환
	s.top(); // 최상위 값에만 접근 가능
	s.size(); // 저장된 원소의 개수를 반환
}

#include <queue>
void how_to_use_queue() {
	// FIFO(First in First out): 선입선출 -> 마트 계산 대기 줄 구조

	queue<int> q;
	q.push(5); // 삽입
	q.pop(); // 삭제
	q.empty(); // 비어있으면 1, 뭔가 있으면 0 반환
	q.front(); // pop하면 나올 값
	q.back(); // 방금 push한 값
	q.size(); // 저장된 원소의 개수를 반환

	// 우선순위 큐, 힙에 관해서는 "heap.cpp"라는 파일에 정리해뒀음.
	priority_queue<int, vector<int> > pq;
}