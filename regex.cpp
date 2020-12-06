/*
	* C++���� ����ǥ����(Regular Expressio) ����ϱ�
	: ���ڿ� ���� Ǯ �� �˾Ƶθ� ���� ���ϴ���

	����� C++11 ���� ǥ�ؿ� ���ԵǾ�����, �� ������ ȯ�濡���� ����� �� ����.
	(11�̸� ���� 10������ �ƴµ�, ��� ������ ���� ��������!)

	���Խ� �ۼ��� ���� ���
	- My Blog: https://blog.naver.com/eddy5360/221919634767
	- ���������̽�: https://wikidocs.net/1642
		-> python��� ������� �ۼ�������, ���Խ��� �� �Ȱ���. (������ �߾�)
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

int main() {
	string target1 = "123123123000";
	string target2 = "123a000";

	// ����(0~9)�� �̷���� ���ڿ� �� ���̰� 1 �̻��� �͵�� ��Ī.
	regex number("^[0-9]+$");

	// ���� ���, ��ȭ��ȣ ��Ī ���Խ��� ������ ����.
	// (0 �Ǵ� 1�� �̷���� 3�ڸ�)-(���� 3�ڸ� �Ǵ� 4�ڸ�)-(����4�ڸ�)
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