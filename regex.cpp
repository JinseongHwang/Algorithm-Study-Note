/*
	* C++���� ����ǥ����(Regular Expressio) ����ϱ�
	: ���ڿ� ���� Ǯ �� �˾Ƶθ� ���� ���ϴ���

	����� C++11 ���� ǥ�ؿ� ���ԵǾ�����, �� ������ ȯ�濡���� ����� �� ����.
	(11�̸� ���� 10������ �ƴµ�, ��� ������ ���� ��������!)
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