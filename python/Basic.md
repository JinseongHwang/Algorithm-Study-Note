# 파이썬 기초

<br>

## range 활용

```python
# 0부터 10 미만까지 저장된 리스트 생성
arr = list(range(10))
print(arr) # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 5부터 12 미만까지 저장된 리스트 생성
arr = list(range(5, 12))
print(arr) # [5, 6, 7, 8, 9, 10, 11]

# -4부터 10 미만까지 2씩 더해진 값이 저장된 리스트 생성
arr = list(range(-4, 10, 2))
print(arr) # [-4, -2, 0, 2, 4, 6, 8]

# 10부터 0 초과까지 -1씩 더해진 값이 저장된 리스트 생성
arr = list(range(10, 0, -1))
print(arr) # [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

# 10부터 1 까지 리스트 반대로 생성
arr = list(reversed(range(1, 11)))
print(arr) # [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
```

<br>

## list 활용

```python
inp = 'hello world'
res = list(inp) # 문자열 쪼개기
print(res) # ['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']

res = list(('a', 'b')) # tuple to list
print(res) # ['a', 'b']
```

<br>

## map 활용 (시퀀스 1개)

```python
inp = "1 2 3 4 5"
res = list(map(int, inp.split())) # 문자열 배열을 반복하며 int() 를 적용
print(res) # [1, 2, 3, 4, 5]
```

- map의 첫 번째 parameter에는 적용할 메서드가 들어가고, 
- 두 번째 parameter에는 첫 번째 parameter의 함수에 전달할 값이 시퀀스 형태로 들어간다.

<br>

## map 활용 (시퀀스 여러개)

```python
x_list = [1, 2, 3, 4]
y_list = [5, 6, 7, 8]
z_list = [9, 10, 11, 12, 13, 14, 15, 16, 17]

res = list(map(lambda x, y, z: (x + 1, y + 2, z + 3), x_list, y_list, z_list))

print(res) # [(2, 7, 12), (3, 8, 13), (4, 9, 14), (5, 10, 15)]
```

- map의 첫 번째 parameter에는 역시 적용할 메서드가 들어간다.
- 두 번째부터는 전달할 시퀀스들이 들어간다.
- 예제의 경우는 3개의 시퀀스를 전달했기 때문에 각 시퀀스의 값들에 lambda 함수를 적용한 결과 tuple이 반환된다.
- 단, 예제에서 3개의 시퀀스는 길이가 서로 다르다.(4, 4, 9) 가장 짧은 시퀀스 기준으로 순회하며, 초과하는 값들은 무시된다.

<br>

## list, map, lambda 활용

```python
res = list(map(lambda x: '가', range(5)))
print(res) # ['가', '가', '가', '가', '가']

res = list(map(lambda x: x + 10, [1, 2, 3])) # lambda의 반환값을 map
print(res) # [11, 12, 13]

res = list(map(lambda x, y: x + y, ['A', 'C'], ['B', 'D']))
print(res) # ['AB', 'CD']

res = list(map(lambda x: f'{x}=홀수' if x & 1 else f'{x}=짝수', range(1, 10)))
print(res) # ['1=홀수', '2=짝수', '3=홀수', '4=짝수', '5=홀수', '6=짝수', '7=홀수', '8=짝수', '9=홀수']
```

<br>

## List Comprehension

```python
# 0 이상 10 미만의 값들을 새로운 리스트로 생성
res = [x for x in range(10)]
print(res) # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 0 이상 10 미만의 값들 중 홀수만 리스트로 생성
res = [x for x in range(10) if x & 1]
print(res) # [1, 3, 5, 7, 9]

# 0 이상 10 미만의 값들 중 홀수는 그대로, 짝수는 +10
res = [x if x & 1 else x + 10 for x in range(10)]
print(res) # [10, 1, 12, 3, 14, 5, 16, 7, 18, 9]

data = {
  'name':'jinseong',
  'age':10,
  'gpa':4.5
}
res = {key: val for key, val in data.items()}
print(res) # {'name': 'jinseong', 'age': 10, 'gpa': 4.5}
```

- if 조건만 붙이고 싶다면 for-in 뒤에,
- if else 둘 다 붙이고 싶다면 for-in 앞에.

<br>

## range와 list comprehension의 차이

```python
import sys

r = range(1_000_000)
print(len(r)) # 1,000,000

lc = [i for i in range(1_000_000)]
print(len(lc)) # 1,000,000

print(len(r) == len(lc)) # True

print(sys.getsizeof(r)) # 48
print(sys.getsizeof(lc)) # 8,448,728
```

- range를 사용하면 제너레이터 방식으로 숫자가 생성된다는 조건만 생성되기 때문에 메모리 점유가 적다. (lazy initialize를 생각하면 편하다.)
- 하지만 list comprehension 방식으로 생성하면 모조리 생성되어서 메모리에 적재된다. 메모리 점유가 크다.
- 컴퓨팅 리소스 점유 측면에서 서로 다르니 필요한 방식에 따라 적절히 선택해서 사용하자!

<br>

## enumerate

```python
arr = ['A', 'B', 'C', 'D', 'E']
for idx, val in enumerate(arr):
  print(f'{idx} : {val}')

""" output
0 : A
1 : B
2 : C
3 : D
4 : E
"""
```

- 순서가 있는 자료형을 인덱스를 포함한 enumerate 객체로 반환시킨다.
- 시퀀스에 인덱스를 부여하며 반복할 때 유용하게 사용된다.

<br>

## locals

```python
import pprint

arr = ['A', 'B', 'C', 'D', 'E']
fset = frozenset(['a', 'b', 'c'])
dic = {
  'first_name':'jinseong',
  'last_name':'hwang',
  'age':15,
  'gpa':{
    'operating_system':'A+',
    'data_structure':'B0'
  }
}
pprint.pprint(locals())
```
```text
{'__annotations__': {},
 '__builtins__': <module 'builtins' (built-in)>,
 '__cached__': None,
 '__doc__': None,
 '__file__': '/opt/project/src/test_only.py',
 '__loader__': <_frozen_importlib_external.SourceFileLoader object at 0xffffb1348c40>,
 '__name__': '__main__',
 '__package__': None,
 '__spec__': None,
 'arr': ['A', 'B', 'C', 'D', 'E'],
 'dic': {'age': 15,
         'first_name': 'jinseong',
         'gpa': {'data_structure': 'B0', 'operating_system': 'A+'},
         'last_name': 'hwang'},
 'fset': frozenset({'c', 'b', 'a'}),
 'pprint': <module 'pprint' from '/usr/local/lib/python3.9/pprint.py'>}
```

- `locals()` 는 로컬 심볼 테이블 딕셔너리를 가져오는 메서드이다. 디버깅 시 유용하다.
- `pprint.pprint()` 를 사용하면 줄바꿈이 포함되어 깔끔하게 확인할 수 있다.

<br>

## filter

```python
def samyukgu_filter(value):
	split = list(str(value))
	return '3' in split or '6' in split or '9' in split


ls = list(range(1, 30))  # 1 ~ 29
res = list(filter(samyukgu_filter, ls))

print(res)  # [3, 6, 9, 13, 16, 19, 23, 26, 29]
```

- 3,6,9 게임 필터이다. 조건에 부합하는 숫자만 걸러낸다.
- 1 ~ 29 숫자가 들어있는 리스트에서 filter를 거치면 True를 반환하는 값들만 뽑아낸다.
- 첫 번째 인자에는 적용할 메서드가 들어가는데, lambda가 들어갈 수도 있다.

<br>

## reduce

```python
from functools import reduce
from collections import defaultdict

# user dataset
users = [{'mail': 'gregorythomas@gmail.com', 'name': 'Brett Holland', 'sex': 'M', 'age': 73},
         {'mail': 'hintoncynthia@hotmail.com', 'name': 'Madison Martinez', 'sex': 'F', 'age': 29},
         {'mail': 'wwagner@gmail.com', 'name': 'Michael Jenkins', 'sex': 'M', 'age': 51},
         {'mail': 'daniel79@gmail.com', 'name': 'Karen Rodriguez', 'sex': 'F', 'age': 32},
         {'mail': 'ujackson@gmail.com', 'name': 'Amber Rhodes', 'sex': 'F', 'age': 42}]

"""
:param acc 누산 값
:param curr 현재 순회 값
"""
# 마지막 인자는 초기값이다. 따라서 정수 계산 시 아래와 같이 표현한다면, 생략해도 동일한 표현이다.
age_sum = reduce(lambda acc, curr: acc + curr['age'], users, 0)
print(age_sum)  # 227

# 리스트의 extend는 '+' 연산자로도 가능하다.
mails = reduce(lambda acc, curr: acc + [curr['mail']], users, [])
print(mails)  # ['gregorythomas@gmail.com', 'hintoncynthia@hotmail.com', 'wwagner@gmail.com', 'daniel79@gmail.com', 'ujackson@gmail.com']


# 성별로 분류하기
def names_by_sex(acc, curr):
    sex = curr['sex']
    acc[sex].append(curr['name'])
    return acc


names_with_sex = reduce(names_by_sex, users, defaultdict(lambda: []))
print(names_with_sex)  # {'M': ['Brett Holland', 'Michael Jenkins'], 'F': ['Madison Martinez', 'Karen Rodriguez', 'Amber Rhodes']})
print(names_with_sex['M'])  # ['Brett Holland', 'Michael Jenkins']
print(names_with_sex['F'])  # ['Madison Martinez', 'Karen Rodriguez', 'Amber Rhodes']
```

- Python 3 부터는 reduce가 기본 모듈에서 빠져서, functools 에서 import 해서 사용해야 한다.
- 마지막 인자는 초기값이다. acc에 해당 값을 넣어두고 실행한다고 생각하면 편하다.
- Referernce by https://www.daleseo.com/python-functools-reduce/#reduce-%ED%95%A8%EC%88%98