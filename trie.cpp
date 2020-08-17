/*
	* 트라이(Trie) 알고리즘: 트리 형태에 여러 문자열을 저장해서, 탐색 속도를 극대화시킨 알고리즘이다.
	* 다른 이름으로 Radix Tree 또는 Prefix Tree 라고 불린다.

	- 탐색 시간복잡도: O(n)

	- 트라이 구조는 빠른 시간복잡도를 얻기 위해 공간복잡도를 희생한 구조이다.
	
	1. 하나의 문자열을 트리 구조에 삽입하는데,
	  - root 노드는 비어있다. 그 아래 알파벳 배열(노드)이 생성된다.
	  - 알파벳 하나씩 삽입하는 과정을 거친다.
	  - 알파벳 하나를 삽입할 때마다 트리의 depth가 깊어지며, 마지막 노드(NULL)에는 terminal에 true값을 준다.
	  - 공통된 접두사를 가지고 있지 않다면 노드를 추가 생성해서 연결해준다.

	2. 트라이 구조에 저장된 문자열을 찾고 싶다면,
	  - 이 역시 알파벳 하나씩 탐색한다.
	  - 마지막 문자(NULL)까지 찾았다면 그 정점의 정보(this)를 반환한다.
	  - 만약 찾을 수 없다면 NULL을 반환해서 탐색에 실패했음을 의미한다.
*/


// 소스코드 출처: 알고리즘 문제해결전략(구종만 저)
// 본인이 일부 수정함
#include <memory.h>
using namespace std;

// 알파벳 대문자로 이루어진 문자열이라고 가정.
// 만약 알파벳 대소문자, 숫자, 특수문자 등으로 이뤄졌다고 가정하면
// 공간복잡도 측면에서 치명적이다.
const int ALPHABETS = 26; // 알파벳 대문자 개수
__inline int toNumber(char ch) { return ch - 'A'; } // 'A': 0 ~ 'Z': 25

// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS]; // 다음 문자를 가리키는 포인터 배열
	bool terminal; // 마지막 노드인지 판별

	TrieNode() : terminal(false) { // 생성자
		memset(children, 0, sizeof(children));
	}

	~TrieNode() { // 소멸자
		for (int i = 0; i < ALPHABETS; ++i) {
			if (children[i]) delete children[i]; // 메모리 할당 해제
		}
	}
	// 문자열 삽입 연산
	void insert(const char* key) {
		if (*key == 0) { // 문자열의 마지막(null)이라면
			terminal = true; // 마지막 노드 체크해준다
		}
		else {
			int nxt = toNumber(*key);
			if (children[nxt] == NULL) children[nxt] = new TrieNode();
			children[nxt]->insert(key + 1);
		}
	}

	// 현재 노드를 root로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다.
	// 만약 찾을 수 없다면 NULL을 반환한다.
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int nxt = toNumber(*key);
		if (children[nxt] == NULL) return NULL;
		return children[nxt]->find(key + 1);
	}
};

// ===================================================================

// 대표 예제
// #5052 전화번호 목록

// C++11부터는 컴파일러에서 NULL을 0으로 치환해서 컴파일한다.
// 포인터 변수를 초기화 할 때 NULL보다 nullptr로 초기화하도록 하자.

#include <iostream>
using namespace std;

// 최대 단어의 개수, 전화번호의 최대 길이이자 숫자는 0부터 9까지 있다.
const int MAX_WORD = 10010, MAX_LEN = 10;

class Trie {
private:
	Trie* word[MAX_LEN]; // 다음 문자를 가리키는 포인터 배열
	bool terminal; // 마지막 노드이면 true값을 가진다.
	bool nextNodeExist; // 자식 노드가 존재하면 true값을 가진다.

public:
	// 생성자
	Trie() { // 초기화 역할
		fill(word, word + MAX_LEN, nullptr);
		terminal = nextNodeExist = false;
	}
	// 소멸자
	~Trie() { // 메모리 누수 방지, 사용하고 나서 반납
		for (int i = 0; i < MAX_LEN; ++i)
			if (word[i] != nullptr) delete word[i];
	}
	// 문자열 삽입 연산
	void insert(char* currWord) {
		// 문자열의 마지막까지 탐색했다면
		if (*currWord == '\0') {
			terminal = true;
		}
		// 더 탐색할 문자열이 남아있다면
		else {
			int currNum = *currWord - '0';
			if (word[currNum] == nullptr) word[currNum] = new Trie(); // 동적할당
			nextNodeExist = true;
			word[currNum]->insert(currWord + 1); // 자식 노드 삽입
		}
	}
	// 일관성이 있는 문자열인지 판별
	bool consistent() {
		// 마지막 노드인데 다음 노드가 있는 경우 false
		if (terminal && nextNodeExist) return false;
		// 서브트리 중 일관성이 하나라도 없으면 false
		for (int i = 0; i < MAX_LEN; ++i) {
			if (word[i] != nullptr && !word[i]->consistent()) return false;
		}
		// 위 두 조건을 만족하지 않는다면 일관성이 있으므로 true
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		Trie* root = new Trie(); // 루트 생성
		for (int i = 0; i < n; ++i) {
			char input[MAX_LEN]; cin >> input; // 입력받음
			root->insert(input); // 문자열 삽입
		}
		cout << ((root->consistent()) ? "YES\n" : "NO\n");
		delete root; // 소멸
	}

	return 0;
}