# 집합(Set)

<br>

## 집합의 표현과 비교

```python
tmp_list = [1, 2, 3, 4, 5, 6]
set1 = {1, 2, 3, 4, 5, 6}
set2 = set(tmp_list)

print(set1 == set2)  # True
print(set1 is set2)  # False
```

<br>

## 집합 원소 추가, 삭제 + 집합 복제

```python
set1 = {1, 2, 3, 4, 5, 6}
set1.add(7)  # 원소 7 추가
print(set1)  # {1, 2, 3, 4, 5, 6, 7}

set2 = set1.copy()  # 집합 복사
print(set1 == set2)  # True: 내용은 같지만
print(set1 is set2)  # False: 참조는 다르다 (deepcopy)

set2.remove(1)  # 원소 1 삭제
set2.remove(2)  # 원소 2 삭제

print(set1)  # {1, 2, 3, 4, 5, 6, 7}
print(set2)  # {3, 4, 5, 6, 7}
```

<br>

## 집합 간 추가

```python
set1 = {1, 2, 3, 4, 5, 6}
set2 = {6, 7}
set1.update(set2)

print(set1)  # {1, 2, 3, 4, 5, 6, 7}
```

- `update()` 는 `union()` 과 헷갈릴 수 있다.
- `${SOURCE}.update(${TARGET})` 을 하게 되면 SOURCE에 TARGET과 합집합 결과를 SOURCE에 바로 적용한다.
- 반면에 `${NEW} = ${SOURCE}.union(${TARGET})` 을 하게 되면 두 집합에는 변화가 없으며, 새로운 결과 합집합을 반환한다.

<br>

## 교집합

```python
set1 = {1, 2, 3, 4, 5, 6}
set2 = {3, 4, 5, 6, 8, 9}

print(set1 & set2)  # {3, 4, 5, 6}
print(set1.intersection(set2))  # {3, 4, 5, 6}
```

<br>

## 합집합

```python
set1 = {1, 2, 3, 4, 5, 6}
set2 = {3, 4, 5, 6, 8, 9}

print(set1 | set2)  # {1, 2, 3, 4, 5, 6, 8, 9}
print(set1.union(set2))  # {1, 2, 3, 4, 5, 6, 8, 9}
```

<br>

## 차집합

```python
set1 = {1, 2, 3, 4, 5, 6}
set2 = {3, 4, 5, 6, 8, 9}

print(set1 - set2)  # {1, 2}
print(set1.difference(set2))  # {1, 2}
```

<br>

## 대칭 차집합

```python
set1 = {1, 2, 3, 4, 5, 6}
set2 = {3, 4, 5, 6, 8, 9}

print(set1 ^ set2)  # {1, 2, 8, 9}
```

<br>