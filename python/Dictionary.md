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
	dic['key2'] # 삭제된 key에 접근하면 KeyError 가 발생한다.
except KeyError:
	print('key2 가 정상적으로 삭제되었습니다.') # 따라서 이 부분이 실행된다.
```

- 파이썬의 딕셔너리에는 해시할 수만 있다면, 숫자, 문자열, 집합 등 불변 객체를 모두 key로 사용 가능하다.
- 대부분이 연산이 O(1)이다.
- 3.6 버전까지는 순서를 유지하지 않았다. 3.7버전 부터는 순서를 유지한다.

