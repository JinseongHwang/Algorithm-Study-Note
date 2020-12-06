
// C������ ���ڿ��� �ٷ�� ��ٷӽ��ϴ�.
// ������ C++ string class�� ���� �˾ƺ��ô�.

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// ���� <-> ���� �Դٰ���
// ������ �����̴� inline ó���ؼ� ���� �ӵ� UP
__inline char itoc(int x) { return x + '0'; }
__inline int ctoi(char x) { return x - '0'; }

string to_lower_case(string);
string to_upper_case(string);

int main() {

	/*

	// [ ���� ]
	// string ���� ����� ���ÿ� �ʱ�ȭ
	string str = "Jinseong Hwang";
	
	// ���� s1�� �����ϴµ�, str�� ������ �����Ѵ�.
	string s1(str); // -> "Jinseong Hwang"
	
	// ���� s2�� �����ϴµ�, str�� ������ 5���� ������ �����Ѵ�.
	string s2(str, 5); // -> "ong Hwang"
	
	// ���� s3�� �����ϴµ�, str�� ������ 3��°���� 8���� �����Ѵ�.
	string s3(str, 3, 8); // -> "seong Hw"

	
	// [ ���� ���� ]
	// �ٸ� C++ Container�� �����ϰ� operator[]�� at()���� Random Access�� �����ϴ�.
	char c1 = str[5]; // -> 'o'
	char c2 = str.at(6); // -> 'n'

	// front()�� back()���� ���� ��, �� ���ҿ� ���� �����ϴ�.
	c1 = str.front(); // -> 'J'
	c2 = str.back(); // -> 'g'

	
	// [ C������ ���ڿ��� const char* Ÿ������ ��ȯ ]
	const char* CString = str.c_str();


	// [ iterator�� Ȱ���� Ž�� ]
	// iterator ����
	string::iterator iter;
	string::reverse_iterator riter;

	// ���� Ž�� �� ���
	for (iter = str.begin(); iter != str.end(); ++iter) cout << *iter; // -> "Jinseong Hwang"
	
	// ���� Ž�� �� ���
	// �� ����� iter�� ����ؼ� --iter�� ���������� �ص� �������.
	for (riter = str.rbegin(); riter != str.rend(); ++riter) cout << *riter; // -> "gnawH gnoesniJ"


	// [ ���� �� �Ҵ���� ]
	cout << str.length(); // str.size()�� ����.
	cout << str.capacity(); // �Ҵ�� ������ ��ü ũ�⸦ ��ȯ�Ѵ�. length()�� �ٸ� �����̴�.
	str.shrink_to_fit(); // �������� ���� capacity�� length�� �°� �Ҵ� �����Ѵ�.

	*/

	string str = "This is the moment, When all I've done";

	// ���ڿ��� ���Ե� ���� ����
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	// -> "Thisisthemoment,WhenallI'vedone"

	cout << to_lower_case(str) << "\n"; // ��� ���ĺ��� �ҹ��� ���·� ǥ���Ѵ�.
	cout << to_upper_case(str) << "\n"; // ��� ���ĺ��� �빮�� ���·� ǥ���Ѵ�.


	// [ ������ �Լ� ]
	// ���ڿ� �ڸ���
	// substr(x): [x, END) ���� -> x��° index���� ������
	// substr(x, y): [x, x+y) ���� -> x��° index���� y�� ��ŭ
	str.substr(6); // -> "s the moment, When all I've done"
	str.substr(6, 15); // -> "s the moment, W"
	
	// ���� �� ���ڿ� Ž��
	// find(s): ���ڿ����� s�� Ž���ϰ�, ���� ó�� �߰��� s�� ���� index�� ��ȯ�Ѵ�. ���ٸ� string::npos�� ��ȯ�Ѵ�.
	// find(s, i): ���ڿ����� s�� Ž���ϴµ�, i��° index���� Ž���ϱ� �����Ѵ�. �۵� ����� ���� ����.
	// rfind(): find�� ����������, �ڿ��� ���� Ž���Ѵ�.
	str.find("is"); // -> 2
	
	// ���ڿ����� "is"�� �����ϴ� ��� index�� �˰� �ʹٸ� Ž�� ��ġ�� ��� ����������.
	int start_index = -1;
	while ((start_index = str.find("is", start_index + 1)) != string::npos) {
		cout << start_index << "\n";
	} // -> 2 5

	// ���ڿ� ��ü(replace)
	char from = 'e';
	char to = '#';
	// ���ڿ��� ���Ե� ��� from�� to�� �����Ѵ�.
	replace(str.begin(), str.end(), from, to); // -> "This is th# mom#nt, Wh#n all I'v# don#"

	// ���ڿ��� ���Ե� ù ��° from_s�� to_s�� �����Ѵ�.
	string from_s = "moment";
	string to_s = "samsung laptop";
	str.replace(str.find(from_s), from_s.length(), to_s); // -> "This is the samsung laptop, When all I've done"

	// ��� ���ڿ��� �����Ϸ��� find()���� ����� �� ó�� �ݺ����ָ� �ȴ�.
	start_index = -1;
	from_s = "is";
	to_s = "ISISIS";
	while ((start_index = str.find(from_s, start_index + 1)) != string::npos) {
		str.replace(start_index, from_s.length(), to_s);
	} // -> "ThISISIS ISISIS the moment, When all I've done"

	// ���ڿ� <-> ���� �Դٰ���
	int x = 123;
	string y = "456";
	// ���ڿ��� ������ ��ȯ: atoi(), �ٸ� ������ Ÿ���� const char* �̱� ������ string�� �ִ´ٸ� .c_str()�� �ٿ�����.
	// intŸ������ ��ȯ�� ���� atoi()�ϰ�, �ٸ� ���� Ÿ���� ��� atof(), atol(), atoll() � �����Ѵ�.
	// C++11���ʹ� stoi(), stol(), stod(), stoll(), stof() � �����Ѵ�.
	/* since C++98 */cout << x + atoi(y.c_str()) << "\n"; // -> 579
	/* since C++11 */cout << x + stoi(y) << "\n"; // -> 579
	// ������ ���ڿ��� ��ȯ: stringstream, to_string()
	stringstream ssInt; // need include <sstream>
	ssInt << x;
	/* since C++98 */cout << ssInt.str() + y << "\n"; // -> "123456"
	/* since C++11 */cout << to_string(x) + y << "\n"; // -> "123456"

	str.clear(); // size�� 0���� �����.

	return 0;
}

// ASCII���� lower case�� upper case���� ū ���� ������.
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