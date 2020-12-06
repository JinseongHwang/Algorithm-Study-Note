/*
	* C ����� ǥ�� ����� �Լ��� printf / scanf �� ���� �˾ƺ���.

	>>> C++�� ǥ�� ����� �Լ��� iostream�� cout, cin�� �� ������ �ʳ���?? ������ cout, cin ���� �ƴѰ���??
	: ����, cout�� cin�� ���� ������ ���� �Ű������ �ʾƵ� �ǰ�,
	�������� Ÿ�����ϱ� �����, ������ ��Ÿ�� �߻��� Ȯ���� ������ ��������.
	���� ���� cout�� cin�� ����Ѵ� ��
	������ ���� �Է°� ��¿� ������ �����ؾ� �ϴ� �������� �ִ�. �׷��� printf�� scanf�� ���� ���Ѵ�.
	
	������ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); �� ����Ѵٸ�,
	�����ؾ��� printf�� scanf�� ����� �� �ִ�.
	�� ������ ����ϴ� �Ͱ� ���ϴ� ���� ���̴� ũ�� ������ �� �����ؾ� �Ѵ�.
	(��� PS�� ���� ����¹��� �׸� ���� ������� �ʱ� ������ ������ �ٲ��൵ �ð��� ���� �Ȱɸ���^^)
	

	���� ���̴� ���� ������:
	> %d: ����(10����), %u: ���� ����(10����), %o: 8����, %x: 16����, %i: ���¿� ���� �ڵ� ���� ����, %lld: long long�� ����
	> %f: float�� �Ǽ�, %lf: double�� �Ǽ�, %Lf: long double�� �Ǽ�
	> %c: ���� 1��, %s: ���ڿ�
	> %p: ������ �ּ�
*/

#include <stdio.h>

/* %i�� �ǽ��غ���.
8����(0���� ����), 10����, 16����(0x�� ����)�� ���¸� ���� �Ǵ�
input�� 10���� ������ �����̹Ƿ� 10������ ����. 

* %i ����ϱ�!
	>   10 �Է�(10����) -> 10�� �ν�
	>  010 �Է�( 8����) ->  8�� �ν�
	> 0x10 �Է�(16����) -> 16�� �ν� */
void solve_11816() { // 8����, 10����, 16����
	int input;
	scanf("%i", &input);
	printf("%d\n", input);
}

// printf�� ���� �˾Ƶθ� ���� �͵�
void learn_printf() { 
	int var;

	/* ���� ������ ���̿� '*'�� �ְ� �Ǹ� ����� ������ ���� ������ ������ �� �ִ�.
	�Ʒ��� ���ÿ� ���� �ۼ��ϸ�, 6ĭ �ȿ� input�̶�� ������ ����ϰڴٴ� �ǹ��̴�.
	�Ű������δ� ���� �����ϴ� ������ �ְ�����, ����� ������ ������ ������ �ȴ�.
	('*' ��ġ�� ����� ������ ��� ������ ������ �� �ִ�!)

	> input == 12345 ��� �����ϸ�,
	���� 1 ~ 5 ���̷� ������ �� ��ȭ ����.
	6���� �����ϸ� " 12345" �� ��µȴ�. */
	printf("%*d\n", 6, var); // ���� ��
	printf("%6d\n", var); // ��� ��

	/* �Ҽ��� �ڸ����� �����ϰ� �ʹٸ� '.*' �� ������ �� �ִ�.
	����� ������ ���� ������ ���� �����ϴ�. */
	int precision = 4;
	double pi = 3.141592;
	printf("%.*lf\n", precision, pi); // ���� ���е�
	printf("%.4lf\n", pi); // ��� ���е�

	/* printf �Լ��� ���ϰ���
	��� ���� ��, ��µ� ������ ������ ��ȯ�ǰ�
	��� ���� ��, ������ ��ȯ�ȴ�. */
}

// scanf�� ���� �˾Ƶθ� ���� �͵�
void learn_scanf() {
	int var;

	/* scanf �Լ��� ����� ���๮�ڸ� �����Ѵ�.
	���� 10 20 30 �� �־��� ������� ����� ���๮�ڷ� ���������� �־,
	scanf("%d %d %d")�� �ϰԵǸ�, ��Ȯ�ϰ� ������ �Է¹޴´�. */

	/* scanf �Լ��� ����(char)�� �Է¹��� �� �ַ� ������ �߻��Ѵ�.
	���� ���, 3�� �Է� �� A�� �Է��Ѵٰ� ��������.
	scanf("%d%c"); ��� �ۼ��ϰ� 3�� �Է��ϰ� ���͸� ������,
	���Ͱ� "\n" ���� ���ڸ� �ǹ��ϱ� ������ ���ڴ� �Է��ϱ⵵ ���� ����������.
	���� ���ڿ� �ϳ��� �Է��Ѵٰ� �ϸ� scanf(" %c")ó�� �տ� ������ �߰�����.
	'%c' �տ� ���� �ϳ��� �߰��ϸ� ����� ���� ���ڸ� �����ϴ� ������ �Ѵ�. */

	// "A B C" �� ���� a, b, c�� �����ϰ� �ʹٸ�?
	char a, b, c;
	scanf(" %c %c %c", &a, &b, &c);

	/* ���� �����ڸ� %[...] ���·� ���Խ� �������� ������ ���� �� �ִ�.
	���� ���, scanf("%[123]", str); �̶�� ������ �ִٰ� ��������.
	str�� �Է¹��� ��, str�� ���������� 1, 2 �Ǵ� 3 ���ڸ� �Է¹ް� �ƴ� ���� ������ �Է��� �ߴ��Ѵ�.
	��, scanf("%[^123]", str); �̶�� ������ �ִٰ� ��������.
	str�� �Է¹��� ��, str�� ���������� 1, 2 �Ǵ� 3 ���ڰ� ������ �Է��� �ߴ��Ѵ�. */
	char str[100];
	scanf("%[123]", str); printf("%s", str); // case 1
	scanf("%[^123]", str); printf("%s", str); // case 2

	/* ���� ������ ���̿� '*' �� ���� �Է��� �����Ѵ�. 
	�Ʒ��� ���� �������� 10 20 30�� �Է��ϸ� a�� 10��, b�� 30�� ����ȴ�. */
	int a, b;
	scanf("%d %*d %d", &a, &b);
}

/* ���� ������ ���̿� ����� �־��ָ�, �� ��� ���̸�ŭ �Է¹��� �� �ִ�.
���� �پ��ִ� ���ڵ��� ����� �ϴ� ��찡 �ִ�.
�׷� �� �� ����� �������. */
void solve_11720() { // ������ ��
	int n, sum = 0;
	scanf("%d", &n);
	while (n--) {
		// �پ��ִ� �� ���ڰ� �־����� �ϳ����� �Է¹���
		int input; scanf("%1d", &input); sum += input;
	}
	printf("%d\n", sum);
}

void solve_11718() { // �״�� ����ϱ�
	// in C
	// ��� 1: ���� �ϳ��� �״�� ������ֱ�
	char c;
	while (scanf("%c", &c) != EOF) printf("%c", c);

	// �� �� ��°�� �Է¹ޱ�
	// ��� 2: '\n' ������ ������ �Է¹޴ٰ� '\n'���� �Է¹ް�, �״�� ����ϰ� '\n' �ٽóֱ�
	char str[105];
	while (scanf("%[^\n]\n", str) != EOF) printf("%s\n", str);

	// in C++
	// #include <iostream>, <string>, std::
	string str;
	while (getline(cin, str)) cout << str << "\n";
}

/* scanf �Լ��� ���ϰ���
�Է� ���� ��, �о���� ������ ������ ��ȯ�ϰ�,
�Է� ���� ��, 0 �Ǵ� NULL�� ��ȯ�ȴ�. */
void solve_10951() { // Ȱ�� ����: A+B - 4
	// �׽�Ʈ���̽��� �־����� �ʰ� EOF���� �о�� �ϴ� ��Ȳ
	int a, b;

	// in C
	// EOF�� -1�� ���ǵǾ� �ִ� ����̴�.
	// scanf �Լ��� �Է¹޴ٰ� ������ ���� �����ϸ� EOF�� ��ȯ�Ѵ�.
	while (scanf("%d %d", &a, &b) != EOF) printf("%d\n", a + b);

	// in C++
	// #include <iostream>, std::
	while (cin >> a >> b) cout << a + b << "\n";
}