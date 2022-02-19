# 정렬

<br>

## Array 정렬(오름차순, 내림차순)

```java
public static void main(String[] args) {
    int[] primArr = new int[]{5, 0, 4, 6, 3, 2, 1, 9, 8, 7};
    Arrays.sort(primArr);
    printArray(primArr); // 0 1 2 3 4 5 6 7 8 9

    // Primitive type 배열을 내림차순 정렬하고 싶으면 Boxing 이 필요하다.
    Integer[] wrapArr = new Integer[]{5, 0, 4, 6, 3, 2, 1, 9, 8, 7};
    Arrays.sort(wrapArr, Collections.reverseOrder());
    printArray(wrapArr); // 9 8 7 6 5 4 3 2 1 0

    // Boxing 을 하기 싫다면 stream API 를 사용하는 방법도 있다.
    int[] sortedPrimArr = Arrays.stream(primArr).boxed() // 사실 여기서 Boxing 된다.
        .sorted(Collections.reverseOrder())
        .mapToInt(Integer::intValue)
        .toArray();
    printArray(sortedPrimArr); // 9 8 7 6 5 4 3 2 1 0
}
```

<br>

## Array 부분 정렬

```java
public static void main(String[] args) {
    int[] primArr = new int[]{5, 0, 4, 6, 3, 2, 1, 9, 8, 7};
    Arrays.sort(primArr, 2, 7); // [2, 7) 부분 정렬
    printArray(primArr); // 5 0 "1 2 3 4 6" 9 8 7
}
```

<br>

## Collection 정렬(문자열)

```java
public static void main(String[] args) {
    List<String> krList = new ArrayList<>(Arrays.asList(
        "김철수", "김영희", "한택희", "이나영", "이혁", "안영희", "고영희"
    ));

    krList.sort(Comparator.naturalOrder()); // 오름차순 (사전순)
    printCollection(krList); // 고영희 김영희 김철수 안영희 이나영 이혁 한택희

    krList.sort(Comparator.reverseOrder()); // 내림차순(사전역순)
    printCollection(krList); // 한택희 이혁 이나영 안영희 김철수 김영희 고영희

    // ---------------------------------------------------------------
    List<String> enList = new ArrayList<>(Arrays.asList(
        "Massachusetts", "Atlanta", "Tennessee", "Florida", "Saint Paul", "abc"
    ));

    enList.sort(Comparator.naturalOrder()); // 오름차순(사전순)
    printCollection(enList); // Atlanta Florida Massachusetts Saint Paul Tennessee abc

    enList.sort(String.CASE_INSENSITIVE_ORDER); // 오름차순(대소문자 무시 && 사전순)
    printCollection(enList); // abc Atlanta Florida Massachusetts Saint Paul Tennessee

    enList.sort(Collections.reverseOrder(String.CASE_INSENSITIVE_ORDER)); // 내림차순(대소문자 무시 && 사전역순)
    printCollection(enList); // Tennessee Saint Paul Massachusetts Florida Atlanta abc
}
```

<br>

## 정렬 Custom 하기

아래 코드를 참고하자. 일맥상통하다.

- [Custom 객체 힙 사용(Comparable 구현)](https://github.com/JinseongHwang/programmers-java/blob/master/docs/Heap.md#custom-%EA%B0%9D%EC%B2%B4-%ED%9E%99-%EC%82%AC%EC%9A%A9comparable-%EA%B5%AC%ED%98%84)
- [Custom 객체 힙 사용(Comparator 일반적인 구현)](https://github.com/JinseongHwang/programmers-java/blob/master/docs/Heap.md#custom-%EA%B0%9D%EC%B2%B4-%ED%9E%99-%EC%82%AC%EC%9A%A9comparator-%EC%9D%BC%EB%B0%98%EC%A0%81%EC%9D%B8-%EA%B5%AC%ED%98%84)
- [Custom 객체 힙 사용(Comparator 람다 구현)](https://github.com/JinseongHwang/programmers-java/blob/master/docs/Heap.md#custom-%EA%B0%9D%EC%B2%B4-%ED%9E%99-%EC%82%AC%EC%9A%A9comparator-%EB%9E%8C%EB%8B%A4-%EA%B5%AC%ED%98%84)

람다 표현식과 `Comparator.comparing` 을 실습해보자.

```java
static class Student {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return String.format("이름 = %s, 나이 = %d", name, age);
    }
}

public static void main(String[] args) {
    List<Student> studentList = new ArrayList<>();

    studentList.add(new Student("김철수", 20));
    studentList.add(new Student("김영희", 100));
    studentList.add(new Student("한택희", 66));
    studentList.add(new Student("이나영", 7));
    studentList.add(new Student("이혁", 43));
    studentList.add(new Student("안영희", 100));
    studentList.add(new Student("고영희", 100));

    // 나이 기준 내림차순 -> 같으면 이름 사전순
    studentList.sort((curr, next) -> {
        if (curr.age == next.age) {
            return curr.name.compareTo(next.name);
        }
        return curr.age < next.age ? 1 : -1;
    });

    // 간단한 기준이라면 Comparator.comparing 을 사용해도 좋다.
    studentList.sort(Comparator.comparing(student -> student.age));
}
```
