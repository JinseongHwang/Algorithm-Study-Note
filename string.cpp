
// C에서는 문자열을 다루기 까다롭습니다.
// 편해진 C++ string class에 대해 알아봅시다.

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// 문자 <-> 정수 왔다갔다
// 가벼운 연산이니 inline 처리해서 연산 속도 UP
__inline char itoc(int x) { return x + '0'; }
__inline int ctoi(char x) { return x - '0'; }

string to_lower_case(string);
string to_upper_case(string);

int main() {

	/*

	// [ 선언 ]
	// string 변수 선언과 동시에 초기화
	string str = "Jinseong Hwang";
	
	// 변수 s1을 선언하는데, str의 내용을 복사한다.
	string s1(str); // -> "Jinseong Hwang"
	
	// 변수 s2를 선언하는데, str의 내용의 5부터 끝까지 복사한다.
	string s2(str, 5); // -> "ong Hwang"
	
	// 변수 s3를 선언하는데, str의 내용을 3번째부터 8개를 복사한다.
	string s3(str, 3, 8); // -> "seong Hw"

	
	// [ 원소 접근 ]
	// 다른 C++ Container와 동일하게 operator[]와 at()으로 Random Access가 가능하다.
	char c1 = str[5]; // -> 'o'
	char c2 = str.at(6); // -> 'n'

	// front()와 back()으로 가장 앞, 뒤 원소에 접근 가능하다.
	c1 = str.front(); // -> 'J'
	c2 = str.back(); // -> 'g'

	
	// [ C문법의 문자열인 const char* 타입으로 변환 ]
	const char* CString = str.c_str();


	// [ iterator을 활용한 탐색 ]
	// iterator 선언
	string::iterator iter;
	string::reverse_iterator riter;

	// 순차 탐색 및 출력
	for (iter = str.begin(); iter != str.end(); ++iter) cout << *iter; // -> "Jinseong Hwang"
	
	// 역순 탐색 및 출력
	// 위 방식의 iter을 사용해서 --iter로 증감연산을 해도 상관없다.
	for (riter = str.rbegin(); riter != str.rend(); ++riter) cout << *riter; // -> "gnawH gnoesniJ"


	// [ 길이 및 할당공간 ]
	cout << str.length(); // str.size()와 같다.
	cout << str.capacity(); // 할당된 공간의 전체 크기를 반환한다. length()와 다른 개념이다.
	str.shrink_to_fit(); // 쓰고있지 않은 capacity를 length에 맞게 할당 해제한다.

	*/

	string str = "This is the moment, When all I've done";

	// 문자열에 포함된 공백 제거
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	// -> "Thisisthemoment,WhenallI'vedone"

	cout << to_lower_case(str) << "\n"; // 모든 알파벳을 소문자 형태로 표현한다.
	cout << to_upper_case(str) << "\n"; // 모든 알파벳을 대문자 형태로 표현한다.


	// [ 구현된 함수 ]
	// 문자열 자르기
	// substr(x): [x, END) 추출 -> x번째 index에서 끝까지
	// substr(x, y): [x, x+y) 추출 -> x번째 index에서 y개 만큼
	str.substr(6); // -> "s the moment, When all I've done"
	str.substr(6, 15); // -> "s the moment, W"
	
	// 문자 및 문자열 탐색
	// find(s): 문자열에서 s를 탐색하고, 가장 처음 발견한 s의 시작 index를 반환한다. 없다면 string::npos를 반환한다.
	// find(s, i): 문자열에서 s를 탐색하는데, i번째 index부터 탐색하기 시작한다. 작동 방식은 위와 같다.
	// rfind(): find와 동일하지만, 뒤에서 부터 탐색한다.
	str.find("is"); // -> 2
	
	// 문자열에서 "is"가 존재하는 모든 index를 알고 싶다면 탐색 위치를 계속 갱신해주자.
	int start_index = -1;
	while ((start_index = str.find("is", start_index + 1)) != string::npos) {
		cout << start_index << "\n";
	} // -> 2 5

	// 문자열 대체(replace)
	char from = 'e';
	char to = '#';
	// 문자열에 포함된 모든 from을 to로 변경한다.
	replace(str.begin(), str.end(), from, to); // -> "This is th# mom#nt, Wh#n all I'v# don#"

	// 문자열에 포함된 첫 번째 from_s를 to_s로 변경한다.
	string from_s = "moment";
	string to_s = "samsung laptop";
	str.replace(str.find(from_s), from_s.length(), to_s); // -> "This is the samsung laptop, When all I've done"

	// 모든 문자열을 변경하려면 find()에서 언급한 것 처럼 반복해주면 된다.
	start_index = -1;
	from_s = "is";
	to_s = "ISISIS";
	while ((start_index = str.find(from_s, start_index + 1)) != string::npos) {
		str.replace(start_index, from_s.length(), to_s);
	} // -> "ThISISIS ISISIS the moment, When all I've done"

	// 문자열 <-> 정수 왔다갔다
	int x = 123;
	string y = "456";
	// 문자열을 정수로 변환: atoi(), 다만 인자의 타입이 const char* 이기 때문에 string을 넣는다면 .c_str()을 붙여주자.
	// int타입으로 변환할 때는 atoi()하고, 다른 숫자 타입일 경우 atof(), atol(), atoll() 등도 존재한다.
	// C++11부터는 stoi(), stol(), stod(), stoll(), stof() 등도 존재한다.
	/* since C++98 */cout << x + atoi(y.c_str()) << "\n"; // -> 579
	/* since C++11 */cout << x + stoi(y) << "\n"; // -> 579
	// 정수를 문자열로 변환: stringstream, to_string()
	stringstream ssInt; // need include <sstream>
	ssInt << x;
	/* since C++98 */cout << ssInt.str() + y << "\n"; // -> "123456"
	/* since C++11 */cout << to_string(x) + y << "\n"; // -> "123456"

	str.clear(); // size를 0으로 만든다.

	return 0;
}

// ASCII에서 lower case가 upper case보다 큰 값을 가진다.
string to_lower_case(string str) {
	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] += ('a' - 'A');
		}
	}
	return str;
}

string to_upper_case(string str) {
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] -= ('a' - 'A');
		}
	}
	return str;
}