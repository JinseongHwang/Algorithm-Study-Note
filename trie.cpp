/*
	* Ʈ����(Trie) �˰���: Ʈ�� ���¿� ���� ���ڿ��� �����ؼ�, Ž�� �ӵ��� �ش�ȭ��Ų �˰����̴�.
	* �ٸ� �̸����� Radix Tree �Ǵ� Prefix Tree ��� �Ҹ���.

	- Ž�� �ð����⵵: O(n)

	- Ʈ���� ������ ���� �ð����⵵�� ��� ���� �������⵵�� ����� �����̴�.
	
	1. �ϳ��� ���ڿ��� Ʈ�� ������ �����ϴµ�,
	  - root ���� ����ִ�. �� �Ʒ� ���ĺ� �迭(���)�� �����ȴ�.
	  - ���ĺ� �ϳ��� �����ϴ� ������ ��ģ��.
	  - ���ĺ� �ϳ��� ������ ������ Ʈ���� depth�� �������, ������ ���(NULL)���� terminal�� true���� �ش�.
	  - ����� ���λ縦 ������ ���� �ʴٸ� ��带 �߰� �����ؼ� �������ش�.

	2. Ʈ���� ������ ����� ���ڿ��� ã�� �ʹٸ�,
	  - �� ���� ���ĺ� �ϳ��� Ž���Ѵ�.
	  - ������ ����(NULL)���� ã�Ҵٸ� �� ������ ����(this)�� ��ȯ�Ѵ�.
	  - ���� ã�� �� ���ٸ� NULL�� ��ȯ�ؼ� Ž���� ���������� �ǹ��Ѵ�.
*/


// �ҽ��ڵ� ��ó: �˰��� �����ذ�����(������ ��)
// ������ �Ϻ� ������
#include <memory.h>
using namespace std;

// ���ĺ� �빮�ڷ� �̷���� ���ڿ��̶�� ����.
// ���� ���ĺ� ��ҹ���, ����, Ư������ ������ �̷����ٰ� �����ϸ�
// �������⵵ ���鿡�� ġ�����̴�.
const int ALPHABETS = 26; // ���ĺ� �빮�� ����
__inline int toNumber(char ch) { return ch - 'A'; } // 'A': 0 ~ 'Z': 25

// Ʈ������ �� ��带 ��Ÿ���� ��ü
struct TrieNode {
	TrieNode* children[ALPHABETS]; // ���� ���ڸ� ����Ű�� ������ �迭
	bool terminal; // ������ ������� �Ǻ�

	TrieNode() : terminal(false) { // ������
		memset(children, 0, sizeof(children));
	}

	~TrieNode() { // �Ҹ���
		for (int i = 0; i < ALPHABETS; ++i) {
			if (children[i]) delete children[i]; // �޸� �Ҵ� ����
		}
	}
	// ���ڿ� ���� ����
	void insert(const char* key) {
		if (*key == 0) { // ���ڿ��� ������(null)�̶��
			terminal = true; // ������ ��� üũ���ش�
		}
		else {
			int nxt = toNumber(*key);
			if (children[nxt] == NULL) children[nxt] = new TrieNode();
			children[nxt]->insert(key + 1);
		}
	}

	// ���� ��带 root�� �ϴ� Ʈ���̿� ���ڿ� key�� �����Ǵ� ��带 ã�´�.
	// ���� ã�� �� ���ٸ� NULL�� ��ȯ�Ѵ�.
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int nxt = toNumber(*key);
		if (children[nxt] == NULL) return NULL;
		return children[nxt]->find(key + 1);
	}
};

// ===================================================================

// ��ǥ ����
// #5052 ��ȭ��ȣ ���

// C++11���ʹ� �����Ϸ����� NULL�� 0���� ġȯ�ؼ� �������Ѵ�.
// ������ ������ �ʱ�ȭ �� �� NULL���� nullptr�� �ʱ�ȭ�ϵ��� ����.

#include <iostream>
using namespace std;

// �ִ� �ܾ��� ����, ��ȭ��ȣ�� �ִ� �������� ���ڴ� 0���� 9���� �ִ�.
const int MAX_WORD = 10010, MAX_LEN = 10;

class Trie {
private:
	Trie* word[MAX_LEN]; // ���� ���ڸ� ����Ű�� ������ �迭
	bool terminal; // ������ ����̸� true���� ������.
	bool nextNodeExist; // �ڽ� ��尡 �����ϸ� true���� ������.

public:
	// ������
	Trie() { // �ʱ�ȭ ����
		fill(word, word + MAX_LEN, nullptr);
		terminal = nextNodeExist = false;
	}
	// �Ҹ���
	~Trie() { // �޸� ���� ����, ����ϰ� ���� �ݳ�
		for (int i = 0; i < MAX_LEN; ++i)
			if (word[i] != nullptr) delete word[i];
	}
	// ���ڿ� ���� ����
	void insert(char* currWord) {
		// ���ڿ��� ���������� Ž���ߴٸ�
		if (*currWord == '\0') {
			terminal = true;
		}
		// �� Ž���� ���ڿ��� �����ִٸ�
		else {
			int currNum = *currWord - '0';
			if (word[currNum] == nullptr) word[currNum] = new Trie(); // �����Ҵ�
			nextNodeExist = true;
			word[currNum]->insert(currWord + 1); // �ڽ� ��� ����
		}
	}
	// �ϰ����� �ִ� ���ڿ����� �Ǻ�
	bool consistent() {
		// ������ ����ε� ���� ��尡 �ִ� ��� false
		if (terminal && nextNodeExist) return false;
		// ����Ʈ�� �� �ϰ����� �ϳ��� ������ false
		for (int i = 0; i < MAX_LEN; ++i) {
			if (word[i] != nullptr && !word[i]->consistent()) return false;
		}
		// �� �� ������ �������� �ʴ´ٸ� �ϰ����� �����Ƿ� true
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		Trie* root = new Trie(); // ��Ʈ ����
		for (int i = 0; i < n; ++i) {
			char input[MAX_LEN]; cin >> input; // �Է¹���
			root->insert(input); // ���ڿ� ����
		}
		cout << ((root->consistent()) ? "YES\n" : "NO\n");
		delete root; // �Ҹ�
	}

	return 0;
}