# 힙(우선순위 큐)

<br>

## Integer 힙 사용

```java
/**
 * offer(E e) : pq에 e를 추가
 * peek() : 우선순위가 가장 높은 값을 반환
 * poll() : 우선순위가 가장 높은 값을 삭제하며 반환
 */
public static void main(String[] args) {
    PriorityQueue<Integer> minPq = new PriorityQueue<>(); // 최소힙 (default)
    PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder()); // 최대힙
    minPq.offer(10);
    minPq.offer(2);
    minPq.offer(8);

    System.out.println(minPq.peek()); // 2

    System.out.println(minPq.poll()); // 2
    System.out.println(minPq.poll()); // 8
    System.out.println(minPq.poll()); // 10
}
```

<br>

## String 힙 사용

```java
public static void main(String[] args) {
    PriorityQueue<String> minPq = new PriorityQueue<>(); // 사전순
    PriorityQueue<String> maxPq = new PriorityQueue<>(Collections.reverseOrder()); // 사전역순
    minPq.offer("ABC");
    minPq.offer("ABZ");
    minPq.offer("AB");

    System.out.println(minPq.peek()); // AB

    System.out.println(minPq.poll()); // AB
    System.out.println(minPq.poll()); // ABC
    System.out.println(minPq.poll()); // ABZ
}
```

<br>

## Custom 객체 힙 사용(Comparable 구현)

```java
static class Student implements Comparable<Student> {
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

    @Override
    public int compareTo(Student next) {
        // 나이 기준 내림차순 -> 같으면 이름 사전순
        if (this.age == next.age) {
            return this.name.compareTo(next.name);
        }
        return this.age <= next.age ? 1 : -1;
    }
}

public static void main(String[] args) {
    PriorityQueue<Student> pq = new PriorityQueue<>();

    pq.offer(new Student("김철수", 20));
    pq.offer(new Student("김영희", 100));
    pq.offer(new Student("한택희", 66));
    pq.offer(new Student("이나영", 7));
    pq.offer(new Student("이혁", 43));
    pq.offer(new Student("안영희", 100));
    pq.offer(new Student("고영희", 100));

    while (!pq.isEmpty()) {
        System.out.println(pq.poll());
    }
}
```
```text
이름 = 고영희, 나이 = 100
이름 = 김영희, 나이 = 100
이름 = 안영희, 나이 = 100
이름 = 한택희, 나이 = 66
이름 = 이혁, 나이 = 43
이름 = 김철수, 나이 = 20
이름 = 이나영, 나이 = 7
```

<br>

## Custom 객체 힙 사용(Comparator 일반적인 구현)

```java
// 나이 기준 내림차순 -> 같으면 이름 사전순
PriorityQueue<Student> pq = new PriorityQueue<>(new Comparator<Student>() {
    @Override
    public int compare(Student curr, Student next) {
        if (curr.age == next.age) {
            return curr.name.compareTo(next.name);
        }
        return curr.age <= next.age ? 1 : -1;
    }
});
```

<br>

## Custom 객체 힙 사용(Comparator 람다 구현)

```java
// 나이 기준 내림차순 -> 같으면 이름 사전순
PriorityQueue<Student> pq = new PriorityQueue<>((curr, next) -> {
    if (curr.age == next.age) {
        return curr.name.compareTo(next.name);
    }
    return curr.age <= next.age ? 1 : -1;
});
```