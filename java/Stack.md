# 스택

<br>

## 스택 사용하기

```java
public static void main(String[] args) {
    Stack<Integer> stack = new Stack<>();

    stack.push(1);
    stack.push(3);
    stack.push(5);

    System.out.println(stack.size()); // 3
    System.out.println(stack.peek()); // 5

    if (stack.contains(3)) { // O(n) -> 사용하지 말자
        System.out.println("스택 내에 3이 존재합니다.");
    }

    while (!stack.empty()) {
        System.out.println(stack.pop()); // 5 3 1
    }
    System.out.println(stack.empty()); // true
}
```