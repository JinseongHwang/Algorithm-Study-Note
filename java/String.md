# 문자열

<br>

## 문자열 사용하기

```java
/**
 * literal 형태로 문자열을 사용하는 것을 String interning 이라고 한다.
 * 저장된 literal 은 힙 메모리 내의 String constant pool(Metaspace) 에 저장된다. HashTable 구조이다.
 * 불변성을 띄며, 단독으로 존재하기 때문에 동일한 문자열이라면 동일한 참조값을 가진다.
 * 때문에 새로운 메모리 할당이 필요 없어서 재사용 가능하다는 장점이 있다.
 */
public static void main(String[] args) {

    String str = "AbCdEfffG";

    String lowerCase = str.toLowerCase();
    System.out.println(lowerCase); // abcdefffg

    String upperCase = str.toUpperCase();
    System.out.println(upperCase); // ABCDEFFFG

    String joined = String.join(", ", "A", "B", "C");
    System.out.println(joined); // A, B, C

    // String to char[]
    char[] charArr = new char[str.length()];
    // getChars(시작 index, 끝 index, 복사 받을 char 배열 이름, 복사 시작 위치 index)
    str.getChars(0, str.length(), charArr, 0);

    // d의 위치, 못 찾으면 -1 반환
    int indexOfD = str.indexOf('d'); // 3

    // f의 마지막 위치, 못 찾으면 -1 반환
    int lastIndexOfF = str.lastIndexOf('f'); // 7

    // [5, END)
    String substring1 = str.substring(5); // fffG

    // [4, 6)
    String substring2 = str.substring(4, 6); // Ef

    // 문자열 붙이기
    String concat = str.concat("KKK"); // AbCdEfffGKKK

    // 문자열 분리
    String splitTest = "A B C D E   F";
    String[] split = splitTest.split(" "); // 공백 기준
    System.out.println(Arrays.toString(split)); // [A, B, C, D, E, , , F]

    // 앞 뒤 공백 제거
    String trimTest = "  A B C D E   F  ";
    String trim = trimTest.trim();
    System.out.println(trim); // "A B C D E   F"
}
```

<br>

## 문자열 치환하기

```java
public static void main(String[] args) {

    // 문자 1개 단위로 치환
    String replace1 = "__x___x___x_x____xx_";
    String newReplace1 = replace1.replace('x', 'o');
    System.out.println(newReplace1); // __o___o___o_o____oo_

    // 일치하는 문자 단위로 치환
    String replace2 = "one fish, two fish, three fish";
    String newReplace2 = replace2.replace("fish", "sheep");
    System.out.println(newReplace2); // one sheep, two sheep, three sheep

    // 정규표현식에 만족하는 것만 치환
    String replaceAll1 = "Hello OK, OK World OK";
    String newRepaceAll1 = replaceAll1.replaceAll("(OK)", "NO"); // OK로 grouping
    System.out.println(newRepaceAll1); // Hello NO, NO World NO

    // 정규표현식으로 숫자 치환
    String replaceAll2 = "__1_6____3__6_345____0";
    String newReplaceAll2 = replaceAll2.replaceAll("\\d", "#");
    System.out.println(newReplaceAll2); // __#_#____#__#_###____#

    // 정규표현식으로 공백 제거
    String replaceAll3 = "   Horse         Cow\n\n   \r Camel \t\t Sheep \n Goat        ";
    String newReplaceAll3 = replaceAll3.replaceAll("\\s", "");
    System.out.println(newReplaceAll3); // HorseCowCamelSheepGoat

    // 정규표현식에 만족하는 것 1개 치환
    String replaceFirstTest = "Hello OK-12, OK-34, OK-56";
    String replaceFirst = replaceFirstTest.replaceFirst("[0-9]+", "##");
    System.out.println(replaceFirst); // Hello OK-##, OK-34, OK-56
}
```
