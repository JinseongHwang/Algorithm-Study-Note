# 이분 탐색

<br>

## 이분탐색 Binary Search

```java
public static int binarySearch(int[] data, int target) {
    int L = 0, R = data.length - 1, mid;
    while (L <= R) {
        mid = (L + R) / 2;
        if (target < data[mid]) {
            R = mid - 1;
        } else if (target > data[mid]) {
            L = mid + 1;
        } else {
            return mid;
        }
    }
    throw new NoSuchElementException();
}
public static void main(String[] args) {
    int[] data = new int[]{1, 3, 3, 4, 7, 7, 7, 9, 10, 10};
    System.out.printf("찾으려는 숫자 4는 data[%s] 에 있습니다!\n", binarySearch(data, 4)); // 3
}
```

<br>

## Lower Bound

```java
/**
 * @return target 보다 크거나 같은 첫번째 원소의 index
 */
public static int lowerBound(int[] data, int target) {
    int L = 0, R = data.length, mid;
    while (L < R) {
        mid = (L + R) / 2;
        if (target <= data[mid]) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    return R;
}
public static void main(String[] args) {
    int[] data = new int[]{1, 3, 3, 4, 7, 7, 7, 9, 10, 10};
    System.out.println(lowerBound(data, 2)); // 1
}
```

<br>

## Upper Bound

```java
/**
 * @return target 보다 큰 첫번째 원소의 index
 */
public static int upperBound(int[] data, int target) {
    int L = 0, R = data.length, mid;
    while (L < R) {
        mid = (L + R) / 2;
        if (data[mid] <= target) {
            L = mid + 1;
        } else {
            R = mid;
        }
    }
    return R;
}
public static void main(String[] args) {
    int[] data = new int[]{1, 3, 3, 4, 7, 7, 7, 9, 10, 10};
    System.out.println(upperBound(data, 4)); // 4
}
```