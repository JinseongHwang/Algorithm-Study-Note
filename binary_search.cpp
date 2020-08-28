/*
	* ���� Ž��(Binary Search): ���ĵ� �迭���� ���� ���� ������ �Ǵ�

	������������ ���ĵǾ��ٰ� �����ϸ�,
	- ���� ���� ��Ұ� �ּҰ��̰�, ���� ������ ��Ұ� �ִ밪�̴�.
	- ã�� ��(target)�� �߰���(�߰� ���)�� ��� �񱳸� ���� O(log N)���� Ž���Ѵ�.
	
	���� �����ؼ� ����ϴ� �͵� ũ�� ����� �ʴ�.
	������ ��� ������ �ܼ��ϰ�, ������ �и��ϴٸ� STL�� ����ϴ� ����
	���� �ð��� ������� �� �� �ִ�.

	"algorithm" ���̺귯�� �ȿ� �����ִ� binary_search() �Լ��� 3���� �Ű������� �޴´�.
	-> Ž�� ���� �ּ�, �� �ּ� + 1, ã������ ��

	�ſ� �����ϴ� ���ϴ� ������� ����ϵ��� ����.
*/

// #1920 �� ã��

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
int N, M, arr[MAX];

// ���� Ž�� ���� �����ϱ�
bool My_Binary_Search(int target) {
	int L = 0, R = N; // 0 ���� N���� �̴�!
	while (L <= R) { // ���� ���� !
		int mid = (L + R) / 2;
		if (arr[mid] == target) { // ���ϴ� ���� ã�� ���
			return true;
		}
		else if (arr[mid] < target) { // ���ϴ� ������ ���� ���� ���� ���
			L = mid + 1;
		}
		else { // arr[mid] > target // ���ϴ� ������ ���� ���� Ŭ ���
			R = mid - 1;
		}
	}
	return false; // �� ã�� ���
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N; // �Է¹޴� ���� ����
	for (int i = 0; i < N; ++i) cin >> arr[i];

	sort(arr, arr + N); // ������ STL�� ���

	cin >> M; // ���� ����
	for (int inp, i = 0; i < M; ++i) {
		cin >> inp;
		// ���� �Լ��� �����ؼ� ����ϴ� ���
		My_Binary_Search(inp) ? cout << "1\n" : cout << "0\n";

		// �̹� ������ STL�� ����ϴ� ���
		binary_search(arr, arr + N, inp) ? cout << "1\n" : cout << "0\n";
	}
	return 0;
}



/*
	* ���� Ž���� Ȱ���� bound �Լ���: lower_bound(), upper_bound()
	 - �� �Լ� ���� "algorithm" ��� ���� �ȿ� �����ִ�.
	 - �� �Լ� ��� 3���� �Ű������� �޴µ�, binary_search()�� �����ϴ�.
	 
	lower_bound(): target ������ ũ�ų� �����鼭 ���� ���� ���� �ּҰ��� ��ȯ�Ѵ�.
	upper_bound(): target ������ ū ���� �� ���� ���� ���� �ּҰ��� ��ȯ�Ѵ�.
	����, target���� �������� �ʴ´ٸ� ���ּ� + 1 ���� ��ȯ�Ѵ�.

	�������� ���� �����ϰ� �ʹٸ� *lower_bound()�� ���� ����ؾ� �Ѵ�.

	���� �����ϰų� STL�� ����ص� �ȴ�.

	���� ������ bound �Լ�����,
	target�� ã���� ���, ã�� ���� �迭 index�� ��ȯ�Ѵ�.
	�� ã���� ���, �迭�� ������ index + 1�� ��ȯ�Ѵ�.
*/

// #10807 ���� ����

// �� ������ STL�� ����ϴ� �� ���� �����ؼ� ����ϴ� ���� �´ٰ� �����Ѵ�.
// ��� N�� �ִ� 100�̱� ������ ���Ʈ������ Ǯ� ������,
// bound�� ����ؼ� Ǯ ���� �ֱ� ������ ������ �� Ǯ��Ҵ�.

int n, k, arr[105] = { 0, };

int My_Lower_Bound() {
	int L = 0, R = n; // ���� ������ 0���� n������!
	while (L < R) {
		int mid = (L + R) / 2;
		// ���ǹ��� '=' �� ������ lower bound
		if (arr[mid] < k) L = mid + 1;
		else R = mid;
	}
	return R;
}

int My_Upper_Bound() {
	int L = 0, R = n; // ���� ������ 0���� n������!
	while (L < R) {
		int mid = (L + R) / 2;
		// ���ǹ��� '=' �� ������ upper bound
		if (arr[mid] <= k) L = mid + 1;
		else R = mid;
	}
	return R;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	cin >> k;
	int lb = My_Lower_Bound();
	int ub = My_Upper_Bound();

	// STL ��� ����
	int stl_lb = *lower_bound(arr, arr + n, k);
	int stl_ub = *upper_bound(arr, arr + n, k);

	if (lb == n) cout << "0\n";
	else cout << ub - lb << "\n";

	return 0;
}