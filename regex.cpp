/*
	* C++에서 정규표현식(Regular Expressio) 사용하기
	: 문자열 문제 풀 때 알아두면 가끔 편하더라

	참고로 C++11 부터 표준에 포함되었으니, 그 이전의 환경에서는 사용할 수 없다.
	(11이면 이제 10년정도 됐는데, 모든 곳에서 지원 해줬으면!)

	정규식 작성에 대한 방법
	- My Blog: https://blog.naver.com/eddy5360/221919634767
	- 점프투파이썬: https://wikidocs.net/1642
		-> python언어 기반으로 작성됐지만, 정규식은 다 똑같다. (경험적 발언)
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

int main() {
	string target1 = "123123123000";
	string target2 = "123a000";

	// 숫자(0~9)로 이루어진 문자열 중 길이가 1 이상인 것들과 매칭.
	regex number("^[0-9]+$");

	// 예를 들어, 전화번호 매칭 정규식은 다음과 같다.
	// (0 또는 1로 이루어진 3자리)-(숫자 3자리 또는 4자리)-(숫자4자리)
	regex phone_number("[01]{3}-\d{3,4}-\d{4}");

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