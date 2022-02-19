# Set

<br>

## Set 활용하기

- 중복을 허용하지 않는 것이 가장 큰 특징 아닐까?

```java
public static void main(String[] args) {
    Set<Integer> set = new HashSet<>();

    set.add(1); set.add(1); set.add(1);
    set.add(2); set.add(2);
    set.add(3);

    System.out.println(set.size()); // 3

    Iterator<Integer> iterator = set.iterator();
    while (iterator.hasNext()) {
        System.out.print(iterator.next() + " "); // 1 2 3
    }
}
```

<br>

## Key값을 기준으로 정렬, 중복 없는 Set 자료구조

- Red-Black tree 기반, HashSet 보다 느림
- headSet(x) : exclusive
- tailSet(x) : inclusive

```java
SortedSet<Integer> set = new TreeSet<>();
set.add(3);
set.add(5);
set.add(1);
set.add(4);
set.add(2);
System.out.println(Arrays.toString(set.toArray())); // [1, 2, 3, 4, 5]
System.out.println(Arrays.toString(set.headSet(3).toArray())); // [1, 2]
System.out.println(Arrays.toString(set.tailSet(3).toArray())); // [3, 4, 5]
System.out.println(Arrays.toString(set.subSet(2, 4).toArray())); // [2, 3]
System.out.println(set.first()); // 1
System.out.println(set.last()); // 5
```