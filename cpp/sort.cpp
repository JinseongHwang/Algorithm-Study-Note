/*
	* 정렬(Sort) STL 사용 및 사용자 정의 비교 함수 만들기

	: C++ 표준 라이브러리 중 "algorithm" 라이브러리 안에 정의된 sort()함수를 사용한다.

	인트로 정렬(Intro Sort) 방식으로 정렬되는데, 이는 Quick sort, Heap sort를 혼합한 방식이다.
	참고: https://justicehui.github.io/medium-algorithm/2019/03/24/IntroSort/
	영문위키: https://en.wikipedia.org/wiki/Introsort
	
	시간복잡도: O(n log n)

	sort(①, ②, ③) : 일반적으로 2개 또는 3개의 매개변수를 가진다.
	① 배열 시작 주소(배열의 경우에는 배열의 이름, 벡터의 경우에는 vector.begin())
	② 배열 끝 주소 + 1(배열의 경우에는 배열의 이름 + ARRAY_SIZE, 벡터의 경우에는 vector.end())
	③ 사용자 정의 비교 함수 
		-> 반환 값이 true이면 그대로 두고, false이면 swap하는 원리.
	
	참고: https://gshscs.tistory.com/11?category=442923
		: https://gshscs.tistory.com/13?category=442923
		: https://debugjung.tistory.com/entry/stl%EC%97%90%EC%84%9C-%EA%B5%AC%ED%98%84%ED%95%9C-intro-sort-%EC%B0%B8%EC%A1%B0
		: http://www.secmem.org/blog/2019/04/10/special-sorts/
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort, stable_sort
#include <functional> // greater

using namespace std;

// int 타입 정렬

const int ARRAY_SIZE = 10;

int main() {
	int arr[ARRAY_SIZE] = { 5,0,4,6,3,2,1,9,8,7 };
	
	for (const int elem : arr) cout << elem << " "; // 출력
	cout << endl;
	// expected output: 5 0 4 6 3 2 1 9 8 7

	// 오름차순 정렬
	sort(arr, arr + ARRAY_SIZE); // 기본(생략가능)
	sort(arr, arr + ARRAY_SIZE, less<int>()); // 명시
	sort(arr, arr + ARRAY_SIZE, [](const int& a, const int& b) {return a < b; }); // 람다식
	for (const int elem : arr) cout << elem << " "; // 출력
	cout << endl;
	// expected output: 0 1 2 3 4 5 6 7 8 9
	
	// 내림차순 정렬
	sort(arr, arr + ARRAY_SIZE, greater<int>()); // 명시
	sort(arr, arr + ARRAY_SIZE, [](const int& a, const int& b) {return a > b; }); // 람다식
	for (const int elem : arr) cout << elem << " "; // 출력
	cout << endl;
	// expected output: 9 8 7 6 5 4 3 2 1 0

	return 0;
}



// class 타입 정렬 (구조체 정렬 방식 또한 이와 비슷하다.)

// class의 멤버 변수에 여러 값들이 존재할 때, 무슨 값을 기준으로 비교하고 정렬할지 모르겠다!
// 그럴 때 연산자 오버로딩 또는 비교 함수를 재정의 해서 sort에게 비교 대상을 알려주자.

// 정렬 기준을 정해주는 데에는 여러가지 방법이 존재한다.
// 그냥 선호하는 방식을 사용하자.

// pair 타입 또는 string 타입은 내부에 비교 함수가 구현되어 있다!
//  - pair: first 값 비교 -> 같다면 second 비교 후 정렬한다.
//  - string: 문자열의 길이와 상관없이 사전순으로 정렬한다.

#include <string>

class GPA {
public:
	int math, english, history;
	string name;

	GPA(int math, int english, int history, string name) { // 생성자(초기화)
		this->math = math;
		this->english = english;
		this->history = history;
		this->name = name;
	}
	void print() { // 출력
		cout << name << " => " << "Math: " << math << "  English: " << english << "  History: " << history << "\n";
	}
	/* 기본적으로 sort 함수 내부에서 '<' 연산자를 통해 비교 후 정렬한다.
	하지만 현재 클래스에는 int 타입 변수 3개와 string 타입 변수 1개가 있기 때문에,
	무엇을 기준으로 정렬할지 알려주는 것이 중요하다.

	아래의 연산자 오버로딩 함수는 이름을 기준으로
	사전 순 정렬을 하도록 하는 함수이다.
	문자열 사전 순 비교는 string 라이브러리 안에 선언되어 있으므로 '<' 연산자 하나로 비교가 가능하다. */
	bool operator<(const GPA& nxt) const {
		return this->name < nxt.name;
	}
};

/* 연산자 오버로딩으로 인해서 이 클래스를 정렬 할 시 이름 순으로 정렬이 된다.
사용자가 원하는 정렬 형식이 있다면 비교 함수를 만들어 주는 것도 좋은 방법이다.
아래는 수학, 영어, 역사의 총점이 가장 큰 사람이 앞으로 오도록 만드는 함수이다. */
bool totalCompare(const GPA& a, const GPA& b) {
	int total_a = a.math + a.english + a.history,
		total_b = b.math + b.english + b.history;
	return total_a > total_b;
}

/* 함수 객체를 생성해서, 정렬 방식을 재정의한다.
수학 점수가 낮은 사람이 앞으로 오도록 정렬한다. */
struct {
	bool operator()(const GPA& a, const GPA& b) const {
		return a.math < b.math;
	}
} mathCompare;

int main() {
	vector<GPA> vgpa;

	GPA stu1 = GPA(50, 60, 30, "Jonas");
	GPA stu2 = GPA(30, 40, 50, "Keras");
	GPA stu3 = GPA(90, 10, 10, "Python");
	GPA stu4 = GPA(80, 80, 80, "James");
	GPA stu5 = GPA(100, 10, 50, "Pandas");

	vgpa.push_back(stu1);
	vgpa.push_back(stu2);
	vgpa.push_back(stu3);
	vgpa.push_back(stu4);
	vgpa.push_back(stu5);

	sort(vgpa.begin(), vgpa.end()); // 기본 정렬(연산자 오버로딩으로 인한 이름 사전순 정렬)
	for (auto& s : vgpa) s.print();

	cout << "\n====================================================\n\n";

	sort(vgpa.begin(), vgpa.end(), totalCompare); // 사용자 정의 함수 사용
	for (auto& s : vgpa) s.print();

	cout << "\n====================================================\n\n";

	sort(vgpa.begin(), vgpa.end(), mathCompare); // 함수 객체를 활용한 정렬
	for (auto& s : vgpa) s.print();

	cout << "\n====================================================\n\n";

	sort(vgpa.begin(), vgpa.end(), [](const GPA& a, const GPA& b) { return a.english > b.english; }); // 람다식을 활용한 정렬
	for (auto& s : vgpa) s.print();

	return 0;
}



/*
	* 안정 정렬(Stable Sort) 사용하기
	stable_sort() 함수 역시 "algorithm" 라이브러리 안에 속해있다.

	sort()와 stable_sort()의 차이점이 뭘까?
	: sort()는 값의 비교 및 정렬을 최우선으로 하여 빠른 속도를 자랑한다.
	  하지만 동일한 값에 대한 순서는 보장하지 못한다.
	  이를 보완한 정렬 함수가 stable_sort()이다.

	이게 무슨말일까?

	예를들어, { 2, 5, 4, 3, 2, 3, 6, 3 } 이라는 8칸 짜리 배열이 있다고 가정하자.
	일반적으로 sort() 함수로 정렬을 수행하면 { 2, 2, 3, 3, 3, 4, 5, 6 } 와 같은 결과를 얻는다.

	다시,
	주어진 배열을 조금 다른 시각으로 바라보자.
	{ 2¹, 5, 4, 3¹, 2², 3², 6, 3³ } : 같은 값이 존재할 경우, 순서가 존재한다고 가정하자.

	이 때 stable_sort()를 수행하면, { 2¹, 2², 3¹, 3², 3³, 4, 5, 6} 와 같은 결과를 얻는다.
	하지만 sort() 함수는 같은 값에 대한 순서를 보장받지 못한다.
	즉, 동일한 값이라면 뒤죽박죽으로 섞어놓는다는 의미이다.

	따라서 sort() 보다는 조금 느리다.

	stable_sort()는 stable을 보장해야 하기 때문에 Merge Sort 기반으로 동작한다.
	시간복잡도: O(n log n)
*/

typedef struct S {
	int x, y;
	bool operator<(const S& nxt) const { return x < nxt.x; }
} S;

int main() {
	// 순서를 저장하는 second 값의 default 는 1이다.
	S arr[8] = { {2,1},{5,1},{4,1},{3,1},{2,2},{3,2},{6,1},{3,3} };

	stable_sort(arr, arr + 8);
	for (const auto& elem : arr)
		cout << "{" << elem.x << ", " << elem.y << "}" << ", ";

	return 0;
}



/*
	* 부분 정렬(Partial Sort) 사용하기
	partial_sort() 함수 역시 "algorithm" 라이브러리 안에 속해있다.

	partial_sort(①, ②, ③) : 일반적으로 3개의 매개변수를 가진다.
	① 배열의 시작 주소 (벡터의 경우 vector.begin())
	② 정렬 구간
	③ 배열의 끝 주소 + 1 (벡터의 경우 vector.end())

	예를 들어, 배열에 { 5, 3, 1, 6, 4, 7, 2, 9, 8 } 와 같은 값이 있다면,
	partial_sort(v.begin(), v.begin() + 5, v.end()) 를 수행하면,
	{ 1, 2, 3, 4, 5, ... } 이 출력된다.

	정렬 구간에 속하지 않은 부분에는 질서를 보장하지 않는다.
	100명의 학생들의 성적 중 상위 10명의 학생들의 데이터만 보고싶다면,
	굳이 모든 학생을 정렬할 필요 없다.

	시작 주소부터 정렬 구간으로 정해준 부분까지 정렬을 수행하는데,
	전체 원소의 개수가 n개이고, 정렬 구간에 속한 원소의 개수가 m개일 때,
	시간복잡도는 O(n log m) 이다.

	상황에 따라 다르지만, 대부분의 경우에서 sort() 보다 빠르다.

	참고: http://www.cplusplus.com/reference/algorithm/partial_sort/
		: https://modoocode.com/225
*/

int main() {
	int arr[9] = { 5,3,1,6,4,7,2,9,8 };
	
	partial_sort(arr, arr + 5, arr + 9);

	for (const auto& elem : arr) cout << elem << " ";

	return 0;
}