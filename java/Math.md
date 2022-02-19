# 수학

<br>

## 소수 판별 - 단순 알고리즘(시간복잡도 개선)

```java
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    }
    if (n == 1 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= Math.sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
```

<br>

## 소수 판별 - 에라토스테네스의 체

```java
static int max = -1;

public static void checkPrime(boolean[] checked) {
    checked[0] = checked[1] = true; // 소수 아님
    checked[2] = false; // 소수

    for (int i = 2; i <= Math.sqrt(max); i++) {
        if (checked[i]) {
            continue;
        }
        for (int j = i * i; j < max + 1; j += i) {
            checked[j] = true;
        }
    }
}
public static void main(String[] args){
    boolean[] checked = new boolean[max + 1];
}
```

<br>

## 유클리드 호제법 - 최대공약수 - GCD(Greatest Common Divisor)

```java
static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

<br>

## 유클리드 호제법 - 최소공배수 - LCM(Least common multiple)

```java
static long lcm(long a, long b, long gcd) {
    return (a * b) / gcd;
}
```

<br>

## 약수 찾기

```java
static List<Integer> getDivisors(int dividend) {
    List<Integer> divisors = new ArrayList<>();
    int i = 0;
    for (i = 1; i * i < dividend; i++) {
        if (dividend % i == 0) {
            divisors.add(i);
            divisors.add(dividend / i);
        }
    }
    if (i * i == dividend) {
        divisors.add(i);
    }
    return divisors;
}
```