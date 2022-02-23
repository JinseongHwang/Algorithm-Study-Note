# 딕셔너리(Dictionary)

<br>

## 딕셔너리 주요 연산

```python
# 딕셔너리 선언
dic = {
	'key1': 'value1',
	'key2': 'value2',
	'key3': 'value3'
}

# 딕셔너리의 요소 갯수 => O(1)
print(len(dic))  # 3

# key에 대한 value 접근 => O(1)
print(dic['key1'])  # value1

# key에 대한 value를 수정 => O(1)
dic['key1'] = 'new value !!!'
print(dic['key1'])  # new value !!!

# key 존재 유무 확인 => O(1)
print('key1' in dic)  # True
print('key123' in dic)  # False

# key, value 순회하기
for k, v in dic.items():
	print(f'key = {k}, value = {v}')
""" output
key = key1, value = new value !!!
key = key2, value = value2
key = key3, value = value3
"""

# key 삭제하기
del dic['key2']
try:
	dic['key2']  # 삭제된 key에 접근하면 KeyError 가 발생한다.
except KeyError:
	print('key2 가 정상적으로 삭제되었습니다.')  # 따라서 이 부분이 실행된다.
```

- 파이썬의 딕셔너리에는 해시할 수만 있다면, 숫자, 문자열, 집합 등 불변 객체를 모두 key로 사용 가능하다.
- 대부분이 연산이 O(1)이다.
- 3.6 버전까지는 순서를 유지하지 않았다. 3.7버전 부터는 순서를 유지한다.

<br>

## collections.defaultdict 알아보기

```python
import collections

dic = collections.defaultdict(int)
print(f"dic['ABC'] = {dic['ABC']}, type = {type(dic['ABC'])}")
# dic['ABC'] = 0, type = <class 'int'>

dic = collections.defaultdict(list)
print(f"dic['ABC'] = {dic['ABC']}, type = {type(dic['ABC'])}")
# dic['ABC'] = [], type = <class 'list'>

dic = collections.defaultdict(tuple)
print(f"dic['ABC'] = {dic['ABC']}, type = {type(dic['ABC'])}")
# dic['ABC'] = (), type = <class 'tuple'>

dic = collections.defaultdict(set)
print(f"dic['ABC'] = {dic['ABC']}, type = {type(dic['ABC'])}")
# dic['ABC'] = set(), type = <class 'set'>

dic = collections.defaultdict(dict)
print(f"dic['ABC'] = {dic['ABC']}, type = {type(dic['ABC'])}")
# dic['ABC'] = {}, type = <class 'dict'>

dic = collections.defaultdict(lambda: 'banana')
print(f"dic['ABC'] = {dic['ABC']}, type = {type(dic['ABC'])}")
# dic['ABC'] = banana, type = <class 'str'>
```

- 존재하지 않는 key에 접근해도 `KeyError` 가 발생하지 않는다.
- 각 타입의 기본 값을 default 값으로 두고 싶으면 타입명을 적으면 되고, 그 외에는 람다식으로 작성한다.

<br>

## collections.Counter 알아보기

```python
import collections

ls = [1, 2, 3, 4, 5, 5, 5, 6, 6]
dic = collections.Counter(ls)  # 요소 별 빈도수를 value로 한다.
print(dic)  # Counter({5: 3, 6: 2, 1: 1, 2: 1, 3: 1, 4: 1})
print(dic[6])  # 2

# 가장 빈도수(value) 가 높은 엔트리를 2개 뽑아서 리스트로 반환
mc = dic.most_common(2)
print(mc)  # [(5, 3), (6, 2)]

# 비슷하게 리스트에서 제공되는 count() 메서드도 있다.
print(ls.count(6))  # 2
```

- 리스트의 각 요소의 갯수를 counting 한 결과를 딕셔너리 형태에 저장한다.

<br>

## collections.OrderedDict 알아보기

```python
import collections

dic = collections.OrderedDict()
dic['banana'] = 3
dic['apple'] = 4
dic['pear'] = 1
dic['orange'] = 2

print(dic)
# OrderedDict([('banana', 3), ('apple', 4), ('pear', 1), ('orange', 2)])
```

- 순서를 보장하는 딕셔너리이다.
- 3.7 버전 이상을 사용한다면, 내부적으로 인덱스를 사용해서 입력 순서를 유지한다.
- 대부분 3.7버전 이상을 사용하므로, 거의 사용 할 일이 없을 것이다.
