# Array 관련 타입 변환

<br>

## List\<Integer> 를 int[] 로 변환하기

```java
List<Integer> resultList = new ArrayList<>();
int[] result = resultList.stream()
    .mapToInt(Integer::intValue)
    .toArray();
```

<br>

## int[] 를 List\<Integer> 로 변환하기

```java
int[] ints = {1,2,3};
List<Integer> list = Arrays.stream(ints)
    .boxed()
    .collect(Collectors.toList());
```

<br>

## Map의 value가 List일 경우, values를 2차원 배열로 변환하기

```java
Map<Integer, List<Integer>> fooMap = new HashMap<>();
fooMap.put(1, new ArrayList<>(List.of(1, 2, 3, 4, 5)));
fooMap.put(2, new ArrayList<>(List.of(6, 7, 8, 9, 10)));

int[][] answer = fooMap.values().stream()
        .map(valueList -> valueList.stream()
                .mapToInt(Integer::intValue)
                .toArray())
        .toArray(int[][]::new);

System.out.println(Arrays.deepToString(answer)); // [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]]
```
