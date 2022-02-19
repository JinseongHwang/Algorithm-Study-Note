# Map

<br>

## Map과 Entry에 저장된 데이터 활용하기(+ 정렬)

```java
public static void main(String[] args) {
    Map<String, Integer> map = new HashMap<>();

    map.put("카드 분실 신고는", 1);
    map.put("계좌 이체는", 2);
    map.put("잔액 조회는", 3);
    map.put("상담원 연결은", 0);

    List<String> keys = new ArrayList<>(map.keySet());
    System.out.println(keys);
    // [상담원 연결은, 잔액 조회는, 카드 분실 신고는, 계좌 이체는]

    List<Integer> values = new ArrayList<>(map.values());
    System.out.println(values);
    // [0, 3, 1, 2]

    List<Entry<String, Integer>> entries = new ArrayList<>(map.entrySet());
    System.out.println(entries);
    // [상담원 연결은=0, 잔액 조회는=3, 카드 분실 신고는=1, 계좌 이체는=2]

    entries.sort(Entry.comparingByKey());
    System.out.println(entries); // Entry key 기준 정렬 
    // [계좌 이체는=2, 상담원 연결은=0, 잔액 조회는=3, 카드 분실 신고는=1]

    entries.sort(Entry.comparingByValue());
    System.out.println(entries); // Entry value 기준 정렬
    // [상담원 연결은=0, 카드 분실 신고는=1, 계좌 이체는=2, 잔액 조회는=3]
}
```

<br>

## Map에서 없는 key에 접근했을 경우, default 설정하기

```java
Map<String, Integer> map = new HashMap<>();
map.put("my_key", map.getOrDefault("my_key", 1));
System.out.println(map.get("my_key")); // 1
```

<br>

## Map merge() 활용하기

```java
Map<String, Integer> map = new HashMap<>();

map.put("abc", 1);
map.merge("abc", 5, Integer::sum);
System.out.println(map.get("abc")); // 6

map.merge("abc", 2, (src, val) -> src * val);
System.out.println(map.get("abc")); // 12
```

<br>

## Map putIfAbsent() 활용하기

```java
Map<String, Integer> map = new HashMap<>();

System.out.println(map.putIfAbsent("putIfAbsent", 10)); // null
System.out.println(map.get("putIfAbsent")); // 10
System.out.println(map.putIfAbsent("putIfAbsent", 20)); // 10
System.out.println(map.get("putIfAbsent")); // 10
```

<br>

## Map computeIfAbsent() 활용하기

```java
Map<String, Integer> map = new HashMap<>();

System.out.println(map.computeIfAbsent("computeIfAbsent", key -> 10)); // 10
System.out.println(map.get("computeIfAbsent")); // 10
System.out.println(map.computeIfAbsent("computeIfAbsent", key -> 20)); // 10
System.out.println(map.get("computeIfAbsent")); // 10

Map<String, List<Integer>> mapList = new HashMap<>();
mapList.computeIfAbsent("AB", key -> new ArrayList<>()).add(1);
System.out.println(mapList.get("AB")); // [1]
mapList.computeIfAbsent("AB", key -> new ArrayList<>()).add(2);
System.out.println(mapList.get("AB")); // [1, 2]
```

<br>

## Map computeIfPresent() 활용하기

```java
Map<String, Integer> map = new HashMap<>();

System.out.println(map.get("com")); // null
System.out.println(map.computeIfPresent("com", (k, v) -> v + 10)); // null
System.out.println(map.computeIfAbsent("com", key -> 5)); // 5
System.out.println(map.get("com")); // 5
System.out.println(map.computeIfPresent("com", (k, v) -> v + 20)); // 25
System.out.println(map.get("com")); // 25
```
