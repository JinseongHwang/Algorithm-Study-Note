# 큐

<br>

## 큐 사용하기

```java
public static void main(String[] args) {
    Queue<Integer> queue = new LinkedList<>();

    queue.offer(1);
    queue.offer(3);
    queue.offer(5);

    System.out.println(queue.size()); // 3
    System.out.println(queue.peek()); // 1

    if (queue.contains(3)) { // O(n) -> 사용하지 말자
        System.out.println("큐 내에 3이 존재합니다.");
    }

    while (!queue.isEmpty()) {
        System.out.println(queue.poll()); // 1 3 5
    }
    System.out.println(queue.isEmpty()); // true
}
```