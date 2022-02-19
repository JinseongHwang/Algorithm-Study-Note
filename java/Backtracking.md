# 백트래킹

<br>

## 숫자(문자열) 조합 - 백트래킹

```java
static char[] tmp = new char[7];
static boolean[] visited = new boolean[7];
static Set<Integer> repository = new HashSet<>();

public static void backtracking(String numbers, int depth, int len) {
    if (depth == len) {
        repository.add(Integer.parseInt(String.valueOf(tmp, 0, len)));
        return;
    }
    for (int i = 0; i < numbers.length(); i++) {
        if (visited[i]) {
            continue;
        }
        tmp[depth] = numbers.charAt(i);
        visited[i] = true;
        backtracking(numbers, depth + 1, len);
        visited[i] = false;
    }
}
public static void main(String[] args) {
    for (int i = 1; i <= numbers.length(); i++) { // 만들 수 있는 i 자리수를 전부 set 에 저장
        backtracking(numbers, 0, i);
    }
}
```
