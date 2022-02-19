# 정규표현식

<br>

- [정규표현식이 궁금하다면?](https://www.ocpsoft.org/opensource/guide-to-regular-expressions-in-java-part-1/)
- [정규표현식을 활용한 카카오 공채 문제 풀이](https://zzang9ha.tistory.com/322)

<br>

## 정규표현식(RegEx) 사용하기

```java
// 숫자 판별
Pattern numberPattern = Pattern.compile("^[0-9]*$");
assertTrue(numberPattern.matcher("123").matches());

// 공백 제거
Pattern spacePattern = Pattern.compile("\\s*");
assertEquals(
        spacePattern.matcher("A  B    C").replaceAll(""),
        "ABC"
);
```

- String 내부의 정규식 관련 메서드는 비용이 비싸다. 동일한 정규식을 여러번 사용하고자 한다면, Pattern 객체를 compile한 후 matcher()를 사용하도록 하자.

<br>

## 문자열에서 정규표현식 치환

- [여기](https://github.com/JinseongHwang/programmers-java/blob/master/docs/String.md#%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B9%98%ED%99%98%ED%95%98%EA%B8%B0) 를 참고하세요.

<br>

## 카카오 공채 문제([신규 아이디 추천](https://programmers.co.kr/learn/courses/30/lessons/72410)) 로 보는 예제

```java
// stage 2 : new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
new_id = new_id.replaceAll("[^a-z0-9\\-_.]", "");

// stage 3 : new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
new_id = new_id.replaceAll("[.]+", ".");

// stage 4 : 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
new_id = new_id.replaceAll("^[.]|[.]$", "");
```