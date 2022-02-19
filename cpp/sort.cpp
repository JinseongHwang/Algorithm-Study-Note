/*
	* ����(Sort) STL ��� �� ����� ���� �� �Լ� �����

	: C++ ǥ�� ���̺귯�� �� "algorithm" ���̺귯�� �ȿ� ���ǵ� sort()�Լ��� ����Ѵ�.

	��Ʈ�� ����(Intro Sort) ������� ���ĵǴµ�, �̴� Quick sort, Heap sort�� ȥ���� ����̴�.
	����: https://justicehui.github.io/medium-algorithm/2019/03/24/IntroSort/
	������Ű: https://en.wikipedia.org/wiki/Introsort
	
	�ð����⵵: O(n log n)

	sort(��, ��, ��) : �Ϲ������� 2�� �Ǵ� 3���� �Ű������� ������.
	�� �迭 ���� �ּ�(�迭�� ��쿡�� �迭�� �̸�, ������ ��쿡�� vector.begin())
	�� �迭 �� �ּ� + 1(�迭�� ��쿡�� �迭�� �̸� + ARRAY_SIZE, ������ ��쿡�� vector.end())
	�� ����� ���� �� �Լ� 
		-> ��ȯ ���� true�̸� �״�� �ΰ�, false�̸� swap�ϴ� ����.
	
	����: https://gshscs.tistory.com/11?category=442923
		: https://gshscs.tistory.com/13?category=442923
		: https://debugjung.tistory.com/entry/stl%EC%97%90%EC%84%9C-%EA%B5%AC%ED%98%84%ED%95%9C-intro-sort-%EC%B0%B8%EC%A1%B0
		: http://www.secmem.org/blog/2019/04/10/special-sorts/
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort, stable_sort
#include <functional> // greater

using namespace std;

// int Ÿ�� ����

const int ARRAY_SIZE = 10;

int main() {
	int arr[ARRAY_SIZE] = { 5,0,4,6,3,2,1,9,8,7 };
	
	for (const int elem : arr) cout << elem << " "; // ���
	cout << endl;
	// expected output: 5 0 4 6 3 2 1 9 8 7

	// �������� ����
	sort(arr, arr + ARRAY_SIZE); // �⺻(��������)
	sort(arr, arr + ARRAY_SIZE, less<int>()); // ���
	sort(arr, arr + ARRAY_SIZE, [](const int& a, const int& b) {return a < b; }); // ���ٽ�
	for (const int elem : arr) cout << elem << " "; // ���
	cout << endl;
	// expected output: 0 1 2 3 4 5 6 7 8 9
	
	// �������� ����
	sort(arr, arr + ARRAY_SIZE, greater<int>()); // ���
	sort(arr, arr + ARRAY_SIZE, [](const int& a, const int& b) {return a > b; }); // ���ٽ�
	for (const int elem : arr) cout << elem << " "; // ���
	cout << endl;
	// expected output: 9 8 7 6 5 4 3 2 1 0

	return 0;
}



// class Ÿ�� ���� (����ü ���� ��� ���� �̿� ����ϴ�.)

// class�� ��� ������ ���� ������ ������ ��, ���� ���� �������� ���ϰ� �������� �𸣰ڴ�!
// �׷� �� ������ �����ε� �Ǵ� �� �Լ��� ������ �ؼ� sort���� �� ����� �˷�����.

// ���� ������ �����ִ� ������ �������� ����� �����Ѵ�.
// �׳� ��ȣ�ϴ� ����� �������.

// pair Ÿ�� �Ǵ� string Ÿ���� ���ο� �� �Լ��� �����Ǿ� �ִ�!
//  - pair: first �� �� -> ���ٸ� second �� �� �����Ѵ�.
//  - string: ���ڿ��� ���̿� ������� ���������� �����Ѵ�.

#include <string>

class GPA {
public:
	int math, english, history;
	string name;

	GPA(int math, int english, int history, string name) { // ������(�ʱ�ȭ)
		this->math = math;
		this->english = english;
		this->history = history;
		this->name = name;
	}
	void print() { // ���
		cout << name << " => " << "Math: " << math << "  English: " << english << "  History: " << history << "\n";
	}
	/* �⺻������ sort �Լ� ���ο��� '<' �����ڸ� ���� �� �� �����Ѵ�.
	������ ���� Ŭ�������� int Ÿ�� ���� 3���� string Ÿ�� ���� 1���� �ֱ� ������,
	������ �������� �������� �˷��ִ� ���� �߿��ϴ�.

	�Ʒ��� ������ �����ε� �Լ��� �̸��� ��������
	���� �� ������ �ϵ��� �ϴ� �Լ��̴�.
	���ڿ� ���� �� �񱳴� string ���̺귯�� �ȿ� ����Ǿ� �����Ƿ� '<' ������ �ϳ��� �񱳰� �����ϴ�. */
	bool operator<(const GPA& nxt) const {
		return this->name < nxt.name;
	}
};

/* ������ �����ε����� ���ؼ� �� Ŭ������ ���� �� �� �̸� ������ ������ �ȴ�.
����ڰ� ���ϴ� ���� ������ �ִٸ� �� �Լ��� ����� �ִ� �͵� ���� ����̴�.
�Ʒ��� ����, ����, ������ ������ ���� ū ����� ������ ������ ����� �Լ��̴�. */
bool totalCompare(const GPA& a, const GPA& b) {
	int total_a = a.math + a.english + a.history,
		total_b = b.math + b.english + b.history;
	return total_a > total_b;
}

/* �Լ� ��ü�� �����ؼ�, ���� ����� �������Ѵ�.
���� ������ ���� ����� ������ ������ �����Ѵ�. */
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

	sort(vgpa.begin(), vgpa.end()); // �⺻ ����(������ �����ε����� ���� �̸� ������ ����)
	for (auto& s : vgpa) s.print();

	cout << "\n====================================================\n\n";

	sort(vgpa.begin(), vgpa.end(), totalCompare); // ����� ���� �Լ� ���
	for (auto& s : vgpa) s.print();

	cout << "\n====================================================\n\n";

	sort(vgpa.begin(), vgpa.end(), mathCompare); // �Լ� ��ü�� Ȱ���� ����
	for (auto& s : vgpa) s.print();

	cout << "\n====================================================\n\n";

	sort(vgpa.begin(), vgpa.end(), [](const GPA& a, const GPA& b) { return a.english > b.english; }); // ���ٽ��� Ȱ���� ����
	for (auto& s : vgpa) s.print();

	return 0;
}



/*
	* ���� ����(Stable Sort) ����ϱ�
	stable_sort() �Լ� ���� "algorithm" ���̺귯�� �ȿ� �����ִ�.

	sort()�� stable_sort()�� �������� ����?
	: sort()�� ���� �� �� ������ �ֿ켱���� �Ͽ� ���� �ӵ��� �ڶ��Ѵ�.
	  ������ ������ ���� ���� ������ �������� ���Ѵ�.
	  �̸� ������ ���� �Լ��� stable_sort()�̴�.

	�̰� �������ϱ�?

	�������, { 2, 5, 4, 3, 2, 3, 6, 3 } �̶�� 8ĭ ¥�� �迭�� �ִٰ� ��������.
	�Ϲ������� sort() �Լ��� ������ �����ϸ� { 2, 2, 3, 3, 3, 4, 5, 6 } �� ���� ����� ��´�.

	�ٽ�,
	�־��� �迭�� ���� �ٸ� �ð����� �ٶ���.
	{ 2��, 5, 4, 3��, 2��, 3��, 6, 3�� } : ���� ���� ������ ���, ������ �����Ѵٰ� ��������.

	�� �� stable_sort()�� �����ϸ�, { 2��, 2��, 3��, 3��, 3��, 4, 5, 6} �� ���� ����� ��´�.
	������ sort() �Լ��� ���� ���� ���� ������ ������� ���Ѵ�.
	��, ������ ���̶�� ���׹������� ������´ٴ� �ǹ��̴�.

	���� sort() ���ٴ� ���� ������.

	stable_sort()�� stable�� �����ؾ� �ϱ� ������ Merge Sort ������� �����Ѵ�.
	�ð����⵵: O(n log n)
*/

typedef struct S {
	int x, y;
	bool operator<(const S& nxt) const { return x < nxt.x; }
} S;

int main() {
	// ������ �����ϴ� second ���� default �� 1�̴�.
	S arr[8] = { {2,1},{5,1},{4,1},{3,1},{2,2},{3,2},{6,1},{3,3} };

	stable_sort(arr, arr + 8);
	for (const auto& elem : arr)
		cout << "{" << elem.x << ", " << elem.y << "}" << ", ";

	return 0;
}



/*
	* �κ� ����(Partial Sort) ����ϱ�
	partial_sort() �Լ� ���� "algorithm" ���̺귯�� �ȿ� �����ִ�.

	partial_sort(��, ��, ��) : �Ϲ������� 3���� �Ű������� ������.
	�� �迭�� ���� �ּ� (������ ��� vector.begin())
	�� ���� ����
	�� �迭�� �� �ּ� + 1 (������ ��� vector.end())

	���� ���, �迭�� { 5, 3, 1, 6, 4, 7, 2, 9, 8 } �� ���� ���� �ִٸ�,
	partial_sort(v.begin(), v.begin() + 5, v.end()) �� �����ϸ�,
	{ 1, 2, 3, 4, 5, ... } �� ��µȴ�.

	���� ������ ������ ���� �κп��� ������ �������� �ʴ´�.
	100���� �л����� ���� �� ���� 10���� �л����� �����͸� ����ʹٸ�,
	���� ��� �л��� ������ �ʿ� ����.

	���� �ּҺ��� ���� �������� ������ �κб��� ������ �����ϴµ�,
	��ü ������ ������ n���̰�, ���� ������ ���� ������ ������ m���� ��,
	�ð����⵵�� O(n log m) �̴�.

	��Ȳ�� ���� �ٸ�����, ��κ��� ��쿡�� sort() ���� ������.

	����: http://www.cplusplus.com/reference/algorithm/partial_sort/
		: https://modoocode.com/225
*/

int main() {
	int arr[9] = { 5,3,1,6,4,7,2,9,8 };
	
	partial_sort(arr, arr + 5, arr + 9);

	for (const auto& elem : arr) cout << elem << " ";

	return 0;
}