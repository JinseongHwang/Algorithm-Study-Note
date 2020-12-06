/*
	* C++에서 정규표현식(Regular Expressio) 사용하기
	: 문자열 문제 풀 때 알아두면 가끔 편하더라

	참고로 C++11 부터 표준에 포함되었으니, 그 이전의 환경에서는 사용할 수 없다.
	(11이면 이제 10년정도 됐는데, 모든 곳에서 지원 해줬으면!)
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

int main() {
	string target1 = "123123123000";
	string target2 = "123a000";

	regex number("^[0-9]+$");

	if (regex_match(target1, number)) {
		cout << target1 << " is a number.\n";
	}
	else {
		cout << target1 << " is not a number.\n";
	}

	if (regex_match(target2, number)) {
		cout << target2 << " is a number.\n";
	}
	else {
		cout << target2 << " is not a number.\n";
	}

	return 0;
}