# 덱(데크)

<br>

## 덱 사용하기

```java
public static void main(String[] args) {
    Deque<Integer> deque = new ArrayDeque<>();

    deque.offerFirst(1);
    deque.offerLast(3);

    System.out.println(deque.getFirst()); // 1
    System.out.println(deque.getLast()); // 3

    while (!deque.isEmpty()) {
        System.out.println(deque.pollLast()); // 3 1
    }
}
```