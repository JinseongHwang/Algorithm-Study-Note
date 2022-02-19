# 배열

<br>

## 인덱스 범위로 배열 일부분 추출하기
```java
int[] array = {0, 1, 2, 3, 4, 5, 6};
int[] subArray = Arrays.copyOfRange(array, 1, 5);
System.out.println(Arrays.toString(subArray)); // [1, 2, 3, 4]
```
